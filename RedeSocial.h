#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include "Perfil.h"

class RedeSocial
{
public:
    RedeSocial(int numeroMaximoDePerfis);
    virtual ~RedeSocial();
    int getQuantidadeDePerfis();
    Perfil** getPerfis();
    bool adicionar(Perfil* p);
    virtual void imprimir();

protected:
    int quantidadeDePerfis;
    int numeroMaximoDePerfis;
    Perfil* perfis[];
};

#endif // REDESOCIAL_H
