#include "RedeSocial.h"

RedeSocial::~RedeSocial()
{
    //dtor
}

RedeSocial::RedeSocial(int numeroMaximoDePerfis)
{
    Perfil *perfis[numeroMaximoDePerfis];
    for(int i = 0; i<numeroMaximoDePerfis; i++){
        this->perfis[i] = perfis[i];
    }
    this->quantidadeDePerfis = 0;
    this->numeroMaximoDePerfis = numeroMaximoDePerfis;
}

int RedeSocial::getQuantidadeDePerfis()
{
    return this->quantidadeDePerfis;
}

Perfil** RedeSocial::getPerfis()
{
    return this->perfis;
}

bool RedeSocial::adicionar(Perfil* p)
{
    if(quantidadeDePerfis<numeroMaximoDePerfis){
        perfis[quantidadeDePerfis] = p;
        quantidadeDePerfis++;
        return true;
    }
    return false;
}

void RedeSocial::imprimir()
{
    cout << "Escolha uma opcao: " << endl;
    cout << "1) Cadastrar Perfil" << endl;
    cout << "2) Cadastrar Disciplina" << endl;
    cout << "3) Logar" << endl;
    cout << "0) Terminar" << endl;
}
