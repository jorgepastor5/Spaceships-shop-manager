#ifndef ESTACIONES_H
#define ESTACIONES_H

#include <iostream>
#include <string.h>
#include <aplicacion.h>
#include <naves.h>

using namespace std;

class estaciones : public naves {

private:

    string escudo;
    int numeroMax_pasajeros;
    int numero_hangares;

public:
    estaciones();
    void setEscudo(string);
    string getEscudo();
    void setPasajeros(int);
    int getPasajeros();
    void setHangares(int);
    int getHangares();
    int Asignar_Pasajeros();
    int Asignar_Hangares();
    string Asignar_Escudo();
    int Numero_Max_Tripulantes();
    ~estaciones();
};

#endif // ESTACIONES_H
