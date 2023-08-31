#ifndef CARRO_H
#define CARRO_H

#include <istream>

#include <ostream>

#include <sstream>

#include "veiculo.h"

using namespace std;
class carro: public veiculo {

  protected: 
  string tipo_motor;

  public:
  carro();
  carro(string marca, double preco, string chassi, int ano_fabricacao, string tipo_motor): veiculo(marca, preco, chassi, ano_fabricacao){
    this->tipo_motor= tipo_motor;
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