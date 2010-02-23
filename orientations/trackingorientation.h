#pragma once

#include "orientation.h"
#include "trajectory.h"

class TrackingOrientation : public Orientation{
private:
    Trajectory* _traj0;
    Trajectory* _traj1;

public:
    TrackingOrientation();
    TrackingOrientation( Trajectory* traj0, Trajectory* traj1 );

    virtual Vector d( double t );
};
