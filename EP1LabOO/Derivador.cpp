#include "Derivador.h"
#include "Sinal.h"

Derivador::Derivador() {

}

Derivador::~Derivador() {
    delete[] sequenciaOUT;
    delete[] sequenciaAUX;
}

Sinal* Derivador::processar(Sinal* sinalIN) {

    this->comprimentoOUT = sinalIN->getComprimento();
    this->sequenciaAUX = sinalIN->getSequencia();
    this->sequenciaOUT = new double[this->comprimentoOUT];
    this->sequenciaOUT[0] = this->sequenciaAUX[0];

    for(int i = 1; i < this->comprimentoOUT; i ++) 
        this->sequenciaOUT[i] = this->sequenciaAUX[i] - this->sequenciaAUX[i-1];

    Sinal *sinalOUT = new Sinal(this->sequenciaOUT, this->comprimentoOUT);
    
    return sinalOUT;
}