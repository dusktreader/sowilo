#include "material.h"

using namespace std;

Material::Material(){
    _kAmbi = 0.0;
    _shade = Color( 0.0, 0.0, 0.0 );
}


Material::Material( double kAmbi, const Color &shade ){
    _kAmbi = kAmbi;
    _shade = shade;
}

Color Material::l( const Scene* scn, const Point& p, const Vector& n, const Ray& ry ) const{
    Color lI = lIndirect( scn, p, n, ry );
    Color lD;
    Color lA = lAmbient( scn );
    const Luminaire *lum;
    Vector l;
    int i = 0;
    lum = scn->luminaire( i++ );
    while( lum != NULL ){
        l = lum->l( p, ry.t0() );
        if( n.dotProduct( l ) > 0 && !lum->S( scn, p, ry.t0() ) )
            lD += lDirect(lum, p, n, ry );
        lum = scn->luminaire( i++ );
    }
    return ( lI + lD + lA ) * _shade;
}

Color Material::lAmbient( const Scene* scn ) const{
    return scn->ambient() * _kAmbi;
}

Color Material::lIndirect( const Scene* scn, const Point &p, const Vector &n, const Ray& ry ) const{
    return Color();
}

Color Material::lDirect( const Luminaire* lum, const Point &p, const Vector &n, const Ray& ry ) const{
    return Color();
}
