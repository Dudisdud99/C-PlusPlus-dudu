#include <iostream>
#include <string>
#include <vector>
#include "emprestimo.hpp"
#include "livro.hpp"

class Usuario {
    public:
        Usuario(){
            multa = 0;
        };
        ~Usuario(){
            for (Emprestimo* emprestimo : emprestimos) {
                delete emprestimo;
            }
            emprestimos.clear();
        };

        void setLoginSenha(std::string _login, std::string _senha){
            senha = _senha;
            login = _login;
        }

        std::string getLogin(){
            return login;
        }

        std::string getSenha(){
            return senha;
        }

        void setMulta(float _multa){
            multa = _multa;
        }

        void setStatus(bool _status){
            status = _status;
        }

        void exibirDados(){
            std::cout << "\nLogin: " << login << std::endl;
            std::cout << "Multa: " << multa << std::endl;

            if(emprestimos.size() > 0){
                std::cout << "\nLivros emprestados: " << std::endl;
                for(Emprestimo* emprestimo : emprestimos){
                    int id = emprestimo->getIdLivro();
                    std::cout << "\nLivro: " << livros[id-1]->getTitulo() << "\nID: " << id << std::endl;
                    std::cout << "Data de empréstimo: " << emprestimo->getDataEmprestimo();
                    std::cout << "Data de devolução: " << emprestimo->getDataDevolucao();
                    if(livros[id-1]->getStatus()){
                        std::cout << "!!Status: Devolvido!!\n\n";
                    }
                }
            }
        }

        void emprestarLivro(){
            if(multa > 300){
                std::cout << "\nUsuário bloqueado por excesso de multa\n";
                return;
            }
            int id = livrosDisponiveis();
            Emprestimo* emprestimo = new Emprestimo(id);
            emprestimos.push_back(emprestimo);
        }

        void calcMulta(){
            multa = 0;
            for(Emprestimo* emprestimo : emprestimos){
                multa += emprestimo->calcMulta();
            }
            setMulta(multa);
        }

        void devolverLivro(){
            int op;
            bool devolvido = false;
            for(Emprestimo* emprestimo : emprestimos){
                int id = emprestimo->getIdLivro();
                std::cout << "\nLivro: " << livros[id-1]->getTitulo() << "\nID: " << id << std::endl;
            }
            std::cout << "\nDigite o ID de um livro para devolver: ";
            std::cin >> op;
            for(Emprestimo* emprestimo : emprestimos){
                if(op == emprestimo->getIdLivro()){
                    livros[op-1]->setStatus(true);
                    devolvido = true;
                    break;
                }
            }
            if(devolvido==false){
                std::cout << "\nID inválido\n";
            }
            return;
        }

        void pagarMulta(){
            float valor;
            std::cout << "\nDigite o valor que deseja pagar: ";
            std::cin >> valor;
            multa -= valor;
            if(multa < 0){
                multa = 0;
            }
            std::cout << "\nMulta paga com sucesso\n";
        }

        int livrosDisponiveis(){
            int nLivro;
            std::cout << "\nEscolha um livro e digite seu ID\n";
            for (int i = 0; i < livros.size(); i++) {
                Livro* livro = livros[i];
                bool status = livros[i]->getStatus();
                if(status){
                    std::cout << "Livro: " << livro->getTitulo() << ", ID: " << livro->getId()  << ", Autor: " << livro->getAutor() << ", Ano: "<< livro->getAno() << std::endl;
                }
            }
            std::cout << "\nSua escolha: ";
            std::cin >> nLivro;
            if(nLivro > livros.size() || nLivro < 0){
                std::cout << "\nID inválido\n";
                return -1;
            }
            int id = livros[nLivro-1]->getId();
            livros[nLivro-1]->setStatus(false);
            return id;
        }

    private:
        std::string senha, login;
        float multa;
        bool status;
        std::vector<Emprestimo*> emprestimos;

};

std::vector<Usuario*> usuarios;