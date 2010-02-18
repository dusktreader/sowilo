#include "ray.h"

Ray::Ray(){
    _depth = 0;
    _nRefr = 1.0;
    _t0 = 0.0;
}

Ray::Ray( const Point &o, const Vector &d, int depth, double nRefr, double t0 ){
    _o = o;
    _d = d.u();
    _depth = depth;
    _nRefr = nRefr;
    _t0 = t0;
}

Point Ray::o() const{
    return _o;
}

Vector Ray::d() const{
    return _d;
}

Vector Ray::e() const{
    return -_d;
}

Point Ray::p( double D ) const{
    return _o + ( _d * D );
}

int Ray::depth() const{
    return _depth;
}

double Ray::nRefr() const{
    return _nRefr;
}

double Ray::t0() const{
    return _t0;
}
