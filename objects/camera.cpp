#include "camera.h"

using namespace std;

Camera::Camera() : Object(){}

Camera::Camera( const Scene* scn, const Trajectory* traj, Vector& e, Vector& u, int filmW, int filmH, double fovy ) : Object(traj){
    _scn = scn;
    _e = e;
    _u = u;
    _filmW = filmW;
    _filmH = filmH;
    _fovy = fovy * PI / 180;

    _z = -_e.u();
    _x = _u.crossProduct( _z ).u();
    _y = _z.crossProduct( _x ).u();
    _ZImg = _filmH / ( 2 * tan( _fovy / 2 ) );
}

Ray Camera::spawnRay( double i, double j, double t ){
    double x = j - _filmW / 2,
           y = _filmH / 2 - i,
           z = -_ZImg;
    Vector dWorld = Vector( _x * x + _y * y + _z * z );
    return Ray( this->p(t), dWorld, 0, _scn->nRefr(), t );
}

void Camera::render( double t, cv::Mat& img ){
    _img = cv::Mat_<cv::Vec3b>( cv::Size(_filmW,_filmH), cv::Vec3b(0,0,0) );
    img = _img;
    Color c;
    Ray r;
    #pragma omp parallel for private( c,r )
    for( int i=0; i<_filmH; i++ ){
        for( int j=0; j<_filmW; j++ ){
            r = spawnRay( i + 0.5, j + 0.5, t );
            c = _scn->trace( r );
            uchar r = (uchar)( min( 1.0, c.r() ) * 255 );
            uchar g = (uchar)( min( 1.0, c.g() ) * 255 );
            uchar b = (uchar)( min( 1.0, c.b() ) * 255 );
            _img( i, j ) = cv::Vec3b( b, g, r );
        }
    }
}

void Camera::render( double t, std::string fileName ){
    cv::Mat img;
    render( t, img );
    cv::imwrite( fileName, img );
}

void Camera::videoRender( double t0, double t1, int fps, const string& fileName ){
    ASSERT( t1 > t0 );
    double dt = 1.0 / fps;
    double T = (int)( ( t1 - t0 ) / dt );
    /*cv::VideoWriter recorder( fileName, CV_FOURCC('I','Y','U','V'), fps, cv::Size(_filmW,_filmH) );
    if( !recorder.isOpened() ){
        DB_REP;
        return;
    }*/
    cv::Mat frame;
    int i=0;
    for( double t=t0; t<t1; t+=dt ){
        cout << "rendering frame " << i++ << " of " << T << endl;
        render( t, frame );
        cv::imwrite( "op/"+num2str(t)+".png", frame );
        //recorder << frame;
    }
}
