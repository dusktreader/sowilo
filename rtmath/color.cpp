#include "color.h"

using namespace std;

Color::Color() : Triple(){}

Color::Color( double r, double g, double b ) : Triple(r,g,b){}

Color::Color( const Triple &other ) : Triple(other){}

double Color::r() const{
    return val[0];
}

int Color::R() const
{
    return (int)( min( max( val[0], 0.0 ), 1.0 ) * 255.0 );
}

double Color::g() const{
    return val[1];
}

int Color::G() const
{
    return (int)( min( max( val[1], 0.0 ), 1.0 ) * 255.0 );
}
double Color::b() const{
    return val[2];
}

int Color::B() const
{
    return (int)( min( max( val[2], 0.0 ), 1.0 ) * 255.0 );
}


string Color::str() const{
    return "[ " + num2str(r()) + ", " + num2str(g()) + ", " +num2str(b()) + " ]";
}
