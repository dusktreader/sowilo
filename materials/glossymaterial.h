#pragma once

#include "material.h"
#include "color.h"

class GlossyMaterial : public Material
{
private:
    double _kSpec;
    double _xSpec;
    double _kDiff;
public:
    GlossyMaterial();
    GlossyMaterial( double kSpec, double xSpec, double kDiff, double kAmbi, const Color& shade );
    virtual ~GlossyMaterial(){}

    virtual Color lDirect( const Luminaire* lum, const Point &p, const Vector &n, const Ray& ry ) const;
};
