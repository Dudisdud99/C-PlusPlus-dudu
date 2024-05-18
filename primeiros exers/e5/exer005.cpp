#include <iostream>
#include <string>
#include <vector>
#include "usuario.hpp"

std::vector<Usuario*> usuarios;

// opções de usuário

void opcoesUsuario(Usuario* usuario) {
    int opcao;

    while (true){
        std::cout << "\n1 - Emprestar livro\n2 - Devolver livro\n3 - Pagar multa\n4 - Exibir dados\n0 - Sair\nSua opção: ";
        std::cin >> opcao;

        if (opcao == 1) {
            usuario->emprestarLivro();
        } else if (opcao == 2) {
            usuario->devolverLivro();
        } else if (opcao == 3) {
            usuario->pagarMulta();
        } else if(opcao == 4) {
            usuario->exibirDados();
        } else if (opcao == 0) {
            break;
        } else {
            std::cout << "\nOpção inválida\n";
        }
    }
}

// inicio de sessão

void cadastro() {
    std::string login;
    std::string senha;

    while (true) {
        std::cout << "\nDigite o nome de usuário: ";
        std::cin >> login;

        // Verificar se o nome de usuário já existe
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

void login() {
    std::string login, senha;

    std::cout << "\nDigite o nome de usuário: ";
    std::cin >> login;

    std::cout << "Digite a senha: ";
    std::cin >> senha;

    bool found = false;
    for (Usuario* usuario : usuarios) {
        if (usuario->getLogin() == login && usuario->getSenha() == senha) {
            std::cout << "\nUsuário logado\n";
            opcoesUsuario(usuario);
            found = true;
            break;
        }
    }

    if (found == false) {
        std::cout << "\nUsuário ou senha inválidos\n";
    }
}

void inicio() {
    int opcao;
    
    std::cout << "\nBem-vindo ao sistema de biblioteca\n";
    
    do {
        std::cout << "\n1 - Cadastro\n2 - Login\n0 - Sair\nSua opção: ";
        std::cin >> opcao;

        if (opcao == 1) {
            cadastro();
        } else if (opcao == 2) {
            login();
        } else if (opcao == 0) {
            return;
        } else {
            std::cout << "\nOpção inválida\n";
        }
    } while(opcao != 0);
}


int main() {
    inicio();

    for (Usuario* usuario : usuarios) {
        delete usuario;
    }
    usuarios.clear();

    return 0;
}