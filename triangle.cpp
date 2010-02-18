#include "triangle.h"

using namespace std;

Triangle::Triangle() : Primitive(){}

Triangle::Triangle( Point &p0, Point &p1, Point &p2, Material* mat, Trajectory *traj ) : Primitive(mat,traj){
    Vector v01 = ( p1 - p0 );
    Vector v02 = ( p2 - p0 );
    _n = v01.crossProduct( v02 ).u();
    calcRotateMat( _n, Vector(0,0,1), R );
    rotateVect( v01, v01, R );
    rotateVect( v02, v02, R );
    _p0 = v01;
    _p1 = v02;
    theta0 = atan( v01.j() / v01.i() );
    theta1 = atan( v02.j() / v02.i() );
    if( v02.i() < 0 )
        theta1 += PI;
    ASSERT( 0 <= theta0 && theta0 < theta1 && theta1 < PI );
    slope01 = ( _p0.y() - _p1.y() ) / ( _p0.x() - _p1.x() );
}

Vector Triangle::n( const Point &p, double t ) const{
    return _n;
}

double Triangle::ix( const Ray &r ) const{
    Vector rd = r.o();
    rotateVect( rd, rd, R );
    Point rp = rd;
    rotateVect( r.d(), rd, R, true );
    double t = -rp.z() / rd.k();
    if( t < EPS )
        return -1;
    double x = rp.x() + t * rd.i();
    double y = rp.y() + t * rd.j();
    double theta = atan( y / x );
    if( x < 0 )
        theta += PI;
    if( theta < theta0 || theta > theta1 || y > _p0.y() + ( x - _p0.x() ) * slope01 )
        return -1;
    return t;
}
