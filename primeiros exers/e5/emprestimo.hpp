#include <iostream>
#include <chrono>
#include <string>
#include <vector>

class Emprestimo {
    public:
        // Emprestimo(std::string _usuario) : usuario(_usuario){
        //     dataEmprestimo = std::chrono::system_clock::now();
        //     dataDevolucao = dataEmprestimo + std::chrono::hours(24*7);
        // };
        Emprestimo(){
            dataEmprestimo = std::chrono::system_clock::now();
            dataDevolucao = dataEmprestimo + std::chrono::hours(24*7);
        };
    	~Emprestimo(){};

        std::string getDataEmprestimo(){
            std::time_t time = std::chrono::system_clock::to_time_t(dataEmprestimo);
            return std::ctime(&time);
        }

        std::string getDataDevolucao(){
            std::time_t time = std::chrono::system_clock::to_time_t(dataDevolucao);
            return std::ctime(&time);
        }


    private:
        std::chrono::time_point<std::chrono::system_clock> dataEmprestimo, dataDevolucao;
        bool status;
        
};