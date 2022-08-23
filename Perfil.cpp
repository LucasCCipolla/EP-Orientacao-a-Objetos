#include "Perfil.h"
#include "Evento.h"

Perfil::Perfil(int numeroUSP, string nome, string email)
{
    this->numeroUSP = numeroUSP;
    this->nome = nome;
    this->email = email;
    this->quantidadeDePublicacoesFeitas = 0;
    this->quantidadeDePublicacoesRecebidas = 0;
    this->quantidadeDeSeguidores = 0;
}

int Perfil::getNumeroUSP()
{
    return this-> numeroUSP;
}

string Perfil::getNome()
{
    return this->nome;
}

string Perfil::getEmail()
{
    return this->email;
}

bool Perfil::adicionarSeguidor(Perfil* seguidor)
{
    if(this->numeroUSP == seguidor->numeroUSP){
        return false;
    }

    for(int i=0; i<quantidadeDeSeguidores; i++){
        if(seguidor->numeroUSP == seguidores[i]->numeroUSP){
            return false;
        }
    }

    if(quantidadeDeSeguidores<MAXIMO_SEGUIDORES && this->numeroUSP != 0 && this->email != ""){
        seguidores[quantidadeDeSeguidores] = seguidor;
        quantidadeDeSeguidores++;
        publicacoesRecebidas[quantidadeDePublicacoesRecebidas] = new Publicacao(this, "Novo seguidor: " + seguidor->nome);
        quantidadeDePublicacoesRecebidas++;
        return true;
    }else if(quantidadeDeSeguidores<MAXIMO_SEGUIDORES && this->numeroUSP == 0 && this->email == ""){
        seguidores[quantidadeDeSeguidores] = seguidor;
        quantidadeDeSeguidores++;
        return true;
    }

    return false;
}

bool Perfil::publicar(string texto)
{
    Publicacao *p1 = new Publicacao(this, texto);
    if(quantidadeDePublicacoesFeitas<MAXIMO_PUBLICACOES){
        publicacoesFeitas[quantidadeDePublicacoesFeitas] = p1;
        quantidadeDePublicacoesFeitas++;
        for(int i=0; i<quantidadeDeSeguidores; i++){
            seguidores[i]->receber(p1);
        }
        return true;
    }
    return false;
}

bool Perfil::publicar(string texto, string data)
{
    Evento *e1 = new Evento(this, data, texto);
    if(quantidadeDePublicacoesFeitas<MAXIMO_PUBLICACOES){
        publicacoesFeitas[quantidadeDePublicacoesFeitas] = e1;
        quantidadeDePublicacoesFeitas++;
        for(int i=0; i<quantidadeDeSeguidores; i++){
            seguidores[i]->receber(e1);
        }
        return true;
    }
    return false;
}

bool Perfil::receber(Publicacao* p)
{
    if(quantidadeDePublicacoesRecebidas<MAXIMO_PUBLICACOES && this->numeroUSP != 0 && this->email != ""){
        publicacoesRecebidas[quantidadeDePublicacoesRecebidas] = p;
        quantidadeDePublicacoesRecebidas++;
        return true;
    }
    return false;
}

Publicacao** Perfil::getPublicacoesFeitas()
{
    return this->publicacoesFeitas;
}

int Perfil::getQuantidadeDePublicacoesFeitas()
{
    return this->quantidadeDePublicacoesFeitas;
}

Publicacao** Perfil::getPublicacoesRecebidas()
{
    return this->publicacoesRecebidas;
}

int Perfil::getQuantidadeDePublicacoesRecebidas()
{
    return this->quantidadeDePublicacoesRecebidas;
}

Perfil** Perfil::getSeguidores()
{
    return this->seguidores;
}

int Perfil::getQuantidadeDeSeguidores()
{
    return this->quantidadeDeSeguidores;
}

Perfil::~Perfil()
{
    //dtor
}

void Perfil::imprimir()
{
    cout << this->numeroUSP << " - " << this->nome << endl;
}
