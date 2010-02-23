#include "pointluminaire.h"

using namespace std;

PointLuminaire::PointLuminaire(){
    _phi = 0.0;
}

PointLuminaire::PointLuminaire( double phi, Trajectory* traj ) : Luminaire(traj){
    _phi = phi;
}

Vector PointLuminaire::l( const Point &o, double t ) const{
    return ( p( t ) - o ).u();
}

double PointLuminaire::E( const Point &o, double  t ) const{
    double m = ( o - p( t ) ).m();
    return _phi / ( 4 * PI * m * m );
}

bool PointLuminaire::S( Scene* scn, const Point &o, double t ) const{
    Point  pt = p(t);
    Vector d = pt - o;
    Point  q;
    Vector dummyN;
    if( scn->ix( Ray( o, d, 0, 1.0, t ), q, dummyN ) == NULL )
        return false;
    Vector s = q - o;
    return s.m() < d.m();
}
