#include "Item.h"

Item::Item(std::string nome, TipoItem tipo): nome(nome), tipo(tipo){}

std::string Item:: getNome() const {
	return nome;
}
TipoItem Item::getTipo() const {
	return tipo;
}