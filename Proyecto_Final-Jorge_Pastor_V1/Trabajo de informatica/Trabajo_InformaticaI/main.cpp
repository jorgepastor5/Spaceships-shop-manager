#include <iostream>
#include <string.h>

#include <aplicacion.h>
#include <naves.h>
#include <cargueros.h>
#include <cazas.h>
#include <destructores.h>
#include <estaciones.h>
#include <propietarios.h>
#include <humanos.h>
#include <extraterrestres.h>


using namespace std;
class aplicacion;

int main()
{

    aplicacion app;

    //Al iniciar la aplicación cargo los ficheros de usuarios y de naves
    app.Cargar_Usuarios_Registro();
    app.Cargar_Naves_Registradas();

    //Llamo al menu principal de la aplicación
    app.Menu_Principal();

    return 0;
}
