#include <iostream>
#include <string.h>
#include <stdlib.h>

#include "destructores.h"
#include <aplicacion.h>
#include <naves.h>

using namespace std;

destructores::destructores(){
}

void destructores::setNumeroArmas(int numero_armas){    //Paso el numero de armas y lo inicializo

    this->numero_armas = numero_armas;
}

int destructores::getNumeroArmas(){ //Para devolver el numero de armas

    int numero_armas = 0;

    numero_armas = tipo_armamento.size();

    return numero_armas;
}

void destructores::borrar_armas(){      //Borro armas para evitar que se guarden mas de la cuenta al recuperar datos del fichero ya que trabajo siempre con el mismo objeto

    tipo_armamento.clear();
}


void destructores::setTipoArmas(string tipo_armamento){     //Añade un el tipo de arma que se le pase por parametro (Usado en ficheros) y cuando no quiero modificar las armas de destructor

    this->tipo_armamento.push_back(tipo_armamento);
}

void destructores::setTipoArmas2(string tipo_armamento, int i){

    this->tipo_armamento[i] = tipo_armamento;
}

string destructores::getTipoArmas(int j){

    return tipo_armamento[j];
}

int destructores::Asignar_Numero_Armas(){       //Pide el numero de armas del destructor

    int numero_armas;
    string cadena;

    bool numero = true;

    do{
        numero=true;
        cout <<"Introduzca el numero de armas que tiene el destructor: ";
        cin>> cadena;

        for(unsigned i=0; i<cadena.length(); i++){

            if(!isdigit(cadena.at(i))){numero=false;}

        }

        if(numero){

            numero_armas = stoi(cadena);
        }

    }while(numero==false);


    return numero_armas;
}


void destructores::Asignar_Tipo_Armamento(int numero_armas){        //Asigno el tipo de armamento al dar de alta una nave o al modificarla

    char op;
    int cont = 0;

    borrar_armas();     //Me aseguro de que este vacio el vector tipo de armas

    cout << "\nElija " << numero_armas << " de las siguientes armas que equipa la nave: " << endl;
    cout << "\n1) Cañones de plasma.\n2) Misiles termonucleares.\n3) Rayos laser.\n4) PEM.\n" << endl;

    do{
        cout << "Introduzca el arma " << cont+1 << ": ";
        cin>>op;

        switch(op){


        case '1':

            tipo_armamento.push_back("Cañones de plasma");
            cont++;

            break;

        case '2':

            tipo_armamento.push_back("Misiles termonucleares");
            cont++;

            break;

        case '3':

            tipo_armamento.push_back("Rayos laser");
            cont++;

            break;

        case '4':

            tipo_armamento.push_back("PEM");
            cont++;

            break;

        default:

            cout << "\nOpción no válida." << endl;
            break;

        }

    }while((op!='1' || op!='2' || op!='3' || op!='4') && cont<numero_armas);

}

int destructores::Numero_Max_Tripulantes(){

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


destructores::~destructores(){
}
