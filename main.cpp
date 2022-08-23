#include "RedeSocial.h"
#include "Disciplina.h"
#include "Evento.h"
#include <string>
#include <iostream>

class Publicacao;
class Perfil;

using namespace std;

int main()
{
    cout << "Tamanho da rede: ";
    int tamanho;
    cin >> tamanho;
    RedeSocial* r1 = new RedeSocial(tamanho);
    r1->imprimir();
    string opcao = "";
    cin >> opcao;
    for(int i = 0; opcao != "0"; i++){
        if(opcao == "1"){
            cout << "Informe os dados do perfil" << endl;
            cout << "Numero USP: ";
            int numeroUSP = 0;
            cin >> numeroUSP;
            cout << "Nome: ";
            string nome;
            cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
            getline(cin, nome);
            cout << "Email: ";
            string email;
            cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
            getline(cin, email);
            cout << "Professor (s/n): ";
            string professor;
            cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
            getline(cin, professor);
            if(professor == "s"){
                cout << endl << "Departamento: ";
                string departamento;
                cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
                getline(cin, departamento);
                Perfil* p1 = new Professor(numeroUSP, nome, email, departamento);
                r1->getPerfis()[i] = dynamic_cast<Professor*>(p1);
            }else{
                Perfil *p1 = new Perfil(numeroUSP, nome, email);
                r1->getPerfis()[i] = p1;
            }
        }
        if(opcao == "2"){
            cout << "Informe os dados da disciplina: " << endl;
            cout << "Nome: ";
            string nome;
            cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
            getline(cin, nome);
            cout << endl << "Responsavel: " << endl;
            for(int j = 0; j<i; j++){
                cout << i << ") " << r1->getPerfis()[i]->getNome() << endl;
            }
            cout << "Digite o numero ou 0 para cancelar: ";
            int escolha1 = 0;
            cin >> escolha1;
            if(escolha1 != 0){
                if(dynamic_cast<Disciplina*>(r1->getPerfis()[escolha1])->getPreRequisito()){
                    cout << endl << "Pre-requisito: " << endl;
                    for(int j = 0; j<i; j++){
                        cout << i << ") " << r1->getPerfis()[i]->getNome() << endl;
                    }
                    cout << "Digite o numero ou 0 para cancelar: ";
                    int escolha2 = 0;
                    cin >> escolha2;
                    if(escolha2 != 0){
                        if(dynamic_cast<Disciplina*>(r1->getPerfis()[escolha2])->getPreRequisito()){
                            Perfil* p1 = new Disciplina(nome, dynamic_cast<Professor*>(r1->getPerfis()[escolha1]), dynamic_cast<Disciplina*>(r1->getPerfis()[escolha2]));
                            r1->getPerfis()[i] = dynamic_cast<Disciplina*>(p1);
                            cout << endl << "Criado com sucesso!" << endl;
                        }else{
                            cout << endl << "Pre-requisito deve ser uma disciplina!" << endl;
                        }
                    }else{
                        Perfil* p1 = new Disciplina(nome, dynamic_cast<Professor*>(r1->getPerfis()[escolha1]));
                        r1->getPerfis()[i] = dynamic_cast<Disciplina*>(p1);
                        cout << endl << "Criado com sucesso!" << endl;
                    }
                }else{
                    cout << endl << "Somente professores podem ser responsaveis por disciplinas" << endl;
                }
            }
        }
        if(opcao == "3"){
            cout << endl << "Escolha um perfil: " << endl;
            for(int j = 0; j<i; j++){
                cout << i << ") " << r1->getPerfis()[i]->getNome() << endl;
            }
            cout << "Digite o numero ou 0 para cancelar: ";
            int escolha1 = 0;
            cin >> escolha1;
            if(escolha1 != 0){
                r1->getPerfis()[escolha1]->imprimir();
                if(dynamic_cast<Professor*>(r1->getPerfis()[escolha1])->getDepartamento() != ""){
                    cout << endl << "Departamento " << dynamic_cast<Professor*>(r1->getPerfis()[escolha1])->getDepartamento() << endl;
                }
                if(dynamic_cast<Disciplina*>(r1->getPerfis()[escolha1])->getPreRequisito()){
                    cout << endl << "Pre-requisito " << dynamic_cast<Disciplina*>(r1->getPerfis()[escolha1])->getPreRequisito() << endl;
                }
                cout << "Seguidores: " << r1->getPerfis()[escolha1]->getQuantidadeDeSeguidores() << endl;
                cout << "---" << endl;
                cout << "Escolha uma opcao: " << endl;
                cout << "1) Ver publicacoes feitas" << endl << "2) Ver publicacoes recebidas" << endl << "3) Fazer publicacao" << endl;
                if(!dynamic_cast<Disciplina*>(r1->getPerfis()[escolha1])->getPreRequisito()){
                    cout << "4) Seguir perfil" << endl;
                }
                cout << "0) Deslogar" << endl;
                int escolha2 = 0;
                cin >> escolha2;
                if(escolha2 == 1){
                    cout << endl << "Publicacoes feitas: " << endl;
                    Publicacao *pu[r1->getPerfis()[escolha1]->getQuantidadeDePublicacoesFeitas()];
                    for(int k = 0; k < r1->getPerfis()[escolha1]->getQuantidadeDePublicacoesFeitas(); k++){
                        pu[k] = r1->getPerfis()[escolha1]->getPublicacoesFeitas()[k];
                        cout << pu[k]->getTexto() << " (" << pu[k]->getAutor() << ") [" << pu[k]->getCurtidas() << "]" << endl;
                    }
                }
                if(escolha2 == 2){
                    cout << endl << "Publicacoes recebidas: " << endl;
                    Publicacao *pu[r1->getPerfis()[escolha1]->getQuantidadeDePublicacoesRecebidas()];
                    for(int k = 0; k < r1->getPerfis()[escolha1]->getQuantidadeDePublicacoesRecebidas(); k++){
                        pu[k] = r1->getPerfis()[escolha1]->getPublicacoesRecebidas()[k];
                        cout << k << ") " << pu[k]->getTexto() << " (" << pu[k]->getAutor() << ") [" << pu[k]->getCurtidas() << "]" << endl;
                    }
                    cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
                    int escolha3 = 0;
                    cin >> escolha3;
                    if(escolha3 != 0){
                        pu[escolha3]->curtir(r1->getPerfis()[escolha1]);
                    }
                }
                if(escolha2 == 3){
                    cout << endl << "Evento (s\n):";
                    string escolha3;
                    cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
                    getline(cin, escolha3);
                    if(escolha3 == "s"){
                        cout << endl << "Data: ";
                        string data;
                        cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
                        getline(cin, data);
                        cout << endl << "Texto: ";
                        string texto;
                        cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
                        getline(cin, texto);
                        r1->getPerfis()[escolha1]->publicar(texto, data);
                    }else if(escolha3 == "n"){
                        cout << endl << "Texto: ";
                        string texto;
                        cin.ignore(100, '\n'); // Ignorando até 100 caracteres que sobraram de cin anterior
                        getline(cin, texto);
                        r1->getPerfis()[escolha1]->publicar(texto);
                    }
                }
                if(escolha2 == 4 && !dynamic_cast<Disciplina*>(r1->getPerfis()[escolha1])->getPreRequisito()){
                    cout << endl << "Perfil: " << endl;
                    for(int j = 0; j<i; j++){
                        cout << i << ") " << r1->getPerfis()[i]->getNome() << endl;
                    }
                    cout << "Digite o numero ou 0 para cancelar: ";
                    int escolha3 = 0;
                    cin >> escolha3;
                    r1->getPerfis()[escolha3]->adicionarSeguidor(r1->getPerfis()[escolha1]);
                }
            }
        }
        r1->imprimir();
        cin >> opcao;
    }
    return 0;
}
