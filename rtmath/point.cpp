#include "point.h"

using namespace std;

Point::Point() : Triple(){}

Point::Point( double x, double y, double z ) : Triple(x,y,z){}

Point::Point( Triple other ) : Triple(other){}

Vector Point::operator-( const Point &other ) const{
    return Vector( x() - other.x(), y() - other.y(), z() - other.z() );
}

Point Point::operator+( const Vector &other ) const{
    return Point( other.i() + x(), other.j() + y(), other.k() + z() );
}

double Point::x() const{
    return val[0];
}

double Point::y() const{
    return val[1];
}

double Point::z() const{
    return val[2];
}

string Point::str() const{
    return "( " + num2str(x()) + ", " + num2str(y()) + ", " +num2str(z()) + " )";
}

