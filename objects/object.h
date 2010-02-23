#pragma once

#include "trajectory.h"
#include "orientation.h"
#include "point.h"
#include "vector.h"

class Object{
protected:
    Trajectory* _traj;
    Orientation* _ornt;
public:
    Object();
    Object( Trajectory* traj, Orientation* ornt );
    Point p( double t ) const;
    Vector d( double t ) const;
};
