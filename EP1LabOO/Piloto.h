#ifndef Piloto_H
#define Piloto_H

#include "Sinal.h"
#include "Amplificador.h"
#include "Integrador.h"

class Piloto { 
    private:
    Integrador *integrador = new Integrador();
    Amplificador *amp;
    

    public:
    Piloto(double ganho);
    virtual ~Piloto();
    Sinal* processar(Sinal* sinalIN);

};


#endif