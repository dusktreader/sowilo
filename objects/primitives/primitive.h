#pragma once

#include "object.h"
#include "vector.h"
#include "point.h"
#include "ray.h"
#include "material.h"
#include "trajectory.h"
#include "orientation.h"

class Material;

class Primitive : public Object{
private:
    const Material* _mat;
public:
    Primitive();
    Primitive( Material* mat, Trajectory* traj, Orientation* ornt );
    virtual ~Primitive(){}
    void setMat( Material* mat );
    const Material* mat() const;
    virtual Vector n( const Point &p, double t ) = 0;
    virtual double ix( const Ray &r ) = 0;
};
