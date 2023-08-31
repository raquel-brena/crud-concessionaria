#ifndef CAMINHAO_H
#define CAMINHAO_H

#include <istream>

#include <ostream>

#include <sstream>

#include "veiculo.h"

using namespace std;
class caminhao: public veiculo {
  protected: string tipo_carga;
  public: caminhao() ;
  caminhao(string marca, double preco, string chassi, int ano_fabricacao, string carga): veiculo(marca, preco, chassi, ano_fabricacao) {
    this -> tipo_carga = carga;
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