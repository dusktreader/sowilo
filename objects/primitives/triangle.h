#pragma once

#include <vector>

#include "tools.h"

#include "vector.h"
#include "point.h"
#include "trajectory.h"
#include "primitive.h"

class Triangle : public Primitive{
private:
protected:
    Point  _p0;
    Point  _p1;
    double theta0;
    double theta1;
    double slope;
    Vector _n;
    std::vector<double> R;
public:
    Triangle();
    Triangle( Point &p0, Point &p1, Point &p2, Material* mat, Trajectory *traj, Orientation* ornt );
    virtual ~Triangle(){}

    virtual Vector n( const Point &p, double t ) const;
    virtual double ix( const Ray &r ) const;
};
