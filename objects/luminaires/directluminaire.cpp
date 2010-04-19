#include "directluminaire.h"

DirectLuminaire::DirectLuminaire( const Vector &l, double E ) : Luminaire(){
    _l = l;
    _E = E;
}

Vector DirectLuminaire::l( const Point&, double ){
    return -_l.u();
}

double DirectLuminaire::E( const Point&, double ){
    return _E;
}

bool DirectLuminaire::S( Scene* scn, const Point &o, double t ){
    Vector d = l( o, t );
    Point  dummyP;
    Vector dummyN;
    return scn->ix( Ray( o, d, 0, 1.0, t ), dummyP, dummyN ) != NULL;
}
