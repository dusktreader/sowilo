#include "vector.h"

using namespace std;

Vector::Vector() : Triple(){}

Vector::Vector( double i, double j, double k ) : Triple( i, j, k ){}

Vector::Vector( Triple other ): Triple(other){}

double Vector::i() const
{
    return val[0];
}

double Vector::j() const
{
    return val[1];
}

double Vector::k() const
{
    return val[2];
}

double Vector::dotProduct( const Vector &other ) const
{
    return val[0] * other.val[0] + val[1] * other.val[1] + val[2] * other.val[2];
}

Vector Vector::crossProduct( const Vector &other ) const
{
    return Vector( j() * other.k() - k() * other.j(),
                   k() * other.i() - i() * other.k(),
                   i() * other.j() - j() * other.i() );
}

double Vector::m() const
{
    return sqrt( i() * i() + j() * j() + k() * k() );
}

Vector Vector::u() const
{
    return Vector( *this / ( m() ) );
}

Vector Vector::reflect( const Vector& other ) const
{
    Vector np = *this * 2 * this->dotProduct( other ) - other;
    return np.u();
}

Vector Vector::refract( const Vector &other, double nRefrI, double nRefrT ) const
{
    double eta = nRefrI / nRefrT;
    double en = this->dotProduct( other );
    double tmp = 1 - en * en;
    if( tmp <= 0.0 )
    {
        return Vector();
    }
    tmp = 1 - pow( eta * sqrt( tmp ), 2.0 );
    if( tmp <= 0.0 )
    {
        return Vector();
    }
    Vector d = ( *this * en ) * eta - *this * sqrt( tmp );
    return d.u();
}

string Vector::str() const
{
    return "< " + num2str(i()) + ", " + num2str(j()) + ", " +num2str(k()) + " >";
}
