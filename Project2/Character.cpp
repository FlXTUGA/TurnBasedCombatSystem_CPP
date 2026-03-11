#include "Character.h"

Char::Char(int vida, int dano, int defesa, Raca r, Classe c) 
	: vidaMax(vida), dano(dano), valorDefesa(defesa), estaDefendendo(false), vidaAtual(vidaMax), modificadorDanoRaca(0), modificadorDanoClasse(0), raca(r), classe(c)
{
	aplicarBonusIniciais();
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

void Char::aplicarBonusIniciais() {
	DadosClasse dadosC = getDadosClasse(classe);
	DadosRaca dadosR = getDadosRaca(raca);

	vidaMax += dadosR.bonusVida;
	vidaMax += dadosC.bonusVida;

	if (vidaMax < 1) {
		vidaMax = 1;
	}
	vidaAtual = vidaMax;

	modificadorDanoRaca = dadosR.modificadorDano;
	modificadorDanoClasse = dadosC.bonusDano;
}

int Char::curar(int valor) {
	int vidaAntes = vidaAtual;

	vidaAtual += valor;

	if (vidaAtual > vidaMax) { vidaAtual = vidaMax; }
	return vidaAtual - vidaAntes;

}

int Char::getVida() const { return vidaAtual; }
int Char::getDano() const { return dano + modificadorDanoRaca + modificadorDanoClasse ; }
int Char::getVidaMax() const { return vidaMax; }
int Char::getDefesa() const { return valorDefesa; }


std::string Char::getNomeClasse() const { 
	DadosClasse dados = getDadosClasse(classe);
	return dados.nome; 
}
Classe Char::getClasse() const { return classe; }

std::string Char::getNomeRaca() const { 
	DadosRaca dados = getDadosRaca(raca);
	return dados.nome; 
}

Raca Char::getRaca() const { return raca; }
