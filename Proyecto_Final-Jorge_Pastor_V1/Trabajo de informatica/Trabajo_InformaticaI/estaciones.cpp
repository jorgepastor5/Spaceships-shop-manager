#include <iostream>
#include <string.h>

#include "estaciones.h"
#include <aplicacion.h>
#include <propietarios.h>
#include <naves.h>


using namespace std;

estaciones::estaciones(){
}

//Metodos get y set para inicializar y recuperar atributos
void estaciones::setEscudo(string escudo){

    this->escudo = escudo;
}

string estaciones::getEscudo(){

    return escudo;
}

void estaciones::setPasajeros(int numeroMax_pasajeros){

    this->numeroMax_pasajeros = numeroMax_pasajeros;
}

int estaciones::getPasajeros(){

    return numeroMax_pasajeros;
}

void estaciones::setHangares(int numero_hangares){

    this->numero_hangares = numero_hangares;
}

int estaciones::getHangares(){

    return numero_hangares;
}

//Asignar pasajeros a las estaciones
int estaciones::Asignar_Pasajeros(){

    int numeroMax_pasajeros;
    string cadena;
    bool numero = true;

    //Evito salidas del programa por introducir caracteres que no sean numericos
    do{
        numero=true;
        cout << "Introduzca el numero máximo de pasajeros que admite la nave: ";
        cin>> cadena;

        for(unsigned i=0; i<cadena.length(); i++){

            if(!isdigit(cadena.at(i))){numero=false;}

        }

        if(numero){numeroMax_pasajeros = stoi(cadena);}

    }while(numero==false);

    return numeroMax_pasajeros;     //Devuelvo pasajeros
}

int estaciones::Asignar_Hangares(){     //Asigno numero de angares

    int numero_hangares;
    string cadena;
    bool numero = true;

    //Evito salidas del programa por introducir caracteres que no sean numericos
    do{
        numero=true;
        cout <<"Introduzca el numero de hangares que tiene la nave: ";
        cin>> cadena;

        for(unsigned i=0; i<cadena.length(); i++){

            if(!isdigit(cadena.at(i))){numero=false;}

        }

        if(numero){numero_hangares = stoi(cadena);}

    }while(numero==false);


    return numero_hangares;
}

string estaciones::Asignar_Escudo(){        //Asigno si tiene escudo o no la estacion

    char op;
    string escudo;

    do{

        cout << "Pulse S si la nave tiene escudo o N si no: ";
        cin >> op;
        op = toupper(op);

    }while(op!='S' && op!='N');

    if(op=='S'){

        escudo = "Si";

    }else if(op=='N'){

        escudo = "No";
    }

    return escudo;
}

int estaciones::Numero_Max_Tripulantes(){

    int numero_tripulantes;
    string cadena;
    bool numero = true;

    do{
        numero=true;
        cout << "Introduzca el numero máximo de tripulantes de la nave: ";
        cin >> cadena;

        for(unsigned i=0; i<cadena.length(); i++){

            if(!isdigit(cadena.at(i))){numero=false;}

        }

        if(numero){numero_tripulantes = stoi(cadena);}

    }while(numero==false);


    return numero_tripulantes;
}

estaciones::~estaciones(){
}
