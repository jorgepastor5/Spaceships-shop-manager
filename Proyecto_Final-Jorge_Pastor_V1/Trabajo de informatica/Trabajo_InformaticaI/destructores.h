#ifndef DESTRUCTORES_H
#define DESTRUCTORES_H

#include <stdlib.h>

#include <iostream>
#include <string.h>
#include <naves.h>
#include <vector>

using namespace std;


class destructores : public naves {

private:

    int numero_armas;
    vector <string> tipo_armamento;


public:
    destructores();
    void setNumeroArmas(int);
    int getNumeroArmas();
    void setTipoArmas(string);
    string getTipoArmas(int);
    int Asignar_Numero_Armas();
    void Asignar_Tipo_Armamento(int);
    void setTipoArmas2(string, int);
    void borrar_armas();
    int Numero_Max_Tripulantes();
    ~destructores();
};

#endif // DESTRUCTORES_H
