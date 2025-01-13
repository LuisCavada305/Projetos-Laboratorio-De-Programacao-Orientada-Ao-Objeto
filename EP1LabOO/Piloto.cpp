#include "Piloto.h"
#include "Amplificador.h"
#include "Integrador.h"
#include "Sinal.h"

Piloto::Piloto(double ganho) {
    this->amp = new Amplificador(ganho);
}

Piloto::~Piloto() {
    delete this->amp;
    delete this->integrador;
}

Sinal* Piloto::processar(Sinal* sinalIN) {
    Sinal *sinalOUT;

    sinalOUT = this->amp->processar(sinalIN);

    sinalOUT = this->integrador->processar(sinalOUT);

    return sinalOUT;
}


