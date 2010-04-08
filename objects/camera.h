#pragma once

#include <QImage>
#include <QColor>

#include <cmath>

#include "scene.h"
#include "trajectory.h"
#include "orientation.h"
#include "object.h"
#include "point.h"
#include "vector.h"
#include "ray.h"

class Camera : public Object{
protected:
    Scene* _scn;
    Vector _e;
    Vector _u;
    int _filmW;
    int _filmH;
    double _fovy;

    Vector _z;
    Vector _x;
    Vector _y;
    double _ZImg;


public:
    Camera();
    Camera( Scene* scn, Trajectory* traj, Orientation* ornt, Vector& u, int filmW, int filmH, double fovy );
    Ray spawnRay( double i, double j, double t );
    void render( double t, QImage& qimg );
    void render( double t, const QString& fileName );
    void videoRender( double t0, double t1, int fps, const QString& baseName, const QString& extension );
};

