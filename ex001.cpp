#include <iostream>
#define pi 3.1415

class Circulo {
    public:
        Circulo(){};
        ~Circulo(){};

        float calcArea(){
            area = pi * raio * raio;
            return area;
        };

        void setRaio(float _raio){
            raio = _raio;
        };

    private:
        float raio;
        float area;
};

int main(){
    Circulo meuCirculo;
    float raio;
    std::cout << "Digite um raio para o circulo: ";
    std::cin >> raio;
    meuCirculo.setRaio(raio);
    float area = meuCirculo.calcArea();
    std::cout << "A area do circulo eh: " << area;
    return 0;
}