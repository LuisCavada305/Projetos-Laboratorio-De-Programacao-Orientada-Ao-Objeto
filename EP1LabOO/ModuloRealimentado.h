#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Sinal.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Piloto.h"

class ModuloRealimentado {
    private:

    Piloto *piloto;
    Amplificador *amp;
    Somador *sum;
    Sinal *saidaInvertida;
    double vInicial = 0;
    Sinal *diferenca;
    Sinal *saida;
    

    public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);


};


#endif