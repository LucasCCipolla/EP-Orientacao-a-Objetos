#include "Publicacao.h"

Publicacao::~Publicacao()
{
    //dtor
}

Publicacao::Publicacao(Perfil* autor, string texto)
{
    this->autor = autor;
    this->texto = texto;
    this->curtidas = 0;
}

Perfil* Publicacao::getAutor()
{
    return this->autor;
}

string Publicacao::getTexto()
{
    return this->texto;
}

void Publicacao::curtir(Perfil* quemCurtiu)
{
    if(quemCurtiu != this->getAutor()){
        curtidas++;
    }
}

int Publicacao::getCurtidas()
{
    return this->curtidas;
}

void Publicacao::imprimir()
{

}
