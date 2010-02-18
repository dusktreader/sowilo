#include "primitive.h"

using namespace std;

Primitive::Primitive() : Object(){
    _mat = NULL;
}

Primitive::Primitive( const Material* mat, const Trajectory* traj ) : Object(traj){
    _mat = mat;
}

void Primitive::setMat( const Material *mat ){
    _mat = mat;
}

const Material* Primitive::mat() const{
    return _mat;
}
