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
    Sphere( double r, Material* mat, Trajectory* traj, Orientation* ornt );
    virtual ~Sphere(){}
    double R() const;
    virtual Vector n( const Point &q, double t );
    virtual double ix( const Ray &r );

};

