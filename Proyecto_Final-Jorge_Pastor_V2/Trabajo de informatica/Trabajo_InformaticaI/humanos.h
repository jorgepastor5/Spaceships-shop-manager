#ifndef HUMANOS_H
#define HUMANOS_H

#include <iostream>
#include <string>

#include <propietarios.h>
#include <aplicacion.h>

using namespace std;



class humanos : public propietarios {

private:
    string NIF;

public:
    humanos();
    void setNIF(string);
    string getNIF();
    string pedirPlaneta();
    ~humanos();
};

#endif // HUMANOS_H
