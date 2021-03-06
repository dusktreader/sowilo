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
    Quadrilateral( Point &p0, Point &p1, Point &p2, Point &p3, Material* mat, Trajectory *traj, Orientation* ornt );

    virtual Vector n( const Point &p, double t );
    virtual double ix( const Ray &r );
};
