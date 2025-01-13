#include <iostream>
#include <string>
#include "Sinal.h"
#include "Grafico.h"

using namespace std;

Sinal::Sinal(double *sequencia, int comprimento) {
    this->comprimento=comprimento;
    this->sequencia = new double[comprimento];
    for(int i = 0; i < comprimento; i++){
     this->sequencia[i] = sequencia[i];
    }
    
}

Sinal::~Sinal() {
    delete[] sequencia;
}

double* Sinal::getSequencia() {
    return this->sequencia;
}

int Sinal::getComprimento() {
    return this->comprimento;
}

void Sinal::imprimir(string nomeDoSinal) {

    Grafico *graficoI = new Grafico(nomeDoSinal, this->sequencia, this->comprimento);
    graficoI->plot();

    this->~Sinal();
}