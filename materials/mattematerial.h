#pragma once

#include "material.h"
#include "color.h"

class MatteMaterial : public Material{
protected:
    double _kDiff;
public:
    MatteMaterial();
    MatteMaterial( double kDiff, double kAmbi, const Color& shade );
    virtual ~MatteMaterial(){}

    virtual Color lDirect( Luminaire* lum, const Point &p, const Vector &n, const Ray& ry ) const;
};
