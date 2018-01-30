#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>

#include "aplicacion.h"
#include <propietarios.h>
#include <extraterrestres.h>
#include <humanos.h>
#include <naves.h>
#include <cargueros.h>
#include <cazas.h>
#include <destructores.h>
#include <estaciones.h>

using namespace std;

aplicacion::aplicacion(){
}

//Menú principal donde se llamará a distintos submenús y funciones
void aplicacion::Menu_Principal(){

    char op;

    cout << "***BIENVENIDO A NUESTRA APLICACION DE VENTA DE NAVES ESPACIALES***" << endl;


    do
    {
       cout << "\n*****MENU PRINCIPAL*****" << endl;
       cout << "\na) Gestionar perfil de propietarios.\n"
               "b) Gestionar naves espaciales.\n"
               "c) Compra de naves espaciales.\n"
               "d) Mostrar naves registradas por propietarios.\n"
               "e) Mostrar el historico de naves vendidas.\n"
               "f) Busqueda de ventas por fecha\n"
               "g) Guardar los cambios realizados.\n"
               "h) Salir del programa.\n"<<endl;

       cout << "¿Que operacion desea realizar? ";  cin >> op;
       cin.ignore(256, '\n');

       switch(op)
       {

       case 'a':

           Menu_Propietarios(); //Submenú propietarios

       break;

       case 'b':

           Menu_Gestion_Naves(); //Submenú par naves

       break;

       case 'c':

           Comprar_Nave(); //Llamada a la funcion para compra naves

       break;

       case 'd':

           Mostrar_Naves_Propietarios(); //Muestra la spropiedades de los usuarios registrados

       break;

       case 'e':

           Leer_Total_Ventas(); //Muestra todas las ventas realizadas en el sistema

       break;

       case 'f':

           Leer_Total_Ventas_Fecha(); //Muestra las ventas del sistema en una fecha introducida por consola

           break;

       case 'g':

           //Opción para guardar los cambios realizados en el sistema
           Escrbir_Usuarios_Registro();
           Escribir_Naves_Registradas();

           cout << "\nDatos guardados con éxito.\n" << endl;


       break;

       case 'h':
            cout << "\nUsted ha salido del programa.\nGracias por usar nuestros servicios.\n" << endl; //Opción para salir del programa
            return;
       break;

       default: cout<<"\nOpcion no válida."<<endl; break;


       }

    }while(op != 'h');

}

//Submenu de gestión de propietarios
void aplicacion::Menu_Propietarios(){

    char op;

    do
    {
       cout << "\n***USTED HA ACCEDIDO AL MENÚ DE GESTIÓN DE USUARIOS***" << endl;
       cout << "\n1) Dar de alta un nuevo propietario.\n"
               "2) Dar de baja a un propietario.\n"
               "3) Modificar un propietario existente.\n"
               "4) Mostrar Propietarios registrados.\n"
               "5) Volver al menu principal.\n"<<endl;

       cout << "¿Que operacion desea realizar?";  cin >> op;
       cin.ignore(256, '\n');


       switch(op)
       {
       case '1':

           alta_propietario(); //Funcion para dar de alta un propietario
       break;

       case '2':

           baja_propietario(); //Funcion para dar de baja un propietario junto con sus naves asociadas

       break;

       case '3':

           modificar_propietario(); //Funcion que modifica un propietario

       break;

       case '4':

           Mostrar_Propietarios();//Muestro todos los propietarios registrados en el sistema

       break;

       case '5':
           return; //Vuelta al menu principal
        break;

       default: cout<<"\nOpcion no válida."<<endl; break;
       }

    }while(op != '5');

}

//Submenu de gestion de naves espaciales
void aplicacion::Menu_Gestion_Naves(){

    char op;

    do
    {
       cout << "\n***USTED HA ACCEDIDO AL MENÚ DE GESTIÓN DE NAVES***" << endl;
       cout << "\n1) Dar de alta una nueva nave espacial.\n"
               "2) Dar de baja una nave espacial.\n"
               "3) Modificar una nave espacial existente.\n"
               "4) Mostrar naves registradas en el sistema.\n"
               "5) Volver al menu principal.\n"<<endl;

       cout << "¿Que operacion desea realizar? ";
       cin >> op;
       cin.ignore(256, '\n');


       switch(op)
       {
       case '1':

           alta_nave(); //Función para dar de alta una nueva nave espacial

       break;

       case '2':

           baja_nave(); //Funcion da de baja una nave espacial

       break;

       case '3':

           modificar_nave(); //modifico naves espaciales asociadas

       break;

       case '4':

           Mostrar_Naves(); //Muestra todas las naves registradas en el sistema

        break;

        case '5':
           return; //Vuelta al menu principal
        break;

       default: cout<<"\nOpcion no válida."<<endl; break;
       }

    }while(op!= '5');

}

void aplicacion::alta_propietario(){

    //Objetos d ela colase humanos y extraterresres
    humanos registrar_humano;
    extraterrestres registrar_extraterrestre;

    string usuario;
    string planeta;
    bool flag=true;

    cout<<"\n***ALTA PROPIETARIO***\n"<<endl;

    do{
        cout<<"Introduce un numero de usuario en formato [NNNNNNNNL] ó [NNNNNNNNNN]: ";
        cin>> usuario;

        //Inicializo los flags de comprobacion del formato del usuario
        flag=true;

        //Evito que los datos introducidos sean sensibles a minusculas convirtiendo todo a mayusculas
        for(unsigned int i=0; i<usuario.length(); i++){
            usuario[i] = toupper(usuario[i]);
        }


        //Compruebo si es formato de usuario humano recorriendo la cadena introducida
        if(usuario.length()==9){
        for(unsigned int i=0; i<usuario.length()-1; i++){

            if(!isdigit(usuario.at(i))){

                flag=false; //Cambio un flag de comprobacion del formato para salir del bucle

            }
        }

        if(isdigit(usuario[9])){flag=false;}
        }

        if(usuario.length()==10){
        //Compruebo si es formato de usuario extraterrestre
        for(unsigned int i=0; i<usuario.length(); i++){

            if(!isdigit(usuario.at(i))){

                flag=false;//Cambio el flag para poder salir del bucle
            }
        }
        }

        //Compruebo que el humano no este registrado
        for(unsigned int i=0; i<lista_humanos.size(); i++){

            //Si el usuario ya esta registrado cambio los flags y vuelvo a pedir los datos hasta que se introduzcan correctamente
            if(lista_humanos[i].getNIF() == usuario){

                cout << "\nUsuario ya registrado.\n" << endl;
                flag=false;
            }

        }

        //Compruebo que el humano no este registrado
        for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

            if(lista_extraterrestres[i].getNIE() == usuario){

                cout << "\nUsuario ya registrado.\n" << endl;
                flag=false;
            }

        }

    }while((usuario.length()<9 || usuario.length()>10) || (flag==false));

    //Si el formato introducido es el de humano
    if(usuario.length()==9){

        registrar_humano.setNIF(usuario); //Si es formato humano inicializo el atributo NIF
        planeta = registrar_humano.pedirPlaneta();  //Pido el planeta con el metodo virtual pedir planeta que registra el planeta tierra automaticamente
        registrar_humano.setPlaneta(planeta);       //Inicializo el planeta del humano

        lista_humanos.push_back(registrar_humano);  //Registro humano

        cout << "\nUsted se ha registrado como humano satisfactoriamente.\n";
    }


    if(usuario.length()==10){

        registrar_extraterrestre.setNIE(usuario); //Si es formato extraterrestre inicializo el atributo NIE
        planeta = registrar_extraterrestre.pedirPlaneta();  //Pido el planeta con el metodo virtual pedir Planeta y selecciono por teclado el planeta de procedencia
        registrar_extraterrestre.setPlaneta(planeta);       //Inicializo el planeta del extraterrestre registrado

        lista_extraterrestres.push_back(registrar_extraterrestre);  //Registro extraterrestre
        cout << "\nUsted se ha registrado como extraterrestre satisfactoriamente.\n";
    }
}

void aplicacion::baja_propietario(){

    char op;
    unsigned int numero_registro;
    bool numero = true;
    string cadena;

    cout << "\n***BAJA PROPIETARIO***"<<endl;

    //Compruevo si hay usuarios registados en el sistema para dar de baja
    if(lista_humanos.size()==0 && lista_extraterrestres.size()==0){

        cout<<"\nNo hay usuarios registrados para dar de baja."<<endl;
        return; //Si no los hay retorno al menú principal
    }

    //Si hay usuarios:
    do{
            //Pido el tipo de usuario que deseo dar de baja
            cout << "Pulse H si desea dar de baja a un humano o E desea dar de baja a un extraterrestre: ";
            cin >> op;
            cin.ignore(256, '\n');
            op = toupper(op);

            //Compruebo que existan usuarios del tipo seleccionado
            if(op=='H' && lista_humanos.size()==0){

                cout << "\nNo hay humanos para dar de baja.\nPruebe a dar de baja un extraterrestre.\n"<<endl;

            }else if(op=='E' && lista_extraterrestres.size()==0){

                cout << "\nNo hay extraterrestres para dar de baja.\nPruebe a dar de baja un humano.\n"<<endl;
            }


    }while((op!='H' && op!='E') || (op=='H' && lista_humanos.size()==0)|| (op=='E' && lista_extraterrestres.size()==0));

    if(op=='H'){

        //Si hay usuarios humanos registrados muestro todos los humanos numerados

        cout << "\n***LISTA HUMANOS REGISTRADOS***\n"<<endl;
        for(unsigned int i=0; i<lista_humanos.size(); i++){

            cout << "HUMANO " << i+1 << ": " <<endl;
            cout << "NIF: " << lista_humanos[i].getNIF() << endl;
            cout << "Planeta procedencia: " << lista_humanos[i].getPlaneta() << endl << endl;
        }

        //Pido que se introduzca el numero de usuario que se desea dar de baja
        do{
            //Pido el numero en string para evitar salidas del programa accidentales por si se teclea algun caracter no deseado accidentalmente
            numero=true;
            cout <<"Indique el numero de usuario humano que desa dar de baja: ";
            cin>> cadena;


            for(unsigned i=0; i<cadena.length(); i++){

                if(!isdigit(cadena.at(i))){numero=false;}   //Recorro la cadena y si algun elemento no es un numero cambio el flag y vuelvo a pedir
            }
            if(numero){numero_registro = stoi(cadena);}     //Convierto la cadena a int

        }while(numero==false || numero_registro>lista_humanos.size() || numero_registro<=0);


        //Si el usuario tiene estaciones registradas las elimino junto con su perfil
        for(unsigned int i=0; i<lista_estaciones.size(); i++){

            if(lista_estaciones[i].getPropietario()==lista_humanos[numero_registro-1].getNIF()){

                lista_estaciones.erase(lista_estaciones.begin()+i);
            }
        }

        //Si el usuario tiene destructores registrados los elimino junto con su perfil
        for(unsigned int i=0; i<lista_destructores.size(); i++){

            if(lista_destructores[i].getPropietario()==lista_humanos[numero_registro-1].getNIF()){
                lista_destructores.erase(lista_destructores.begin()+i);
            }
        }

        //Si el usuario tiene cargueros registrados los elimino junto con su perfil
        for(unsigned int i=0; i<lista_cargueros.size(); i++){

            if(lista_cargueros[i].getPropietario()==lista_humanos[numero_registro-1].getNIF()){
                lista_cargueros.erase(lista_cargueros.begin()+i);
            }
        }

        //Si el usuario tiene cazas registrados los elimino junto con su perfil
        for(unsigned int i=0; i<lista_cazas.size(); i++){

            if(lista_cazas[i].getPropietario()==lista_humanos[numero_registro-1].getNIF()){
                lista_cazas.erase(lista_cazas.begin()+i);
            }
        }

        //Borro el humano seleccionado
        lista_humanos.erase(lista_humanos.begin()+numero_registro-1);

        cout << "\nUsted se ha dado de baja satisfactoriamente.\n";

        //Muestro la lista de humanos con sin el usuario que he dado de baja
        cout << "\n***LISTA HUMANOS REGISTRADOS ACTUALIZADA***\n"<<endl;
        for(unsigned int i=0; i<lista_humanos.size(); i++){

            cout << "HUMANO " << i+1 << ": " <<endl;
            cout << "NIF: " << lista_humanos[i].getNIF() << endl;
            cout << "Planeta procedencia: " << lista_humanos[i].getPlaneta() << endl << endl;
        }

    }else if(op=='E'){

        //Si hay usuarios extraterrestres registrados muestro todos los extraterrestess numerados
        cout << "\n***LISTA EXTRATERRESTRES REGISTRADOS***\n"<<endl;
        for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

            cout << "EXTRATERRESTRE: " << i+1 << ": " <<endl;
            cout << "NIE: " << lista_extraterrestres[i].getNIE() << endl;
            cout << "Planeta procedencia: " << lista_extraterrestres[i].getPlaneta() << endl << endl;
        }

        //Sigo el mismo procedimiento que al dar de baja un humano
        do{

            numero=true;
            cout <<"Indique el numero de usuario extraterrestre que desa dar de baja: ";
            cin>> cadena;

            //Evito salidas del programa por meter tipos de datos distintos a enteros
            for(unsigned i=0; i<cadena.length(); i++){

                if(!isdigit(cadena.at(i))){numero=false;}
            }

            if(numero){numero_registro = stoi(cadena);}

        }while(numero==false || numero_registro>lista_extraterrestres.size() || numero_registro<=0);

        //Borro estaciones asociadas al extraterrestre
        for(unsigned int i=0; i<lista_estaciones.size(); i++){

            if(lista_estaciones[i].getPropietario()==lista_extraterrestres[numero_registro-1].getNIE()){

                lista_estaciones.erase(lista_estaciones.begin()+i);
            }
        }

        //Borro destructores asociados al extraterrestre
        for(unsigned int i=0; i<lista_destructores.size(); i++){

            if(lista_destructores[i].getPropietario()==lista_extraterrestres[numero_registro-1].getNIE()){
                lista_destructores.erase(lista_destructores.begin()+i);
            }
        }

        //Borro cargueros asociados al extraterrestre
        for(unsigned int i=0; i<lista_cargueros.size(); i++){

            if(lista_cargueros[i].getPropietario()==lista_extraterrestres[numero_registro-1].getNIE()){
                lista_cargueros.erase(lista_cargueros.begin()+i);
            }
        }


        //Borro cazas asociados al extraterrestre
        for(unsigned int i=0; i<lista_cazas.size(); i++){

            if(lista_cazas[i].getPropietario()==lista_extraterrestres[numero_registro-1].getNIE()){
                lista_cazas.erase(lista_cazas.begin()+i);
            }
        }

        //Borro el extraterrestre seleciconado
        lista_extraterrestres.erase(lista_extraterrestres.begin()+numero_registro-1);

        cout << "\nUsted se ha dado de baja satisfactoriamente.\n";

         cout << "\n***LISTA EXTRATERRESTRES REGISTRADOS ACTUALIZADA***\n"<<endl;
        for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

            cout << "EXTRATERRESTRE: " << i+1 << ": " <<endl;
            cout << "NIE: " << lista_extraterrestres[i].getNIE() << endl;
            cout << "Planeta procedencia: " << lista_extraterrestres[i].getPlaneta() << endl << endl;
        }
    }
}

void aplicacion::modificar_propietario(){

    humanos modificar_humano;
    extraterrestres modificar_extraterrestre;

    char op;
    unsigned int numero_humano, numero_extraterrestre;
    bool flag=false;
    bool flag2=true;
    string usuario;
    string planeta;
    string cadena;
    string usuario_antiguo;
    bool numero=true;

    cout << "\n***MODIFICAR PROPIETARIO***\n"<<endl;

    //compruebo que haya usuarios para modificar
    if(lista_humanos.size()==0 && lista_extraterrestres.size()==0){

        cout << "\nNo hay ningun usuario registrado para modificar." << endl;

    }else {

    do{

        //Pido el tipo de usuario a modificar
        cout << "Pulse H si desea modificar un humano o E desea modificar a un extraterrestre: ";
        cin >> op;
        cin.ignore(256, '\n');
        op = toupper(op);

    }while(op!='H' && op!='E');

    if(op=='H' && lista_humanos.size()!=0){

        //MUestro los humanos registrados para elegir el que quiero modificar
        cout << "\n***LISTA DE HUMANOS***\n"<<endl;
        for(unsigned int i=0; i<lista_humanos.size(); i++){

            cout << "HUMANO " << i+1 << ": " <<endl;
            cout << "NIF: " << lista_humanos[i].getNIF() << endl;
            cout << "Planeta procedencia: " << lista_humanos[i].getPlaneta() << endl << endl;
        }

        //Pido el numero de humano a modificar
        do{
            numero=true;
            cout <<"Indique el numero nombre de usuario: ";
            cin>> cadena;

            //Evito salidas insperadas del programa por introducir tipos de dato diferentes al pedido
            for(unsigned i=0; i<cadena.length(); i++){

                if(!isdigit(cadena.at(i))){numero=false;}
            }

            if(numero){numero_humano = stoi(cadena);}

        }while(numero==false || numero_humano>lista_humanos.size() || numero_humano<=0);


        planeta = lista_humanos[numero_humano-1].getPlaneta();  //Recupero el planeta del humano
        usuario_antiguo = lista_humanos[numero_humano-1].getNIF();

        lista_humanos.erase(lista_humanos.begin()+numero_humano-1); //Boroo el humano


        do{
            //Pido el nuevo numero de usuario
            cout << "\nIntroduzca el nuevo numero de usuario: ";
            cin>> usuario;
            flag=false;
            flag2=true;

            for(unsigned int i=0; i<usuario.length(); i++){
                usuario[i] = toupper(usuario[i]);
            }

            //Compruebo que no esté ya registrado
            for(unsigned int i=0; i<lista_humanos.size(); i++){

                if(lista_humanos[i].getNIF() == usuario){

                    cout << "\nUsuario ya registrado." << endl;
                    flag=false;
                    flag2 = false;
                }
            }
            //compruebo que el formato nuevo sea de tipo humano
            for(unsigned int i=0; i<usuario.length()-1; i++){

                if(usuario[i]>='0' && usuario[i]<='9' && usuario[usuario.length()-1]>='A' && usuario[usuario.length()-1]<='Z' && usuario.length()==9){

                    modificar_humano.setNIF(usuario);
                    flag=true;
            }
                }

            //Modifico el atributo propietario de las naves asignadas al usuario modificado
            for(unsigned int i=0; i<lista_estaciones.size(); i++){

                if(lista_estaciones[i].getPropietario()==usuario_antiguo){
                lista_estaciones[i].setPropietario(usuario);
                }
            }

            for(unsigned int i=0; i<lista_destructores.size(); i++){

                if(lista_destructores[i].getPropietario()==usuario_antiguo){
                lista_destructores[i].setPropietario(usuario);
                }
            }

            for(unsigned int i=0; i<lista_cargueros.size(); i++){

                if(lista_cargueros[i].getPropietario()==usuario_antiguo){
                lista_cargueros[i].setPropietario(usuario);
                }
            }

            for(unsigned int i=0; i<lista_cazas.size(); i++){

                if(lista_cazas[i].getPropietario()==usuario_antiguo){
                lista_cazas[i].setPropietario(usuario);
                }
            }

        }while(usuario.length()<9 || usuario.length()>9 || (flag==false || flag2==false));


    }else if(op=='H' && lista_humanos.size()==0){cout << "\nNo hay ningun humano registrado en el sistema para modificar.\n";}

    if(op=='E' && lista_extraterrestres.size()!=0){


        cout << "\n***LISTA DE EXTRATERRESTRES***\n"<<endl;

        //Muestor extraterrestres registrados
        for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

            cout << "EXTRATERRESTRE: " << i+1 << ": " <<endl;
            cout << "NIE: " << lista_extraterrestres[i].getNIE() << endl;
            cout << "Planeta procedencia: " << lista_extraterrestres[i].getPlaneta() << endl << endl;
        }

        //Elijo el numero de extraterrestre que quiero modificar
        do{
            numero=true;
            cout <<"Indique el numero de usuario extraterrestre que desa modificar: ";
            cin>> cadena;

            //Evito salidas del programa por introducir tipos de datos por teclado no deseados
            for(unsigned i=0; i<cadena.length(); i++){

                if(!isdigit(cadena.at(i))){numero=false;}
            }

            if(numero){numero_extraterrestre = stoi(cadena);}

        }while(numero==false || numero_extraterrestre>lista_extraterrestres.size() || numero_extraterrestre<=0);

        usuario_antiguo = lista_extraterrestres[numero_extraterrestre-1].getNIE();
        planeta = lista_extraterrestres[numero_extraterrestre-1].getPlaneta();          //recupero planeta de origen
        lista_extraterrestres.erase(lista_extraterrestres.begin()+numero_extraterrestre-1); //Borro el usuario

        //pido el nuevo numero de extraterrestre
        do{
            cout << "\nIntroduzca el nuevo numero de usuario: ";
            cin>> usuario;
            flag=true;
            flag2=true;

            //paso a mayusculas el extraterrestre introducido
            for(unsigned int i=0; i<usuario.length(); i++){
                usuario[i] = toupper(usuario[i]);
            }

            //Compruebo que no esté registrado ya dicho numero
            for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

                if(lista_extraterrestres[i].getNIE() == usuario){

                    cout << "\nUsuario ya registrado." << endl;
                    flag=false;
                }
            }

            if(usuario.length()==10){
            //Compruebo si es formato de usuario extraterrestre
            for(unsigned int i=0; i<usuario.length(); i++){

                if(!isdigit(usuario.at(i))){

                    flag=false;//Cambio el flag para poder salir del bucle
                }
            }
            }

            //Modifico el atributo propietario de las naves asignadas al usuario modificado
            for(unsigned int i=0; i<lista_estaciones.size(); i++){

                if(lista_estaciones[i].getPropietario()==usuario_antiguo){
                lista_estaciones[i].setPropietario(usuario);
                }
            }

            for(unsigned int i=0; i<lista_destructores.size(); i++){

                if(lista_destructores[i].getPropietario()==usuario_antiguo){
                lista_destructores[i].setPropietario(usuario);
                }
            }

            for(unsigned int i=0; i<lista_cargueros.size(); i++){

                if(lista_cargueros[i].getPropietario()==usuario_antiguo){
                lista_cargueros[i].setPropietario(usuario);
                }
            }

            for(unsigned int i=0; i<lista_cazas.size(); i++){

                if(lista_cazas[i].getPropietario()==usuario_antiguo){
                lista_cazas[i].setPropietario(usuario);
                }
            }
        }while(usuario.length()<10 || usuario.length()>10 || (flag==false));


    }else if(op=='E' && lista_extraterrestres.size()==0){cout << "\nNo hay ningun extraterrestre registrado en el sistema para modificar.\n";}

    //Guardo el usuario dependiendo de si es humano o extraterrestre
    if(usuario.length()==9){
        modificar_humano.setNIF(usuario);
        modificar_humano.setPlaneta(planeta);
        lista_humanos.insert(lista_humanos.begin()+numero_humano-1, modificar_humano);
        cout << "\nUsted se ha modificado al usuario humano satisfactoriamente.\n";
    }


    if(usuario.length()==10){

        modificar_extraterrestre.setNIE(usuario);
        modificar_extraterrestre.setPlaneta(planeta);
        lista_extraterrestres.insert(lista_extraterrestres.begin()+numero_extraterrestre-1, modificar_extraterrestre);
        cout << "\nUsted se ha modificado al usuario extraterrestre satisfactoriamente.\n";
    }
    }


}

void aplicacion::Mostrar_Propietarios(){

    //Recorro el vector de humanos y lo muestro
    if(lista_humanos.size()>0){

        cout << "\n***LISTA DE HUMANOS REGISTRADOS***\n"<<endl;
        for(unsigned int i=0; i<lista_humanos.size(); i++){

            cout << "HUMANO " << i+1 << ": " <<endl;
            cout << "\nNIF: " << lista_humanos[i].getNIF() << endl;
            cout << "Planeta procedencia: " << lista_humanos[i].getPlaneta() << endl << endl;
        }
    }

    //Recorro el vector de extraterrestres y lo muestro
    if(lista_extraterrestres.size()>0){
        cout << "\n***LISTA DE EXTRATERRESTRES REGISTRADOS***\n"<<endl;
        for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

            cout << "EXTRATERRESTRE " << i+1 << ": " <<endl;
            cout << "NIE: " << lista_extraterrestres[i].getNIE() << endl;
            cout << "Planeta procedencia: " << lista_extraterrestres[i].getPlaneta() << endl << endl;
        }
    }
    //Veo si hay usuarios para mostrar
    if(lista_humanos.size()==0 && lista_extraterrestres.size()==0){

        cout<<"\nNo hay usuarios registrados en el sistema para mostrar.\n";
    }

}

void aplicacion::alta_nave(){

    //Compruevo que haya unuarios registrados para dar de alta naves
    if(lista_humanos.size()==0 && lista_extraterrestres.size()==0){

        cout << "\nNo hay usuarios registrados para poder poner a la venta su nave.\n" << endl;
    }else{

    char op;
    int numero_tripulantes, numeroMax_pasajeros, numero_hangares, numero_armas;
    string propietario, numero_registro, tipo_propulsion, escudo, velocidad_crucero, arma1, arma2;
    bool flag=true, flag1 = false;
    float precio, carga_maxima, velocidad_maxima;

    estaciones estacion;
    destructores destructor;
    cargueros carguero;
    cazas caza;

    //Menu para dar de alta un determinado tipo de nave
    do
    {
       cout << "\n***ALTA NAVE ESPACIAL***\n" << endl;

       cout << "Tipos de naves que puede registrar:\n\n"
               "1) Estación espacial.\n"
               "2) Destructor.\n"
               "3) Carguero.\n"
               "4) Caza.\n"
               "5) Volver atras."<<endl;

       cout << "\n¿Que nave desea registrar?";
       cin >> op;
       cin.ignore(256, '\n');

       flag=true;
       flag1=false;

       switch(op)
       {
           case '1':    //Alta estaciones

           cout << "\nUSTED ESTA DANDO DE ALTA UNA ESTACION ESPACIAL:\n" << endl;

          do{

              propietario = estacion.Asignar_Propietario(); //Asigno un propietario a la nave
              flag = false;

              //Compruebo que existan usuarios para asociarlos a las naves
              for(unsigned int i = 0; i<lista_humanos.size(); i++){

                  if(lista_humanos[i].getNIF() == propietario){flag1 = true;}
              }


              for(unsigned int i = 0; i<lista_extraterrestres.size(); i++){

                  if(lista_extraterrestres[i].getNIE() == propietario){flag1 = true;}
              }

          }while(flag1 == false);

          estacion.setPropietario(propietario); //Inicializo propietarios

          do{
               numero_registro = estacion.Asignar_Numero_Registro();    //Asigno numero de nave espacial
               estacion.setNumeroRegistro(numero_registro);
               flag=Comprobar_Numero_Registro(numero_registro);         //Compruebo que no exista el numero a registrar

          }while(flag==false);

           tipo_propulsion = estacion.Tipo_Propulsion();                //Asigno propulsión
           estacion.setPropulsion(tipo_propulsion);                     //Inicializo propulsión

           precio = estacion.Fijar_Precio();                            //Asigno precio
           estacion.setPrecio(precio);                                  //Inicializo precio

           numero_tripulantes = estacion.Numero_Max_Tripulantes();    //Asigno tripulantes
           estacion.setTripulantes(numero_tripulantes);                         //Inicializo tripulantes

           numeroMax_pasajeros = estacion.Asignar_Pasajeros();                  //Asigno maximo pasajeros
           estacion.setPasajeros(numeroMax_pasajeros);                          //Inicializo max pasajeros

           numero_hangares = estacion.Asignar_Hangares();                       //Asigno numero de hangares
           estacion.setHangares(numero_hangares);                               //Inicializo numero de hangares

           escudo = estacion.Asignar_Escudo();                                  //Asigno escudo
           estacion.setEscudo(escudo);                                          //inicializo escudo

           lista_estaciones.push_back(estacion);        //Guardo la estación


           cout << "\nESTACIÓN ESPACIAL REGISTRADA CON ÉXITO."<<endl;

           break;

           //Doy de alta un destructor
           case '2':

           cout << "\nUSTED ESTA DANDO DE ALTA UN DESTRUCTOR ESPACIAL:\n" << endl;


           //Mismo procedimiento que para dar de alta una estación
           //Compruebo formatos e inicializo atributos
           do{

               propietario = destructor.Asignar_Propietario();

               for(unsigned int i = 0; i<lista_humanos.size(); i++){

                   if(lista_humanos[i].getNIF() == propietario){flag1 = true;}
               }


               for(unsigned int i = 0; i<lista_extraterrestres.size(); i++){

                   if(lista_extraterrestres[i].getNIE() == propietario){flag1 = true;}
               }

           }while(flag1 == false);

           destructor.setPropietario(propietario);


           do{
               numero_registro = destructor.Asignar_Numero_Registro();
               destructor.setNumeroRegistro(numero_registro);
               flag=Comprobar_Numero_Registro(numero_registro);

           }while(flag==false);

           tipo_propulsion = destructor.Tipo_Propulsion();
           destructor.setPropulsion(tipo_propulsion);

           precio = destructor.Fijar_Precio();
           destructor.setPrecio(precio);

           numero_tripulantes = destructor.Numero_Max_Tripulantes();
           destructor.setTripulantes(numero_tripulantes);


           numero_armas = destructor.Asignar_Numero_Armas();
           destructor.setNumeroArmas(numero_armas);

           destructor.Asignar_Tipo_Armamento(numero_armas);


           lista_destructores.push_back(destructor);


           cout << "\nDESTRUCTOR ESPACIAL REGISTADO CON ÉXITO."<<endl;


           break;

           case '3':

           cout << "\nUSTED ESTA DANDO DE ALTA UN CARGUERO ESPACIAL:\n" << endl;

           //Mismo procedimiento que para dar de alta una estación
           //Compruebo formatos e inicializo atributos
           do{

               propietario = carguero.Asignar_Propietario();

               for(unsigned int i = 0; i<lista_humanos.size(); i++){

                   if(lista_humanos[i].getNIF() == propietario){flag1 = true;}
               }


               for(unsigned int i = 0; i<lista_extraterrestres.size(); i++){

                   if(lista_extraterrestres[i].getNIE() == propietario){flag1 = true;}
               }

           }while(flag1 == false);

           carguero.setPropietario(propietario);


           do{

               numero_registro = carguero.Asignar_Numero_Registro();
               carguero.setNumeroRegistro(numero_registro);
               flag=Comprobar_Numero_Registro(numero_registro);

           }while(flag==false);

           tipo_propulsion = carguero.Tipo_Propulsion();
           carguero.setPropulsion(tipo_propulsion);

           precio = carguero.Fijar_Precio();
           carguero.setPrecio(precio);

           numero_tripulantes = carguero.Numero_Max_Tripulantes();
           carguero.setTripulantes(numero_tripulantes);

           carga_maxima = carguero.Asignar_Carga_Maxima();
           carguero.setCarga(carga_maxima);

           velocidad_crucero = carguero.Asignar_Vel_Crucero();
           carguero.setVelocidad(velocidad_crucero);

           escudo = carguero.Asignar_Escudo();
           carguero.setEscudo(escudo);

           lista_cargueros.push_back(carguero);

           cout << "\nCARGUERO ESPACIAL DADO DE ALTA CON ÉXITO."<<endl;

           break;

           //Mismo procedimiento que para dar de alta una estación
           //Compruebo formatos e inicializo atributos
           case '4':

           cout << "\nUSTED ESTA DANDO DE ALTA UN CAZA ESPACIAL:\n" << endl;


           do{

               propietario = caza.Asignar_Propietario();

               for(unsigned int i = 0; i<lista_humanos.size(); i++){

                   if(lista_humanos[i].getNIF() == propietario){flag1 = true;}
               }


               for(unsigned int i = 0; i<lista_extraterrestres.size(); i++){

                   if(lista_extraterrestres[i].getNIE() == propietario){flag1 = true;}
               }

           }while(flag1 == false);

           caza.setPropietario(propietario);


           do{
               numero_registro = caza.Asignar_Numero_Registro();
               caza.setNumeroRegistro(numero_registro);
               flag=Comprobar_Numero_Registro(numero_registro);

           }while(flag==false);

           tipo_propulsion = caza.Tipo_Propulsion();
           caza.setPropulsion(tipo_propulsion);

           precio = caza.Fijar_Precio();
           caza.setPrecio(precio);

           numero_tripulantes = caza.Numero_Max_Tripulantes();    //A la función numero_max_tripulantes le paso un identificador 'caza' para que solo pueda asignar 1 tripulantr
           caza.setTripulantes(numero_tripulantes);

           velocidad_maxima = caza.Asignar_Velocidad_Maxima();
           caza.setVel_Max(velocidad_maxima);

           arma1 = caza.Asignar_Arma1();
           caza.setArma1(arma1);

           arma2 = caza.Asignar_Arma2();
           caza.setArma2(arma2);

           lista_cazas.push_back(caza);


           cout << "\nCAZA ESPACIAL DADO DE ALTA CON ÉXITO.\n"<<endl;

           break;

           case '5':

               return;
            break;

           default: cout<<"\nOpcion no válida."<<endl; break;
       }

    }while(op != '5');
    }
}

void aplicacion::baja_nave(){


    char op;
    unsigned int numero_nave;
    string cadena;
    bool numero=true;

     cout << "\n***Usted procedera a dar de baja una nueva nave espacial***\n" << endl;

     //Comopruebo que haya naves en el sistema
    if(lista_estaciones.size()==0 && lista_cargueros.size()==0 && lista_destructores.size()==0 && lista_cazas.size()==0){

        cout<<"\nNo hay naves registradas para dar de baja."<<endl;
        return;
    }

    //Elijo el tipo de nave para dard e baja
    do{

            cout << "1) Baja estación.\n"
                    "2) Baja destructor.\n"
                    "3) Baja carguero.\n"
                    "4) Baja caza.\n"
                    "5) Volver atrás.\n";

            cout << "\nIndique el número de nave que desea dar de baja:";
            cin >> op;
            cin.ignore(256, '\n');
            op = toupper(op);

            if((op=='1' && lista_estaciones.size()==0) || (op=='2' && lista_destructores.size()==0) || (op=='3' && lista_cargueros.size()==0) || (op=='4' && lista_cazas.size()==0)){

                cout << "\nNo hay existen naves para dar de baja de este tipo.\nPruebe a dar de baja otro tipo de nave.\n"<<endl;
            }

    }while((op!='1' && op!='2' && op!='3'  && op!='4' && op!='5') || (op=='1' && lista_estaciones.size()==0) || (op=='2' && lista_destructores.size()==0) || (op=='3' && lista_cargueros.size()==0) || (op=='4' && lista_cazas.size()==0));

    if(op=='1'){

        //Muestro naves disponibles para dar de baja
        cout << "\n***LISTA ESTACIONES REGISTRADAS***\n"<<endl;
        for(unsigned int i=0; i<lista_estaciones.size(); i++){

            cout << "Estacion "<<i+1<<":\n"<<endl;
            cout << "Propietario: " << lista_estaciones[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_estaciones[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_estaciones[i].getPropulsion() << endl;
            cout << "Precio: " << lista_estaciones[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_estaciones[i].getTripulantes()<<endl;
            cout << "Numero de pasajeros: " << lista_estaciones[i].getPasajeros()<< endl;
            cout << "Numero de hangares: " << lista_estaciones[i].getHangares()<< endl;
            cout << "Escudo: " << lista_estaciones[i].getEscudo()<< endl<<endl;
        }

        do{
            numero=true;
            cout <<"Indique el numero estación que desa dar de baja: ";
            cin>> cadena;           //Pido el numero de estacion para dar de baja


            for(unsigned i=0; i<cadena.length(); i++){  //Evito salidas del sistema al por tipo de dato introdcido erroneo

                if(!isdigit(cadena.at(i))){numero=false;}

            }

            if(numero){numero_nave = stoi(cadena);}

        }while(numero==false || numero_nave>lista_estaciones.size() || numero_nave<=0);

        lista_estaciones.erase(lista_estaciones.begin()+numero_nave-1);     //Borro la estacion seleccionada

        //Muestro las estaciones para comprobar que se haya dado d ebaja correctamente
        cout << "\n***LISTA ESTACIONES REGISTRADAS ACTUALIZADA***\n"<<endl;
        for(unsigned int i=0; i<lista_estaciones.size(); i++){

            cout << "Estacion "<<i+1<<":\n"<<endl;
            cout << "Propietario: " << lista_estaciones[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_estaciones[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_estaciones[i].getPropulsion() << endl;
            cout << "Precio: " << lista_estaciones[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_estaciones[i].getTripulantes()<<endl;
            cout << "Numero de pasajeros: " << lista_estaciones[i].getPasajeros()<< endl;
            cout << "Numero de hangares: " << lista_estaciones[i].getHangares()<< endl;
            cout << "Escudo: " << lista_estaciones[i].getEscudo()<< endl<<endl;
        }

    }else if(op=='2'){

        //Muestro los destructores registrados
        cout << "\n***LISTA DESTRUCTORES REGISTRADOS***\n"<<endl;
        for(unsigned int i=0; i<lista_destructores.size(); i++){

            cout << "Destructor "<<i+1<<":\n"<<endl;
            cout << "Propietario: " << lista_destructores[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_destructores[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_destructores[i].getPropulsion() << endl;
            cout << "Precio: " << lista_destructores[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_destructores[i].getTripulantes()<<endl;
            for(int j = 0; j<lista_destructores[i].getNumeroArmas(); j++){
                cout << "Arma numero " << j+1 << ": " <<lista_destructores[i].getTipoArmas(j)<<endl;
            }
            cout <<endl;
        }

        //Pido destructor a eliminar
        do{
            numero=true;
            cout <<"Indique el numero destructor que desa dar de baja: ";
            cin>> cadena;

            for(unsigned i=0; i<cadena.length(); i++){  //Evito salidas del sistema por meter un tipo de dato erroneo

                if(!isdigit(cadena.at(i))){numero=false;}

            }

            if(numero){numero_nave = stoi(cadena);}

        }while(numero==false || numero_nave>lista_destructores.size() || numero_nave<=0);

        lista_destructores.erase(lista_destructores.begin()+numero_nave-1); //Borro destructor

        cout << "\n***LISTA DESTRUCTORES REGISTRADOS ACTUALIZADA***\n"<<endl;
        for(unsigned int i=0; i<lista_destructores.size(); i++){

            cout << "Destructor "<<i+1<<":\n"<<endl;
            cout << "Propietario: " << lista_destructores[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_destructores[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_destructores[i].getPropulsion() << endl;
            cout << "Precio: " << lista_destructores[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_destructores[i].getTripulantes()<<endl;
            for(int j = 0; j<lista_destructores[i].getNumeroArmas(); j++){

                cout << "Arma numero " << j+1 << ": " <<lista_destructores[i].getTipoArmas(j)<<endl;
            }
            cout << endl;
        }

    }else if(op=='3'){


        //Muestro cargueros disponibles para dar de baja
        cout << "\n***LISTA CARGUEROS REGISTRADOS***\n"<<endl;
        for(unsigned int i=0; i<lista_cargueros.size(); i++){

            cout << "Estacion "<<i+1<<":\n"<<endl;
            cout << "Propietario: " << lista_cargueros[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_cargueros[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_cargueros[i].getPropulsion() << endl;
            cout << "Precio: " << lista_cargueros[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_cargueros[i].getTripulantes()<<endl;
            cout << "Carga máxima admitida: " << lista_cargueros[i].getCarga()<<endl;
            cout << "Velocidad máxima: " << lista_cargueros[i].getVelocidad()<<endl;
            cout << "Escudo: " << lista_cargueros[i].getEscudo()<< endl<<endl;
        }

        //Pido numero de carguero a eliminar
        do{
            numero=true;
            cout <<"Indique el numero carguero que desa dar de baja: ";
            cin>> cadena;

            for(unsigned i=0; i<cadena.length(); i++){  //Evito salidas del programa por tipos de datos introducidos erroneos

                if(!isdigit(cadena.at(i))){numero=false;}

            }

            if(numero){numero_nave = stoi(cadena);}

        }while(numero==false || numero_nave>lista_cargueros.size() || numero_nave<=0);

        lista_cargueros.erase(lista_cargueros.begin()+numero_nave-1);   //Borro carguero seleccionado

        cout << "\n***LISTA CARGUEROS REGISTRADOS ACTUALIZADA***\n"<<endl;
        for(unsigned int i=0; i<lista_cargueros.size(); i++){

            cout << "Estacion "<<i+1<<":\n"<<endl;
            cout << "Propietario: " << lista_cargueros[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_cargueros[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_cargueros[i].getPropulsion() << endl;
            cout << "Precio: " << lista_cargueros[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_cargueros[i].getTripulantes()<<endl;
            cout << "Carga máxima admitida: " << lista_cargueros[i].getCarga()<<endl;
            cout << "Velocidad máxima: " << lista_cargueros[i].getVelocidad()<<endl;
            cout << "Escudo: " << lista_cargueros[i].getEscudo()<< endl<<endl;
        }
    }else if(op=='4'){

        //Muestro cazas registrado s en el sistema
        cout << "\n***LISTA CAZAS REGISTRADOS***\n"<<endl;
        for(unsigned int i=0; i<lista_cazas.size(); i++){

            cout << "Caza "<<i+1<<":\n"<<endl;
            cout << "Propietario: " << lista_cazas[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_cazas[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_cazas[i].getPropulsion() << endl;
            cout << "Precio: " << lista_cazas[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_cazas[i].getTripulantes()<<endl;
            cout << "Velocidad máxima: " << lista_cazas[i].getVel_Max()<<endl;
            cout << "Arma 1: " << lista_cazas[i].getArma1()<<endl;
            cout << "Arma 2: " << lista_cazas[i].getArma2()<<endl<<endl;
        }

        do{         //Pido numero de caza a eliminar
            numero=true;
            cout <<"Indique el numero caza que desa dar de baja: ";
            cin>> cadena;

            for(unsigned i=0; i<cadena.length(); i++){      //Evito salidas del sistema por tipos de datos introducidos erroneamente

                if(!isdigit(cadena.at(i))){numero=false;}

            }

            if(numero){numero_nave = stoi(cadena);}

        }while(numero==false || numero_nave>lista_cazas.size() || numero_nave<=0);


        lista_cazas.erase(lista_cazas.begin()+numero_nave-1);       //Borro el caza selecionado

        numero_nave=0;

        cout << "\n***LISTA CAZAS REGISTRADOS ACTUALIZADA***\n"<<endl;
        for(unsigned int i=0; i<lista_cazas.size(); i++){

            cout << "Caza "<<i+1<<":\n"<<endl;
            cout << "Propietario: " << lista_cazas[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_cazas[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_cazas[i].getPropulsion() << endl;
            cout << "Precio: " << lista_cazas[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_cazas[i].getTripulantes()<<endl;
            cout << "Velocidad máxima: " << lista_cazas[i].getVel_Max()<<endl;
            cout << "Arma 1: " << lista_cazas[i].getArma1()<<endl;
            cout << "Arma 2: " << lista_cazas[i].getArma2()<<endl;
        }
    }else if(op=='5'){
        return;     //Vuelta al menu de gestion de naves
    }

}

void aplicacion::modificar_nave(){


    char op1;   

    //Compruebo que haya naves para midificar
    if(lista_cargueros.size()!=0 || lista_cazas.size()!=0 || lista_destructores.size()!=0 || lista_estaciones.size()!=0){

    do{

        cout << "\n***USTED PROCEDERÁ A MODIFICAR UNA NAVE ESPCIAL***\n" << endl;
        cout << "Pulse el tipo de nave que desea modificar:\n\n"
                "1) Estación espacial.\n"
                "2) Destructor.\n"
                "3) Carguero.\n"
                "4) Caza.\n"
                "5) Volver atras."<<endl;

        cout <<"\nLa opción seleccionada es: ";

        cin >> op1;     //Selecciono el tipo de nave a modificar
        cin.ignore(256, '\n');


        switch(op1){

        case '1':

            Modificar_Estacion();   //Funcion para modificar estacion

            break;

        case  '2':

            Modificar_Destructor(); //Funcion para modificar caza


            break;

        case '3':

            Modificar_Carguero();   //Funcion para modificar carguero

            break;

        case '4':

            Modificar_Caza();   //Funcion para modificar caza

            break;

        case '5':

            return;             //Vuelta al menu de gestion de naves
            break;

        default:

            cout << "\nOpción incorrecta.\n" << endl;
            break;

        }

    }while(op1!='5');

    }else {cout << "\nNo hay naves disponibles para modificar.\n";}

}

void aplicacion::Mostrar_Naves(){



    //Compruebo que haya naves en el sistema registradas
    if(lista_cazas.size()==0 && lista_cargueros.size()==0 && lista_destructores.size()==0 && lista_estaciones.size()==0){

        cout<<"\nNo hay naves registradas en el sistema para mostrar.\n";

    }else{

        cout << "\n*****SE PROCEDE A MOSTRAR LAS NAVES DADAS DE ALTA EN EL SISTEMA*****" << endl;

        //Imprime las naves registradas en el sistema
        if(lista_estaciones.size()>0){

            cout << "\n***LISTA ESTACIONES REGISTRADAS***\n"<<endl;
            for(unsigned int i=0; i<lista_estaciones.size(); i++){

                cout << "ESTACIONES: "<<i+1<<":\n"<<endl;
                cout << "Propietario: " << lista_estaciones[i].getPropietario()<<endl;
                cout << "Numero de registro: " << lista_estaciones[i].getNumeroRegistro()<<endl;
                cout << "Tipo de propulsion: " << lista_estaciones[i].getPropulsion() << endl;
                cout << "Precio: " << lista_estaciones[i].getPrecio() << endl;
                cout << "Numero de tripulantes: " << lista_estaciones[i].getTripulantes()<<endl;
                cout << "Numero de pasajeros: " << lista_estaciones[i].getPasajeros()<< endl;
                cout << "Numero de hangares: " << lista_estaciones[i].getHangares()<< endl;
                cout << "Escudo: " << lista_estaciones[i].getEscudo() << endl << endl;
            }
        }

        if(lista_destructores.size()>0){

            cout << "\n***LISTA DESTRUCTORES REGISTRADOS***\n"<<endl;
            for(unsigned int i=0; i<lista_destructores.size(); i++){

                cout << "DESTRUCTORES "<<i+1<<":\n"<<endl;
                cout << "Propietario: " << lista_destructores[i].getPropietario()<<endl;
                cout << "Numero de registro: " << lista_destructores[i].getNumeroRegistro()<<endl;
                cout << "Tipo de propulsion: " << lista_destructores[i].getPropulsion() << endl;
                cout << "Precio: " << lista_destructores[i].getPrecio() << endl;
                cout << "Numero de tripulantes: " << lista_destructores[i].getTripulantes()<<endl;
                for(int j = 0; j<lista_destructores[i].getNumeroArmas(); j++){

                    cout << "Arma numero " << j+1 << ": " <<lista_destructores[i].getTipoArmas(j)<<endl;
                }
                cout << endl;
            }
        }

        if(lista_cargueros.size()>0){

            cout << "\n***LISTA CARGUEROS REGISTRADOS***\n"<<endl;
            for(unsigned int i=0; i<lista_cargueros.size(); i++){

                cout << "CARGUEROS "<<i+1<<":\n"<<endl;
                cout << "Propietario: " << lista_cargueros[i].getPropietario()<<endl;
                cout << "Numero de registro: " << lista_cargueros[i].getNumeroRegistro()<<endl;
                cout << "Tipo de propulsion: " << lista_cargueros[i].getPropulsion() << endl;
                cout << "Precio: " << lista_cargueros[i].getPrecio() << endl;
                cout << "Numero de tripulantes: " << lista_cargueros[i].getTripulantes()<<endl;
                cout << "Carga máxima admitida: " << lista_cargueros[i].getCarga()<<endl;
                cout << "Velocidad crucero: " << lista_cargueros[i].getVelocidad()<<endl;
                cout << "Escudo: " << lista_cargueros[i].getEscudo()<< endl << endl;
            }
        }
        if(lista_cazas.size()>0){

            cout << "\n***LISTA CAZAS REGISTRADOS***\n"<<endl;
            for(unsigned int i=0; i<lista_cazas.size(); i++){

                cout << "CAZAS "<<i+1<<":\n"<<endl;
                cout << "Propietario: " << lista_cazas[i].getPropietario()<<endl;
                cout << "Numero de registro: " << lista_cazas[i].getNumeroRegistro()<<endl;
                cout << "Tipo de propulsion: " << lista_cazas[i].getPropulsion() << endl;
                cout << "Precio: " << lista_cazas[i].getPrecio() << endl;
                cout << "Numero de tripulantes: " << lista_cazas[i].getTripulantes()<<endl;
                cout << "Velocidad máxima: " << lista_cazas[i].getVel_Max()<<endl;
                cout << "Arma 1: " << lista_cazas[i].getArma1()<<endl;
                cout << "Arma 2: " << lista_cazas[i].getArma2()<<endl<<endl;
            }
        }
    }
}

void aplicacion::Comprar_Nave(){

    string usuario, identificador, cadena;

    char op;
    unsigned int numero_nave;
    bool numero=true;
    bool flag2=true;

    //Compruebo que haya naves para comprar
    if(lista_cargueros.size()==0 && lista_cazas.size()==0 && lista_destructores.size()==0 && lista_estaciones.size()==0){

        cout << "\nNo hay naves disponibles para comprar." << endl;
        return;
    }


    //Compruebo que haya usuarios registrados para comprar
    if(lista_humanos.size()==0 && lista_extraterrestres.size()==0){

        cout << "\nNo hoy usuarios para comprar realizar la compra." << endl;
        return;
    }

    cout<<"\n***COMPRAR NAVE ESPACIAL***\n";

    do{

        cout<<"\nIntroduce su numero de usuario: ";     //INtroduzco numero de usuario
        cin >> usuario;

        flag2=false;


        //Evito que los datos introducidos sean sensibles a minusculas
        for(unsigned int i=0; i<usuario.length(); i++){
            usuario[i] = toupper(usuario[i]);
        }

        //Compruebo que esté registrado
        for(unsigned int i=0; i<lista_humanos.size(); i++){

            if(lista_humanos[i].getNIF()==usuario){
            flag2=true;
            }

        }

        for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

            if(lista_extraterrestres[i].getNIE()==usuario){
            flag2=true;
            }
        }

        //Si no esta registrado muestro mensaje
        if(flag2==false){

            cout << "\nEs necesario estar registrado en el sistema para adquirir una nave.\n";
        }


    }while(flag2==false);

    if(usuario.length()==9){

        for(unsigned int i=0; i<lista_humanos.size(); i++){

            //Si es humano y está registrado inicializo identificador humano para acceder al menu compras de humanos
            if(usuario==lista_humanos[i].getNIF()){

                cout << "\nUsted ha accedido al sistema como humano." << endl;
                identificador = "humano";
            }
        }
    }


    if(usuario.length()==10){

        for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

            //Si es extraterrestre y está registrado inicializo identificador extraterestre para acceder al menu compras de humanos
            if(usuario==lista_extraterrestres[i].getNIE()){

                cout << "\nUsted ha accedido al sistema como humano como extraterrestre." << endl;
                identificador = "extraterrestre";
            }
        }
    }

    //Menu humano
    if(identificador=="humano"){


        do{

            cout << "\n***Usted procederá a comprar una nave espacial***\n" << endl;

            cout << "\n1) Estaciones espaciales.\n"
                    "2) Cargueros.\n"
                    "3) Cazas.\n"
                    "4) Volver al menú principal.\n"<<endl;

            cout << "\n¿Que tipo de nave desea comprar? ";  cin >> op;

            switch(op){

            case '1':

                if(lista_estaciones.size()!=0){

                //Muestro estaciones disponibles
                cout << "\n***LISTA ESTACIONES REGISTRADAS***\n"<<endl;
                for(unsigned int i=0; i<lista_estaciones.size(); i++){

                    cout << "Estacion "<<i+1<<":\n"<<endl;
                    cout << "Numero de registro: " << lista_estaciones[i].getNumeroRegistro()<<endl;
                    cout << "Tipo de propulsion: " << lista_estaciones[i].getPropulsion() << endl;
                    cout << "Precio: " << lista_estaciones[i].getPrecio() << endl;
                    cout << "Numero de tripulantes: " << lista_estaciones[i].getTripulantes()<<endl;
                    cout << "Numero de pasajeros: " << lista_estaciones[i].getPasajeros()<< endl;
                    cout << "Numero de hangares: " << lista_estaciones[i].getHangares()<< endl;
                    cout << "Escudo: " << lista_estaciones[i].getEscudo()<< endl << endl;
                }

                do{
                    numero=true;
                    cout << "Seleccione la estación que desea comprar:";
                    cin>> cadena;       //Selecciono la nave a comprar

                    for(unsigned i=0; i<cadena.length(); i++){  //Evito salidas del sistema

                        if(!isdigit(cadena.at(i))){numero=false;}
                    }

                    if(numero){numero_nave = stoi(cadena);}

                }while(numero==false || numero_nave>lista_estaciones.size() || numero_nave<=0);



                if(lista_estaciones[numero_nave-1].getPropietario()!=usuario){

                    cout << "\nEl humano de NIF " << usuario << " ha comprado la estacion " << numero_nave<< "." << endl;

                    //Escribo la nave vendida en un fichero de texto
                    Escribir_Ventas("1", usuario, numero_nave-1);

                    lista_estaciones.erase(lista_estaciones.begin() + numero_nave-1);//Borro la nave vendida

                }else{cout << "\nNo puede comprar su propia nave espacial\n";}


                }else cout << "\nNo hay estaciones disponibles para comprar.\n" << endl;

                break;

            case '2':

                if(lista_cargueros.size()!=0){

                //IMprimo cargueros disponibles para laventa
                cout << "\n***LISTA CARGUEROS REGISTRADOS***\n"<<endl;
                for(unsigned int i=0; i<lista_cargueros.size(); i++){

                    cout << "Estacion "<<i+1<<":\n"<<endl;
                    cout << "Numero de registro: " << lista_cargueros[i].getNumeroRegistro()<<endl;
                    cout << "Tipo de propulsion: " << lista_cargueros[i].getPropulsion() << endl;
                    cout << "Precio: " << lista_cargueros[i].getPrecio() << endl;
                    cout << "Numero de tripulantes: " << lista_cargueros[i].getTripulantes()<<endl;                    
                    cout << "Carga máxima admitida: " << lista_cargueros[i].getCarga()<<endl;
                    cout << "Velocidad máxima: " << lista_cargueros[i].getVelocidad()<<endl;
                    cout << "Escudo: " << lista_cargueros[i].getEscudo()<< endl << endl;

                }

                do{
                    numero=true;
                    cout << "Seleccione el carguero que desea comprar:";
                    cin>> cadena;   //Selecciono carguero

                    for(unsigned i=0; i<cadena.length(); i++){

                        if(!isdigit(cadena.at(i))){numero=false;}
                    }

                    if(numero){numero_nave = stoi(cadena);}

                }while(numero==false || numero_nave>lista_cargueros.size() || numero_nave<=0);


                if(lista_cargueros[numero_nave-1].getPropietario()!=usuario){

                    cout << "\nEl humano de NIF " << usuario << " ha comprado el carguero " << numero_nave<< "." << endl;

                    Escribir_Ventas("3", usuario, numero_nave-1);       //Escribo la venta en un fichero de texto

                    //Tendria que mandar el usuario y la estacion vendida a un fichero para registrarlo.

                    lista_cargueros.erase(lista_cargueros.begin() + numero_nave-1);//Borro la nave vendida

                }else{cout << "\nNo puede comprar su propia nave espacial\n";}

                }else cout << "\nNo hay cargueros disponibles para comprar.\n" << endl;

                break;

            case '3':

                if(lista_cazas.size()!=0){

                //Imprimo cazas disponibles
                cout << "\n***LISTA CAZAS REGISTRADOS***\n"<<endl;
                for(unsigned int i=0; i<lista_cazas.size(); i++){

                    cout << "Caza "<<i+1<<":\n"<<endl;
                    cout << "Numero de registro: " << lista_cazas[i].getNumeroRegistro()<<endl;
                    cout << "Tipo de propulsion: " << lista_cazas[i].getPropulsion() << endl;
                    cout << "Precio: " << lista_cazas[i].getPrecio() << endl;
                    cout << "Numero de tripulantes: " << lista_cazas[i].getTripulantes()<<endl;
                    cout << "Velocidad máxima: " << lista_cazas[i].getVel_Max()<<endl;
                    cout << "Arma 1: " << lista_cazas[i].getArma1()<<endl;
                    cout << "Arma 2: " << lista_cazas[i].getArma2()<<endl << endl;
                }


                do{
                    numero=true;
                    cout << "Seleccione el caza que desea comprar:";
                    cin>> cadena;   //Selecciono caza a comprar

                    for(unsigned i=0; i<cadena.length(); i++){

                        if(!isdigit(cadena.at(i))){numero=false;}
                    }

                    if(numero){numero_nave = stoi(cadena);}

                }while(numero==false || numero_nave>lista_cazas.size() || numero_nave<=0);


                if(lista_cazas[numero_nave-1].getPropietario()!=usuario){

                    cout << "\nEl humano de NIF " << usuario << " ha comprado el caza " << numero_nave<< "." << endl;

                    Escribir_Ventas("4", usuario, numero_nave-1);       //Escribo venta en el fichero

                    lista_cazas.erase(lista_cazas.begin() + numero_nave-1);     //Borro la nave vendida

                }else{cout << "\nNo puede comprar su propia nave espacial\n";}

                }else cout << "\nNo hay cargueros disponibles para comprar.\n" << endl;

                break;

            case '4':

                return;     //Vuelvo al menu de gestion de naves
                break;

            default: cout<< "\nOpción no valida.\n"; break;

            }
        }while(op!='4');
    }

    //Menu de compra de extraterrestres
    if(identificador=="extraterrestre"){


        do{
            cout << "\n***Usted procederá a comprar una nave espacial***\n" << endl;

            cout << "\n1) Destructores.\n"
                    "2) Cargueros.\n"
                    "3) Cazas.\n"
                    "4) Volver al menú principal.\n"<<endl;

            cout << "\n¿Que tipo de nave desea comprar? ";  cin >> op;

            switch(op){

            case '1':

                if(lista_destructores.size()!=0){

                //Muestro destructores disponibles para la venta
                cout << "\n***LISTA DESTRUCTORES REGISTRADOS***\n"<<endl;
                for(unsigned int i=0; i<lista_destructores.size(); i++){

                    cout << "Destructor "<<i+1<<":\n"<<endl;
                    cout << "Numero de registro: " << lista_destructores[i].getNumeroRegistro()<<endl;
                    cout << "Tipo de propulsion: " << lista_destructores[i].getPropulsion() << endl;
                    cout << "Precio: " << lista_destructores[i].getPrecio() << endl;
                    cout << "Numero de tripulantes: " << lista_destructores[i].getTripulantes()<<endl;
                    for(int j = 0; j<lista_destructores[i].getNumeroArmas(); j++){

                        cout << "Arma numero " << j+1 << ": " <<lista_destructores[i].getTipoArmas(j)<<endl;
                    }
                    cout << endl;
                }

                do{
                    numero=true;
                    cout << "Seleccione el destructor espacial que desea comprar:";
                    cin>> cadena;       //Elijo el destructor a comprar

                    for(unsigned i=0; i<cadena.length(); i++){

                        if(!isdigit(cadena.at(i))){numero=false;}
                    }

                    if(numero){numero_nave = stoi(cadena);}

                }while(numero==false || numero_nave>lista_destructores.size() || numero_nave<=0);

                if(lista_destructores[numero_nave-1].getPropietario()!=usuario){

                    cout << "\nEl extraterrestre de NIE " << usuario << " ha comprado el destructor " << numero_nave<< "." << endl;

                    //Escribo la venta en un fichero
                    Escribir_Ventas("2", usuario, numero_nave-1);

                    lista_destructores.erase(lista_destructores.begin() + numero_nave-1);//Borro la nave vendida
                }else{cout << "\nNo puede comprar su propia nave espacial\n";}

                }else cout << "\nNo hay destructores disponibles para comprar.\n" << endl;

                break;

            case '2':

                if(lista_cargueros.size()!=0){
                //Muestro los cargueros disponibles para vender
                cout << "\n***LISTA CARGUEROS REGISTRADOS***\n"<<endl;
                for(unsigned int i=0; i<lista_cargueros.size(); i++){

                    cout << "Estacion "<<i+1<<":\n"<<endl;
                    cout << "Numero de registro: " << lista_cargueros[i].getNumeroRegistro()<<endl;
                    cout << "Tipo de propulsion: " << lista_cargueros[i].getPropulsion() << endl;
                    cout << "Precio: " << lista_cargueros[i].getPrecio() << endl;
                    cout << "Numero de tripulantes: " << lista_cargueros[i].getTripulantes()<<endl;
                    cout << "Carga máxima admitida: " << lista_cargueros[i].getCarga()<<endl;
                    cout << "Velocidad máxima: " << lista_cargueros[i].getVelocidad()<<endl;
                    cout << "Escudo: " << lista_cargueros[i].getEscudo()<< endl << endl;
                }

                do{
                    numero=true;
                    cout << "Seleccione el carguero espacial que desea comprar:";
                    cin>> cadena;   //Selecciono el carguero a comprar

                    for(unsigned i=0; i<cadena.length(); i++){

                        if(!isdigit(cadena.at(i))){numero=false;}
                    }

                    if(numero){numero_nave = stoi(cadena);}

                }while(numero==false || numero_nave>lista_cargueros.size() || numero_nave<=0);

                if(lista_cargueros[numero_nave-1].getPropietario()!=usuario){

                    cout << "\nEl extraterrestre de NIE " << usuario << " ha comprado el carguero " << numero_nave<< "." << endl;

                    Escribir_Ventas("3", usuario, numero_nave-1);       //Escribo el carguero vendidoen el fichero

                    lista_cargueros.erase(lista_cargueros.begin() + numero_nave-1);//Borro la nave vendida
                }else{cout << "\nNo puede comprar su propia nave espacial\n";}

                }else cout << "\nNo hay cargueros disponibles para comprar.\n" << endl;

                break;

            case '3':

                if(lista_cazas.size()!=0){

                //Muestro cazas disponibles para la compra
                cout << "\n***LISTA CAZAS REGISTRADOS***\n"<<endl;
                for(unsigned int i=0; i<lista_cazas.size(); i++){

                    cout << "Caza "<<i+1<<":\n"<<endl;
                    cout << "Numero de registro: " << lista_cazas[i].getNumeroRegistro()<<endl;
                    cout << "Tipo de propulsion: " << lista_cazas[i].getPropulsion() << endl;
                    cout << "Precio: " << lista_cazas[i].getPrecio() << endl;
                    cout << "Numero de tripulantes: " << lista_cazas[i].getTripulantes()<<endl;
                    cout << "Velocidad máxima: " << lista_cazas[i].getVel_Max()<<endl;
                    cout << "Arma 1: " << lista_cazas[i].getArma1()<<endl;
                    cout << "Arma 2: " << lista_cazas[i].getArma2()<<endl << endl;
                }

                do{
                    numero=true;
                    cout << "Seleccione el carguero espacial que desea comprar:";
                    cin>> cadena;   //Numero de caza a comprar

                    for(unsigned i=0; i<cadena.length(); i++){

                        if(!isdigit(cadena.at(i))){numero=false;}
                    }

                    if(numero){numero_nave = stoi(cadena);}

                }while(numero==false || numero_nave>lista_cazas.size() || numero_nave<=0);


                if(lista_cazas[numero_nave-1].getPropietario()!=usuario){
                    cout << "\nEl extraterrestre de NIE " << usuario << " ha comprado el caza " << numero_nave<< "." << endl;

                    //Escribo la venta en un fichero
                    Escribir_Ventas("4", usuario, numero_nave-1);

                    lista_cazas.erase(lista_cazas.begin() + numero_nave-1);//Borro la nave vendida
                }else{cout << "\nNo puede mostrar su nave espacial.\n";}

                }else cout << "\nNo hay cargueros disponibles para comprar.\n" << endl;

                break;

            case '4':

                return;
                break;

            default: cout<< "\nOpción no valida.\n"; break;

            }

        }while(op!='4');


    }
}

void aplicacion::Escribir_Ventas(string id, string comprador, int pos_nave){    //Paso por parametro una identificacion para el tipo de nave, el comprador y la posicion de la neve a comprar

    ofstream archivo;
    string nombre_archivo = "lista_ventas.txt";

    time_t now = time(0);

    tm *time = localtime(&now);     //Registro la hora actual del ordenador justo en el momento de la compra

    int dia = time->tm_mday;
    int mes = time->tm_mon + 1;
    int anio = time->tm_year + 1900;

    //Paso el dia el mes y el año a string
    string d =to_string(dia);
    string m=to_string(mes);
    string y=to_string(anio);
    string fecha = d  + "/" + m + "/" + y;      //Junto dia mes y año en un msmo string


    archivo.open(nombre_archivo.c_str(), ios::app);     //Abro fichero modo escritura, sobrescribe el fichero cada vez que se llama a esta funcion

    //COmpruebo si existe el fichero
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo 'lista_ventas.txt. ";
    }

    if(id == "1"){      //Identificador para escribir como estacion espacial

        archivo << id << ";" << fecha << ";" <<comprador << ";" << lista_estaciones[pos_nave].getNumeroRegistro() << ";" << lista_estaciones[pos_nave].getPropulsion() << ";" <<
                   lista_estaciones[pos_nave].getPrecio() << ";" << lista_estaciones[pos_nave].getTripulantes() << ";" << lista_estaciones[pos_nave].getPasajeros() << ";" <<
                   lista_estaciones[pos_nave].getHangares() << ";" <<lista_estaciones[pos_nave].getEscudo() << endl;

    }else if(id== "2"){     //Identificador para escribir como destructor

        archivo << id << ";" << fecha << ";" <<comprador << ";" << lista_destructores[pos_nave].getNumeroRegistro() << ";" << lista_destructores[pos_nave].getPropulsion() << ";" <<
                   lista_destructores[pos_nave].getPrecio() << ";" << lista_destructores[pos_nave].getTripulantes() << ";";

        for(int j = 0; j<lista_destructores[pos_nave].getNumeroArmas(); j++){

            archivo <<lista_destructores[pos_nave].getTipoArmas(j);

            if(lista_destructores[pos_nave].getNumeroArmas() > j+1){

                archivo << ";";
            }
        }

        archivo << endl;

    }else if(id== "3"){     //Identificador para escribir como carguero

        archivo << id << ";" << fecha << ";" <<comprador << ";" << lista_cargueros[pos_nave].getNumeroRegistro() << ";" << lista_cargueros[pos_nave].getPropulsion() << ";" <<
                   lista_cargueros[pos_nave].getPrecio() << ";" << lista_cargueros[pos_nave].getTripulantes() << ";" << lista_cargueros[pos_nave].getCarga() << ";" <<
                   lista_cargueros[pos_nave].getVelocidad() << ";" <<lista_cargueros[pos_nave].getEscudo() << endl;

    }else if(id=="4"){      //Identificador para escribir como caza

         archivo << id << ";" << fecha << ";" <<comprador << ";" << lista_cazas[pos_nave].getNumeroRegistro() << ";" << lista_cazas[pos_nave].getPropulsion() << ";" <<
                    lista_cazas[pos_nave].getPrecio() << ";" << lista_cazas[pos_nave].getTripulantes() << ";" << lista_cazas[pos_nave].getVel_Max() << ";" <<
                    lista_cazas[pos_nave].getArma1() << ";" <<lista_cazas[pos_nave].getArma2() << endl;

    }

    archivo.close();        //Cierro fichero

}

void aplicacion::Leer_Total_Ventas(){

    ifstream archivo;
    string nombreArchivo_Ventas = "lista_ventas.txt";

    char texto_linea[200];
    char *ptr;
    string texto_linea_aux;
    int num_armas=0, i=0, j=0, k=0;
    string *tipo_arma;
    string propietario, id, fecha, registro, motor, tripulantes, precio, pasajeros, hangares, velocidad_crucero, carga, escudo, velocidad_max, arma1, arma2;
    int cont=0, contador=0;

    cout << "\n*****USTED HA ACCEDIDO AL REGISTRO VENTAS DE LA APLICACIÓN*****\n";

    archivo.open(nombreArchivo_Ventas.c_str(), ios::in);

    if(archivo.fail()){

        cout << "No se pudo abrir el archivo 'lista_estaciones.txt'.";
    }

    while(!archivo.eof()){

        archivo.getline(texto_linea, 200, '\n');
        texto_linea_aux = texto_linea;
        int longitud = strlen(texto_linea);
        contador=0;

        for(int i=0; i<longitud; i++){      //Recojo la cantidad de puntos y comas por linea en la variable contador

            if(texto_linea[i]==';'){

                contador++;

            }
        }

        if(texto_linea[0]!='\0'){

            ptr = strtok(texto_linea, ";");     //Cada vez que encuentro un punto y coma esta funcion lo separa en palabras en el bucle y transforma la linea leida en la primera palabra de la linea antes dl punto y coma
            id=ptr;


            if(id=="1"){    //Forma de leer estaciones

            k++;

            cout << "\nNAVE NUMERO " << k << ": (Estación espacial)\n" << endl;

            while(ptr!=NULL){       //Se repite hasta que no encuentre mas puntos y comas el puntero

                ptr = strtok(NULL, ";");

                //Recupero los parametros en el orden de escritura y los imprimo uno a uno
                if(cont==0){

                    fecha = ptr;
                    cout << "Fecha de compra: " << fecha << endl;
                    cont++;

                }else if(cont==1){

                    propietario = ptr;
                    cout << "Comprador: " << propietario << endl;
                    cont++;

                }else if(cont==2){

                    registro=ptr;
                    cout << "Número de registro: " << registro << endl;
                    cont++;

                }else if(cont==3){

                    motor=ptr;
                    cout << "Tipo de motor: " << motor << endl;
                    cont++;

                }else if(cont==4){

                    precio=ptr;
                    cout << "Precio de venta: " << precio << endl;
                    cont++;

                }else if(cont==5){

                    tripulantes=ptr;
                    cout << "Número de tripulantes: " << tripulantes << endl;
                    cont++;

                }else if(cont==6){

                    pasajeros=ptr;
                    cout << "Número de pasajeros: " << pasajeros << endl;
                    cont++;
                }else if(cont==7){

                    hangares=ptr;
                    cout << "Número de hangares: " << hangares << endl;
                    cont++;
                }else if(cont == 8){

                    escudo=ptr;
                    cout << "Escudo: " << escudo << endl;
                    cont++;
                }
            }


            cont =0;
            contador=0;
            }

            if(id=="2"){    //Forma de leer destructores

            k++;
            cout << "\nNAVE NUMERO " << k << ": (Destructor espacial)\n" << endl;

            num_armas = contador - 6; //Inicializo numero de armas restando 6 que son los ; que hay antes de la primera arma al numero de ; totales de la frase


            //recupero los parametros en el orden de escritura y los imprimo 1 a 1
            while(ptr!=NULL){

                ptr = strtok(NULL, ";");

                if(cont==0){

                    fecha = ptr;
                    cout << "Fecha de compra: " << fecha << endl;
                    cont++;

                }else if(cont==1){

                    propietario = ptr;
                    cout << "Comprador: " << propietario << endl;
                    cont++;

                }else if(cont==2){

                    registro=ptr;
                    cout << "Número de registro: " << registro << endl;
                    cont++;

                }else if(cont==3){

                    motor=ptr;
                    cout << "Tipo de motor: " << motor << endl;
                    cont++;

                }else if(cont==4){

                    precio=ptr;
                    cout << "Precio de venta: " << precio << endl;
                    cont++;

                }else if(cont==5){

                    tripulantes=ptr;
                    cout << "Número de tripulantes: " << tripulantes << endl;
                    cont++;
                    i=0;


                }else if(cont<contador){

                    tipo_arma = new string[num_armas];
                    tipo_arma[i] = ptr;

                    cout << "Tipo arma " << j+1 << ": " << tipo_arma[i] << endl;
                    i++;
                    j++;
                    cont++;
                }                
            }
            cont=0;
            j=0;
            contador=0;
            }

            if(id=="3"){        //Forma de leer cargueros

            k++;


            cout << "\nNAVE NUMERO " << k << ": (Carguero espacial)\n" << endl;

            //Recorro la linea y recupero he imprimo los parametros 1 a 1 en orden de escritura
            while(ptr!=NULL){

                ptr = strtok(NULL, ";");

                if(cont==0){

                    fecha = ptr;
                    cout << "Fecha de compra: " << fecha << endl;
                    cont++;

                }else if(cont==1){

                    propietario = ptr;
                    cout << "Comprador: " << propietario << endl;
                    cont++;

                }else if(cont==2){

                    registro=ptr;
                    cout << "Número de registro: " << registro << endl;
                    cont++;

                }else if(cont==3){

                    motor=ptr;
                    cout << "Tipo de motor: " << motor << endl;
                    cont++;

                }else if(cont==4){

                    precio=ptr;
                    cout << "Precio de venta: " << precio << endl;
                    cont++;

                }else if(cont==5){

                    tripulantes=ptr;
                    cout << "Número de tripulantes: " << tripulantes << endl;
                    cont++;

                }else if(cont==6){

                    carga=ptr;
                    cout << "Carga máxima: " << carga << endl;
                    cont++;
                }else if(cont==7){

                    velocidad_crucero=ptr;
                    cout << "Velocidad crucero: " << velocidad_crucero << endl;
                    cont++;
                }else if(cont == 8){

                    escudo=ptr;
                    cout << "Escudo: " << escudo << endl;
                    cont++;
                }
            }
            cont =0;
            contador=0;
            }

            if(id=="4"){        //Forma de leer cazas

            k++;

            cout << "\nNAVE NUMERO " << k << ": (Caza)\n" << endl;

            //Recorro la linea y recupero he imprimo los parametros 1 a 1 en orden de escritura
            while(ptr!=NULL){

                ptr = strtok(NULL, ";");

                if(cont==0){

                    fecha = ptr;
                    cout << "Fecha de compra: " << fecha << endl;
                    cont++;

                }else if(cont==1){

                    propietario = ptr;
                    cout << "Comprador: " << propietario << endl;
                    cont++;

                }else if(cont==2){

                    registro=ptr;
                    cout << "Número de registro: " << registro << endl;
                    cont++;

                }else if(cont==3){

                    motor=ptr;
                    cout << "Tipo de motor: " << motor << endl;
                    cont++;

                }else if(cont==4){

                    precio=ptr;
                    cout << "Precio de venta: " << precio << endl;
                    cont++;

                }else if(cont==5){

                    tripulantes=ptr;
                    cout << "Número de tripulantes: " << tripulantes << endl;
                    cont++;

                }else if(cont==6){

                    velocidad_max=ptr;
                    cout << "Velocidad máxima: " << velocidad_max << endl;
                    cont++;
                }else if(cont==7){

                    arma1=ptr;
                    cout << "Arma 1: " << arma1 << endl;
                    cont++;
                }else if(cont == 8){

                    arma2=ptr;
                    cout << "Arma 2: " << arma2 << endl;
                    cont++;
                }
            }
            cont =0;
            contador=0;
            }
        }
    }

    archivo.close(); //Cierro el fichero

    if(k==0){cout << "\nNo hay ventas registradas en el sistema.\n";}

}

void aplicacion::Leer_Total_Ventas_Fecha(){

    ifstream archivo;
    string nombreArchivo_Ventas = "lista_ventas.txt";

    char texto_linea[200];
    char *ptr;
    string texto_linea_aux;
    int num_armas=0, i=0, j=0, k=0, cont_1=0;
    string *tipo_arma;
    string propietario, id, fecha, registro, motor, tripulantes, precio, pasajeros, hangares, velocidad_crucero, carga, escudo, velocidad_max, arma1, arma2;
    int cont=0, contador=0;
    bool flag = false;
    bool numero = true;
    string dia, mes, anio, fecha_introducida;

    cout << "\n*****USTED HA ACCEDIDO A LA BUSQUEDA DE NAVES POR FECHA DE COMPRA*****\n";

    cout << "\nLas ventas de que fecha desea mostrar.\nFormato: d/m/yyyy: " << endl;

    //Pido dia de tal forma que solo sean validos los caracteres numericos
    do{
        numero=true;
        cout << "Día: "; cin >> dia;

        for(unsigned i=0; i<dia.length(); i++){

            if(!isdigit(dia.at(i))){numero=false;}

        }

    }while(numero==false);

    //Pido mes de tal forma que solo sean validos los caracteres numéricos
    do{
        numero=true;
        cout << "Mes: "; cin >> mes;

        for(unsigned i=0; i<mes.length(); i++){

            if(!isdigit(mes.at(i))){numero=false;}

        }

    }while(numero==false);

    //Pido año de tal forma que solo sean validos los caracteres numéricos
    do{
        numero=true;
        cout << "Año: "; cin >> anio;

        for(unsigned i=0; i<anio.length(); i++){

            if(!isdigit(anio.at(i))){numero=false;}

        }

    }while(numero==false);


    fecha_introducida = dia + "/" + mes + "/" + anio;       //Junto dia/mes/año en fecha


    archivo.open(nombreArchivo_Ventas.c_str(), ios::in);        //Abro fichero

    if(archivo.fail()){     //Compruebo que exista

        cout << "No se pudo abrir el archivo 'lista_estaciones.txt'.";
    }

    cout << "\n***VENTAS REALIZADAS EN LA FECHA " << fecha_introducida << "***" << endl;

    while(!archivo.eof()){      //Recorro el fichero linea a linea

        archivo.getline(texto_linea, 200, '\n');
        texto_linea_aux = texto_linea;
        int longitud = strlen(texto_linea);
        contador=0;

        for(int i=0; i<longitud; i++){      //Recojo los ; en la variable contador de cada linea

            if(texto_linea[i]==';'){

                contador++;
            }
        }

        if(texto_linea[0]!='\0'){

            ptr = strtok(texto_linea, ";"); //Me quedo solo con la primera cadena del fichero
            id=ptr;     //identificador del tipo de nave que lee


            if(id=="1"){        //Identificador para leer el formato de texto de estacion espacial


            while(ptr!=NULL){

                ptr = strtok(NULL, ";");

                if(cont==0){

                    fecha = ptr;        //Recojo la segunda palabra del fichero que es la fecha de venta
                    if(fecha==fecha_introducida){   //Si coincide con la introducida por teclado imprime las caracteristicas de la estacion

                        flag=true;      //Flag para ssaber si son iguales
                    }
                    cont++;
                //A partir de aqui escribo el resto de caracteristicas de la nave espacial
                }else if(cont==1 && flag==true){

                    k++;
                    cout << "\nNAVE NUMERO " << k << ": (Estación espacial)\n" << endl;
                    propietario = ptr;
                    cout << "Comprador: " << propietario << endl;
                    cont_1++;
                    cont++;

                }else if(cont==2 && flag==true){

                    registro=ptr;
                    cout << "Número de registro: " << registro << endl;
                    cont++;

                }else if(cont==3 && flag==true){

                    motor=ptr;
                    cout << "Tipo de motor: " << motor << endl;
                    cont++;

                }else if(cont==4 && flag==true){

                    precio=ptr;
                    cout << "Precio de venta: " << precio << endl;
                    cont++;

                }else if(cont==5 && flag==true){

                    tripulantes=ptr;
                    cout << "Número de tripulantes: " << tripulantes << endl;
                    cont++;

                }else if(cont==6 && flag==true){

                    pasajeros=ptr;
                    cout << "Número de pasajeros: " << pasajeros << endl;
                    cont++;
                }else if(cont==7 && flag==true){

                    hangares=ptr;
                    cout << "Número de hangares: " << hangares << endl;
                    cont++;
                }else if(cont == 8 && flag==true){

                    escudo=ptr;
                    cout << "Escudo: " << escudo << endl;
                    cont++;
                }
            }


            cont =0;
            contador=0;
            flag = false;
            }

            if(id=="2"){

            num_armas = contador - 6;       //Obtengo el numero de armas restando 6 (numero de parametros antes de la primera arma escrita en el fichero) a la cantidad
                                            //de puntos y comas almacenados en la variable contador
            while(ptr!=NULL){

                ptr = strtok(NULL, ";");

                if(cont==0){

                    fecha = ptr;
                    if(fecha==fecha_introducida){   //Comparo la fecha leida con la introducida

                        flag=true;
                    }
                    cont++;
                    //Si coinciden imprimo el resto de características del destructor

                }else if(cont==1 && flag==true){

                    k++;
                    cout << "\nNAVE NUMERO " << k << ": (Destructor espacial)\n" << endl;
                    propietario = ptr;
                    cout << "Comprador: " << propietario << endl;
                    cont_1++;
                    cont++;

                }else if(cont==2 && flag==true){

                    registro=ptr;
                    cout << "Número de registro: " << registro << endl;
                    cont++;

                }else if(cont==3 && flag==true){

                    motor=ptr;
                    cout << "Tipo de motor: " << motor << endl;
                    cont++;

                }else if(cont==4 && flag==true){

                    precio=ptr;
                    cout << "Precio de venta: " << precio << endl;
                    cont++;

                }else if(cont==5  && flag==true){

                    tripulantes=ptr;
                    cout << "Número de tripulantes: " << tripulantes << endl;
                    cont++;
                    i=0;

                }else if(cont<contador  && flag==true){

                    tipo_arma = new string[num_armas]; //Vector dinámico para almacenar el tipo de armas
                    tipo_arma[i] = ptr;     //Asigno el tipo de armas

                    cout << "Tipo arma " << j+1 << ": " << tipo_arma[i] << endl;
                    i++;
                    j++;
                    cont++;
                }
            }
            cont=0;
            j=0;
            flag=false;
            delete[] tipo_arma;     //Borro el vextor dinámico
            contador=0;
            }

            if(id=="3"){        //Leer cargueros

            while(ptr!=NULL){

                ptr = strtok(NULL, ";");        //Recupero los datos del carguero palabra a palabra

                if(cont==0){

                    fecha = ptr;
                    if(fecha==fecha_introducida){       //Comparo fechas

                        flag=true;
                    }
                    cont++;

                //Si coinciden las fechas imprimo las caracteristicas del carguero
                }else if(cont==1 && flag==true){

                    k++;
                    cout << "\nNAVE NUMERO " << k << ": (Carguero espacial)\n" << endl;
                    propietario = ptr;
                    cout << "Comprador: " << propietario << endl;
                    cont_1++;
                    cont++;

                }else if(cont==2 && flag==true){

                    registro=ptr;
                    cout << "Número de registro: " << registro << endl;
                    cont++;

                }else if(cont==3 && flag==true){

                    motor=ptr;
                    cout << "Tipo de motor: " << motor << endl;
                    cont++;

                }else if(cont==4 && flag==true){

                    precio=ptr;
                    cout << "Precio de venta: " << precio << endl;
                    cont++;

                }else if(cont==5 && flag==true){

                    tripulantes=ptr;
                    cout << "Número de tripulantes: " << tripulantes << endl;
                    cont++;

                }else if(cont==6 && flag==true){

                    carga=ptr;
                    cout << "Carga máxima: " << carga << endl;
                    cont++;
                }else if(cont==7 && flag==true){

                    velocidad_crucero=ptr;
                    cout << "Velocidad crucero: " << velocidad_crucero << endl;
                    cont++;
                }else if(cont == 8 && flag==true){

                    escudo=ptr;
                    cout << "Escudo: " << escudo << endl;
                    cont++;
                }
            }
            cont =0;
            flag=false;
            contador=0;
            }

            if(id=="4"){        //Leer los cazas del fichero

            while(ptr!=NULL){

                ptr = strtok(NULL, ";");        //Recupero palabra a plabra

                if(cont==0){

                    fecha = ptr;
                    if(fecha==fecha_introducida){       //Comparo fechas

                        flag=true;
                    }
                    cont++;

                //Si coinciden imprimo datos
                }else if(cont==1 && flag==true){

                    k++;
                    cout << "\nNAVE NUMERO " << k << ": (Caza)\n" << endl;
                    propietario = ptr;
                    cout << "Comprador: " << propietario << endl;
                    cont_1++;
                    cont++;

                }else if(cont==2 && flag==true){

                    registro=ptr;
                    cout << "Número de registro: " << registro << endl;
                    cont++;

                }else if(cont==3 && flag==true){

                    motor=ptr;
                    cout << "Tipo de motor: " << motor << endl;
                    cont++;

                }else if(cont==4 && flag==true){

                    precio=ptr;
                    cout << "Precio de venta: " << precio << endl;
                    cont++;

                }else if(cont==5 && flag==true){

                    tripulantes=ptr;
                    cout << "Número de tripulantes: " << tripulantes << endl;
                    cont++;

                }else if(cont==6 && flag==true){

                    velocidad_max=ptr;
                    cout << "Velocidad máxima: " << velocidad_max << endl;
                    cont++;
                }else if(cont==7 && flag==true){

                    arma1=ptr;
                    cout << "Arma 1: " << arma1 << endl;
                    cont++;
                }else if(cont == 8 && flag==true){

                    arma2=ptr;
                    cout << "Arma 2: " << arma2 << endl;
                    cont++;
                }
            }
            cont =0;
            flag = false;
            contador=0;
            }
        }
    }

    archivo.close();        //Cierro el fichero

    if(cont_1==0){

        cout << "\nDurante la fecha " << fecha_introducida << " no se registró ninguna venta.\n";
    }

}

bool aplicacion::Comprobar_Numero_Registro(string numero_registro){     //Funcion para comparar los numeros de registro de las distintas naves para comprobar que no esten registrado el numero al dar de alta o modificar

    bool flag = true;

    for(unsigned int i=0; i<lista_estaciones.size(); i++){

        if(lista_estaciones[i].getNumeroRegistro() == numero_registro){

            cout << "\nEstación ya registrada.\nPor favor registre otra nave.\n" << endl;
            flag=false;
        }
    }


    for(unsigned int i=0; i<lista_destructores.size(); i++){

        if(lista_destructores[i].getNumeroRegistro() == numero_registro){

            cout << "\nDestructor ya registrado.\nPor favor registre otra nave.\n" << endl;
            flag=false;
        }
    }


    for(unsigned int i=0; i<lista_cargueros.size(); i++){

        if(lista_cargueros[i].getNumeroRegistro() == numero_registro){

            cout << "\nCarguero ya registrado.\nPor favor registre otra nave.\n" << endl;
            flag=false;
        }
    }


    for(unsigned int i=0; i<lista_cazas.size(); i++){

        if(lista_cazas[i].getNumeroRegistro() == numero_registro){

            cout << "\nCaza ya registrado.\nPor favor registre otra nave.\n" << endl;
            flag=false;
        }
    }

    return flag;

}

void aplicacion::Escrbir_Usuarios_Registro(){       //Funcion para escribir usuarios en un fichero de texto

    ofstream archivo;
    string nombreArchivo_Humanos = "lista_humanos.txt";

    archivo.open(nombreArchivo_Humanos.c_str(), ios::out);      //Abro el fichero donde escribo humanos

    if(archivo.fail()){     //Compruebo que exista el fichero

        cout << "No se pudo abrir el archivo 'lista_humanos.txt'.";
    }

    for(unsigned int i=0; i<lista_humanos.size(); i++){     //Escribo los humanos

        archivo << lista_humanos[i].getNIF() << ";" << lista_humanos[i].getPlaneta() << endl;
    }
    archivo.close();        //Cierro el fichero

    string nombreArchivo_Extraterrestres = "lista_extraterrestres.txt";


    archivo.open(nombreArchivo_Extraterrestres.c_str(), ios::out);      //Abro el fichero de extraterrestres

    if(archivo.fail()){     //Compruebo que exista el fichero

        cout << "No se pudo abrir el archivo 'lista_extraterrestres.txt'.";
    }

    //Escribo extraterrestres en el archivo de extraterrestres
    for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

        archivo << lista_extraterrestres[i].getNIE() << ";" << lista_extraterrestres[i].getPlaneta() << endl;
    }

    archivo.close();
}

void aplicacion::Cargar_Usuarios_Registro(){

    ifstream archivo;
    string nombreArchivo_Humanos = "lista_humanos.txt";
    string nombreArchivo_Extraterrestres = "lista_extraterrestres.txt";
    humanos humano;
    extraterrestres extraterrestre;
    char texto_linea[50], *ptr;
    string planeta, usuario;
    int cont=0;

    //Cargar datos humano
    archivo.open(nombreArchivo_Humanos.c_str(), ios::in);

    if(archivo.fail()){     //Compruebo que el fichero exista

        cout << "No se pudo abrir el archivo 'lista_humanos.txt'.";
    }


    while(!archivo.eof()){  //Leo fichero linea a linea

        archivo.getline(texto_linea, 200, '\n');

        if(texto_linea[0]!='\0'){   //Imprimo hasta que el primer caracter de la linea sea \0

            ptr = strtok(texto_linea, ";");
            usuario= string(texto_linea);
            humano.setNIF(usuario); //Inicializo desde el fichero

            while(ptr!=NULL){

                ptr = strtok(NULL, ";");


                if(cont==0){
                    planeta = ptr;
                    humano.setPlaneta(planeta); //Inicializo desde el fichero
                    cont++;
                }
            }
            cont =0;
            lista_humanos.push_back(humano);        //Guardo en el vector de humanos
        }
    }

    archivo.close();        //Cierro el fichero

    //Cargar datos extraterrestre
    archivo.open(nombreArchivo_Extraterrestres.c_str(), ios::in);

    if(archivo.fail()){     //Compruebo el fichero

        cout << "No se pudo abrir el archivo 'lista_extraterrestres.txt'.";
    }

    while(!archivo.eof()){      //Leo linea a linea

        archivo.getline(texto_linea, 200, '\n');

        if(texto_linea[0]!='\0'){       //Recupero datos del fichero

            ptr = strtok(texto_linea, ";");
            usuario= string(texto_linea);
            extraterrestre.setNIE(usuario);

            while(ptr!=NULL){

                ptr = strtok(NULL, ";");


                if(cont==0){
                    planeta = ptr;
                    extraterrestre.setPlaneta(planeta);
                    cont++;
                }
            }
            cont =0;
            lista_extraterrestres.push_back(extraterrestre);        //Guardo los datos en el vector de extraterrestres
        }
    }

        archivo.close();        //Cierro el fichero
}

void aplicacion::Escribir_Naves_Registradas(){

    ofstream archivo;
    string nombreArchivo_Estaciones = "lista_estaciones.txt";
    string nombreArchivo_Destructores = "lista_destructores.txt";
    string nombreArchivo_Cargueros = "lista_cargueros.txt";
    string nombreArchivo_Cazas = "lista_cazas.txt";

    archivo.open(nombreArchivo_Estaciones.c_str(), ios::out);       //Abro el fichero de texto de estaciones

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo 'lista_estaciones.txt'.";
    }

    for(unsigned int i=0; i<lista_estaciones.size(); i++){      //Escribo una estacion por linea

        archivo << lista_estaciones[i].getPropietario() << ";" << lista_estaciones[i].getNumeroRegistro() << ";" << lista_estaciones[i].getPropulsion() << ";" <<
                   lista_estaciones[i].getPrecio() << ";" << lista_estaciones[i].getTripulantes() << ";" << lista_estaciones[i].getPasajeros() << ";" <<
                   lista_estaciones[i].getHangares() << ";" <<lista_estaciones[i].getEscudo() << endl;

    }
    archivo.close();    //Cierro el fichero


    archivo.open(nombreArchivo_Destructores.c_str(), ios::out);     //Abro el fichero destructores

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo 'lista_destructores.txt'.";
    }

    for(unsigned int i=0; i<lista_destructores.size(); i++){        //Escribo un destructor por linea

        archivo << lista_destructores[i].getPropietario() << ";" << lista_destructores[i].getNumeroRegistro() << ";" << lista_destructores[i].getPropulsion() << ";" <<
                   lista_destructores[i].getPrecio() << ";" << lista_destructores[i].getTripulantes() << ";";

        for(int j = 0; j<lista_destructores[i].getNumeroArmas(); j++){

            archivo <<lista_destructores[i].getTipoArmas(j);

            if(lista_destructores[i].getNumeroArmas() > j+1){

                archivo << ";";
            }
        }

        archivo << endl;
    }
    archivo.close();        //Cierro destructor

    archivo.open(nombreArchivo_Cargueros.c_str(), ios::out);        //Abro el fichero de cargueros

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo 'lista_cargueros.txt'.";
    }

    for(unsigned int i=0; i<lista_cargueros.size(); i++){       //Escribo un carguero por linea

        archivo << lista_cargueros[i].getPropietario() << ";" << lista_cargueros[i].getNumeroRegistro() << ";" << lista_cargueros[i].getPropulsion() << ";" <<
                   lista_cargueros[i].getPrecio() << ";" << lista_cargueros[i].getTripulantes() << ";" << lista_cargueros[i].getCarga() << ";" <<
                   lista_cargueros[i].getVelocidad() << ";" <<lista_cargueros[i].getEscudo() << endl;

    }
    archivo.close();

    archivo.open(nombreArchivo_Cazas.c_str(), ios::out);        //Cierro fichero de cargueros

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo 'lista_cazas.txt'.";
    }

    for(unsigned int i=0; i<lista_cazas.size(); i++){

        archivo << lista_cazas[i].getPropietario() << ";" << lista_cazas[i].getNumeroRegistro() << ";" << lista_cazas[i].getPropulsion() << ";" <<
                   lista_cazas[i].getPrecio() << ";" << lista_cazas[i].getTripulantes() << ";" << lista_cazas[i].getVel_Max() << ";" <<
                   lista_cazas[i].getArma1() << ";" <<lista_cazas[i].getArma2() << endl;

    }
    archivo.close();

}

void aplicacion::Cargar_Naves_Registradas(){


    ifstream archivo;
    string nombreArchivo_Estaciones = "lista_estaciones.txt";
    string nombreArchivo_Destructores = "lista_destructores.txt";
    string nombreArchivo_Cargueros = "lista_cargueros.txt";
    string nombreArchivo_Cazas = "lista_cazas.txt";

    estaciones estacion;
    destructores destructor;
    cargueros carguero;
    cazas caza;
    char texto_linea[200];
    char *ptr;
    string texto_linea_aux;
    int num_armas;
    string tipo_arma;
    string propietario, registro, motor, tripulantes, precio, pasajeros, hangares, velocidad_crucero, carga, escudo, velocidad_max, arma1, arma2;
    int cont=0, contador=0, tripulantes_int, pasajeros_int, hangares_int, contador_linea=0;
    float precio_flo, carga_flo, velocidad_max_flo;

    //Cargar datos estacion
    archivo.open(nombreArchivo_Estaciones.c_str(), ios::in);

    if(archivo.fail()){

        cout << "No se pudo abrir el archivo 'lista_estaciones.txt'.";
    }

    while(!archivo.eof()){      //Leo linea a linea del fichero

        archivo.getline(texto_linea, 200, '\n');
        texto_linea_aux = string(texto_linea);

        //Solo si la primera posicion de fichero esta esrita sigo leyendo esa linea
        if(texto_linea[0]!='\0'){      

            ptr = strtok(texto_linea, ";");
            propietario= string(texto_linea);
            estacion.setPropietario(propietario);

            while(ptr!=NULL){       //Recupero los atributos uno a uno

                ptr = strtok(NULL, ";");

                //Inicializo los atributos segun los recupero
                if(cont==0){
                    registro = ptr;
                    estacion.setNumeroRegistro(registro);
                    cont++;
                }else if(cont==1){

                    motor = ptr;
                    estacion.setPropulsion(motor);
                    cont++;
                }else if(cont==2){

                    precio=ptr;
                    precio_flo = strtof(precio.c_str(), 0);
                    estacion.setPrecio(precio_flo);
                    cont++;

                }else if(cont==3){

                    tripulantes=ptr;
                    tripulantes_int = atoi(tripulantes.c_str());
                    estacion.setTripulantes(tripulantes_int);
                    cont++;

                }else if(cont==4){

                    pasajeros=ptr;
                    pasajeros_int = atoi(pasajeros.c_str());
                    estacion.setPasajeros(pasajeros_int);
                    cont++;

                }else if(cont==5){

                    hangares=ptr;
                    hangares_int = atoi(hangares.c_str());
                    estacion.setHangares(hangares_int);
                    cont++;

                }else if(cont==6){

                    escudo=ptr;
                    estacion.setEscudo(escudo);
                    cont++;
                }
            }
            cont =0;
            lista_estaciones.push_back(estacion);       //Guardo la estacion leida
        }
    }

    archivo.close();    //Cierro el fichero estaciones


    archivo.open(nombreArchivo_Destructores.c_str(), ios::in);  //Abro el fichero de destructores

    if(archivo.fail()){

        cout << "No se pudo abrir el archivo 'lista_destructores.txt'.";
    }

    while(!archivo.eof()){      //Leo linea a linea del fichero

        archivo.getline(texto_linea, 200, '\n');

        contador_linea = 0;
        //Extraigo el numero de ; de la linea
        while(texto_linea[contador_linea]!='\0'){

            if(texto_linea[contador_linea]==';'){
                contador++;
            }
            contador_linea++;
        }


        num_armas = contador - 4;       //Calculo el numero de armas numero de ; menos 4(Atributos antes de la primera arma)

        texto_linea_aux = string(texto_linea);

        if(texto_linea[0]!='\0'){       //Leo hasta que el primer caracter leido sea distinto de \0

            ptr = strtok(texto_linea, ";");
            propietario= string(texto_linea);
            destructor.setPropietario(propietario);

            //Recupero 1 a 1 los atributos y los inicializo
            while(ptr!=NULL || cont<num_armas){

                ptr = strtok(NULL, ";");


                if(cont==0){
                    registro = ptr;
                    destructor.setNumeroRegistro(registro);
                    cont++;
                }else if(cont==1){

                    motor = ptr;
                    destructor.setPropulsion(motor);
                    cont++;
                }else if(cont==2){

                    precio=ptr;
                    precio_flo = strtof(precio.c_str(), 0);
                    destructor.setPrecio(precio_flo);
                    cont++;

                }else if(cont==3){

                    tripulantes=ptr;
                    tripulantes_int = atoi(tripulantes.c_str());
                    destructor.setTripulantes(tripulantes_int);
                    cont++;


                }else if(cont<contador){

                    tipo_arma = ptr;
                    destructor.setTipoArmas(tipo_arma);

                    cont++;
                }

            }

            cont=0;
            contador=0;
            lista_destructores.push_back(destructor);       //Guardo el destructor en el vector de destructores
            destructor.borrar_armas();

        }
    }

    archivo.close();        //Cierro el archivo de destructores


    archivo.open(nombreArchivo_Cargueros.c_str(), ios::in);     //Abro el archivo de cargueros

    if(archivo.fail()){

        cout << "No se pudo abrir el archivo 'lista_cargueros.txt'.";
    }

    while(!archivo.eof()){      //Leo linea a linea

        archivo.getline(texto_linea, 200, '\n');

        if(texto_linea[0]!='\0'){       //Recupero los datos del carguero de la linea 1 a 1

            ptr = strtok(texto_linea, ";");
            propietario= string(texto_linea);
            carguero.setPropietario(propietario);

            //Recupero e inicializo los atributos de los cargueros
            while(ptr!=NULL){

                ptr = strtok(NULL, ";");

                if(cont==0){
                    registro = ptr;
                    carguero.setNumeroRegistro(registro);
                    cont++;
                }else if(cont==1){

                    motor = ptr;
                    carguero.setPropulsion(motor);
                    cont++;
                }else if(cont==2){

                    precio=ptr;
                    precio_flo = strtof(precio.c_str(), 0);
                    carguero.setPrecio(precio_flo);
                    cont++;

                }else if(cont==3){

                    tripulantes=ptr;
                    tripulantes_int = atoi(tripulantes.c_str());
                    carguero.setTripulantes(tripulantes_int);
                    cont++;

                }else if(cont==4){

                    carga=ptr;
                    carga_flo = strtof(carga.c_str(),0);
                    carguero.setCarga(carga_flo);
                    cont++;

                }else if(cont==5){

                    velocidad_crucero=ptr;
                    carguero.setVelocidad(velocidad_crucero);
                    cont++;

                }else if(cont==6){

                    escudo=ptr;
                    carguero.setEscudo(escudo);
                    cont++;
                }
            }
            cont =0;
            lista_cargueros.push_back(carguero);        //Guardo el carguero en el vector de cargueros
        }
    }

    archivo.close();        //Cierro fichero cargueros

    archivo.open(nombreArchivo_Cazas.c_str(), ios::in);     //Abro el fichero de cazas

    if(archivo.fail()){

        cout << "No se pudo abrir el archivo 'lista_cazas.txt'.";
    }

    while(!archivo.eof()){  //Leo el fichero linea a linea

        archivo.getline(texto_linea, 200, '\n');

        if(texto_linea[0]!='\0'){

            ptr = strtok(texto_linea, ";");
            propietario= string(texto_linea);
            caza.setPropietario(propietario);
            //Recupero e inicializo los atributos de los cazas leidos
            while(ptr!=NULL){

                ptr = strtok(NULL, ";");

                if(cont==0){
                    registro = ptr;
                    caza.setNumeroRegistro(registro);
                    cont++;
                }else if(cont==1){

                    motor = ptr;
                    caza.setPropulsion(motor);
                    cont++;
                }else if(cont==2){

                    precio=ptr;
                    precio_flo = strtof(precio.c_str(), 0);
                    caza.setPrecio(precio_flo);
                    cont++;

                }else if(cont==3){

                    tripulantes=ptr;
                    tripulantes_int = atoi(tripulantes.c_str());
                    caza.setTripulantes(tripulantes_int);
                    cont++;

                }else if(cont==4){

                    velocidad_max=ptr;
                    velocidad_max_flo = strtof(velocidad_max.c_str(),0);
                    caza.setVel_Max(velocidad_max_flo);
                    cont++;

                }else if(cont==5){

                    arma1=ptr;
                    caza.setArma1(arma1);
                    cont++;

                }else if(cont==6){

                    arma2=ptr;
                    caza.setArma2(arma2);
                    cont++;
                }
            }
            cont =0;
            lista_cazas.push_back(caza);        //Guardo el caza leido en el vector de cazas
        }
    }

    archivo.close();        //Cierro archivo de cazas
}

void aplicacion::Mostrar_Naves_Propietarios(){      //Muestro las naves registradas a nombre de un propietario

    string usuario;
    bool flag=false;
    int j=0;

    //Compruebo si hay naves y usuarios registrados
    if(lista_humanos.size()==0 && lista_extraterrestres.size()==0){

        cout << "\nNo hay usuarios registrados para realizar la comprobacion.\n";

    }else{

    cout << "\n***BUSQUEDA DE NAVES REGISTRADAS POR USUARIOS***\n" << endl;

    cout << "¿De que usuario desea mostrar las naves registradas en el sistema?: ";
    cin>> usuario;      //Pido de que usuario dseo mostrar las propiedades
    cout << endl;

    for(unsigned int i=0; i<usuario.length(); i++){
        usuario[i] = toupper(usuario[i]);
    }

    //Compruebo que esten registrados en el sistema
    for(unsigned int i=0; i<lista_humanos.size(); i++){

        if(lista_humanos[i].getNIF()==usuario){flag=true;}
    }

    for(unsigned int i=0; i<lista_extraterrestres.size(); i++){

        if(lista_extraterrestres[i].getNIE()==usuario){flag=true;}
    }

    if(flag==false){ cout << "El usuario " << usuario << " no esta registrado en el sistema.";}

    //Recorro las listas para ver si ha naves a su nombre
    for(unsigned int i=0; i < lista_estaciones.size(); i++){

        if(lista_estaciones[i].getPropietario()==usuario){

            cout << "ESTACION: "<<j+1<<":\n"<<endl;
            cout << "Propietario: " << lista_estaciones[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_estaciones[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_estaciones[i].getPropulsion() << endl;
            cout << "Precio: " << lista_estaciones[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_estaciones[i].getTripulantes()<<endl;
            cout << "Numero de pasajeros: " << lista_estaciones[i].getPasajeros()<< endl;
            cout << "Numero de hangares: " << lista_estaciones[i].getHangares()<< endl;
            cout << "Escudo: " << lista_estaciones[i].getEscudo() << endl << endl;
            j++;
        }
    }

    j=0;

    for(unsigned int i=0; i < lista_destructores.size(); i++){

        if(lista_destructores[i].getPropietario()==usuario){

            cout << "DESTRUCTOR "<<j+1<<":\n"<<endl;
            cout << "Propietario: " << lista_destructores[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_destructores[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_destructores[i].getPropulsion() << endl;
            cout << "Precio: " << lista_destructores[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_destructores[i].getTripulantes()<<endl;
            for(int j = 0; j<lista_destructores[i].getNumeroArmas(); j++){
                cout << "Arma numero " << j+1 << ": " <<lista_destructores[i].getTipoArmas(j)<<endl;
                j++;
            }

        }
        cout << endl;
    }

    j=0;

    for(unsigned int i=0; i < lista_cargueros.size(); i++){

        if(lista_cargueros[i].getPropietario()==usuario){

            cout << "CARGUERO "<< j+1 <<":\n"<<endl;
            cout << "Propietario: " << lista_cargueros[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_cargueros[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_cargueros[i].getPropulsion() << endl;
            cout << "Precio: " << lista_cargueros[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_cargueros[i].getTripulantes()<<endl;
            cout << "Carga máxima admitida: " << lista_cargueros[i].getCarga()<<endl;
            cout << "Velocidad máxima: " << lista_cargueros[i].getVelocidad()<<endl;
            cout << "Escudo: " << lista_cargueros[i].getEscudo()<< endl << endl;
            j++;
        }       
    }

    j=0;

    for(unsigned int i=0; i < lista_cazas.size(); i++){

        if(lista_cazas[i].getPropietario()==usuario){

            cout << "CAZA "<<j+1<<":\n"<<endl;
            cout << "Propietario: " << lista_cazas[i].getPropietario()<<endl;
            cout << "Numero de registro: " << lista_cazas[i].getNumeroRegistro()<<endl;
            cout << "Tipo de propulsion: " << lista_cazas[i].getPropulsion() << endl;
            cout << "Precio: " << lista_cazas[i].getPrecio() << endl;
            cout << "Numero de tripulantes: " << lista_cazas[i].getTripulantes()<<endl;
            cout << "Velocidad máxima: " << lista_cazas[i].getVel_Max()<<endl;
            cout << "Arma 1: " << lista_cazas[i].getArma1()<<endl;
            cout << "Arma 2: " << lista_cazas[i].getArma2()<<endl<<endl;
            j++;

        }
    }
    }
}

void aplicacion::Modificar_Estacion(){


    string propietario, numero_registro, tipo_propulsion, escudo, cadena;
    unsigned int tripulantes, numero_maximo_pasajeros, numero_hangares, numero_nave;
    float precio;
    char seleccion;
    bool flag = true, numero=true;
    bool flag1= false;

    estaciones modificar_estacion;

    if(lista_estaciones.size()!=0){

    //Muestro cargueros para odificar
    cout << "\n***LISTA ESTACIONES REGISTRADAS***\n"<<endl;
    for(unsigned int i=0; i<lista_estaciones.size(); i++){

        cout << "Estacion "<<i+1<<":\n"<<endl;
        cout << "Propietario: " << lista_estaciones[i].getPropietario()<<endl;
        cout << "Numero de registro: " << lista_estaciones[i].getNumeroRegistro()<<endl;
        cout << "Tipo de propulsion: " << lista_estaciones[i].getPropulsion() << endl;
        cout << "Precio: " << lista_estaciones[i].getPrecio() << endl;
        cout << "Numero de tripulantes: " << lista_estaciones[i].getTripulantes()<<endl;
        cout << "Numero de pasajeros: " << lista_estaciones[i].getPasajeros()<< endl;
        cout << "Numero de hangares: " << lista_estaciones[i].getHangares()<< endl;
        cout << "Escudo: " << lista_estaciones[i].getEscudo()<< endl << endl;
    }

    do{
        numero=true;
        cout <<"Indique el numero estacion que desea modificar: ";
        cin>> cadena;           //Elijo el numero de estacion a modificar

        for(unsigned i=0; i<cadena.length(); i++){  //Evito salidas del sistema por datos introducidos erroneamente

            if(!isdigit(cadena.at(i))){numero=false;}
        }

        if(numero){numero_nave = stoi(cadena);}

    }while(numero==false || numero_nave>lista_estaciones.size() || numero_nave<=0);

    //Pregunto si deseo modificar este campo
    do{
        cout << "\n¿Desea modificar el propietario de la nave seleccionada (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){


        do{ //Pido nuevo numero de propietario
            propietario = modificar_estacion.Asignar_Propietario();

            //Compruebo que este registrado
            for(unsigned int i = 0; i<lista_humanos.size(); i++){

                if(lista_humanos[i].getNIF() == propietario){flag1 = true;}
            }


            for(unsigned int i = 0; i<lista_extraterrestres.size(); i++){

                if(lista_extraterrestres[i].getNIE() == propietario){flag1 = true;}
            }


        }while(flag1 == false);

        modificar_estacion.setPropietario(propietario);     //Inicializo el atributo propietario


    }else if(seleccion=='N'){

        propietario = lista_estaciones[numero_nave-1].getPropietario(); //Recupero el propietario anterior
        modificar_estacion.setPropietario(propietario);     //Se lo asigno al nuevo objeto
    }

    //Pregunto si deseo modificar este parámetro
    do{
        cout << "\n¿Desea modificar el numero de registro de la nave seleccionada (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){

        do{
            numero_registro = modificar_estacion.Asignar_Numero_Registro(); //Pido nuevo numero de registro
            modificar_estacion.setNumeroRegistro(numero_registro);          //Inicializo el numero de registro
            flag=true;

            //Compruebo que no haya otra estación con el mismo numero de registro
            for(unsigned int i=0; i<lista_estaciones.size(); i++){

                if(lista_estaciones[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_destructores.size(); i++){

                if(lista_destructores[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_cargueros.size(); i++){

                if(lista_cargueros[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_cazas.size(); i++){

                if(lista_cazas[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }

            if(flag==false){cout << "\nNumero ya registrado.\nPor favor registre otro numero de serie.\n" << endl;}

        }while(flag==false);



    }else if(seleccion=='N'){       //Recupero datos y los introduzco enel nuevo objeto

        numero_registro = lista_estaciones[numero_nave-1].getNumeroRegistro();
        modificar_estacion.setNumeroRegistro(numero_registro);
    }


    do{
        cout << "\n¿Desea modificar el tipo de propulsion de la nave seleccionada (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){     //Pido datos nuevos y los inicializo en el nuevo objeto

        tipo_propulsion = modificar_estacion.Tipo_Propulsion();
        modificar_estacion.setPropulsion(tipo_propulsion);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        tipo_propulsion = lista_estaciones[numero_nave-1].getPropulsion();
        modificar_estacion.setPropulsion(tipo_propulsion);
    }


    do{
        cout << "\n¿Desea modificar el numero de tripulantes de la nave seleccionada (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){     //Pido datos nuevos y los inicializo en el nuevo objeto

        tripulantes = modificar_estacion.Numero_Max_Tripulantes();
        modificar_estacion.setTripulantes(tripulantes);

    }else if(seleccion=='N'){        //Recupero datos y los introduzco en el nuevo objeto

        tripulantes = lista_estaciones[numero_nave-1].getTripulantes();
        modificar_estacion.setTripulantes(tripulantes);
    }

    do{
        cout << "\n¿Desea modificar el precio de la nave seleccionada (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){          //Pido datos nuevos y los inicializo en el nuevo objeto

        precio = modificar_estacion.Fijar_Precio();
        modificar_estacion.setPrecio(precio);

    }else if(seleccion=='N'){        //Recupero datos y los introduzco en el nuevo objeto

        precio = lista_estaciones[numero_nave-1].getPrecio();
        modificar_estacion.setPrecio(precio);
    }

    do{
        cout << "\n¿Desea modificar el numero máximo de pasajeros de la nave seleccionada (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){     //Pido datos nuevos y los inicializo en el nuevo objeto

        numero_maximo_pasajeros = modificar_estacion.Asignar_Pasajeros();
        modificar_estacion.setPasajeros(numero_maximo_pasajeros);

    }else if(seleccion=='N'){        //Recupero datos y los introduzco en el nuevo objeto

        numero_maximo_pasajeros = lista_estaciones[numero_nave-1].getPasajeros();
        modificar_estacion.setPasajeros(numero_maximo_pasajeros);
    }

    do{
        cout << "\n¿Desea modificar el numero máximo de hangares de la nave seleccionada (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){     //Pido datos nuevos y los inicializo en el nuevo objeto

        numero_hangares = modificar_estacion.Asignar_Hangares();
        modificar_estacion.setHangares(numero_hangares);

    }else if(seleccion=='N'){        //Recupero datos y los introduzco en el nuevo objeto

        numero_hangares = lista_estaciones[numero_nave-1].getHangares();
        modificar_estacion.setHangares(numero_hangares);
    }

    do{
        cout << "\n¿Desea modificar el escudo de la nave seleccionada (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        escudo = modificar_estacion.Asignar_Escudo();
        modificar_estacion.setEscudo(escudo);

    }else if(seleccion=='N'){        //Recupero datos y los introduzco en el nuevo objeto

        escudo = lista_estaciones[numero_nave-1].getEscudo();
        modificar_estacion.setEscudo(escudo);
    }

    lista_estaciones.erase(lista_estaciones.begin()+numero_nave-1);     //Borro la nave a modificar
    lista_estaciones.insert(lista_estaciones.begin()+numero_nave-1, modificar_estacion);    //Introduzco la nueva nave en la posicion en la que estaba


    cout << "\n***LISTA ESTACION MODIFICADA***\n"<<endl;

        cout << "Estacion "<<numero_nave<<":\n"<<endl;
        cout << "Propietario: " << lista_estaciones[numero_nave-1].getPropietario()<<endl;
        cout << "Numero de registro: " << lista_estaciones[numero_nave-1].getNumeroRegistro()<<endl;
        cout << "Tipo de propulsion: " << lista_estaciones[numero_nave-1].getPropulsion() << endl;
        cout << "Precio: " << lista_estaciones[numero_nave-1].getPrecio() << endl;
        cout << "Numero de tripulantes: " << lista_estaciones[numero_nave-1].getTripulantes()<<endl;
        cout << "Numero de pasajeros: " << lista_estaciones[numero_nave-1].getPasajeros()<< endl;
        cout << "Numero de hangares: " << lista_estaciones[numero_nave-1].getHangares()<< endl;
        cout << "Escudo: " << lista_estaciones[numero_nave-1].getEscudo()<< endl << endl;

    }else cout << "\nNo hay ninguna estación registrada para modificar.\n" << endl;

}

void aplicacion::Modificar_Destructor(){


    string propietario, numero_registro, tipo_propulsion, cadena;
    unsigned int tripulantes, numero_nave, numero_armas;
    float precio;
    char seleccion;
    bool flag = true, numero=true;
    bool flag1= false;
    string tipo_arma;

    destructores modificar_destructor;

    if(lista_destructores.size()!=0){

    //Muestro destructores registrados en el sistema

    cout << "\n***LISTA DESTRUCTORES REGISTRADOS***\n"<<endl;
    for(unsigned int i=0; i<lista_destructores.size(); i++){

        cout << "Destructor "<<i+1<<":\n"<<endl;
        cout << "Propietario: " << lista_destructores[i].getPropietario()<<endl;
        cout << "Numero de registro: " << lista_destructores[i].getNumeroRegistro()<<endl;
        cout << "Tipo de propulsion: " << lista_destructores[i].getPropulsion() << endl;
        cout << "Precio: " << lista_destructores[i].getPrecio() << endl;
        cout << "Numero de tripulantes: " << lista_destructores[i].getTripulantes()<<endl;
        for(int j = 0; j<lista_destructores[i].getNumeroArmas(); j++){

            cout << "Arma numero " << j+1 << ": " <<lista_destructores[i].getTipoArmas(j)<<endl;
        }
        cout << endl;
    }

    do{
        numero=true;
        cout <<"Indique el numero destructor que desea modificar: ";
        cin>> cadena;       //Evito salidas por tipos de datos erroneos

        for(unsigned i=0; i<cadena.length(); i++){

            if(!isdigit(cadena.at(i))){numero=false;}

        }

        if(numero){numero_nave = stoi(cadena);}

    }while(numero==false || numero_nave>lista_destructores.size() || numero_nave<=0);

    do{
        cout << "\n¿Desea modificar el propietario de la destructor seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){      //Pido datos nuevos y los inicializo en el nuevo objeto


        do{

            propietario = modificar_destructor.Asignar_Propietario();

            //Compruebo que este registrado
            for(unsigned int i = 0; i<lista_humanos.size(); i++){

                if(lista_humanos[i].getNIF() == propietario){flag1 = true;}
            }


            for(unsigned int i = 0; i<lista_extraterrestres.size(); i++){

                if(lista_extraterrestres[i].getNIE() == propietario){flag1 = true;}
            }

        }while(flag1 == false);


        modificar_destructor.setPropietario(propietario);


    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        propietario = lista_destructores[numero_nave-1].getPropietario();
        modificar_destructor.setPropietario(propietario);
    }

    do{
        cout << "\n¿Desea modificar el numero de registro del destructor seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){          //Pido datos nuevos y los inicializo en el nuevo objeto

        do{
            numero_registro = modificar_destructor.Asignar_Numero_Registro();
            modificar_destructor.setNumeroRegistro(numero_registro);

            flag=true;

            //Compruebo que no haya otra nave con el mismo numero de refistro
            for(unsigned int i=0; i<lista_estaciones.size(); i++){

                if(lista_estaciones[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_destructores.size(); i++){

                if(lista_destructores[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_cargueros.size(); i++){

                if(lista_cargueros[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_cazas.size(); i++){

                if(lista_cazas[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }

            if(flag==false){cout << "\nNumero ya registrado.\nPor favor registre otro numero de serie.\n" << endl;}

        }while(flag==false);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        numero_registro = lista_destructores[numero_nave-1].getNumeroRegistro();
        modificar_destructor.setNumeroRegistro(numero_registro);
    }


    do{
        cout << "\n¿Desea modificar el tipo de propulsion del destructor seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){     //Pido datos nuevos y los inicializo en el nuevo objeto

        tipo_propulsion = modificar_destructor.Tipo_Propulsion();
        modificar_destructor.setPropulsion(tipo_propulsion);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        tipo_propulsion = lista_destructores[numero_nave-1].getPropulsion();
        modificar_destructor.setPropulsion(tipo_propulsion);
    }

    do{
        cout << "\n¿Desea modificar el numero de tripulantes del destructor seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){     //Pido datos nuevos y los inicializo en el nuevo objeto

        tripulantes = modificar_destructor.Numero_Max_Tripulantes();
        modificar_destructor.setTripulantes(tripulantes);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        tripulantes = lista_destructores[numero_nave-1].getTripulantes();
        modificar_destructor.setTripulantes(tripulantes);
    }

    do{
        cout << "\n¿Desea modificar el precio del destructor seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){     //Pido datos nuevos y los inicializo en el nuevo objeto

        precio = modificar_destructor.Fijar_Precio();
        modificar_destructor.setPrecio(precio);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        precio = lista_destructores[numero_nave-1].getPrecio();
        modificar_destructor.setPrecio(precio);
    }
    do{
        cout << "\n¿Desea modificar el armamento del destructor seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){     //Pido datos nuevos y los inicializo en el nuevo objeto

        numero_armas = modificar_destructor.Asignar_Numero_Armas();
        modificar_destructor.setNumeroArmas(numero_armas);
        modificar_destructor.Asignar_Tipo_Armamento(numero_armas);


    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        numero_armas = lista_destructores[numero_nave-1].getNumeroArmas();

        for(unsigned int i=0; i<numero_armas; i++){

            tipo_arma = lista_destructores[numero_nave-1].getTipoArmas(i);
            modificar_destructor.setTipoArmas(tipo_arma);
        }

    }


    lista_destructores.erase(lista_destructores.begin()+numero_nave-1);     //Boro destructor antiguo
    lista_destructores.insert(lista_destructores.begin()+numero_nave-1, modificar_destructor);      //introduzco el nuevo destructor modificado

    cout << "\n***LISTA DESTRUCTOR ACTUALIZADO***\n"<<endl;
        cout << "Destructor "<<numero_nave<<":\n"<<endl;
        cout << "Propietario: " << lista_destructores[numero_nave-1].getPropietario()<<endl;
        cout << "Numero de registro: " << lista_destructores[numero_nave-1].getNumeroRegistro()<<endl;
        cout << "Tipo de propulsion: " << lista_destructores[numero_nave-1].getPropulsion() << endl;
        cout << "Precio: " << lista_destructores[numero_nave-1].getPrecio() << endl;
        cout << "Numero de tripulantes: " << lista_destructores[numero_nave-1].getTripulantes()<<endl;
        for(unsigned int j = 0; j<numero_armas; j++){

            cout << "Arma numero " << j+1 << ": " <<lista_destructores[numero_nave-1].getTipoArmas(j) <<endl;
        }

    }else cout << "\nNo hay ningun destructor registrado para modificar.\n" << endl;

}

void aplicacion::Modificar_Carguero(){

    string propietario, numero_registro, tipo_propulsion, escudo, velocidad_crucero, cadena;
    unsigned int tripulantes, numero_nave;
    float precio, carga_maxima;
    char seleccion;
    bool flag = true, numero=true;
    bool flag1= false;

    cargueros modificar_carguero;

    if(lista_cargueros.size() != 0){

    //Muestro cargueros disponibles para modificar
    cout << "\n***LISTA CARGUEROS REGISTRADOS***\n"<<endl;
    for(unsigned int i=0; i<lista_cargueros.size(); i++){

        cout << "Estacion "<<i+1<<":\n"<<endl;
        cout << "Propietario: " << lista_cargueros[i].getPropietario()<<endl;
        cout << "Numero de registro: " << lista_cargueros[i].getNumeroRegistro()<<endl;
        cout << "Tipo de propulsion: " << lista_cargueros[i].getPropulsion() << endl;
        cout << "Numero de tripulantes: " << lista_cargueros[i].getTripulantes()<<endl;
        cout << "Precio: " << lista_cargueros[i].getPrecio() << endl;
        cout << "Carga máxima admitida: " << lista_cargueros[i].getCarga()<<endl;
        cout << "Velocidad máxima: " << lista_cargueros[i].getVelocidad()<<endl;
        cout << "Escudo: " << lista_cargueros[i].getEscudo()<< endl << endl;
    }

    do{
        numero=true;
        cout <<"Indique el numero de carguero que desea modificar: ";
        cin>> cadena;

        for(unsigned i=0; i<cadena.length(); i++){  //evito la salida del programa por introduccion de un caracter

            if(!isdigit(cadena.at(i))){numero=false;}
        }

        if(numero){ numero_nave = stoi(cadena);}

    }while(numero==false || numero_nave>lista_cargueros.size() || numero_nave<=0);



    do{
        cout << "\n¿Desea modificar el propietario del carguero seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto


        do{

            propietario = modificar_carguero.Asignar_Propietario();


            for(unsigned int i = 0; i<lista_humanos.size(); i++){

                if(lista_humanos[i].getNIF() == propietario){flag1 = true;}
            }


            for(unsigned int i = 0; i<lista_extraterrestres.size(); i++){

                if(lista_extraterrestres[i].getNIE() == propietario){flag1 = true;}
            }

        }while(flag1 == false);


        modificar_carguero.setPropietario(propietario);


    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        propietario = lista_cargueros[numero_nave-1].getPropietario();
        modificar_carguero.setPropietario(propietario);
    }

    do{
        cout << "\n¿Desea modificar el numero de registro del carguero seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        do{
            numero_registro = modificar_carguero.Asignar_Numero_Registro();
            modificar_carguero.setNumeroRegistro(numero_registro);

            flag=true;

            for(unsigned int i=0; i<lista_estaciones.size(); i++){

                if(lista_estaciones[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_destructores.size(); i++){

                if(lista_destructores[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_cargueros.size(); i++){

                if(lista_cargueros[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_cazas.size(); i++){

                if(lista_cazas[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }

            if(flag==false){cout << "\nNumero ya registrado.\nPor favor registre otro numero de serie.\n" << endl;}

        }while(flag==false);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        numero_registro = lista_cargueros[numero_nave-1].getNumeroRegistro();
        modificar_carguero.setNumeroRegistro(numero_registro);
    }


    do{
        cout << "\n¿Desea modificar el tipo de propulsion del carguero seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        tipo_propulsion = modificar_carguero.Tipo_Propulsion();
        modificar_carguero.setPropulsion(tipo_propulsion);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        tipo_propulsion = lista_cargueros[numero_nave-1].getPropulsion();
        modificar_carguero.setPropulsion(tipo_propulsion);
    }


    do{
        cout << "\n¿Desea modificar el numero de tripulantes del carguero seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        tripulantes = modificar_carguero.Numero_Max_Tripulantes();
        modificar_carguero.setTripulantes(tripulantes);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        tripulantes = lista_cargueros[numero_nave-1].getTripulantes();
        modificar_carguero.setTripulantes(tripulantes);
    }

    do{
        cout << "\n¿Desea modificar el precio del carguero seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        precio = modificar_carguero.Fijar_Precio();
        modificar_carguero.setPrecio(precio);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        precio = lista_cargueros[numero_nave-1].getTripulantes();
        modificar_carguero.setPrecio(precio);
    }

    do{
        cout << "\n¿Desea modificar la carga máxima admitida del carguero seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        carga_maxima = modificar_carguero.Fijar_Precio();
        modificar_carguero.setCarga(carga_maxima);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        carga_maxima = lista_cargueros[numero_nave-1].getCarga();
        modificar_carguero.setCarga(carga_maxima);
    }

    do{
        cout << "\n¿Desea modificar la velocidad de crucero del carguero seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        velocidad_crucero = modificar_carguero.Asignar_Vel_Crucero();
        modificar_carguero.setVelocidad(velocidad_crucero);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        velocidad_crucero = lista_cargueros[numero_nave-1].getVelocidad();
        modificar_carguero.setVelocidad(velocidad_crucero);
    }

    do{
        cout << "\n¿Desea modificar el escudo del carguero seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        escudo = modificar_carguero.Asignar_Escudo();
        modificar_carguero.setEscudo(escudo);

    }else if(seleccion=='N'){       //Recupero datos y los introduzco en el nuevo objeto

        escudo = lista_cargueros[numero_nave-1].getEscudo();
        modificar_carguero.setEscudo(escudo);
    }

    lista_cargueros.erase(lista_cargueros.begin()+numero_nave-1);       //Borro carguero sin modificar
    lista_cargueros.insert(lista_cargueros.begin()+numero_nave-1, modificar_carguero);      //Inserto carguero modificado

    cout << "\n***CARGUERO ACTUALIZADO***\n"<<endl;

        cout << "Estacion "<<numero_nave<<":\n"<<endl;
        cout << "Propietario: " << lista_cargueros[numero_nave-1].getPropietario()<<endl;
        cout << "Numero de registro: " << lista_cargueros[numero_nave-1].getNumeroRegistro()<<endl;
        cout << "Tipo de propulsion: " << lista_cargueros[numero_nave-1].getPropulsion() << endl;
        cout << "Numero de tripulantes: " << lista_cargueros[numero_nave-1].getTripulantes()<<endl;
        cout << "Precio: " << lista_cargueros[numero_nave-1].getPrecio() << endl;
        cout << "Carga máxima admitida: " << lista_cargueros[numero_nave-1].getCarga()<<endl;
        cout << "Velocidad crucero: " << lista_cargueros[numero_nave-1].getVelocidad()<<endl;
        cout << "Escudo: " << lista_cargueros[numero_nave-1].getEscudo()<< endl << endl;

    }else cout << "\nNo hay ningun carguero registrado para modificar.\n" << endl;




}

void aplicacion::Modificar_Caza(){

    string propietario, numero_registro, tipo_propulsion, arma1, arma2, cadena;
    unsigned int tripulantes, numero_nave;
    float precio, velocidad_maxima;
    char seleccion;
    bool flag = true, numero=true;
    bool flag1= false;

    cazas modificar_caza;

    if(lista_cazas.size()!=0){

    //Muestro cazas registrados en el sistema
    cout << "\n***LISTA CAZAS REGISTRADOS***\n"<<endl;
    for(unsigned int i=0; i<lista_cazas.size(); i++){

        cout << "Caza "<<i+1<<":\n"<<endl;
        cout << "Propietario: " << lista_cazas[i].getPropietario()<<endl;
        cout << "Numero de registro: " << lista_cazas[i].getNumeroRegistro()<<endl;
        cout << "Tipo de propulsion: " << lista_cazas[i].getPropulsion() << endl;
        cout << "Numero de tripulantes: " << lista_cazas[i].getTripulantes()<<endl;
        cout << "Precio: " << lista_cazas[i].getPrecio() << endl;
        cout << "Velocidad máxima: " << lista_cazas[i].getVel_Max()<<endl;
        cout << "Arma 1: " << lista_cazas[i].getArma1()<<endl;
        cout << "Arma 2: " << lista_cazas[i].getArma2()<<endl << endl;
    }

    do{
        numero=true;
        cout <<"Indique el numero de caza que desea modificar: ";
        cin>> cadena;

        for(unsigned i=0; i<cadena.length(); i++){

            if(!isdigit(cadena.at(i))){numero=false;}

        }

        if(numero){numero_nave = stoi(cadena);}

    }while(numero==false || numero_nave>lista_cazas.size() || numero_nave<=0);

    do{
        cout << "\n¿Desea modificar el propietario del caza seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto


        do{

            propietario = modificar_caza.Asignar_Propietario();

            for(unsigned int i = 0; i<lista_humanos.size(); i++){

                if(lista_humanos[i].getNIF() == propietario){flag1 = true;}
            }


            for(unsigned int i = 0; i<lista_extraterrestres.size(); i++){

                if(lista_extraterrestres[i].getNIE() == propietario){flag1 = true;}
            }

        }while(flag1 == false);


        modificar_caza.setPropietario(propietario);


    }else if(seleccion=='N'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        propietario = lista_cazas[numero_nave-1].getPropietario();
        modificar_caza.setPropietario(propietario);
    }

    do{
        cout << "\n¿Desea modificar el numero de registro del caza seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        do{

            numero_registro = modificar_caza.Asignar_Numero_Registro();
            modificar_caza.setNumeroRegistro(numero_registro);

            flag=true;


            for(unsigned int i=0; i<lista_estaciones.size(); i++){

                if(lista_estaciones[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_destructores.size(); i++){

                if(lista_destructores[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_cargueros.size(); i++){

                if(lista_cargueros[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }
            for(unsigned int i=0; i<lista_cazas.size(); i++){

                if(lista_cazas[i].getNumeroRegistro() == numero_registro){

                    flag=false;
                }
            }

            if(flag==false){cout << "\nNumero ya registrado.\nPor favor registre otro numero de serie.\n" << endl;}

        }while(flag==false);

    }else if(seleccion=='N'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        numero_registro = lista_cazas[numero_nave-1].getNumeroRegistro();
        modificar_caza.setNumeroRegistro(numero_registro);
    }


    do{
        cout << "\n¿Desea modificar el tipo de propulsion del caza seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        tipo_propulsion = modificar_caza.Tipo_Propulsion();
        modificar_caza.setPropulsion(tipo_propulsion);

    }else if(seleccion=='N'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        tipo_propulsion = lista_cazas[numero_nave-1].getPropulsion();
        modificar_caza.setPropulsion(tipo_propulsion);
    }


        tripulantes = lista_cazas[numero_nave-1].getTripulantes();
        modificar_caza.setTripulantes(tripulantes);


    do{
        cout << "\n¿Desea modificar el precio del caza seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        precio = modificar_caza.Fijar_Precio();
        modificar_caza.setPrecio(precio);

    }else if(seleccion=='N'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        precio = lista_cazas[numero_nave-1].getTripulantes();
        modificar_caza.setPrecio(precio);
    }


    do{

        cout << "\n¿Desea modificar la velocidad máxima del caza seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        velocidad_maxima = modificar_caza.Asignar_Velocidad_Maxima();
        modificar_caza.setVel_Max(velocidad_maxima);

    }else if(seleccion=='N'){

        velocidad_maxima = lista_cazas[numero_nave-1].getVel_Max();
        modificar_caza.setVel_Max(velocidad_maxima);
    }

    do{
        cout << "\n¿Desea modificar el arma 1 del caza seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        arma1 = modificar_caza.Asignar_Arma1();
        modificar_caza.setArma1(arma1);

    }else if(seleccion=='N'){

        arma1 = lista_cazas[numero_nave-1].getArma1();
        modificar_caza.setArma1(arma1);
    }

    do{
        cout << "\n¿Desea modificar el arma 2 del caza seleccionado (S/N)?";
        cin >> seleccion;
        seleccion = toupper(seleccion);

    }while(seleccion!='S' && seleccion!='N');

    if(seleccion=='S'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        arma2 = modificar_caza.Asignar_Arma2();
        modificar_caza.setArma2(arma2);

    }else if(seleccion=='N'){             //Pido datos nuevos y los inicializo en el nuevo objeto

        arma2 = lista_cazas[numero_nave-1].getArma2();
        modificar_caza.setArma2(arma2);
    }

    lista_cazas.erase(lista_cazas.begin()+numero_nave-1);
    lista_cazas.insert(lista_cazas.begin()+numero_nave-1, modificar_caza);

    cout << "\n***CAZA ACTUALIZADO***\n"<<endl;

        cout << "Caza "<<numero_nave<<":\n"<<endl;
        cout << "Propietario: " << lista_cazas[numero_nave-1].getPropietario()<<endl;
        cout << "Numero de registro: " << lista_cazas[numero_nave-1].getNumeroRegistro()<<endl;
        cout << "Tipo de propulsion: " << lista_cazas[numero_nave-1].getPropulsion() << endl;
        cout << "Numero de tripulantes: " << lista_cazas[numero_nave-1].getTripulantes()<<endl;
        cout << "Precio: " << lista_cazas[numero_nave-1].getPrecio() << endl;
        cout << "Velocidad máxima: " << lista_cazas[numero_nave-1].getVel_Max()<<endl;
        cout << "Arma 1: " << lista_cazas[numero_nave-1].getArma1()<<endl;
        cout << "Arma 2: " << lista_cazas[numero_nave-1].getArma2()<<endl<<endl;

    }else cout << "\nNo hay ningun caza registrado para modificar.\n" << endl;

}

aplicacion::~aplicacion(){
}

