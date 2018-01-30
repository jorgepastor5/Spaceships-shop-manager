#include <iostream>
#include <string.h>

#include "extraterrestres.h"
#include <naves.h>
#include <aplicacion.h>
#include <propietarios.h>

using namespace std;

extraterrestres::extraterrestres(){
}

//Get y set para nie
void extraterrestres::setNIE(string NIE){

    this->NIE = NIE;
}

string extraterrestres::getNIE(){

    return NIE;
}

//Metodo viertual para asignar el planet a extraterrestres
string extraterrestres::pedirPlaneta(){

    string planeta_procedencia;

    cout << "Introduzca su planeta de procedencia: ";
    cin >> planeta_procedencia;

    cout << "\nSu planeta de procedencia es " << planeta_procedencia << "." << endl;

    return planeta_procedencia;
}

extraterrestres::~extraterrestres(){

}
