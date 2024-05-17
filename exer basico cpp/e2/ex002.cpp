#include <iostream>

class ContaBancaria {
    public:
        ContaBancaria(){
            saldo = 0;
        };
        ~ContaBancaria(){};

        void setNomeTitular(std::string _nomeTitular){
            nomeTitular = _nomeTitular;
        };

        void setSaldo(float _saldo){
            saldo = _saldo;
        };

        void setNConta(int _nConta){
            nConta = _nConta;
        };

        float calcSaque(float _aux){
            saldo -= _aux;
            return saldo;
        };

        float calcDeposito(float _aux){
            saldo += _aux;
            return saldo;
        };

        float getSaldo(){
            return saldo;
        };

    private:
        int nConta;
        float saldo;
        std::string nomeTitular;
};

int main(){
    ContaBancaria conta;
    int op = 0;
    float aux;
    float saldo;
    int nConta;

    std::string nomeTitular;
    
    std::cout << "Digite o nome do titular da conta: ";
    std::cin >> nomeTitular;
    conta.setNomeTitular(nomeTitular);

    std::cout << "Digite o numero da conta: ";
    std::cin >> nConta;
    conta.setNConta(nConta);

    while (op != 5){
        std::cout <<"\nQual acao vc deseja fazer?\n1 - Verificar saldo\n2 - Depositar\n3 - Sacar\n4 - Mostrar conta\n5 - Sair\n\nSua opcao:";
        std::cin >> op;
        switch (op){
            case 1:
                std::cout << "\nSeu saldo eh: " << conta.getSaldo() << "\n";
                break;
            case 2:
                std::cout << "\nQuanto deseja depositar: ";
                std::cin >> aux;
                saldo = conta.calcDeposito(aux);
                break;
            case 3:
                std::cout << "\nQuanto deseja sacar: ";
                std::cin >> aux;
                saldo = conta.calcSaque(aux);
                break;
            case 4:
                std::cout << "\nNome do titular: " << nomeTitular << "\nNumero da conta: " << nConta << "\nSaldo: " << conta.getSaldo() << "\n";
                break;
            case 5:
                std::cout << "\nObrigado por usar nosso sitema\nSaindo...\n\n";
                break;
            default:
                std::cout << "\nOpcao invalida";
                break;
        }
    }
    return 0;
}