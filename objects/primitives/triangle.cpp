#include "triangle.h"

using namespace std;

Triangle::Triangle() : Primitive(){}

Triangle::Triangle( const Point &p0, const Point &p1, const Point &p2, Material* mat, Trajectory *traj, Orientation* ornt ) : Primitive(mat,traj,ornt)
{
    Vector d0 = p0 - traj->p0();
    E0 = d0.m();
    R0 = RotationMatrix( ornt->d0(), d0 );

    Vector d1 = p1 - traj->p0();
    E1 = d1.m();
    R1 = RotationMatrix( ornt->d0(), d1 );

    Vector d2 = p2 - traj->p0();
    E2 = d2.m();
    R2 = RotationMatrix( ornt->d0(), d2 );
}

Point Triangle::p0( double t )
{
    return _traj->p( t ) + R0.rotateVect( _ornt->d( t ) ) * E0;
}

Point Triangle::p1( double t )
{
    return _traj->p( t ) + R1.rotateVect( _ornt->d( t ) ) * E1;
}

Point Triangle::p2( double t )
{
    return _traj->p( t ) + R2.rotateVect( _ornt->d( t ) ) * E2;
}

Vector Triangle::n( const Point&, double t )
{
    Vector u = p1( t ) - p0( t );
    Vector v = p2( t ) - p0( t );
    return u.crossProduct( v ).u();
}

double Triangle::ix( const Ray& r )
{
    // Moeller, Trumbore: Fast, minimum storage ray/triangle intersection
    Vector e1 = p1( r.t0() ) - p0( r.t0() );
    Vector e2 = p2( r.t0() ) - p0( r.t0() );
    Vector  p = r.d().crossProduct( e2 );
    double D = e1.dotProduct( p );
    if( det < EPS )
        return -1;
    Vector  t = r.o() - p0( r.t0() );
    double U = t.dotProduct( p );
    if( U < EPS || U > D )  // less than check might need to use 0.0 instead of EPS
        return -1;
    Vector  q = t.crossProduct( e1 );
    double V = r.d().dotProduct( q );
    if ( V < EPS || U + V > D )
        return -1;
    double t = e1.dotProduct( q ) / D;
    return t;
}

