#ifndef PROPIETARIOS_H
#define PROPIETARIOS_H

#include <iostream>
#include <string.h>

using namespace std;

class aplicacion;
class naves;
class comprar;


class propietarios {

private:

    string planeta;

public:

    propietarios();
    void setPlaneta(string);
    string getPlaneta();
    virtual string pedirPlaneta() = 0;
    ~propietarios();

};

#endif // PROPIETARIOS_H
