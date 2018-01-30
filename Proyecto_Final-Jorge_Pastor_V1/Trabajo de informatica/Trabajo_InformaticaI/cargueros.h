#ifndef CARGUEROS_H
#define CARGUEROS_H

#include <iostream>
#include <string.h>
#include <naves.h>


using namespace std;


class cargueros : public naves {
private:
    float carga_maxima;
    string velocidad_crucero;
    string escudo;

public:
    cargueros();
    void setCarga(float);
    float getCarga();
    void setVelocidad(string);
    string getVelocidad();
    void setEscudo(string);
    string getEscudo();
    float Asignar_Carga_Maxima();
    string Asignar_Vel_Crucero();
    string Asignar_Escudo();
    int Numero_Max_Tripulantes();
    ~cargueros();
};

#endif // CARGUEROS_H
