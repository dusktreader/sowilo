#pragma once

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
    Color l( Scene* scn, const Point &p, const Vector &n, const Ray& ry ) const;
    virtual Color lAmbient( Scene* scn ) const;
    virtual Color lIndirect( Scene* scn, const Point &p, const Vector &n, const Ray& ry ) const;
    virtual Color lDirect( Luminaire* lum, const Point &p, const Vector &n, const Ray& ry ) const;
    //Think of a pure virtual function
};
