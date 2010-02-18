#pragma once

#include "tools.h"

#include "triple.h"

#define CLR_RED     Color( 1.0, 0.0, 0.0 )
#define CLR_GREEN   Color( 0.0, 1.0, 0.0 )
#define CLR_BLUE    Color( 0.0, 0.0, 1.0 )
#define CLR_YELLOW  Color( 1.0, 1.0, 0.0 )
#define CLR_CYAN    Color( 0.0, 1.0, 1.0 )
#define CLR_MAGENTA Color( 1.0, 0.0, 1.0 )
#define CLR_BLACK   Color( 0.0, 0.0, 0.0 )
#define CLR_WHITE   Color( 1.0, 1.0, 1.0 )
#define CLR_GRAY50  Color( 0.5, 0.5, 0.5 )

class Color : public Triple{
private:
public:
    Color();
    Color( double r, double g, double b );
    Color( const Triple& other );
    virtual ~Color(){}
    double r() const;
    double g() const;
    double b() const;

    virtual std::string str() const;
};

