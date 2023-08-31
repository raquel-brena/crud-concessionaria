#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H
#include <istream>

#include <ostream>

#include <sstream>

#include "veiculo.h"

#include "carro.h"

#include "moto.h"

#include "caminhao.h"

#include <string>

#include <utility>

using std::string;

#include <vector>

using std::vector;
// 
class Concessionaria {
  protected: string nome;
  string CNPJ;
  int estoque;
  int capacidade = 100;
  veiculo * veiculos;
  carro * carros;
  moto * motos;
  caminhao * trucks;
  vector < moto > exemplo;
  int tamTrucks = 0;
  int tamCarros = 0;
  int tamMotos = 0;

  public: Concessionaria(string n, string c, int e);
  string getNome();
  string getCNPJ();
  int getEstoque();
  bool add_car(carro carAux);
  bool add_moto(moto motoAux);
  bool add_truck(caminhao truckAux);
  bool emptyCarro();
  int sizeCarro();
  int sizeMoto();
  int sizeTruck();
  void add_estoque();
  void rmv_estoque();
  bool salvar_estoque();
  pair < string, int > verificarChassi(string chassi, string tipo_veiculo);
  bool remove(string remover_veiculo, string tipo_veiculo);
  string search(string tipo, string chassi);
  int financeiroCarro();
  int financeiroMoto();
  int financeiroTruck();
  void raisePrice (int porcentagem);
   string getmarca(int posicao){
    return carros[posicao].get_marca();
  }
};

#endif