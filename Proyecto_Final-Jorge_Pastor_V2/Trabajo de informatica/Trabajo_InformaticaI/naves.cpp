#include <iostream>
#include <string.h>

#include "naves.h"
#include <aplicacion.h>
#include <propietarios.h>


using namespace std;

naves::naves(){
}

//Metodos get y set para inicializar y recuperar los atributos
void naves::setPropietario(string propietario){

    this->propietario = propietario;
}

string naves::getPropietario(){

    return propietario;
}

void naves::setNumeroRegistro(string numero_registro){

    this->numero_registro = numero_registro;
}

string naves::getNumeroRegistro(){

    return numero_registro;
}

void naves::setPropulsion(string tipo_propulsion){

    this->tipo_propulsion = tipo_propulsion;
}

string naves::getPropulsion(){

    return tipo_propulsion;
}

void naves::setPrecio(float precio){

    this->precio = precio;
}

float naves::getPrecio(){

    return precio;
}

void naves::setTripulantes(int numero_tripulantes){

    this->numero_tripulantes = numero_tripulantes;
}

int naves::getTripulantes(){

    return numero_tripulantes;
}

string naves::Asignar_Propietario(){        //Asigna el propietario a las naves

    string propietario;

    cout << "Introduzca el propietario de la nave a registrar: ";
    cin>>propietario;

    for(unsigned int i=0; i<propietario.length(); i++){

        propietario[i] = toupper(propietario[i]);
    }

    return propietario;     //Devuelve el propietario que luego

}

string naves::Asignar_Numero_Registro(){        //Metodo para comprobar el formato del numero de registro de las naves

    string numero_registro;
    int cont =0;
    int cont_final=0;

    do{
        cout << "Introduzca un numero de registro en formato LNNNNLLL: ";
        cin >> numero_registro;

        for(unsigned int i=0; i<numero_registro.length(); i++){

            numero_registro[i] = toupper(numero_registro[i]);
        }

        for(int i=0; i<1; i++){

            if(numero_registro[i]>='A' && numero_registro[i]<='Z'){

                cont++;
            }
        }

        for(int i=1; i<5; i++){

            if(numero_registro[i]>='0' && numero_registro[i]<='9'){

                cont++;
            }
        }

        for(unsigned int i=5; i<numero_registro.length(); i++){

            if(numero_registro[i]>='A' && numero_registro[i]<='Z'){

                cont++;
            }
        }

        if(cont==8){

            cont_final = cont;
        }

        cont =0;

    }while(numero_registro.length()!=8 || cont_final!=8);

    return numero_registro;
}

string naves::Tipo_Propulsion(){        //Asigna el tipo de propulsion de la nave espacial

    char op;
    string tipo_propulsion;

    cout << "\nElija el tipo de propulsión de la nave a registrar:" << endl;

    do{
        cout << "\n1) Motor de curvatura.\n2) Compresor de traza.\n3) Motor FTL.\n4) Velas Solares.\n5) Motor iónico.\n\n";
        cout << "Pulse una opción:"; cin>>op;
        cin.ignore(256, '\n');

        switch(op){

            case '1':
                tipo_propulsion = "Motor curvatura";

           break;

            case '2':
                tipo_propulsion = "Compresor traza";
            break;

            case '3':
                tipo_propulsion = "Motor FTL";
            break;

            case '4':
                tipo_propulsion = "Velas solares";
            break;

            case '5':
                tipo_propulsion = "Motor iónico";
            break;


            default: cout << "\nOpcion incorrecta.\n"<<endl;
            cout << "\nElija el tipo de propulsión de la nave a registrar:" << endl;

            break;

        }
    }while(op!='1' && op!='2' && op!='3' && op!='4' && op!='5');

    cout << "El tipo de motor seleccionado es: " << tipo_propulsion << "." << endl << endl;

    return tipo_propulsion;
}



float naves::Fijar_Precio(){

    float precio;
    string cadena;
    bool numero = true;
    char punto = '.';

    do{
        numero=true;
        cout<<"Introduce el precio de venta de la nave espacial: ";
        cin>> cadena;

        for(unsigned i=0; i<cadena.length(); i++){


            if(!isdigit(cadena.at(i)) && cadena.at(i)!=punto){numero=false;}
        }

        if(numero){precio = strtof(cadena.c_str(), 0);}

    }while(numero==false);

    return precio;
}

naves::~naves(){
}
