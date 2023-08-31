#include "veiculo.h"

using namespace std;

veiculo::veiculo(string marca, double preco, string chassi, int ano_fabricacao){
        this->marca = marca;
        this->preco = preco;
        this->chassi = chassi;
        this->ano_fabricacao = ano_fabricacao;
}