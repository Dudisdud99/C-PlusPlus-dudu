// Implemente a classe Funcionario com nome, salario e os métodos
// addAumento(double valor), ganhoAnual() e exibeDados() - imprime os valores do
// funcionário.
// a. crie a classe Assistente, que também é um funcionário, e que possui um
// número de matrícula (faça os métodos GET e SET). Sobrescreva o método
// exibeDados().
// b. sabendo que os Assistentes Técnicos possuem um bônus salarial e que os
// Assistentes Administrativos possuem um turno (dia ou noite) e um adicional
// noturno, crie as classes Tecnico e Administrativo e sobrescreva o método
// ganhoAnual() de ambas as classes (Administrativo e Tecnico)

#include <iostream>

class Funcionario {
    public:
        Funcionario(){
            salario = 0;
        };
        ~Funcionario(){};

        void setNome(std::string _nome){
            nome = _nome;
        }
        void setSalario(float _salario){
            salario = _salario;
        }

        void addAumento(float _valor){
            salario += _valor;
        }

        void ganhoAnual(){
            salario *= 12;
        }

        void exibirDados(){
            std::cout << "Nome: " << nome << "\nSalario: " << salario << "\n";
        }
    
    protected:
        std::string nome;
        float salario;
};

class Assistente : protected Funcionario {
    public:
        Assistente(){};
        ~Assistente(){};

        void setMatricula(int _matricula){
            matricula = _matricula;
        }

        int getMatricula(){
            return matricula;
        }

    protected:
        int matricula;
};

class Tecnico : protected Assistente {
    public:
        Tecnico(){};
        ~Tecnico(){};

        void ganhoAnual(){
            salario *= 12;
        }

        void setBonus(float _bonus){
            bonus = _bonus;
        }

        void addAumento(float _valor){
            salario += _valor;
        }

        void exibirDados(){
            std::cout << "Nome: " << nome << "\nSalario: " << salario+bonus << "\nBonus: " << bonus << "\nSalario anual: " << salario*12 << "\n";
        }

    private:
        float bonus;
};

class Administrativo : protected Assistente {
    public:
        Administrativo(){};
        ~Administrativo(){};

        void setBonusNoturno(float _bonus){
            adicionalNoturno = _bonus;
        }

        void exibirDados(){
            std::cout << "Nome: " << nome << "\nSalario: " << salario+adicionalNoturno << "\nTurno: " << turno << "\nAdicional noturno: " << adicionalNoturno << "\nSalario anual: " << salario*12 << "\n";
        }   

        void addAumento(float _valor){
            salario += _valor;
        }

    private:
        std::string turno;
        float adicionalNoturno;
};

void menuTecnico(Tecnico tec){
    int op;
    std::cout <<"\nQual acao vc deseja fazer?\n1 - Add aumento\n2 - Exibir informacoes\n3 - Mudar bonus\noutro - Sair\nSua opcao: ";
    std::cin >> op;
    if(op==1){
        float valor;
        std::cout << "Digite o valor do aumento: ";
        std::cin >> valor;
        tec.addAumento(valor);
        menuTecnico(tec);
    }
    else if(op==2){
        tec.exibirDados();
        menuTecnico(tec);
    }
    else if(op==3){
        float bonus;
        std::cout << "Digite o valor do bonus: ";
        std::cin >> bonus;
        tec.setBonus(bonus);
        menuTecnico(tec);
    }
}

void menuAdministrativo(Administrativo adm){
    int op, turno;
    std::cout <<"\nQual o seu turno?\n1 - noite\n2 - dia\nSua opcao: ";
    std::cin >> op;
    if (op==1){
        turno = 1;
    }
    else if(op==2){
        turno = 2;
    }
    else{
        std::cout << "Opcao invalida\n";
        menuAdministrativo(adm);
    }
    while(op!=5){
        if(turno==1){
            std::cout <<"\nQual acao vc deseja fazer?\n1 - Add aumento\n2 - Exibir informacoes\n3 - Add bonus noturno\n5 - Sair\nSua opcao: ";
        }
        else if(turno==2){
            std::cout <<"\nQual acao vc deseja fazer?\n1 - Add aumento\n2 - Exibir informacoes\n5 - Sair\nSua opcao: ";
        }
        std::cin >> op;

        if(op==1){
            float valor;
            std::cout << "Digite o valor do aumento: ";
            std::cin >> valor;
            adm.addAumento(valor);
        }
        else if(op==2){
            adm.exibirDados();
        }
        else if(op==3){
            float bonus;
            std::cout << "Digite o valor do bonus: ";
            std::cin >> bonus;
            adm.setBonusNoturno(bonus);
        }
        else if(op==5){
            op=5;
        }
        else{
            std::cout << "Opcao invalida\n";
        }
    }
}

int main(){
    Funcionario fun;
    Assistente ass;    
    Administrativo adm; 
    Tecnico tec;

    std::string nome;
    float salario;
    int cargo,matricula;
    
    std::cout << "Digite o nome do Funcionario: ";
    std::cin >> nome;
    std::cout << "\nDigite o salario do funcionario: ";
    std::cin >> salario;
    std::cout << "\nDigite a matricula: ";
    std::cin >> matricula;

    fun.setNome(nome);
    fun.setSalario(salario);
    ass.setMatricula(matricula);

    while(cargo!=5){
        std::cout << "\nDigite o cargo do funcionario:\n1 - Assistente tecnico\n2 - Assistente administrativo\n5 - sair\nSua opcao: ";
        std::cin >> cargo; 
        if(cargo==1){
            menuTecnico(tec);
        }
        else if(cargo==2){
            menuAdministrativo(adm);
        }
        else{
            std::cout << "Opcao invalida\n";
        }
    }
    
    return 0;
}