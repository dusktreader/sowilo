#include "circulartrajectory.h"

using namespace std;

CircularTrajectory::CircularTrajectory() : Trajectory(){
    _R = 0.0;
}

CircularTrajectory::CircularTrajectory( Vector& n, double R, double V, Point& p0 ) : Trajectory(p0,V){
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
    return Point( _u * _R * cos( _V * t ) + _v * _R * sin( _V * t ) + _p0 );
}
