#include"Classe.h"

DadosClasse getDadosClasse(Classe c) {
	switch (c) {
	case Classe::Guerreiro: return { 30, 5, "Guerreiro" };
	case Classe::Mago: return { 0, 10, "Mago" };
	case Classe::Arqueiro: return { 10, 3, "Arqueiro" };
	case Classe::Inimigos: return { 0, 0, " " };
	}
	return { 0, 0, "Desconhecida" };
}