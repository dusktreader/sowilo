#pragma once

#include "tools.h"

#include "rtmath.h"
#include "triple.h"

class Vector : public Triple{
private:
protected:
public:
    Vector();
    Vector( double i, double j, double k );
    Vector( Triple other );
    virtual ~Vector(){}
    double i() const;
    double j() const;
    double k() const;

    double dotProduct( const Vector &other ) const;
    Vector crossProduct( const Vector &other ) const;

    double m() const;
    Vector u() const;

    Vector reflect( const Vector& other ) const;
    Vector refract( const Vector& other, double nRefrI, double nRefrT ) const;

    virtual std::string str() const;

};

