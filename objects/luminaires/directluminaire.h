#pragma once

#include "luminaire.h"

class DirectLuminaire : public Luminaire{
protected:
    Vector _l;
    double _E;
public:
    DirectLuminaire( const Vector &l, double E );
    virtual ~DirectLuminaire(){}
    virtual Vector l( const Point& o, double t );
    virtual double E( const Point& o, double t );
    virtual bool   S( Scene* scn, const Point &p, double t );
};
