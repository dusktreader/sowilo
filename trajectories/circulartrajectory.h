#pragma once

#include "trajectory.h"
#include "vector.h"
#include "point.h"
#include "tools.h"
#include <cmath>

class CircularTrajectory : public Trajectory{
protected:
    Vector _n;
    Vector _u;
    Vector _v;
    double _R;
public:
    CircularTrajectory();
    CircularTrajectory( Vector&n, double R, double V, Point& p0 );
    virtual Point p( double t ) const;
};
