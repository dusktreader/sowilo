#include "glassymaterial.h"

using namespace std;

GlassyMaterial::GlassyMaterial() : Material()
{
    _kRefr = 1.0;
    _nRefr = 1.66;
}

GlassyMaterial::GlassyMaterial( double kRefr, double nRefr, double kAmbi, const Color& shade ) : Material(kAmbi,shade)
{
    _kRefr = kRefr;
    _nRefr = nRefr;
}

Color GlassyMaterial::lIndirect( Scene *scn, const Point &p, const Vector &n, const Ray& ry ) const
{
    double en = ry.e().dotProduct( n );
    Vector dRefl = reflect( n, ry.e() );
    Ray ryRefl( p, dRefl, ry.depth() + 1, ry.nRefr(), ry.t0() );
    double nRefrI, nRefrT;
    Vector nI;
    if( en < 0.0 )
    {
        nRefrI = _nRefr;
        nRefrT = scn->nRefr();
        nI = -n;
    }
    else
    {
        nRefrI = scn->nRefr();
        nRefrT = _nRefr;
        nI = n;
    }
    Vector dRefr = refract( nI, ry.e(), nRefrI, nRefrT );
    double f = fresnel( ry.e(), nI, nRefrI, nRefrT );
    Color lRefl, lRefr;
    if( dRefr.m() < EPS )
    {
        lRefl = scn->trace( ryRefl );
    }
    else
    {
        Ray ryRefr( p, dRefr, ry.depth() + 1, nRefrT, ry.t0() );
        lRefl = scn->trace( ryRefl ) * f;
        lRefr = scn->trace( ryRefr ) * ( 1- f );
    }
    return ( lRefl + lRefr ) * _kRefr;
}
