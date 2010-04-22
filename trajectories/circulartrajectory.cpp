#include "circulartrajectory.h"

using namespace std;

CircularTrajectory::CircularTrajectory() : Trajectory(){
    _R = 0.0;
}

CircularTrajectory::CircularTrajectory( const Vector& n, double R, double V, const Point& p0, double t0 ) : Trajectory(p0,V, t0){
    _n = n;
    _R = R;
    double phi = acos( n.k() );
    double theta = phi == 0 ? 0 : acos( n.i() / sin(phi) );
    phi -= PI / 2;
    double i = sin( phi ) * cos( theta ),
           j = sin( phi ) * sin( theta ),
           k = cos( phi );
    _u = Vector( i, j, k ).u();
    _v = _n.crossProduct( _u ).u();
}

Point CircularTrajectory::p( double t ) const{
    double t1 = t + _t0;
    return Point( _u * _R * cos( _V * t1 * 2 * PI) + _v * _R * sin( _V * t1 * 2 * PI ) + _p0 );
}
