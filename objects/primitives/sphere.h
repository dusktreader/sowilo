#pragma once

#include "primitive.h"
#include "vector.h"
#include "point.h"
#include "ray.h"

class Sphere : public Primitive{
private:
    double _R;
    Point  _c;
public:
    Sphere();
    Sphere( double r, const Material* mat, const Trajectory* traj, const Orientation* ornt );
    virtual ~Sphere(){}
    double R() const;
    virtual Vector n( const Point &q, double t ) const;
    virtual double ix( const Ray &r ) const;

};

