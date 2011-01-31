#include "orientation.h"

using namespace std;

Orientation::Orientation(){
    _d0 = Vector( 0, 0, -1 );
}

Orientation::Orientation( const Vector& d0 ){
    _d0 = d0;
}


Vector Orientation::d( double ){
    return _d0;
}

Vector Orientation::d0 ()
{
    return _d0;
}
