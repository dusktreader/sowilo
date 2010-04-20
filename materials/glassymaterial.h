#pragma once

#include "material.h"

class GlassyMaterial : public Material{
private:
    double _nRefr;
    double _kRefr;
public:
    GlassyMaterial();
    GlassyMaterial( double kRefr, double nRefr, double kAmbi, const Color& shade );

    virtual Color lIndirect( Scene *scn, const Point &p, const Vector &n, const Ray& ry ) const;
};
