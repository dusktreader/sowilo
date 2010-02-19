#pragma once

#include "trajectory.h"
#include "orientation.h"
#include "point.h"
#include "vector.h"

class Object{
protected:
    const Trajectory* _traj;
    const Orientation* _ornt;
public:
    Object();
    Object( const Trajectory* traj, const Orientation* ornt );
    Point p( double t ) const;
    Vector d( double t ) const;
};
