#pragma once

#include <vector>
#include <cmath>

#include "vector.h"

#define RAND_INT( lo, hi ) ( rand() % ( ( hi ) - ( lo ) ) + ( lo ) )
#define RAND_DBL ( (double)rand() / RAND_MAX )
#ifndef EPS
#define EPS 1e-10
#endif
#ifndef PI
#define PI 3.1415926535897932
#endif

class Vector;

void calcRotateMat( const Vector& v, const Vector& w, std::vector<double>& R );

void rotateVect( const Vector& v, Vector& w, const std::vector<double>& R, bool reversed=false );

