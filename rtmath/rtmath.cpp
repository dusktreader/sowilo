#include "rtmath.h"

using namespace std;

void calcRotateMat( const Vector& v, const Vector& w, double R[] )
{
    double theta = acos( v.dotProduct(w) );
    if( theta == 0.0 )
        return;
    Vector u = v.crossProduct( w ).u();
    double c = cos( theta ),
           s = sin( theta ),
           ui2 = u.i() * u.i(),
           uj2 = u.j() * u.j(),
           uk2 = u.k() * u.k(),
           uij = u.i() * u.j(),
           uik = u.i() * u.k(),
           ujk = u.j() * u.k();
    R[0] = ui2+(1-ui2)*c    ;  R[1] = uij*(1-c)-u.k()*s;  R[2] = uik*(1-c)+u.j()*s;
    R[3] = uij*(1-c)+u.k()*s;  R[4] = uj2+(1-uj2)*c    ;  R[5] = ujk*(1-c)-u.i()*s;
    R[6] = uik*(1-c)-u.j()*s;  R[7] = ujk*(1-c)+u.i()*s;  R[8] = uk2+(1-uk2)*c    ;
}

void rotateVect( const Vector& v, Vector& w, const double R[], bool reversed )
{
    Vector r0, r1, r2;
    if( reversed )
    {
        r0 = Vector( R[0], R[4], R[7] );
        r1 = Vector( R[1], R[5], R[8] );
        r2 = Vector( R[2], R[6], R[9] );
    }
    else
    {
        r0 = Vector( R[0], R[1], R[2] );
        r1 = Vector( R[3], R[4], R[5] );
        r2 = Vector( R[6], R[7], R[8] );
    }
    w = Vector( v.dotProduct(r0), v.dotProduct(r1), v.dotProduct(r2) );
}

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
