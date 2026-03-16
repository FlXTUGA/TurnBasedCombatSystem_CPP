#include "Character.h"
#include "Combat.h"
#include "UI.h"
#include "PocaoVida.h"
#include "Dificuldade.h"
#include "EnemyGenerator.h"
#include "Rooms.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <limits>

enum class Salas {
	Combate,
	Loja,
	Boss
};
std::vector<Salas> salas = {
	Salas::Combate,
	Salas::Combate,
	Salas::Loja,
	Salas::Boss

};


int main() {
	 
	Dificuldade dificuldadeAtual = obterDificuldade();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::vector<Char> inimigos;

	std::string mensagem = criarMensagemInimigos(inimigos);

	Inventario inventario;

	inventario.adicionar(std::make_unique<PocaoVida>(40));
	inventario.adicionar(std::make_unique<PocaoVida>(50));

	std::string nome = escolherNome();
	Classe classeJogador = escolherClasse();

	Char jogador(100, 30, 15, Raca::Humano, classeJogador );

	int ouroGanho = 0;
	int ouro = 0;

	ouro = jogador.getOuro();

	//textoInicial();
	createRooms(jogador, inventario, nome, dificuldadeAtual);

	if (jogador.getVida() > 0) {
		mudarCor(10);// Verde claro
		escreverLento("Parabens " + nome + ", conseguiste sair da dungeon com vida!\n");
	}
	else {
		mudarCor(4);// Vermelho escuro
		escreverLento(nome + "... a escuridao da dungeon consumiute.\n");

	}

	return 0;
}
