#pragma once
#include "Raca.h"
#include "Inventario.h"
#include "PlayerClass.h"

#include <string>


class Char {

private:
	Raca raca;
	Classe classe;

	int  vidaMax;
	int  vidaAtual;

	int  dano;
	bool estaDefendendo;
	int valorDefesa;

	int modificadorDanoRaca;
	int modificadorDanoClasse;

	int ouro;

public:
	Char(int vida, int dano, int defesa, Raca r, Classe c);
	void fimTurno();
	void defender();
	void ataque(Char& alvo);
	void receberDano(int valor);
	
	void aplicarBonusIniciais();

	void adicionarOuro(int valor);
	void removerOuro(int valor);

	int curar(int valor);
	

	int getVida() const;
	int getVidaMax() const;
	int getDano() const;
	int getDefesa() const;
	int getOuro() const;
	
	std::string getNomeClasse() const;
	Classe getClasse() const;

	std::string getNomeRaca() const;
	Raca getRaca() const;
};

