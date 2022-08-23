#ifndef EVENTO_H
#define EVENTO_H

#include "Publicacao.h"

class Perfil;
class Publicacao;

using namespace std;

class Evento : public Publicacao {
    public:
        Evento(Perfil* autor, string data, string texto);
        virtual ~Evento();
        string getData();

    protected:
        string data;
};

#endif // EVENTO_H
