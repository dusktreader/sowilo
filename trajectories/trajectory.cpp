#include "trajectory.h"

Trajectory::Trajectory(){
    _V = 0.0;
}

Trajectory::Trajectory( const Point& p0, double V ){
    _V = V;
    _p0 = p0;
}

Point Trajectory::p( double t ) const{
    return _p0;
}

Point Trajectory::p0() const{
    return _p0;
}
