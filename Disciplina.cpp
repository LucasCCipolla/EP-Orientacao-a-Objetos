#include "Disciplina.h"

Disciplina::~Disciplina()
{
    //dtor
}

Disciplina::Disciplina (string nome, Professor* responsavel) :
														Perfil (0, nome, "") {
    this->adicionarSeguidor(responsavel);
    this->preRequisito = NULL;
}

Disciplina::Disciplina (string nome, Professor* responsavel, Disciplina* preRequisito) :
														Perfil (0, nome, "") {
    this->adicionarSeguidor(responsavel);
    this->preRequisito = preRequisito;
}

Professor* Disciplina::getResponsavel()
{
    return this->responsavel;
}

Disciplina* Disciplina::getPreRequisito()
{
    if(preRequisito != NULL){
        return this->preRequisito;
    }
    return NULL;
}
