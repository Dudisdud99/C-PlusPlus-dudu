#include <iostream>

class Retangulo {
    public:
        Retangulo(){};
        ~Retangulo(){};

        float calcArea(){
            area = altura * largura;
            return area;
        };

        float calcPerimetro(){
            perimetro = 2 * (altura + largura);
            return perimetro;
        };

        void setVar(float _altura, float _largura){
            altura = _altura;
            largura = _largura;
        };

    private:
        float altura;
        float largura;
        float perimetro;
        float area;
};

int main(){
    Retangulo meuRetangulo;
    float altura, largura;
    std::cout << "Digite uma altura para o retangulo: ";
    std::cin >> altura;
    std::cout << "Digite uma largura para o retangulo: ";
    std::cin >> largura;
    meuRetangulo.setVar(altura, largura);
    float area = meuRetangulo.calcArea();
    float perimetro = meuRetangulo.calcPerimetro();
    std::cout << "\nA area do retangulo eh: " << area <<"\nO perimetro do retangulo eh: " << perimetro << "\n\n";
    return 0;
}