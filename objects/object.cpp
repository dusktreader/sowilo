#include "object.h"

Object::Object(){
    _traj = NULL;
    _ornt = NULL;
}

/// @todo Add a time constraint t0, t1 where the object only exists in the scene within that time frame
Object::Object( const Trajectory* traj, const Orientation* ornt ){
    _traj = traj;
    _ornt = ornt;
}

Point Object::p( double t ) const{
    ASSERT( _traj != NULL );
    return _traj->p( t );
}

Vector Object::d( double t ) const{
    ASSERT( _ornt != NULL );
    return _ornt->d( t );
}
