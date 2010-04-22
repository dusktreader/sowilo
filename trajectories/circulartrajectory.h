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
    CircularTrajectory( const Vector&n, double R, double V, const Point& p0, double t0 );
    virtual Point p( double t ) const;
};
