#pragma once
#include <string>
#include "Raca.h"
#include "Inventario.h"

class Char {

private:
	Raca raca;

	int  vidaMax;
	int  vidaAtual;

	int  const dano;
	bool estaDefendendo;
	int valorDefesa;

	int modificadorDano;

public:
	Char(int vida, int dano, int defesa, Raca r);
	void fimTurno();
	void defender();
	void ataque(Char& alvo);
	void receberDano(int valor);
	void aplicarBonusRaca();

	int curar(int valor);
	
	int aumentarDano(int valor);

	int getVida() const;
	int getVidaMax() const;

	int getDano() const;

	int getDefesa() const;
	
	std::string getNomeRaca() const;
	Raca getRaca() const;
};

