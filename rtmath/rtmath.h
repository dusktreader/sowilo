#pragma once

#include <vector>
#include <cmath>

#include "vector.h"

#define RAND_INT( lo, hi ) ( rand() % ( ( hi ) - ( lo ) ) + ( lo ) )
#define RAND_DBL ( (double)rand() / RAND_MAX )
#ifndef EPS
#define EPS 1e-6
#endif
#ifndef PI
#define PI 3.1415926535897932
#endif

class Vector;

void calcRotateMat( const Vector& v, const Vector& w, double R[] );

void rotateVect( const Vector& v, Vector& w, const double R[], bool reversed=false );

Vector reflect( const Vector& n, const Vector& e );

Vector refract( const Vector& n, const Vector& e, double nRefrI, double nRefrT );

double fresnel( const Vector& e, const Vector& n, double nRefrI, double nRefrT );
