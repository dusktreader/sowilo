#include "trajectory.h"

Trajectory::Trajectory(){
    _V = 0.0;
    _t0 = 0.0;
}

Trajectory::Trajectory( const Point& p0, double V, double t0 ){
    _V = V;
    _p0 = p0;
    _t0 = t0;
}

Point Trajectory::p( double ) const
{
    return _p0;
}

Point Trajectory::p0() const
{
    return _p0;
}

double Trajectory::t0() const
{
    return _t0;
}
