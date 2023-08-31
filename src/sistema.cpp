#include "sistema.h"

#include "veiculo.h"

#include "carro.h"

#include "moto.h"

#include "caminhao.h"

#include <iostream>

#include <sstream>

#include <algorithm>

#include <fstream>


carro carroAux;
moto motoAux;
caminhao caminhaoAux;

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

// Comando de processamento das entradas.
// Separa a entrada de string para um vector 
// indeterminando a quantidade de entradas.
vector < string > Sistema::separadorEntradas(string entrada) {
  vector < string > aux;
  istringstream buf(entrada); // manda linha
  string caracCarro;
  while (buf) {
    buf >> caracCarro;
    if (buf) {
      aux.push_back(caracCarro);
    }
  }
  return aux;
}

// Método para criar concessionárias
// adiciona nome, cnpj e estoque em uma concessionária.
string Sistema::create_concessionaria(string entrada) {
  vector < string > entradas;
  entradas = separadorEntradas(entrada);
  string nome = entradas[0];
  string CNPJ = entradas[1];
  int estoque = stoi(entradas[2]);

 // caso já exista concessionárias faz o processamento normal.
  if (!concessionarias.empty()) {
    int size = concessionarias.size();
    for (int i = 0; i <= size; i++) {
      if (concessionarias[i].getCNPJ() == CNPJ || concessionarias[i].getNome() == nome) {
        return "Concessionaria " + nome + " ja existe!";
      } else {
        Concessionaria concessionariaAux(nome, CNPJ, estoque);
        concessionarias.push_back(concessionariaAux); //add concessionaria no vector RB
        return "Concessionaria " + nome + " criada!";
      }
    }
  } else {
    Concessionaria concessionariaAux(nome, CNPJ, estoque);
    concessionarias.push_back(concessionariaAux); //add concessionaria no vector RB
    return "Concessionaria " + nome + " criada!";
  }
  return "criou";
}

string Sistema::add_veiculo (string entradas){
  vector < string > entrada;
  entrada = separadorEntradas(entradas);

  string conc = entrada[0];
  string marca = entrada[1];
  double preco = stod(entrada[2]);
  string chassi = entrada[3];
  int ano_fabricacao = stoi(entrada[4]);
  string tipo_motor = entrada[5];

  int size = concessionarias.size();
  pair <string, int> verificador;
  verificador.second = 0;

  
}

string Sistema::add_car(string entradas) {
  vector < string > entrada;
  entrada = separadorEntradas(entradas);
  string conc = entrada[0];
  string marca = entrada[1];
  double preco = stod(entrada[2]);
  string chassi = entrada[3];
  int ano_fabricacao = stoi(entrada[4]);
  string tipo_motor = entrada[5];

  int size = concessionarias.size();
  pair < string, int > verificador;
  verificador.second = 0;

  for (int i = 0; i < size; i++) {
    verificador = concessionarias[i].verificarChassi(chassi, "carro");
    if (verificador.second == 1) { // Verifica se o chassi já existe na concessionária
      return "ERRO - Veiculo " + chassi + " ja adicionado a concessionaria " + concessionarias[i].getNome();
    } else {
      carro carroAux(marca, preco, chassi, ano_fabricacao, tipo_motor);
      if (concessionarias[i].add_car(carroAux)) {
        concessionarias[i].add_estoque();
        return "Carro " + chassi + " adicionado com sucesso!";
      }
    }
  }
  return "Error";
}

//adicionar moto
string Sistema::add_moto(string entradas) {
  vector < string > entrada;
  entrada = separadorEntradas(entradas);
  string conc = entrada[0];
  string marca = entrada[1];
  double preco = stod(entrada[2]);
  string chassi = entrada[3];
  int ano_fabricacao = stoi(entrada[4]);
  string modelo = entrada[5];

  int size = concessionarias.size();
  pair < string, int > verificador;
  verificador.second = 0;

  for (int i = 0; i < size; i++) {
    verificador = concessionarias[i].verificarChassi(chassi, "moto");
    if (verificador.second == 1) { // Verifica se o chassi já existe na concessionária
      return "ERRO - Veiculo " + chassi + " ja adicionado a concessionaria " + concessionarias[i].getNome();
    } else {
      moto motoAux(marca, preco, chassi, ano_fabricacao, modelo);
      if (concessionarias[i].add_moto(motoAux)) {
        concessionarias[i].add_estoque();
        return "Moto " + chassi + " adicionado com sucesso!";
      }
    }
  }
  return "Error";
}
//adicionar caminhão
string Sistema::add_truck(string entradas) {
  vector < string > entrada;
  entrada = separadorEntradas(entradas);
  string conc = entrada[0];
  string marca = entrada[1];
  double preco = stod(entrada[2]);
  string chassi = entrada[3];
  int ano_fabricacao = stoi(entrada[4]);
  string carga = entrada[5];

  int size = concessionarias.size();
  pair < string, int > verificador;
  verificador.second = 0;

  for (int i = 0; i < size; i++) {
    if (concessionarias[i].getNome() == conc) {
      verificador = concessionarias[i].verificarChassi(chassi, "caminhao");
      if (verificador.second == 1) { // Verifica se o chassi já existe na concessionária
        return "ERRO - Veiculo " + chassi + " ja adicionado a concessionaria " + concessionarias[i].getNome();
      } else {
        caminhao truckAux(marca, preco, chassi, ano_fabricacao, carga);
        if (concessionarias[i].add_truck(truckAux)) {
          concessionarias[i].add_estoque();
          return "Caminhao " + chassi + " adicionado com sucesso!";
        }
      }
    }
    return "Concessionaria nao existe";
  }
  return "Error";
}

string Sistema::remove_vehicle(string chassi) {
  int size = concessionarias.size();
  for (int i = 0; i < size; i++) {
    pair < string, int > verificador = concessionarias[i].verificarChassi(chassi, "todos");
    if (verificador.second == 1) { // Verifica se o chassi já existe na concessionária
      concessionarias[i].remove(chassi, verificador.first);
      concessionarias[i].rmv_estoque();
      return "Veiculo " + chassi + " removido da concessionaria " + concessionarias[i].getNome();
    }
  }
  return "Veiculo " + chassi + " ja esta removido";
}

string Sistema::search_vehicle(string chassi) {
  int size = concessionarias.size();
  for (int i = 0; i < size; i++) {
    pair < string, int > verificador = concessionarias[i].verificarChassi(chassi, "todos");
    return concessionarias[i].search(verificador.first, chassi);
  }
  return "nao encontrado";
}
string Sistema::save_concessionaria(string nome) {

  int size2 = concessionarias.size();
  for (int i = 0; i < size2; i++) {
    if (concessionarias[i].getNome() == nome) {
      if (concessionarias[i].salvar_estoque()) {
        return "Arquivo " + concessionarias[i].getNome() + ".txt criado com sucesso";
      }
    }
  }
  return "ERROR Arquivo " + nome + ".txt nao criado";
}

string Sistema::load_concessionaria(string nomeArq) {
  ifstream arqDados;
  vector < string > veiculos, conc;
  string dadosConc, dadosVeic;
  arqDados.open(nomeArq);

  std::getline(arqDados, dadosConc, '\n');
  conc = separadorEntradas(dadosConc);
  create_concessionaria(dadosConc);
 
  while (!arqDados.eof()) {
    std::getline(arqDados, dadosVeic, '\n');
    if (dadosVeic != "") {

      veiculos = separadorEntradas(dadosVeic);
      dadosVeic = conc[0] + " " + dadosVeic;
      if (veiculos[4] == "gasolina" || veiculos[4] == "elétrico") {
        add_car(dadosVeic);
      } else if (veiculos[4] == "classico" || veiculos[4] == "esportivo") {
        add_moto(dadosVeic);
      } else if (veiculos[4] == "comum" || veiculos[4] == "perigosa") {
        add_truck(dadosVeic);
      }
    }
  }
  return "LOAD da Concessionaria " + conc[0] + " criada com sucesso!";
}

string Sistema::list_concessionaria(string nomeConcessionaria) {
  int tam = concessionarias.size();
  for (int i = 0; i < tam; i++) {
    if (nomeConcessionaria == concessionarias[i].getNome()) {
      cout << "Concessionaria " << concessionarias[i].getNome() << endl;
      cout << "Total de Automoveis: " << concessionarias[i].sizeCarro() << "; Valor total: R$ " << concessionarias[i].financeiroCarro() << endl;
      cout << "Total de Motos: " << concessionarias[i].sizeMoto() << "; Valor total: R$ " << concessionarias[i].financeiroMoto() << endl;
      cout << "Total de Caminhoes: " << concessionarias[i].sizeTruck() << "; Valor total: R$ " << concessionarias[i].financeiroTruck()<< endl;
      cout << "Valor Total da frota: R$ " << concessionarias[i].financeiroCarro() + concessionarias[i].financeiroMoto()+ concessionarias[i].financeiroTruck()<< endl;
    }
  }
  return "--------------------------------";
}

string Sistema::raise_price(string entrada) {
  vector <string> dados;
  dados = separadorEntradas(entrada);
  string concessionariaNome = dados[0];
  int porcentagem = stoi(dados[1]);
  int porcentagem1 = stoi(dados[1])*2;
  int porcentagem2 = stoi(dados[1])*3;

  int tam = concessionarias.size();
  for (int i = 0; i < tam; i++) {
    if (concessionariaNome == concessionarias[i].getNome()) {
      concessionarias[i].raisePrice(porcentagem) ;
  }
 
  }
   return "Aumento de " + to_string(porcentagem) + "% nos precos de automoveis da Concessionaria "+ concessionariaNome +" realizado \n"+"Aumento de " + to_string(porcentagem1) + "% nos precos de motos da Concessionaria "+ concessionariaNome +" realizado \n"+"Aumento de " + to_string(porcentagem2) + "% nos precos de caminhoes da Concessionaria "+ concessionariaNome +" realizado \n";
}
