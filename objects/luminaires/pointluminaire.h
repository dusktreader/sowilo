#pragma once

#include "point.h"
#include "vector.h"
#include "trajectory.h"
#include "luminaire.h"
#include "tools.h"

class PointLuminaire : public Luminaire
{
private:
    double _phi;
public:
    PointLuminaire();
    PointLuminaire( double phi, Trajectory* traj );
    virtual Vector l( const Point &o, double t ) const;
    virtual double E( const Point &o, double t ) const;
    virtual bool   S( const Scene* scn, const Point &p, double t ) const;
};
