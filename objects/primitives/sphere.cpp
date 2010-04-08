#include "sphere.h"

using namespace std;

Sphere::Sphere() : Primitive(){
    _R = 1.0;
}

Sphere::Sphere( double R, Material* mat, Trajectory* traj, Orientation* ornt ) : Primitive(mat,traj,ornt){
    _R = R;
}

double Sphere::R() const{
    return _R;
}

Vector Sphere::n( const Point &q, double t )
{
    return ( q - p( t )  ).u();
}

double Sphere::ix( const Ray &r )
{
    Point c = p( r.t0() );
    Vector oc = ( r.o() - c );
    double B = 2.0 * r.d().dotProduct( oc );
    double C = pow( oc.m(), 2.0 ) - _R * _R;
    double temp = B * B - 4 * C;
    if( temp < EPS )
        return -1.0;
    temp = sqrt( temp );
    double D0 = ( -B + temp ) / ( 2 );
    double D1 = ( -B - temp ) / ( 2 );
    double D;
    if( D0 > EPS and D1 > EPS )
        D = min( D0, D1 );
    else if( D0 > EPS )
        D = D0;
    else if( D1 > EPS )
        D = D1;
    else
        return -1.0;
    return D;
}
