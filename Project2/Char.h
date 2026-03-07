#pragma once
#include <string>
enum class Raca {
	Humano,
	Ogro,
	Esqueleto
};

struct DadosRaca {
	int bonusVida;
	bool ataqueDuplo;
	std::string nome;
	int nerfDano;
};

DadosRaca getDadosRaca(Raca r);

class Char {

private:
	Raca raca;

	int  vidaMax;
	int  vidaAtual;

	int  const dano;
	bool estaDefendendo;
	int valorDefesa;

	int bonusDano;

public:
	Char(int vida, int dano, int defesa, Raca r);


	void fimTurno();
	void defender();
	void ataque(Char& alvo);
	void receberDano(int valor);
	void aplicarBonusRaca();

	int getVida() const;
	int getVidaMax() const;

	int getDano() const;

	int getDefesa() const;
	
	std::string getNomeRaca() const;
	Raca getRaca() const;
};

