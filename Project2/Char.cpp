#include "Char.h"



Char::Char(int vida, int dano, int defesa, Raca r) 
	: vidaMax(vida), dano(dano), valorDefesa(defesa), estaDefendendo(false), vidaAtual(vidaMax), bonusDano(0), raca(r) 
{
	aplicarBonusRaca();
}

DadosRaca getDadosRaca(Raca r) {
	switch (r) {
	case Raca::Humano:
		return { 0, false, "Humano", 0 };

	case Raca::Ogro:
		return { 20, false, "Ogro", 0 };

	case Raca::Esqueleto:
		return { -20, true, "Esqueleto", -5 };
	}

	return { 0, false, "Desconhecida", 0 };
}

void Char::fimTurno() {
	estaDefendendo = false;
}
void Char::defender() {
	estaDefendendo = true;
}

void Char::ataque(Char& alvo) {
	DadosRaca dados = getDadosRaca(raca);

	alvo.receberDano(getDano());

	if (dados.ataqueDuplo) {
		alvo.receberDano(getDano());
	}
}
void Char::receberDano(int valor) {

	if (estaDefendendo) {
		valor -= valorDefesa;
	}
	if (valor < 0) { valor = 0; }
	vidaAtual -= valor;
	if (vidaAtual < 0) { vidaAtual = 0; }
}

void Char::aplicarBonusRaca() {
	DadosRaca dados = getDadosRaca(raca);
	vidaMax += dados.bonusVida;
	vidaAtual = vidaMax;
	bonusDano -= dados.nerfDano;
}

int Char::getVida() const { return vidaAtual; }
int Char::getDano() const { return dano - bonusDano ; }
int Char::getVidaMax() const { return vidaMax; }
int Char::getDefesa() const { return valorDefesa; }

std::string Char::getNomeRaca() const { 
	DadosRaca dados = getDadosRaca(raca);
	return dados.nome; 
}

Raca Char::getRaca() const { return raca; }
