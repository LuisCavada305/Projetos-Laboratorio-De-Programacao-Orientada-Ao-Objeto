#include <iostream>
#include <string>
#include "Sinal.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "Piloto.h"
#include "ModuloRealimentado.h"
#include <cmath>

using namespace std;
Sinal* novoSinal() {
    int escolha;
    cout << "Qual sinal voce gostaria de utilizar como entrada de sua simulacao?" << endl;
    cout << "1) 5+3*cos(n*pi/8)" << endl;
    cout << "2) constante" << endl;
    cout << "3) rampa" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    cout << endl;

    if(escolha == 1) {
        double *seq = new double[60];
        for(int n = 0; n < 60; n++) {
            seq[n] = 5+3*cos((n*M_PI)/8);
        }
        Sinal *sinalOUT = new Sinal(seq, 60);
        delete[] seq;
        return sinalOUT;
    }

    if(escolha == 2) {
        double cte;

        cout << "Qual o valor dessa constante?" << endl;
        cout << "C = ";
        cin >> cte;
        cout << endl;

        double *seq = new double[60];
        for(int i = 0; i < 60; i++) {
            seq[i] = cte;
        }

        Sinal *sinalOUT = new Sinal(seq, 60);
        delete[] seq;
        return sinalOUT;
    }

    if(escolha == 3) {
        double a;
        cout << "Qual a inclinacao dessa rampa?" << endl;
        cout << "a = ";
        cin >> a;
        cout << endl;
        double *seq = new double[60];
        for(int i = 0; i < 60; i++) {
            seq[i] = a*i;
        }

        Sinal *sinalOUT = new Sinal(seq, 60);
        delete[] seq;
        return sinalOUT;

    }

}

void novaOperacao(Sinal *sinalIN) {
    Sinal *sinalAUX;
    double g;
    int escolha2;

    cout << "Qual operacao voce gostaria de fazer?" << endl;

    cout << "1) Amplificar" << endl << "2) Somar" << endl << "3) Derivar" << endl << "4) Integrar" << endl;
    
    cout << "Escolha: ";
    cin >> escolha2;
    cout << endl;

    if(escolha2 == 1) {
            
        cout << "Qual o ganho dessa amplificacao?" << endl;
        cout << "g = ";
        cin >> g;
        cout << endl;
        Amplificador *amp = new Amplificador(g);
        sinalIN = amp->processar(sinalIN);
    }

    if(escolha2 == 2) {
            
        cout << "Informe mais um sinal para ser somado." << endl;
        sinalAUX = novoSinal(); 
        Somador *soma = new Somador();
        sinalIN = soma->processar(sinalIN, sinalAUX);
    }

    if(escolha2 == 3) {
        Derivador *der = new Derivador();
        sinalIN = der->processar(sinalIN);
    }

    if(escolha2 == 4) {
        Integrador *integrador = new Integrador();
        sinalIN = integrador->processar(sinalIN);
    }

    cout << "O que voce quer fazer agora?" << endl;
    cout << "1) Realizar mais uma operacao no resultado" << endl;
    cout << "2) Imprimir o resultado para terminar" << endl;
    cout << "Escolha: "; 
    cin >> escolha2;
    cout << endl;

    if(escolha2 == 1) {
        novaOperacao(sinalIN);
    }

    if(escolha2 == 2) {
        sinalIN->imprimir("Resultado Final");
    }
    }




void menu() {
    Sinal *sinalIN;
    int escolha;
    cout << "   Simulink em C++" << endl;
    cout << "Qual simulacao voce gostaria de fazer?" << endl;
    cout << "1) Piloto Automatico" << endl;
    cout << "2) Sua propria sequencia de operacoes" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    cout << endl;

    sinalIN = novoSinal();

    if(escolha == 1) {
        double ac;
        cout << "Qual o ganho do acelerador?" << endl;
        cout << "a = ";
        cin >> ac;
        cout << endl;

        ModuloRealimentado *mod = new ModuloRealimentado(ac);

        mod->processar(sinalIN)->imprimir("Velocidade do Carro");

    }

    if(escolha == 2) {
        novaOperacao(sinalIN);
        
    }

}

