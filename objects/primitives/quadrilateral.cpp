#include "quadrilateral.h"

using namespace std;

Quadrilateral::Quadrilateral() : Primitive(){}

Quadrilateral::Quadrilateral( Point &p0, Point &p1, Point &p2, Point &p3, Material *mat, Trajectory *traj, Orientation* ornt ) : Primitive(mat,traj,ornt){
    // assert co-planarity?
    A = Triangle( p0, p1, p2, mat, traj, ornt );
    B = Triangle( p0, p2, p3, mat, traj, ornt );
}

Vector Quadrilateral::n( const Point &p, double t )
{
    return A.n( p, t );
}

double Quadrilateral::ix( const Ray &r )
{
    double t = A.ix( r );
    if( t > EPS )
        return t;
    t = B.ix( r );
    if( t > EPS )
        return t;
    return -1;
}
