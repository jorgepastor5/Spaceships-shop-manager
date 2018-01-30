#ifndef NAVES_H
#define NAVES_H

#include <iostream>
#include <string.h>

using namespace std;

class propietarios;
class aplicacion;

class naves{

private:
    string propietario;
    string numero_registro;
    string tipo_propulsion;
    float precio;
    int numero_tripulantes;

public:
    naves();
    virtual int Numero_Max_Tripulantes()=0;
    void setPropietario(string);
    string getPropietario();
    void setNumeroRegistro(string);
    string getNumeroRegistro();
    void setPropulsion(string);
    string getPropulsion();
    void setPrecio(float);
    float getPrecio();
    void setTripulantes(int);
    int getTripulantes();
    string Asignar_Propietario();
    string Asignar_Numero_Registro();
    string Tipo_Propulsion();
    float Fijar_Precio();
    ~naves();
};

#endif // NAVES_H
