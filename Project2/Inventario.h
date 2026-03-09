#pragma once
#include <vector>
#include <memory>
#include "Item.h"

class Char;

class Inventario {
private:

	std::vector<std::unique_ptr<Item>> itens;

public:
	void adicionar(std::unique_ptr<Item> item);

	void mostrar() const;

	void usarItem(int indice, Char& jogador);

	bool vazio()const;
};