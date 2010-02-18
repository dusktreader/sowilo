#include "color.h"

using namespace std;

Color::Color() : Triple(){}

Color::Color( double r, double g, double b ) : Triple(r,g,b){}

Color::Color( const Triple &other ) : Triple(other){}

double Color::r() const{
    return val[0];
}

double Color::g() const{
    return val[1];
}

double Color::b() const{
    return val[2];
}

string Color::str() const{
    return "[ " + num2str(r()) + ", " + num2str(g()) + ", " +num2str(b()) + " ]";
}
