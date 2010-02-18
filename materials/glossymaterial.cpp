#include "glossymaterial.h"

using namespace std;

GlossyMaterial::GlossyMaterial() : Material(){
    _kSpec = 0.0;
    _xSpec = 0.0;
}

GlossyMaterial::GlossyMaterial( double kSpec, double xSpec, double kDiff, double kAmbi, const Color& shade ) : Material(kAmbi,shade){
    _kSpec = kSpec;
    _xSpec = xSpec;
    _kDiff = kDiff;
}

Color GlossyMaterial::lDirect( const Luminaire* lum, const Point &p, const Vector &n, const Ray& ry ) const{
    Vector r = n.reflect( ry.e() );
    double E = lum->E( p, ry.t0() );
    Vector l = lum->l( p, ry.t0() );
    double lDiff = E * _kDiff * n.dotProduct( l );
    double lr = l.dotProduct( r );
    if( lr < 0 )
        return Color( 1.0, 1.0, 1.0 ) * lDiff;
    double lSpec = E * _kSpec * pow( lr, _xSpec );
    return Color( 1.0, 1.0, 1.0 ) * ( lSpec + lDiff );
}
