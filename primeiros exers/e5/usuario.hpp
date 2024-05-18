#include <iostream>
#include <string>
#include <vector>
#include "emprestimo.hpp"

class Usuario {
    public:
        Usuario(){
            multa = 0;
        };
        ~Usuario(){};

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
                    std::cout << "\nData de empréstimo: " << emprestimo->getDataEmprestimo() << std::endl;
                    std::cout << "Data de devolução: " << emprestimo->getDataDevolucao() << std::endl;
                }
            }
        }

         void emprestarLivro(){
            Emprestimo* emprestimo = new Emprestimo(login);
            emprestimos.push_back(emprestimo);
        }

        void calcMulta(){}

        void devolverLivro(){}

        void pagarMulta(){}

    private:
        std::string senha, login;
        float multa;
        bool status;
};

std::vector<Usuario*> usuarios;