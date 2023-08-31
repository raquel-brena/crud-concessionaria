#include "carro.h"

using namespace std;

  carro::carro(){}

  string carro::get_funcionalidade(){
    return tipo_motor;
  }

  // Getters
  string carro::get_marca() {
    return marca;
  }

  int carro::get_preco() {
    return preco;
  }

  string carro::get_chassi() {
    return chassi;
  }

    void carro::set_chassi(string chassi) {
    this->chassi = chassi;
  }

  int carro::get_fabricacao() {
    return ano_fabricacao;
  }

   void carro::set_preco(double novoPreco) {
    this->preco = novoPreco;
  }