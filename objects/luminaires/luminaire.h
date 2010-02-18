#pragma once

#include "vector.h"
#include "point.h"
#include "scene.h"
#include "trajectory.h"
#include "object.h"

class Scene;

class Luminaire : public Object{
protected:
public:
    Luminaire();
    Luminaire( const Trajectory* traj );
    virtual ~Luminaire(){}
    virtual Vector l( const Point &p, double t ) const = 0;
    virtual double E( const Point &p, double t ) const = 0;
    virtual bool   S( const Scene* scn, const Point &p, double t ) const = 0;
};

// It might be cool to have an on/off switch and some sort of fade factor so that after toggling, the light
// intensity fades in and out based on the elapsed time.  Using a time parameter it would also be possible to have
// flicker, pulse, and other such effects

// Also, if luminaires and primitives and camera all inherited from some base class that had a position, velocity
// and other such dynamic features, they could be made to move during an animation render
