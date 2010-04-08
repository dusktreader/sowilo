#pragma once

#include "vector.h"

class Orientation{
private:
protected:
    Vector _d0;
public:
    Orientation();
    virtual ~Orientation(){}
    Orientation( const Vector& d0 );
    virtual Vector d( double t );
};
