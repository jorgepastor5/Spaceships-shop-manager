#include <iostream>
#include <string.h>

#include "humanos.h"
#include <naves.h>
#include <aplicacion.h>
#include <propietarios.h>


using namespace std;


humanos::humanos(){
}

//Get y set para NIF
void humanos::setNIF(string NIF){

    this->NIF = NIF;
}

string humanos::getNIF(){

    return NIF;
}

//Metodo virtual para asignar planeta a humanos
string humanos::pedirPlaneta(){

    string planeta_procedencia = "Planeta Tierra";

    cout << "\nSu planeta de procedencia es 'El Planeta Tierra." << endl;

    return planeta_procedencia;
}

humanos::~humanos(){

}
