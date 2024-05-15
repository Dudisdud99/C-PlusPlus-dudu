#include <iostream>

class Aluno {
    public:
        Aluno(){
            nota1 = 0;
            nota2 = 0;
            nota3 = 0;
            media = 0;
        };
        ~Aluno(){};

        void setNome(std::string _nome, int _matricula){
            nome = _nome;
            matricula = _matricula;
        }

        float getNotas(int _op2){
            int op2 = _op2;
            switch (op2){
                case 1:
                    return nota1;
                    break;
                case 2:
                    return nota2;
                    break;
                case 3:
                    return nota3;
                    break;
                default:
                    std::cout << "Opcao invalida";
                    return -1;
                    break;
            }
        }

        std::string getNome(){
            return nome;
        }

        float getMatricula(){
            return matricula;
        }

        float calcMedia(){
            media = (nota1 + nota2 + nota3)/3;
        }

        void setNotas(int _op2, float _nota){
        int op2 = _op2;
        switch (op2){
            case 1:
                nota1 = _nota;
                break;
            case 2:
                nota2 = _nota;
                break;
            case 3:
                nota3 = _nota;
                break;
            default:
                break;
        }

    };

    private:
        float nota1,nota2,nota3,media;
        std::string nome;
        int matricula;
};

int main(){
    Aluno aluno;
    int op = 0, op2 = 0, matricula;
    std::string nome;
    float media;

    std::cout << "Digite o nome do aluno: ";
    std::cin >> nome;

    std::cout << "Digite o numero da matricula: ";
    std::cin >> matricula;

    aluno.setNome(nome, matricula);

    while (op != 3){
        std::cout <<"\nQual acao vc deseja fazer?\n1 - Verificar boletim\n2 - Alterar notas\n3 - Sair\n\nSua opcao:";
        std::cin >> op;
        if (op ==1){
            std::cout << "\nNome: " << aluno.getNome() << "\nMatricula: " << aluno.getMatricula() <<"\nNota 1: " << aluno.getNotas(1) << "\nNota 2: " << aluno.getNotas(2) << "\nNota 3: " << aluno.getNotas(3) << "\n";
            media = aluno.calcMedia();
            std::cout << "Media: " << media << "\n";
            if(media <=7){
                std::cout << "Reprovado\n";
            }
            else{
                std::cout << "Aprovado\n";
            
            }
        }
        else if (op ==2){
            std::cout << "\nQual nota vc deseja alterar?\n1 - Nota 1\n2 - Nota 2\n3 - Nota 3\n\nSua opcao:";
            std::cin >> op2;
            if(op2 < 1 || op2 > 3){
                std::cout << "\nOpcao invalida\n\n";
                break;
            }
            float nota;
            std::cout << "\nDigite a nova nota: ";
            std::cin >> nota;
            aluno.setNotas(op2, nota);
        }
        else if (op == 3){
            std::cout << "\nObrigado por usar nosso sitema\nSaindo...\n\n";
        }
        else{
            std::cout << "\nOpcao invalida";
        }
    }
    return 0;
}