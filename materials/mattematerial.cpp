#include "mattematerial.h"

using namespace std;

MatteMaterial::MatteMaterial() : Material(){
    _kDiff = 0.0;
}

MatteMaterial::MatteMaterial( double kDiff, double kAmbi, const Color& shade ) : Material(kAmbi,shade){
    _kDiff = kDiff;
}

Color MatteMaterial::lDirect( const Luminaire* lum, const Point &p, const Vector &n, const Ray& ry ) const{
    return Color( 1.0, 1.0, 1.0 ) * _kDiff * n.dotProduct( lum->l( p, ry.t0() ) ) * lum->E( p, ry.t0() );
}
