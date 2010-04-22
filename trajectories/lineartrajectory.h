#pragma once

#include "trajectory.h"
#include "point.h"
#include "vector.h"

class LinearTrajectory : public Trajectory
{
protected:
    Vector _d;
public:
    LinearTrajectory();
    LinearTrajectory( Vector& d, double V, Point& p0, double t0 );
    virtual Point p( double t ) const;
};
