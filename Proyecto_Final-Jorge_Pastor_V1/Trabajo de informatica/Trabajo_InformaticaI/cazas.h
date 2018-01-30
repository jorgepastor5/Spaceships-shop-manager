#ifndef CAZAS_H
#define CAZAS_H

#include <iostream>
#include <string.h>
#include <naves.h>

using namespace std;

class aplicacion;
class propietarios;

class cazas : public naves {

private:

    string arma1;
    string arma2;
    float velocidad_maxima;

public:
    cazas();
    void setArma1(string);
    string getArma1();
    void setArma2(string);
    string getArma2();
    void setVel_Max(float);
    float getVel_Max();
    float Asignar_Velocidad_Maxima();
    string Asignar_Arma1();
    string Asignar_Arma2();
    int Numero_Max_Tripulantes();
    ~cazas();
};

#endif // CAZAS_H
