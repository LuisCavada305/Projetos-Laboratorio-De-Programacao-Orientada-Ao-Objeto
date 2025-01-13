#include "ModuloRealimentado.h"
#include "Sinal.h"
#include "Piloto.h"

    ModuloRealimentado::ModuloRealimentado(double ganho){
            this->piloto = new Piloto(ganho);
            this->sum = new Somador();
            this->amp = new Amplificador(-1);
    }

    ModuloRealimentado::~ModuloRealimentado() {
        delete this->piloto;
        delete this->sum;
        delete this->amp;
        
    }

    Sinal* ModuloRealimentado::processar(Sinal* sinalIN) {

        double *sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
        sequenciaSaidaInvertida[0] = this->vInicial;
        this->diferenca = new Sinal(sinalIN->getSequencia(), 1);
        this->saida = this->piloto->processar(this->diferenca);
        delete diferenca;

        for(int i = 1; i < sinalIN->getComprimento(); i++) {

            this->saida = amp->processar(saida);
            double *aux = this->saida->getSequencia();
            sequenciaSaidaInvertida[i] = aux[i-1];

            this->saidaInvertida = new Sinal(sequenciaSaidaInvertida, i+1);
            this->diferenca = this->sum->processar(sinalIN, saidaInvertida);

            delete saida;
            this->saida = this->piloto->processar(diferenca);

            delete this->saidaInvertida;
            delete this->diferenca;
        }

        delete[] sequenciaSaidaInvertida;
        return saida;
    }