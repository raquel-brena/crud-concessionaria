#ifndef MOTO_H
#define MOTO_H

#include <istream>

#include <ostream>

#include <sstream>

#include "veiculo.h"

using namespace std;

class moto: public veiculo {
  protected: string modelo;
  public: moto();
  moto(string marca, double preco, string chassi, int ano_fabricacao, string modelo): veiculo(marca, preco, chassi, ano_fabricacao) {
    this -> modelo = modelo;
  }
  string get_marca();
  string get_chassi();
  int get_preco();
  string get_funcionalidade();
  int get_fabricacao();
  void set_chassi(string chassi);
  void set_preco(double novoPreco);
};
#endif