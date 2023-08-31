#ifndef VEICULO_H
#define VEICULO_H
#include <istream>

  #include <ostream>

  #include <sstream>

using namespace std;

class veiculo {
  protected: string marca;
  double preco;
  string chassi;
  int ano_fabricacao;

  public:
    //marca, preco, chassi, fabricacao, motor
    veiculo() {};
  veiculo(string marca, double preco, string chassi, int ano_fabricacao);
  virtual string get_marca() {
    return 0;
  }; // Getter
  virtual int get_preco() {
    return 0;
  }; // Getter
  virtual string get_chassi() {
    return 0;
  }; // Getter
  virtual int get_fabricacao() {
    return 0;
  }; // Getter
};

#endif