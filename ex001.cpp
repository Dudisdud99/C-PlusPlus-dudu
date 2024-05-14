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

        float calcPerimetro(){
            perimetro = 2 * pi * raio;
            return perimetro;
        };

        void setRaio(float _raio){
            raio = _raio;
        };

    private:
        float raio,area,perimetro;
};

int main(){
    Circulo meuCirculo;
    float raio;
    std::cout << "Digite um raio para o circulo: ";
    std::cin >> raio;
    meuCirculo.setRaio(raio);
    float area = meuCirculo.calcArea();
    float perimetro = meuCirculo.calcPerimetro();
    std::cout << "\nA area do circulo eh: " << area << "\nA circunferencia do circulo eh: " << perimetro << "\n\n";
    return 0;
}