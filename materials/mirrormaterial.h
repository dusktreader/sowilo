#pragma once

#include "material.h"

class MirrorMaterial : public Material{
private:
    double _kRefl;
public:
    MirrorMaterial();
    MirrorMaterial( double _kRefl, double _kAmbi, const Color& shade );

    virtual Color lIndirect( const Scene *scn, const Point &p, const Vector &n, const Ray& ry ) const;
};
