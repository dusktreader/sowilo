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
private:
    double _nRefr;
    int _depthLim;
    Color _ambient;
    std::vector<const Luminaire*> luminaires;
    std::vector<const Primitive*> primitives;
    Color _background;

public:
    Scene( double nRefr, Color &ambient, Color &background, int depthLim );
    void addLuminaire( const Luminaire* lum  );
    void addPrimitive( const Primitive* prim );
    //remove method for luminaire and primitive
    const Luminaire* luminaire( int i ) const;
    const Primitive* ix( const Ray &r, Point &p, Vector &n ) const;
    Color trace( Ray &r ) const;
    double nRefr() const;
    Color ambient() const;
};
