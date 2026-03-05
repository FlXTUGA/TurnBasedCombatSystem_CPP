#pragma once

class Char {

private:
	int const vidaMax;
	int  vidaAtual;

	int  const dano;
	bool estaDefendendo;
	int valorDefesa;

	int bonusDano;

public:
	Char(int vida, int dano, int defesa);

	void fimTurno();
	void defender();
	void ataque(Char& alvo);
	void receberDano(int valor);

	int getVida() const;
	int getVidaMax() const;

	int getDano() const;

	int getDefesa() const;

};