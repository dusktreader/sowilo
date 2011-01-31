#include "rtmath.h"

using namespace std;

Vector reflect( const Vector& n, const Vector& e )
{
    double en = n.dotProduct(e);
    Vector t = n * 2 * en - e;
    return t.u();
}

Vector refract( const Vector& n, const Vector& e, double nRefrI, double nRefrT )
{
    double eta = nRefrI / nRefrT;
    double en = n.dotProduct( e );
    double tmp = 1 - en * en;
    if( tmp < 0.0 )
        return Vector();
    tmp = 1 - pow( eta * sqrt( tmp ), 2 );
    if( tmp < 0.0 )
        return Vector();
    Vector t = ( n * en - e ) * eta - n * sqrt( tmp );
    return t.u();
}

double fresnel( const Vector& e, const Vector& n, double nRefrI, double nRefrT )
{
    double etaInv = nRefrT / nRefrI;
    double en  = e.dotProduct( n );
    double R0 = pow( ( etaInv - 1 ) / ( etaInv + 1 ), 2.0 );
    return R0 + ( 1 - R0 ) * pow( 1 - en, 5.0 );
}
