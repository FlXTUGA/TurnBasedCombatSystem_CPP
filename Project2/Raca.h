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
	int modificadorDano;
};

DadosRaca getDadosRaca(Raca r);