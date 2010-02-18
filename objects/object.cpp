#include "object.h"

Object::Object(){
    _traj = NULL;
}

// Perhaps an Object could have a time constraint t0, t1 where it only exists in the scene within that time frame
Object::Object( const Trajectory* traj ){
    _traj = traj;
}

Point Object::p( double t ) const{
    ASSERT( _traj != NULL );
    return _traj->p( t );
}
