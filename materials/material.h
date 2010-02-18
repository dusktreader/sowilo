#pragma once

#include <vector>

#include "scene.h"
#include "luminaire.h"
#include "point.h"
#include "vector.h"
#include "color.h"
#include "ray.h"

class Scene;
class Luminaire;

class Material{
private:
    double _kAmbi;
    Color _shade;
public:
    Material();
    Material( double kAmbi, const Color &shade );
    virtual ~Material(){}
    Color l( const Scene* scn, const Point &p, const Vector &n, const Ray& ry ) const;
    virtual Color lAmbient( const Scene* scn ) const;
    virtual Color lIndirect( const Scene* scn, const Point &p, const Vector &n, const Ray& ry ) const;
    virtual Color lDirect( const Luminaire* lum, const Point &p, const Vector &n, const Ray& ry ) const;
    //Think of a pure virtual function
};
