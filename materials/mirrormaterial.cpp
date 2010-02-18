#include "mirrormaterial.h"

MirrorMaterial::MirrorMaterial() : Material(){
    _kRefl = 0.0;
}

MirrorMaterial::MirrorMaterial( double kRefl, double kAmbi, const Color& shade ) : Material(kAmbi,shade){
    _kRefl = kRefl;
}

Color MirrorMaterial::lIndirect( const Scene *scn, const Point &p, const Vector &n, const Ray& ry ) const{
    Vector d = n.reflect( ry.e() );
    Ray    rr( p, d, ry.depth() + 1, ry.nRefr(), ry.t0() );
    return scn->trace( rr ) * _kRefl;
}
