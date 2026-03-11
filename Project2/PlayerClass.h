#pragma once
#include<string>

enum Classe {
	Guerreiro,
	Mago,
	Arqueiro,
	Inimigos
};

struct DadosClasse
{
	int bonusVida;
	int bonusDano;
	std::string nome;

};

DadosClasse getDadosClasse(Classe c);