#ifndef APLICACION_H
#define APLICACION_H
#include <iostream>
#include <string.h>
#include <vector>

#include <propietarios.h>
#include <humanos.h>
#include <extraterrestres.h>
#include <naves.h>
#include <estaciones.h>
#include <cargueros.h>
#include <cazas.h>
#include <destructores.h>

using namespace std;

class humanos;
class estaciones;

class aplicacion{


private:

    vector <humanos> lista_humanos;
    vector <extraterrestres> lista_extraterrestres;
    vector <estaciones> lista_estaciones;
    vector <cargueros> lista_cargueros;
    vector <cazas> lista_cazas;
    vector <destructores> lista_destructores;

public:
    aplicacion();
    void Menu_Principal();
    void Menu_Propietarios();
    void Menu_Gestion_Naves();
    void alta_propietario();
    void baja_propietario();
    void modificar_propietario();
    void Mostrar_Propietarios();
    void alta_nave();
    void baja_nave();
    void modificar_nave();
    void Mostrar_Naves();
    void Comprar_Nave();
    bool Comprobar_Numero_Registro(string);
    void Escrbir_Usuarios_Registro();
    void Cargar_Usuarios_Registro();
    void Escribir_Naves_Registradas();
    void Cargar_Naves_Registradas();
    void Mostrar_Naves_Propietarios();
    void Escribir_Ventas(string, string, int);
    void Leer_Total_Ventas();
    void Leer_Total_Ventas_Fecha();
    void Modificar_Estacion();
    void Modificar_Destructor();
    void Modificar_Carguero();
    void Modificar_Caza();
    ~aplicacion();
};

#endif // APLICACION_H
