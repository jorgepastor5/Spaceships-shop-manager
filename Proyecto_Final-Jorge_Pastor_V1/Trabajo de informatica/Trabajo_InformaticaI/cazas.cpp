#include <iostream>
#include <string.h>

#include "cazas.h"
#include <naves.h>
#include <aplicacion.h>
#include <propietarios.h>

using namespace std;

cazas::cazas(){

}

//Metodos get y set para inicializar y recuperar atributos
void cazas::setArma1(string arma1){

    this->arma1=arma1;
}

string cazas::getArma1(){

    return arma1;
}

void cazas::setArma2(string arma2){

    this->arma2=arma2;
}

string cazas::getArma2(){

    return arma2;
}

void cazas::setVel_Max(float velocidad_maxima){

    this->velocidad_maxima = velocidad_maxima;
}

float cazas::getVel_Max(){

    return velocidad_maxima;
}

float cazas::Asignar_Velocidad_Maxima(){        //Asigno la velocidad maxima del caza

    float velocidad_maxima;
    string cadena;
    bool numero = true;
    char punto = '.';

    //Evito que salga del programa al introducir un caracter no deseado (Letras, comas...) distintos de numeros o puntos(tipo float)
    do{
        numero=true;
        cout << "Introduzca cúal es la velocidad máxima de la nave: ";
        cin>> cadena;

        for(unsigned i=0; i<cadena.length(); i++){


            if(!isdigit(cadena.at(i)) && cadena.at(i)!=punto){numero=false;}
        }

        if(numero){velocidad_maxima = strtof(cadena.c_str(), 0);}

    }while(numero==false);

    return velocidad_maxima;        //Devuelvo la la velocidad
}

string cazas::Asignar_Arma1(){      //Pido el tipo de arma

    char op;

    cout << "\nSeleccione 2 de las siguientes armas que equipa la nave: " << endl;
    cout << "\n1) Cañones de plasma.\n2) Misile nuclear.\n3) Rayos laser.\n4) PEM.\n" << endl;

    do{
        cout << "Introduzca el arma 1: ";
        cin>>op;

        switch(op){

        case '1':
            arma1 = "Cañones plasma";

            break;

        case '2':

            arma1 = "Misil nuclear";

            break;

        case '3':

            arma1 = "Rayos laser";

            break;

        case '4':

            arma1 = "PEM";

            break;

        default: cout << "\nOpción no válida.\n"; break;

        }

    }while(op!='1' && op!='2' && op!='3' && op!='4');

    return arma1;   //Devuelvo el tipo de arma

}

string cazas::Asignar_Arma2(){      //Pido el tipo de arma2

    char op;

    do{
        cout << "Introduzca el arma 2: ";
        cin>>op;

        switch(op){

        case '1':
            arma2 = "Cañon  plasma";

            break;

        case '2':

            arma2 = "Misil nuclear";

            break;

        case '3':

            arma2 = "Rayos laser";

            break;

        case '4':

            arma2 = "PEM";

            break;

        default: cout << "\nOpción no válida.\n"; break;

        }

    }while(op!='1' && op!='2' && op!='3' && op!='4');

    return arma2;   //Devuelvo el tipo de arma2
}

int cazas::Numero_Max_Tripulantes(){

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

                if(numero){

                    numero_tripulantes = stoi(cadena);
                }

            }while(numero_tripulantes!=1);

    return numero_tripulantes;
}

cazas::~cazas(){

}
