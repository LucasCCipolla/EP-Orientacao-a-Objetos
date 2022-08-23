#ifndef PUBLICACAO_H
#define PUBLICACAO_H
#include <string>

#include "Perfil.h"

using namespace std;

class Perfil;

class Publicacao {
public:
    Publicacao(Perfil* autor, string texto);
    virtual ~Publicacao();
    Perfil* getAutor();
    string getTexto();
    virtual void curtir(Perfil* quemCurtiu);
    virtual int getCurtidas();
    virtual void imprimir();

protected:
    Perfil* autor;
    string texto;
    int curtidas;
};

#endif // PUBLICACAO_H
