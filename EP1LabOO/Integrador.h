#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include "Sinal.h"
    
class Integrador {
    private:
    double *sequenciaOUT;
    double *sequenciaAUX;
    int comprimentoOUT;


    public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN);
};


#endif
