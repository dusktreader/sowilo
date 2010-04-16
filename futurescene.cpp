#include "futurescene.h"

Primitive* FutureScene::ix( const Ray &r, Point &p, Vector &n )
{
    double DMin = DBL_MAX;
    Primitive* prim;
    #pragma mta assert parallel
    #pragma mta loop future
    for( int i=0; i<(int)primitives.size(); i++ )
    {
        double D = primitives[i]->ix( r );
        double d = readfe( DMin );
        if( D > EPS && D < d )
        {
            prim = primitives[i];
            p = r.p( D );
            n = prim->n( p, r.t0() );
            writeef( DMin, D )
        }
        else
            writeef( DMin, d );
    }
    if( DMin == DBL_MAX )
        return NULL;
    else
        return prim;
}
