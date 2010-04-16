#pragma once

#include "scene.h"
#include "ray.h"
#include "point.h"
#include "vector.h"
#include "primitive.h"

class FutureScene : public Scene
{
public:
    FutureScene( double nRefr, Color &ambient, Color &background, int depthLim ) : Scene(nRefr,ambient,background,depthLim){}
    virtual ~FutureScene(){}
    virtual Primitive* ix( const Ray &r, Point &p, Vector &n );
};

