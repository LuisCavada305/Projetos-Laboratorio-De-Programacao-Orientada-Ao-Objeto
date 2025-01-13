#include "Amplificador.h"

void Amplificador::setGanho(double ganho) {
    this->ganho = ganho;
}

Amplificador::Amplificador(double ganho) {
    this->setGanho(ganho);
}

Amplificador::~Amplificador() {
    delete[] sequenciaOUT;
}

Sinal* Amplificador::processar(Sinal* sinalIN) {

    this->sequenciaOUT = new double[sinalIN->getComprimento()];
    this->sequenciaOUT = sinalIN->getSequencia();
    for(int i =0; i < sinalIN->getComprimento(); i++) 
        this->sequenciaOUT[i] *= this->ganho;
    Sinal *sinalOUT = new Sinal(sequenciaOUT, sinalIN->getComprimento());
    
    return sinalOUT;
    
}

double Amplificador::getGanho() {
    return this->ganho;
}
