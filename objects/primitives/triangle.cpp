#include "triangle.h"

using namespace std;

Triangle::Triangle() : Primitive(){}

Triangle::Triangle( Point &p0, Point &p1, Point &p2, Material* mat, Trajectory *traj, Orientation* ornt ) : Primitive(mat,traj,ornt){
    Vector v01 = ( p1 - p0 );
    Vector v02 = ( p2 - p0 );
    Vector n = v01.crossProduct( v02 ).u();
    calcRotateMat( n, Vector(0,0,1), R );
    rotateVect( v01, v01, R );
    rotateVect( v02, v02, R );
    _p0 = v01;
    _p1 = v02;
    theta0 = atan( v01.j() / v01.i() );
    theta1 = atan( v02.j() / v02.i() );
    if( v02.i() < 0 )
        theta1 += PI;
    ASSERT( 0 <= theta0 && theta0 < theta1 && theta1 < PI );
    slope = ( _p0.y() - _p1.y() ) / ( _p0.x() - _p1.x() );
}

Vector Triangle::n( const Point &p, double t )
{
    return d( t );
}

double Triangle::ix( const Ray &r )
{

    calcRotateMat( d( r.t0() ), Vector(0,0,1), R );

    Vector v = r.o() - _traj->p( r.t0() );
    rotateVect( v, v, R );
    Point o = v;
    rotateVect( r.d(), v, R );
    double t = -o.z() / v.k();
    if( t < EPS )
        return -1;
    double x = o.x() + t * v.i();
    double y = o.y() + t * v.j();
    double theta = atan( y / x );
    if( x < 0 )
        theta += PI;
    if( theta < theta0 || theta > theta1 || y > _p0.y() + ( x - _p0.x() ) * slope )
        return -1;
    return t;
}
