#include "camera.h"

using namespace std;

Camera::Camera() : Object(){}

Camera::Camera( Scene* scn, Trajectory* traj, Orientation* ornt, Vector& u, int filmW, int filmH, double fovy ) :
Object(traj,ornt)
{
    _scn = scn;
    _u = u;
    _filmW = filmW;
    _filmH = filmH;
    _fovy = fovy * PI / 180;

    _ZImg = _filmH / ( 2 * tan( _fovy / 2 ) );
}

Ray Camera::spawnRay( double i, double j, double t )
{

    _z = -d( t );
    _x = _u.crossProduct( _z ).u();
    _y = _z.crossProduct( _x ).u();
    double x = j - _filmW / 2,
           y = _filmH / 2 - i,
           z = -_ZImg;
    Vector dWorld = Vector( _x * x + _y * y + _z * z );
    return Ray( this->p(t), dWorld, 0, _scn->nRefr(), t );
}

void Camera::render( double t, QImage& qimg )
{
    qimg = QImage( _filmW, _filmH, QImage::Format_RGB888 );
    Color c;
    Ray r;

    #pragma omp parallel for private( c,r )
    for( int i=0; i<_filmH; i++ )
    {
        for( int j=0; j<_filmW; j++ )
        {
            r = spawnRay( i + 0.5, j + 0.5, t );
            c = _scn->trace( r );
            QColor qc( c.R(), c.G(), c.B() );
            qimg.setPixel( j, i, qc.rgb() );
        }
    }
}

void Camera::render( double t, const QString& fileName )
{
    QImage qimg;
    render( t, qimg );
    qimg.save( fileName );
}

void Camera::videoRender( double t0, double t1, int fps, const QString& baseName, const QString& extension )
{
    ASSERT( t1 > t0 );
    double dt = 1.0 / fps;
    double T = (int)( ( t1 - t0 ) / dt );
    int i=0;
    for( double t=t0; t<t1; t+=dt )
    {
        cout << "rendering frame " << i++ << " of " << T << endl;
        render( t, baseName + QString::number( t, 'f', 3 ) + extension );
    }
}
