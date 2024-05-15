#include <iostream>

class Funcionario {
    public:
        Funcionario(){};
        ~Funcionario(){};

        float getSalario(){
            return salario;
        };

        void setVar(std::string _nome, std::string _cargo, float _salario){
            nome = _nome;
            cargo = _cargo;
            salario = _salario;
        };

        float calcSalarioL(float _desconto, float _beneficio, float _imposto){
            float desconto = _desconto;
            float beneficio = _beneficio;
            float imposto = _imposto;
            float salarioL = salario - desconto + beneficio - imposto;
            return salarioL;
        }

    private:
        float salario;
        std::string nome,cargo;
};

int main(){
    Funcionario funcionario;

    std::string nome,cargo;
    float salario,desconto,imposto,beneficio;
    
    std::cout << "Digite o nome do Funcionario: ";
    std::cin >> nome;
    std::cout << "\nDigite o cargo do Funcionario: ";
    std::cin >> cargo;
    std::cout << "\nDigite o salario do Funcionario: ";
    std::cin >> salario;
    std::cout << "\nDigite o desconto de salario (penalidade): ";
    std::cin >> nome;
    std::cout << "\nDigite o imposto: ";
    std::cin >> cargo;
    std::cout << "\nDigite o beneficio: ";
    std::cin >> salario;

    funcionario.setVar(nome,cargo,salario);

    std::cout << "\nSalario: " << funcionario.getSalario() << "\nSalario liquido: " << funcionario.calcSalarioL(desconto,beneficio,imposto) <<"\n\n";

    return 0;
}