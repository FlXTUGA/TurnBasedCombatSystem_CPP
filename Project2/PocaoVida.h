#pragma once
#include "Item.h"
#include <string>

class PocaoVida:public Item {
private:
	int cura;
public:
	PocaoVida(int valorCura);

	int usar(Char& jogador) override;
	bool consomeAoUsar() const override;
	std::string getDescricao() const override;
};