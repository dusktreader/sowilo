#include "rtmath.h"

using namespace std;

void calcRotateMat( const Vector& v, const Vector& w, vector<double>& R ){
    // optimize for w = Vector( 0, 0, 1 )
    double theta = acos( v.dotProduct(w) );
    if( theta == 0.0 )
        return;
    Vector u = v.crossProduct( w ).u();
    R.clear();
    double c = cos( theta ),
           s = sin( theta ),
           ui2 = u.i() * u.i(),
           uj2 = u.j() * u.j(),
           uk2 = u.k() * u.k(),
           uij = u.i() * u.j(),
           uik = u.i() * u.k(),
           ujk = u.j() * u.k();
    R.push_back( ui2+(1-ui2)*c     );  R.push_back( uij*(1-c)-u.k()*s );  R.push_back( uik*(1-c)+u.j()*s );
    R.push_back( uij*(1-c)+u.k()*s );  R.push_back( uj2+(1-uj2)*c     );  R.push_back( ujk*(1-c)-u.i()*s );
    R.push_back( uik*(1-c)-u.j()*s );  R.push_back( ujk*(1-c)+u.i()*s );  R.push_back( uk2+(1-uk2)*c     );
}

void rotateVect( const Vector& v, Vector& w, const vector<double>& R, bool reversed ){
    if( R.size() == 0 ){
        w = v;
        return;
    }
    Vector r0, r1, r2;
    if( reversed ){
        r0 = Vector( R[0], R[3], R[6] );
        r1 = Vector( R[1], R[4], R[7] );
        r2 = Vector( R[2], R[5], R[8] );
    }
    else{
        r0 = Vector( R[0], R[1], R[2] );
        r1 = Vector( R[3], R[4], R[5] );
        r2 = Vector( R[6], R[7], R[8] );
    }
    w = Vector( v.dotProduct(r0), v.dotProduct(r1), v.dotProduct(r2) );
}
