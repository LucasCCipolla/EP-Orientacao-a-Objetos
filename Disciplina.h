#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "Professor.h"


class Disciplina : public Perfil
{
    public:
        Disciplina(string nome, Professor* responsavel);
        Disciplina(string nome, Professor* responsavel, Disciplina* preRequisito);
        virtual ~Disciplina();
        Professor* getResponsavel();
        Disciplina* getPreRequisito();

    protected:
        Professor* responsavel;
        Disciplina* preRequisito;
    private:
};

#endif // DISCIPLINA_H
