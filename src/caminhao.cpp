#include "caminhao.h"

using namespace std;

  caminhao::caminhao(){}

  string caminhao::get_funcionalidade(){
    return tipo_carga;
  }

  // Getters
  string caminhao::get_marca() {
    return marca;
  }

  int caminhao::get_preco() {
    return preco;
  }

  string caminhao::get_chassi() {
    return chassi;
  }

    void caminhao::set_chassi(string chassi) {
    this->chassi = chassi;
  }

  int caminhao::get_fabricacao() {
    return ano_fabricacao;
  }

   void caminhao::set_preco(double novoPreco) {
    this->preco = novoPreco;
  }