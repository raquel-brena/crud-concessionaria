
#ifndef APOIOCONCESSIONARIA_H
#define APOIOCONCESSIONARIA_H
using namespace std;

#include <fstream>
#include<stdlib.h>

template < typename tipoVeiculo > // ou template <class tipoGenerico>
  void printVeiculo(tipoVeiculo veic, int pos) {
    cout << "Marca: "<<  veic[pos].get_marca()<<endl;
    cout << "Preco: "<<  veic[pos].get_preco()<<endl;
    cout << "Chassi: "<<  veic[pos].get_chassi()<<endl;
    cout << "Ano: " <<  veic[pos].get_fabricacao()<<endl;
    cout << "Tipo de Motor: " <<  veic[pos].get_funcionalidade()<<endl;
  }

  int quantidadeVeiculo (string tipo_veiculo, int tamCarros,int tamMotos,int tamTrucks){
    
   int quantidadeVeiculos = 0;
  if (tipo_veiculo == "carro") {
    quantidadeVeiculos = tamCarros;
  } else if (tipo_veiculo == "moto") {
    quantidadeVeiculos = tamMotos;
  } else if (tipo_veiculo == "caminhao") {
    quantidadeVeiculos = tamTrucks;
  } else {
    quantidadeVeiculos = tamCarros + tamMotos + tamTrucks;
  }
  return quantidadeVeiculos;
  }

  #endif