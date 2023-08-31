#include "moto.h"

using namespace std;

  moto::moto(){}

  string moto::get_funcionalidade(){
    return modelo;
  }

  // Getters
  string moto::get_marca() {
    return marca;
  }

  int moto::get_preco() {
    return preco;
  }

  string moto::get_chassi() {
    return chassi;
  }

    void moto::set_chassi(string chassi) {
    this->chassi = chassi;
  }

  int moto::get_fabricacao() {
    return ano_fabricacao;
  }

   void moto::set_preco(double novoPreco) {
    this->preco = novoPreco;
  }