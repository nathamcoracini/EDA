#include <iostream>

using namespace std;

class Penis {
private:
    int largura, comprimento;
protected:
    int raio;
public:
    Penis() {
      cout << "Construtor do penis chamado" << endl;
    };
    Penis(int l, int c, int r) : largura(l), comprimento(c), raio(r) {
       cout << "Construtor do penis com parâmetros chamado" << endl;
    };
    virtual void gozar() = 0;
    friend ostream &operator<< (ostream &output, const Penis &p) {
       output << "largura:" << p.largura << " comprimento:" << p.comprimento << " raio:" << p.raio;
       return output;
    };

    friend istream &operator>> (istream  &input, Penis &p) {
       input >> p.largura >> p.comprimento >> p.raio;
       return input;
    };
};

class Glande : public Penis {

public:
    Glande() {
      std::cout << "Construtor da glande chamado" << std::endl;
    };
    Glande(int r) {
      raio = r;
      std::cout << "Construtor da glande com parâmetros chamado" << std::endl;
    };
    void gozar() {
       std::cout << "Glande gozando" << std::endl;
    };
};

int main() {
  Penis *p;
  p = new Glande;

  p->gozar();

  cin >> *p;
  cout << *p;

  delete p;

  return 0;
}
