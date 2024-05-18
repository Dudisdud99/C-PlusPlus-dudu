#include <iostream>
#include <chrono>

class Emprestimo {
    public:
        Emprestimo(){
            dataEmprestimo = std::chrono::system_clock::now();
            dataDevolucao = dataEmprestimo + std::chrono::hours(24*7);
        };
        ~Emprestimo(){};

    private:
        std::chrono::system_clock::time_point dataEmprestimo, dataDevolucao;
        bool status;
};