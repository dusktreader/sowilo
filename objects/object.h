#pragma once

#include "trajectory.h"
#include "point.h"

class Object{
protected:
    const Trajectory* _traj;
public:
    Object();
    Object( const Trajectory* traj );
    Point p( double t ) const;
};
