#pragma once

#include "tools.h"


class Triple{
protected:
    double val[3];
public:
    Triple();
    Triple( double v0, double v1, double v2 );
    virtual ~Triple(){}
    virtual Triple  operator+ ( const Triple& other ) const;
    virtual Triple  operator+ ( const double scalar ) const;
    virtual Triple& operator+=( const Triple& other );
    virtual Triple  operator- () const;
    virtual Triple  operator- ( const Triple& other ) const;
    virtual Triple& operator-=( const Triple& other );
    virtual Triple  operator* ( const double scalar ) const;
    virtual Triple& operator*=( const double scalar );
    virtual Triple  operator* ( const Triple& other ) const;
    virtual Triple& operator*=( const Triple& other );
    virtual Triple  operator/ ( const double scalar ) const;
    virtual Triple& operator/=( const Triple& other );

    virtual std::string str() const;
    friend std::ostream& operator<<( std::ostream& out, const Triple& self );
};

