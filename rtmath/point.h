#pragma once

#include "tools.h"

#include "triple.h"
#include "vector.h"

class Point: public Triple{
private:
public:
    Point();
    Point( double x, double y, double z );
    Point( Triple other );
    virtual ~Point(){}
    Vector operator-( const Point &other ) const;
    Point operator+( const Vector &other ) const;

    double x() const;
    double y() const;
    double z() const;

    virtual std::string str() const;
};

