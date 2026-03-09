#pragma once
#include "Item.h"

class PocaoVida:public Item {
private:
	int cura;
public:
	PocaoVida(int cura);

	void usar(Char& jogador) override;
	bool consomeAoUsar() const override;
};