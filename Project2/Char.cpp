#include "Char.h"

Char::Char(int vida, int dano, int defesa, Raca r) 
	: vidaMax(vida), dano(dano), valorDefesa(defesa), estaDefendendo(false), vidaAtual(vidaMax), modificadorDano(0), raca(r)
{
	aplicarBonusRaca();
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
	if (vidaMax < 1) {
		vidaMax = 1;
	}
	vidaAtual = vidaMax;
	modificadorDano = dados.modificadorDano;
}

int Char::getVida() const { return vidaAtual; }
int Char::getDano() const { return dano + modificadorDano ; }
int Char::getVidaMax() const { return vidaMax; }
int Char::getDefesa() const { return valorDefesa; }

std::string Char::getNomeRaca() const { 
	DadosRaca dados = getDadosRaca(raca);
	return dados.nome; 
}

Raca Char::getRaca() const { return raca; }
