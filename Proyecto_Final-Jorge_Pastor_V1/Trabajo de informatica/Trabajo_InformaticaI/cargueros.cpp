#include <iostream>
#include <string.h>

#include <aplicacion.h>
#include <naves.h>
#include <cargueros.h>

using namespace std;

cargueros::cargueros(){
}

//Meodos get y set para inicializar y recuperar atributos
void cargueros::setCarga(float carga_maxima){

    this->carga_maxima = carga_maxima;
}

float cargueros::getCarga(){

    return carga_maxima;
}

void cargueros::setVelocidad(string velocidad_crucero){

    this->velocidad_crucero = velocidad_crucero;
}

string cargueros::getVelocidad(){

    return velocidad_crucero;
}

void cargueros::setEscudo(string escudo){

    this->escudo = escudo;
}

string cargueros::getEscudo(){

    return escudo;
}

//Asigna la carga maxima del carguero
float cargueros::Asignar_Carga_Maxima(){

    float carga_maxima;
    string cadena;
    bool numero = true;
    char punto = '.';

    //Evito que salga del programa al introducir un caracter no deseado (Letras, comas...) distintos de numeros o puntos(tipo float)
    do{
        numero=true;
        cout << "Introduzca la carga máxima de la nave: ";
        cin>> cadena;//Pido la carga

        for(unsigned i=0; i<cadena.length(); i++){


            if(!isdigit(cadena.at(i)) && cadena.at(i)!=punto){numero=false;}
        }

        if(numero){carga_maxima = strtof(cadena.c_str(), 0);}

    }while(numero==false);

    return carga_maxima;    //Devuelvo la carga
}

string cargueros::Asignar_Vel_Crucero(){        //Pregunta si tiene velocidad de crucero o no el carguero y se lo asigna

    char op;
    string velocidad_crucero;

    do{
        cout << "Pulse S si la nave tiene velocidad de crucero o N si no: ";
        cin >> op;
        op = toupper(op);

    }while(op!='S' && op!='N');

    if(op=='S'){

        velocidad_crucero = "Si";

    }else if(op=='N'){

        velocidad_crucero = "No";
    }

    return velocidad_crucero;
}

string cargueros::Asignar_Escudo(){           //Pregunta si tiene velocidad de crucero o no el carguero y se lo asigna

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

int cargueros::Numero_Max_Tripulantes(){

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

cargueros::~cargueros(){
}
