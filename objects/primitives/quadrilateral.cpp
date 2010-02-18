#include "quadrilateral.h"

using namespace std;

Quadrilateral::Quadrilateral() : Primitive(){}

Quadrilateral::Quadrilateral( Point &p0, Point &p1, Point &p2, Point &p3, Material *mat, Trajectory *traj ) : Primitive(mat,traj){
    // assert co-planarity?
    A = Triangle( p0, p1, p2, mat, traj );
    B = Triangle( p0, p2, p3, mat, traj );
}

Vector Quadrilateral::n( const Point &p, double t ) const{
    return A.n( p, t );
}

double Quadrilateral::ix( const Ray &r ) const{
    double t = A.ix( r );
    if( t > EPS )
        return t;
    t = B.ix( r );
    if( t > EPS )
        return t;
    return -1;
}
