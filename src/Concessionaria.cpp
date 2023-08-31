#include <iostream>

#include <sstream>

#include <algorithm>

#include <vector>

#include<iterator>

#include <fstream>

#include <utility>

#include <string.h>

#include<stdlib.h>

#include "Concessionaria.h"

#include "veiculo.h"

#include "apoioConcessionaria.h"

using namespace std;


Concessionaria::Concessionaria(string nome, string cnpj, int estoque) {
  this -> nome = nome;
  this -> CNPJ = cnpj;
  this -> estoque = estoque;
  veiculos = new veiculo[capacidade];
  carros = new carro[capacidade];
  motos = new moto[capacidade];
  trucks = new caminhao[capacidade];
}

bool Concessionaria::remove(string chassi, string tipo_veiculo) {
  int quantidadeVeiculos = quantidadeVeiculo(tipo_veiculo, tamCarros, tamMotos, tamTrucks);

  for (int i = 0; i < quantidadeVeiculos; i++) {
    if (chassi == carros[i].get_chassi()) {
      carros[i] = carros[i + 1];
      tamCarros--;
    } else if (chassi == motos[i].get_chassi()) {
      motos[i] = motos[i + 1];
      tamMotos--;
    } else if (chassi == trucks[i].get_chassi()) {
      trucks[i] = trucks[i + 1];
      tamTrucks--;
    }
  }
  return true;
}
// Verificar se o chassi já existe

pair < string, int > Concessionaria::verificarChassi(string chassi, string tipo_veiculo) {
  pair < string, int > par;

  int quantidadeVeiculos = quantidadeVeiculo(tipo_veiculo, tamCarros, tamMotos, tamTrucks);
  if (quantidadeVeiculos != 0) {
    for (int i = 0; i <= quantidadeVeiculos; i++) {
      if (chassi == carros[i].get_chassi()) {
        return pair < string, int > ("carro", 1);
      } else if (chassi == motos[i].get_chassi()) {
        return pair < string, int > ("moto", 1);
      } else if (chassi == trucks[i].get_chassi()) {
        return pair < string, int > ("caminhao", 1);
      }
    }
  } else {
    return pair < string, int > (tipo_veiculo, 0);
  }
  return pair < string, int > (tipo_veiculo, 0);
}


int Concessionaria::financeiroCarro() {
  int total = 0;
  for (int i = 0; i < tamCarros; i++) {
    total = carros[i].get_preco() + total;
  }
  return total;
}

int Concessionaria::financeiroMoto() {
  int total = 0;
  for (int i = 0; i < tamMotos; i++) {
    total = motos[i].get_preco() + total;
  }
  return total;
}
int Concessionaria::financeiroTruck() {
  int total = 0;
  for (int i = 0; i < tamTrucks; i++) {
    total = trucks[i].get_preco() + total;
  }
  return total;
}

string Concessionaria::search(string tipo_veiculo, string chassi) {
  pair < string, int > par;

  if (tipo_veiculo == "carro") {
    for (int posicao = 0; posicao < tamCarros; posicao++) {
      cout << "Concessionaria: " << this -> nome << endl;
      printVeiculo(carros, posicao);
    }
  } else if (tipo_veiculo == "moto") {
    for (int posicao = 0; posicao < tamMotos; posicao++) {
      cout << "Concessionaria: " << this -> nome << endl;
      printVeiculo(motos, posicao);
    }
  } else if (tipo_veiculo == "caminhao") {
    for (int posicao = 0; posicao < tamTrucks; posicao++) {
      cout << "Concessionaria: " << this -> nome << endl;
      printVeiculo(trucks, posicao);
    }
  } else {
    return "Nao encontrado";
  }
  return "--------------------------------";
}

bool Concessionaria::add_car(carro carAux) {
  //cout << "adicionando o carro no tamanho " << tamCarros << endl;
  carros[tamCarros] = carAux;
  tamCarros++;
  return true;
}

bool Concessionaria::add_moto(moto motoAux) {
  motos[tamMotos] = motoAux;
  tamMotos++;
  return true;
}

bool Concessionaria::add_truck(caminhao truckAux) {
  trucks[tamTrucks] = truckAux;
  tamTrucks++;
  return true;
}

bool Concessionaria::salvar_estoque() {
  fstream arqDados;
  string nomeArq = nome + ".txt";
  arqDados.open(nomeArq, ios::ate | ios::out | ios::trunc);

  arqDados << nome << " " << CNPJ << " " << estoque << endl;
  for (int i = 0; i < tamCarros; i++) {
    if (arqDados.is_open()) {
      arqDados << carros[i].get_marca() << " ";
      arqDados << carros[i].get_preco() << " ";
      arqDados << carros[i].get_chassi() << " ";
      arqDados << carros[i].get_fabricacao() << " ";
      arqDados << carros[i].get_funcionalidade() << endl;
    }
  }
  for (int i = 0; i < tamMotos; i++) {
    if (arqDados.is_open()) {
      arqDados << motos[i].get_marca() << " ";
      arqDados << motos[i].get_preco() << " ";
      arqDados << motos[i].get_chassi() << " ";
      arqDados << motos[i].get_fabricacao() << " ";
      arqDados << motos[i].get_funcionalidade() << endl;
    }
  }
  for (int i = 0; i < tamTrucks; i++) {
    if (arqDados.is_open()) {
      arqDados << trucks[i].get_marca() << " ";
      arqDados << trucks[i].get_preco() << " ";
      arqDados << trucks[i].get_chassi() << " ";
      arqDados << trucks[i].get_fabricacao() << " ";
      arqDados << trucks[i].get_funcionalidade() << endl;
    }
  }
  
  arqDados.close();
  return true;
} 

string Concessionaria::getNome() {
  return nome;
}

void Concessionaria::add_estoque() {
  estoque++;
}

void Concessionaria::rmv_estoque() {
  estoque--;
}

  void Concessionaria::raisePrice (int porcentagem){
    for (int i = 0 ; i < tamCarros; i++){
      int novoPreco = carros[i].get_preco() + (carros[i].get_preco()*porcentagem)/100;
      carros[i].set_preco(novoPreco);
    }
    for (int i = 0 ; i < tamMotos; i++){
      int novoPreco = motos[i].get_preco() + (motos[i].get_preco()*porcentagem)/100;
      motos[i].set_preco(novoPreco);
    }
    for (int i = 0 ; i < tamTrucks; i++){
      int novoPreco = trucks[i].get_preco() + (trucks[i].get_preco()*porcentagem)/100;
      trucks[i].set_preco(novoPreco);
    }
  }

  string Concessionaria::getCNPJ() {
  return CNPJ;
}

int Concessionaria::getEstoque() {
  return estoque;
}

bool Concessionaria::emptyCarro() {
  return tamCarros == 0;
}

int Concessionaria::sizeCarro() {
  return tamCarros;
}
int Concessionaria::sizeMoto() {
  return tamMotos;
}
int Concessionaria::sizeTruck() {
  return tamTrucks;
}


