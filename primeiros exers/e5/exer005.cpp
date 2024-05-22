#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"
#include "adm.hpp"
#include "livro.hpp"
#define senhaAdm "admin"

// inicio de sessão

void cadastro(std::vector<Usuario*>& usuarios, std::vector<Adm*>& adms) {
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

    if(senha==senhaAdm){
        Adm* adm = new Adm(login, senha);
        adms.push_back(adm);
    }
    else{
        Usuario* usuario = new Usuario();
        usuario->setLoginSenha(login, senha);
        usuarios.push_back(usuario);
    }

    std::cout << "\nUsuário adicionado: \n";
}

void login(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros) {
    std::string login, senha;

    std::cout << "\nDigite o nome de usuário: ";
    std::cin >> login;

    std::cout << "Digite a senha: ";
    std::cin >> senha;

    bool found = false;

    if(senha=="admin" && login=="admin"){
        std::cout << "\nAdiminstrador logado\n";
        // opcoesUsuario();
        return;
    }
    else{
        for (Usuario* usuario : usuarios) {
            if (usuario->getLogin() == login && usuario->getSenha() == senha) {
                std::cout << "\nUsuário logado\n";
                usuario->opcoesUsuario(livros);
                found = true;
                break;
            }
        }
    }

    if(found == false) {
        std::cout << "\nUsuário ou senha inválidos\n";
    }
}

void inicio(std::vector<Usuario*>& usuarios, std::vector<Livro*>& livros, std::vector<Adm*>& adms) {
    int opcao;
    
    std::cout << "\nBem-vindo ao sistema de biblioteca\n";
    
    do {
        std::cout << "\n1 - Cadastro\n2 - Login\n0 - Sair\nSua opção: ";
        std::cin >> opcao;

        if (opcao == 1) {
            cadastro(usuarios, adms);
        } else if (opcao == 2) {
            login(usuarios, livros);
        } else if (opcao == 0) {
            return;
        } else {
            std::cout << "\nOpção inválida\n";
        }
    } while(opcao != 0);
}

// inicialização de adicionais

void iniciarMultas(std::vector<Usuario*>& usuarios) {
    for (Usuario* usuario : usuarios) {
        usuario->calcMulta();
    }
}

void inicializarLivros(std::vector<Livro*>& livros){
    for (int i = 0; i < 10; i++) {
        Livro* livro = new Livro();
        livro->setTitulo("Livro " + std::to_string(i+1));
        livro->setAutor("Autor " + std::to_string(i+1));
        livro->setAno(2000 + i+1);
        livro->setGenero("Genero " + std::to_string(i+1));
        livro->setId(i);
        livros.push_back(livro);
    }
}

int main() {
    std::vector<Usuario*> usuarios;
    std::vector<Livro*> livros;
    std::vector<Adm*> adms;

    inicializarLivros(livros);
    iniciarMultas(usuarios);
    inicio(usuarios, livros, adms);

    for (Usuario* usuario : usuarios) {
        delete usuario;
    }
    usuarios.clear();

    for (Livro* livro : livros) {
        delete livro;
    }
    livros.clear();

    return 0;
}