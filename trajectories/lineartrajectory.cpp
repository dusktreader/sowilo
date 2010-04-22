#include "lineartrajectory.h"

using namespace std;

LinearTrajectory::LinearTrajectory() : Trajectory(){
    _d = Vector( 0.0, 0.0, 1.0 );
}

LinearTrajectory::LinearTrajectory( Vector& d, double V, Point& p0, double t0 ): Trajectory(p0,V,t0){
    _d = d;
}

Point LinearTrajectory::p( double t ) const{
    double t1 = t + _t0;
    return _p0 + _d * t1 * _V;
}
