#include <iostream>
#include <string.h>

#include "propietarios.h"
#include <aplicacion.h>
#include <naves.h>


using namespace std;

propietarios::propietarios(){
}

void propietarios::setPlaneta(string planeta){

    this->planeta = planeta;
}

string propietarios::getPlaneta(){

    return planeta;
}


propietarios::~propietarios(){
}
