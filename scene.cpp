#include "scene.h"

using namespace std;

Scene::Scene( double nRefr, Color &ambient, Color &background, int depthLim ){
    _nRefr = nRefr;
    _ambient = ambient;
    _background = background;
    _depthLim = depthLim;
}

void Scene::addLuminaire( Luminaire* lum ){
    luminaires.push_back( lum );
}

Luminaire* Scene::luminaire( int i )
{
    Luminaire* lum;
    if( i<0 || i >= (int)luminaires.size() )
        lum = NULL;
    else
        lum = luminaires[i];
    return lum;
}

void Scene::addPrimitive( Primitive* prim ){
    primitives.push_back( prim );
}

Primitive* Scene::ix( const Ray &r, Point &p, Vector &n  )
{
    double D, DMin = DBL_MAX;
    Primitive* prim;
    for( int i=0; i<(int)primitives.size(); i++ ){
        D = primitives[i]->ix( r );
        if( D > EPS && D < DMin ){
            DMin = D;
            prim = primitives[i];
            p = r.p( D );
            n = prim->n( p, r.t0() );
        }
    }
    if( DMin == DBL_MAX )
        return NULL;
    else
        return prim;
}


Color Scene::trace( Ray &r )
{
    if( r.depth() > _depthLim )
        return Color();
    Point p;
    Vector n;
    Primitive* prim = ix( r, p, n );
    if( prim == NULL )
        return _background;
    else
        return prim->mat()->l( this, p, n, r );
}

double Scene::nRefr() const{
    return _nRefr;
}

Color Scene::ambient() const{
    return _ambient;
}
