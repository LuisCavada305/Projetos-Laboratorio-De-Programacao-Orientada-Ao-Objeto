#include "Integrador.h"
#include "Sinal.h"
Integrador::Integrador() {

}

Integrador::~Integrador() {
    delete[] sequenciaOUT;
    delete[] sequenciaAUX;
}

Sinal* Integrador::processar(Sinal* sinalIN) {
    this->comprimentoOUT = sinalIN->getComprimento();
    this->sequenciaAUX = sinalIN->getSequencia();
    this->sequenciaOUT = new double[comprimentoOUT];
    this->sequenciaOUT[0] = this->sequenciaAUX[0];

    for(int i = 1; i < this->comprimentoOUT; i++) {
        this->sequenciaOUT[i] = this->sequenciaOUT[i-1] + this->sequenciaAUX[i];
    }

    Sinal *sinalOUT = new Sinal(this->sequenciaOUT, this->comprimentoOUT);
    
    return sinalOUT;

}