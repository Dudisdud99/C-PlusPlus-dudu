#include <iostream>
#include <string>
#include <vector>

class Livro{
    public:
        Livro(){
            status = true;
        };
        ~Livro(){};

        void setTitulo(std::string _titulo){
            titulo = _titulo;
        }

        void setAutor(std::string _autor){
            autor = _autor;
        }

        void setAno(int _ano){
            ano = _ano;
        }

        void setGenero(std::string _genero){
            genero = _genero;
        }   

        std::string getTitulo(){
            return titulo;
        }

        std::string getAutor(){
            return autor;
        }

        int getAno(){
            return ano;
        }

        std::string getGenero(){
            return genero;
        }

        bool getStatus(){
            return status;
        }

        void setStatus(bool _status){
            status = _status;
        }

        void setId(int _id){
            id = _id;
        }

        int getId(){
            return id;
        }
    
    private:
        std::string titulo, autor, genero;
        int ano, id;
        bool status;
};

std::vector<Livro*> livros;

void inicializarLivros(){
    for (int i = 0; i < 10; i++) {
        Livro* livro = new Livro();
        livro->setTitulo("Livro " + std::to_string(i+1));
        livro->setAutor("Autor " + std::to_string(i+1));
        livro->setAno(2000 + i+1);
        livro->setGenero("Genero " + std::to_string(i+1));
        livro->setId(i+1);
        livros.push_back(livro);
    }
}