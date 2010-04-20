#pragma once

#include <cfloat>

#include "luminaire.h"
#include "primitive.h"
#include "ray.h"
#include "color.h"
#include "vector.h"
#include "point.h"

class Primitive;

class Scene{
protected:
    double _nRefr;
    int _depthLim;
    Color _ambient;
    std::vector<Luminaire*> luminaires;
    std::vector<Primitive*> primitives;
    Color _background;

public:
    Scene( double nRefr, Color &ambient, Color &background, int depthLim );
    void addLuminaire( Luminaire* lum  );
    void addPrimitive( Primitive* prim );
    //remove method for luminaire and primitive
    Luminaire* luminaire( int i );
    virtual Primitive* ix( const Ray &r, Point &p, Vector &n );
    virtual Color trace( Ray &r );
    double nRefr() const;
    Color ambient() const;
};
