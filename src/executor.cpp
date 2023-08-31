#include <istream>

#include <ostream>

#include <iostream>

#include <sstream>

#include <queue>

#include "executor.h"

using namespace std;
// vector responsável por guardar as entradas 
// em quanitidade inderteminada após o processamento
// na função restoDe()
vector < string > entrada;

// Função de apoio que recebe um istringstream e
// le todo texto restante até o fim da linha
string restoDe(istringstream & ss) {
  string resto;
  getline(ss, resto, '\0'); // ler o resto da linha
  if (resto != "" && (resto[0] == ' ' || resto[0] == '\t')) {
    resto = resto.substr(1); // o primeiro caractere é um espaço, descartar

  }
  return resto;
}

// Construtor. Recebe uma referência ao sistema que vai operar
// Guarda o seu endereço para executar as operações.
Executor::Executor(Sistema & sistema) {
  this -> sair = false;
  this -> sistema = & sistema;
}

// Inicia o processamento dos comentarios.
// Esse método recebe por exemplo o "cin" e o "cout" no main
// Dessa forma ele faz o necessário para ler 1 comando por linha e
// o processar corretamente, colocando no stream de saída o resultado de cada um.
void Executor::iniciar(istream & inputStream, ostream & outputStream) {
  string linha, saida;
  this -> sair = false;
  while (!this -> sair) {
    if (std::getline(inputStream, linha)) {
      saida = processarLinha(linha);
      outputStream << saida << endl;
    }
  }
}

// Método responsável por processar cada linha, capturando o nome do comando
// e seus parâmetros em variáveis e executar o método correspondente no sistema
string Executor::processarLinha(string linha) {
istringstream buf(linha);
  string nomeComando;
  buf >> nomeComando;

  if (nomeComando.empty()) {
    return "Comando Inválido <vazio>";
  }
  if (nomeComando == "quit") {
    this -> sair = true;
    return sistema -> quit();
  } else if (nomeComando == "create-concessionaria") {
    cout<<endl;
    return sistema -> create_concessionaria(restoDe(buf));
  } else if (nomeComando == "add-car") {
    cout<<endl;
    return sistema -> add_car(restoDe(buf));
  } else if (nomeComando == "add-motorcycle") {
    cout<<endl;
   return sistema -> add_moto(restoDe(buf));
  } else if (nomeComando == "add-truck") {
    cout<<endl;
    return sistema -> add_truck(restoDe(buf));
  } else if (nomeComando == "remove-vehicle") {
    cout<<endl;
    return sistema -> remove_vehicle(restoDe(buf));
  } else if (nomeComando == "search-vehicle") {
    cout<<endl;
     return sistema -> search_vehicle(restoDe(buf));
    }else if (nomeComando == "save-concessionaria") {
    cout<<endl;
     return sistema -> save_concessionaria(restoDe(buf));
    }else if (nomeComando == "load-concessionaria") {
    cout<<endl;
     return sistema -> load_concessionaria(restoDe(buf));
    }else if (nomeComando == "list-concessionaria") {
    cout<<endl;
      return sistema -> list_concessionaria(restoDe(buf));
    }else if (nomeComando == "raise-price") {
    cout<<endl;
      return sistema -> raise_price(restoDe(buf));
    }
  return "Erro";
}//mingw32-make 