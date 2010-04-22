#pragma once

#include "point.h"

class Trajectory
{
protected:
    double _V;
    Point _p0;
    double _t0;
public:
    Trajectory();
    Trajectory( const Point& p0, double V, double t0 );
    virtual ~Trajectory(){}
    virtual Point p( double t ) const;
    Point p0() const;
    double t0() const;
};
