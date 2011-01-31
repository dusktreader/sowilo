#pragma once


#include "tools.h"

#include "rotationmatrix.h"
#include "vector.h"
#include "point.h"
#include "trajectory.h"
#include "primitive.h"

class Triangle : public Primitive{
private:
protected:
    double E0;
    double E1;
    double E2;

    RotationMatrix R0;
    RotationMatrix R1;
    RotationMatrix R2;

public:
    Triangle();
    Triangle( const Point &p0, const Point &p1, const Point &p2, Material* mat, Trajectory *traj, Orientation* ornt );
    virtual ~Triangle(){}

    Point p0( double t );
    Point p1( double t );
    Point p2( double t );

    virtual Vector n( const Point &p, double t );
    virtual double ix( const Ray &r );
};
