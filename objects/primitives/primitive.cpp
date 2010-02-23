#include "primitive.h"

using namespace std;

Primitive::Primitive() : Object(){
    _mat = NULL;
}

Primitive::Primitive( Material* mat, Trajectory* traj, Orientation* ornt ) : Object(traj,ornt){
    _mat = mat;
}

void Primitive::setMat( Material *mat ){
    _mat = mat;
}

const Material* Primitive::mat() const{
    return _mat;
}
