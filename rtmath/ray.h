#pragma once

#include "point.h"
#include "vector.h"

class Ray{
private:
    Point _o;
    Vector _d;
    int _depth;
    double _nRefr;
    double _t0;
public:
    Ray();
    Ray( const Point &o, const Vector &d, int depth, double nRefr, double t0 );
    Point o() const;
    Vector d() const;
    Vector e() const;
    Point p( double D ) const;
    int depth() const;
    double nRefr() const;
    double t0() const;
};

