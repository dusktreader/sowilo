#pragma once

#include "trajectory.h"
#include "primitive.h"
#include "triangle.h"

class Quadrilateral : public Primitive{
protected:
    Triangle A;
    Triangle B;
public:
    Quadrilateral();
    Quadrilateral( Point &p0, Point &p1, Point &p2, Point &p3, Material* mat, Trajectory *traj, const Orientation* ornt );

    virtual Vector n( const Point &p, double t ) const;
    virtual double ix( const Ray &r ) const;
};
