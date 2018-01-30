#ifndef EXTRATERRESTRES_H
#define EXTRATERRESTRES_H

#include <iostream>
#include <string.h>
#include <propietarios.h>

using namespace std;

class extraterrestres : public propietarios{
private:

    string NIE;

public:

    extraterrestres();
    void setNIE(string);
    string getNIE();
    string pedirPlaneta();
    ~extraterrestres();

};

#endif // EXTRATERRESTRES_H
