#include "triple.h"

using namespace std;

Triple::Triple(){
    val[0] = 0.0;
    val[1] = 0.0;
    val[2] = 0.0;
}

Triple::Triple( double v0, double v1, double v2 ){
    val[0] = v0;
    val[1] = v1;
    val[2] = v2;
}

Triple Triple::operator+( const Triple &other ) const{
    return Triple( val[0] + other.val[0], val[1] + other.val[1], val[2] + other.val[2] );
}

Triple Triple::operator+( const double scalar ) const{
    return Triple( val[0] + scalar, val[1] + scalar, val[2] + scalar );
}

Triple& Triple::operator+=( const Triple &other ){
    val[0] += other.val[0];
    val[1] += other.val[1];
    val[2] += other.val[2];
    return *this;
}

Triple Triple::operator-() const{
    return Triple( -val[0], -val[1], -val[2] );
}

Triple Triple::operator-( const Triple &other ) const{
    return *this + ( -other );
}

Triple& Triple::operator-=( const Triple &other ){
    val[0] -= other.val[0];
    val[1] -= other.val[1];
    val[2] -= other.val[2];
    return *this;
}

Triple Triple::operator*( const double scalar ) const{
    return Triple( scalar * val[0], scalar * val[1], scalar * val[2] );
}

Triple& Triple::operator*=( const double scalar ){
    val[0] *= scalar;
    val[1] *= scalar;
    val[2] *= scalar;
    return *this;
}

Triple Triple::operator* ( const Triple& other ) const{
    return Triple( val[0] * other.val[0], val[1] * other.val[1], val[2] * other.val[2] );
}

Triple& Triple::operator*=( const Triple &other ){
    val[0] *= other.val[0];
    val[1] *= other.val[1];
    val[2] *= other.val[2];
    return *this;
}

Triple Triple::operator/( const double scalar ) const{
    return *this * ( 1.0/scalar );
}

Triple& Triple::operator/=( const Triple &other ){
    val[0] /= other.val[0];
    val[1] /= other.val[1];
    val[2] /= other.val[2];
    return *this;
}

string Triple::str() const{
    return "{ " + num2str(val[0]) + ", " + num2str(val[1]) + ", " +num2str(val[2]) + " }";
}

std::ostream& operator<<( std::ostream&out, const Triple& self ){
    return out << self.str();
}
