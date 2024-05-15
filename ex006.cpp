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

        float addAumento(float _valor){
            salario += _valor;
        }

        float ganhoAnual(){
            salario *= 12;
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

        float ganhoAnual(){

        }

        void exibirDados(){
            std::cout << "Aparece aqui";
        }

        void setBonus(float _bonus){
            bonus = _bonus;
        }

    private:
        float bonus;
};

class Administrativo : protected Assistente {
    public:
        Administrativo(){};
        ~Administrativo(){};

        float ganhoAnual(){

        }

    private:
        std::string turno;
        float adicionalNoturno;
};

void menuTecnico(){
    Tecnico tec;
    Funcionario fun;
    int op;
    std::cout <<"\nQual acao vc deseja fazer?\n1 - Add aumento\n2 - Exibir informacoes\n3 - Mudar bonus\n5 - Sair\nSua opcao: ";
    std::cin >> op;
    if(op==1){
        float valor;
        std::cout << "Digite o valor do aumento: ";
        std::cin >> valor;
        fun.addAumento(valor);
    }
    else if(op==2){
        tec.exibirDados();
    }
    else if(op==3){
        float bonus;
        std::cout << "Digite o valor do bonus: ";
        std::cin >> bonus;
        tec.setBonus(bonus);
    }
    else{
        std::cout << "Opcao invalida\n";
        menuTecnico();
    }
}

void menuAdministrativo(){
    Administrativo adm; 
    Funcionario fun;
    int op,turno;
    std::cout <<"\nQual acao vc deseja fazer?\n1 - Add aumento\n2 - Exibir informacoes\n3 - Mudar bonus\n5 - Sair\nSua opcao: ";
    std::cin >> op;
    if(op==-1){
        menuAdministrativo();
    }
}

int main(){
    Funcionario fun;
    Assistente ass;

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

    while(cargo!=3){
        std::cout << "\nDigite o cargo do funcionario:\n1 - Assistente tecnico\n2 - Assistente administrativo\n3 - sair\nSua opcao: ";
        std::cin >> cargo;
        if(cargo==1){
            menuTecnico();
        }
        else if(cargo==2){
            menuAdministrativo();
        }
        else{
            std::cout << "Opcao invalida\n";
            break;
        }
    }
    
    return 0;
}