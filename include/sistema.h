#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>

#include "Concessionaria.h"
// Sistema deve concentrar todas as operações
class Sistema {
  private:
		vector<Concessionaria> concessionarias; //um vetor com todos as concessionarias
  public:

		/*Encerra o funcionamento do programa.
			@return uma string com a mensagem "Saindo.."
		*/
		string quit();

		/* Cria uma concessionaria e retorna uma string de erro/sucesso 
			@param nome o nome da concessionaria
			@return uma string contendo uma mensagem de erro ou "Concessionaria Criada"
		*/
		string create_concessionaria (string entrada);
        string add_veiculo(string entradas);
        string add_car(string entrada);
        string add_moto(string entrada);
		string add_truck(string entrada);
		vector <string> separadorEntradas(string entrada);
		string remove_vehicle(string entrada);
		string search_vehicle(string entrada);
		string save_concessionaria(string conc);
		string load_concessionaria(string conc);
		string list_concessionaria(string conc);
		string raise_price(string conc);
		void printRaise();
		
};

#endif
