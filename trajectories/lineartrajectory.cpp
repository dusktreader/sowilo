#include "lineartrajectory.h"

using namespace std;

LinearTrajectory::LinearTrajectory() : Trajectory(){
    _d = Vector( 0.0, 0.0, 1.0 );
}

LinearTrajectory::LinearTrajectory( Vector& d, double V, Point& p0 ): Trajectory(p0,V){
    _d = d;
}

Point LinearTrajectory::p( double t ) const{
    return _p0 + _d * t * _V;
}
