#pragma once
#include <string>

enum class Raca {
	Esqueleto,
	Goblin,
	Ogro,
	Golem,
	Humano
};

struct DadosRaca {
	int bonusVida;
	bool ataqueDuplo;
	std::string nome;
	int modificadorDano;
};

DadosRaca getDadosRaca(Raca r);