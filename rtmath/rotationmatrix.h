#pragma once

#include "vector.h"

class RotationMatrix
{
private:
protected:
    vector<double> _R;
public:
    RotationMatrix();
    RotationMatrix( const Vector& v, const Vector& w );

    Vector rotateVect( const Vector &v, bool reversed=false );
};

