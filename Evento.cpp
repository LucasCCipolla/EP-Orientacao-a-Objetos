#include "Evento.h"

Evento::~Evento()
{
    //dtor
}

Evento::Evento (Perfil* autor, string data, string texto) :
														Publicacao (autor, texto), data (data) {
}

string Evento::getData()
{
    return this->data;
}
