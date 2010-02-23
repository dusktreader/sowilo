#include "trackingorientation.h"

TrackingOrientation::TrackingOrientation() : Orientation(){
    _traj0 = NULL;
    _traj1 = NULL;
}

TrackingOrientation::TrackingOrientation( Trajectory* traj0, Trajectory* traj1 ) : Orientation(){
    _traj0 = traj0;
    _traj1 = traj1;
}

Vector TrackingOrientation::d( double t ){
    if( _traj0 == NULL || _traj1 == NULL )
        return _d0;
    return ( _traj1->p(t) - _traj0->p(t) ).u();
};
