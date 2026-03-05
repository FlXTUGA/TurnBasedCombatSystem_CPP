#include "Char.h"

Char::Char(int vida, int dano, int defesa) : vidaMax(vida), dano(dano), valorDefesa(defesa), estaDefendendo(false), vidaAtual(vidaMax), bonusDano(0) {}

void Char::fimTurno() {
	estaDefendendo = false;
}
void Char::defender() {
	estaDefendendo = true;
}

void Char::ataque(Char& alvo) {
	alvo.receberDano(getDano());
}
void Char::receberDano(int valor) {

	if (estaDefendendo) {
		valor -= valorDefesa;
	}
	if (valor < 0) { valor = 0; }
	vidaAtual -= valor;
	if (vidaAtual < 0) { vidaAtual = 0; }
}

int Char::getVida() const { return vidaAtual; }
int Char::getDano() const { return dano + bonusDano; }
int Char::getVidaMax() const { return vidaMax; }
int Char::getDefesa() const { return valorDefesa; }
