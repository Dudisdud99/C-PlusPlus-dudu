#ifndef ADM_HPP
#define ADM_HPP
#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"

class Adm : private Usuario{
    public:
        Adm(std::string _login, std::string _senha){
            setLoginSenha(_login, _senha);
        };
        ~Adm(){};

        void exibirUsuarios(std::vector<Usuario*> usuarios){
            for(Usuario* usuario : usuarios){
                std::cout << "\nLogin: " << usuario->getLogin() << std::endl;
                std::cout << "Multa: " << usuario->getMulta() << std::endl;
            }
        }

        void exibirLivros(std::vector<Livro*> livros){
            for(Livro* livro : livros){
                std::cout << "\nTítulo: " << livro->getTitulo() << std::endl;
                std::cout << "Autor: " << livro->getAutor() << std::endl;
                std::cout << "Ano: " << livro->getAno() << std::endl;
                std::cout << "Gênero: " << livro->getGenero() << std::endl;
                std::cout << "ID: " << livro->getId() << std::endl;
                if(livro->getStatus()){
                    std::cout << "Status: Disponível\n";
                } else {
                    std::cout << "Status: Indisponível\n";
                }
            }
        }

        void deletarUsuarioLivro(std::vector<Usuario*> usuarios, std::vector<Livro*> livros){
            int id;
            std::cout << "\nDigite o ID do usuário que deseja deletar: ";
            std::cin >> id;
            delete usuarios[id];
            usuarios.erase(usuarios.begin() + id);
        }

        void adicionarUsuarioLivro(std::vector<Usuario*> usuarios, std::vector<Livro*> livros){
            std::string login, senha;

            while (true) {
                std::cout << "\nDigite o nome de usuário: ";
                std::cin >> login;

                bool existe = false;
                for (Usuario* usuario : usuarios) {
                    if (usuario->getLogin() == login) {
                        existe = true;
                        break;
                    }
                }

                if (existe) {
                    std::cout << "\nNome de usuário já existe\n";
                } else {
                    break;
                }
            }

            std::cout << "Digite a senha: ";
            std::cin >> senha;

            Usuario* usuario = new Usuario();
            usuario->setLoginSenha(login, senha);
            usuarios.push_back(usuario);

            std::cout << "\nUsuário adicionado: \n";
        }

        int opcoesUsuario(std::vector<Livro*> livros) {
            int opcao;

            while (true){
                std::cout << "\n1 - Emprestar livro\n2 - Devolver livro\n3 - Pagar multa\n4 - Exibir dados\n0 - Sair\nSua opção: ";
                std::cin >> opcao;

                if (opcao == 1) {
                    emprestarLivro(livros);
                } else if (opcao == 2) {
                    devolverLivro(livros);
                } else if (opcao == 3) {
                    pagarMulta();
                } else if(opcao == 4) {
                    exibirDados(livros);
                } else if(){
                    exibirUsuarios();
                } else if(){
                    exibirLivros();                   
                } else if(){
                    deletarUsuarioLivro();
                } else if(){
                    adicionarUsuarioLivro();
                } else if (opcao == 0) {
                    break;
                } else {
                    std::cout << "\nOpção inválida\n";
                }
            }
            return 0;
        }
};
#endif