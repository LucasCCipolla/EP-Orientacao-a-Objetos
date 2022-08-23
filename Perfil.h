#ifndef PERFIL_H
#define PERFIL_H
#define MAXIMO_SEGUIDORES 20
#define MAXIMO_PUBLICACOES 20
#include <iostream>
#include <string>

class Publicacao;

using namespace std;

class Perfil{
public:
    Perfil(int numeroUSP, string nome, string email);
    virtual ~Perfil();

    int getNumeroUSP();
    string getNome();
    string getEmail();

    virtual bool adicionarSeguidor(Perfil* seguidor);

    virtual bool publicar(string texto);
    virtual bool publicar(string texto, string data);

    virtual bool receber(Publicacao* p);

    virtual Publicacao** getPublicacoesFeitas();
    virtual int getQuantidadeDePublicacoesFeitas();

    virtual Publicacao** getPublicacoesRecebidas();
    virtual int getQuantidadeDePublicacoesRecebidas();

    virtual Perfil** getSeguidores();
    virtual int getQuantidadeDeSeguidores();

    virtual void imprimir();

protected:
    int numeroUSP;
    string nome;
    string email;
    Perfil* seguidores[MAXIMO_SEGUIDORES];
    int quantidadeDeSeguidores;
    Publicacao* publicacoesRecebidas[MAXIMO_PUBLICACOES];
    int quantidadeDePublicacoesRecebidas;
    Publicacao* publicacoesFeitas[MAXIMO_PUBLICACOES];
    int quantidadeDePublicacoesFeitas;

};

#endif // PERFIL_H
