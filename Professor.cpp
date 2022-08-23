#include "Professor.h"

Professor::Professor (int numeroUSP, string nome, string email, string departamento) :
														Perfil (numeroUSP, nome, email) {
    this->departamento = departamento;
}

string Professor::getDepartamento()
{
    return this->departamento;
}

Professor::~Professor()
{
    //dtor
}
