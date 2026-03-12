#include "Character.h"
#include "Combat.h"
#include "UI.h"
#include "PocaoVida.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

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
	int numeroSalas = 1;


	for (Salas sala : salas) {
		escreverLento("\nSala " + std::to_string(numeroSalas) + "\n");
		if (sala == Salas::Combate) {
			inimigos.clear();
			if (numeroSalas == 1) {
				inimigos.push_back(Char(30, 10, 0, Raca::Esqueleto, Inimigos));

			}
			else if (numeroSalas == 2) {
				inimigos.push_back(Char(40, 10, 0, Raca::Esqueleto, Inimigos));
				inimigos.push_back(Char(40, 10, 0, Raca::Esqueleto, Inimigos));
			}
			
			mudarCor(12);//Vermelho
			escreverLento(criarMensagemInimigos(inimigos));

			mudarCor(7); // branco
			escreverLento("Prepara-te para lutar " + nome + "\n");

			iniciarCombate(jogador, inimigos, inventario, nome, ouro);
			
			if (!haInimigosVivos(inimigos)) {
				if (numeroSalas == 1) {
					ouroGanho = 20;
				}
				else if (numeroSalas == 2) {
					ouroGanho = 40;
				}

				jogador.adicionarOuro(ouroGanho);

				escreverLento("Ganhaste " + std::to_string(ouroGanho) +" de ouro! Agora tens " + std::to_string(jogador.getOuro()) + " de ouro.\n");
				std::this_thread::sleep_for(std::chrono::milliseconds(900));
			}

			if (jogador.getVida() <= 0) {
				break;
			}

		}
		else if (sala == Salas::Loja) {
			char escolhaLoja;
			mudarCor(2);// Verde
			escreverLento("Encontraste uma loja secreta no meio da dungeon!\n");
			escreverLento("O lojista oferece-te um item misterioso em troca de 50 de ouro\n");
			escreverLento("Queres comprar o item?          Tu tens " + std::to_string(jogador.getOuro()) + " ouro\n");
			escreverLento("1 - Sim\n");
			escreverLento("2 - Nao\n");
			escreverLento("> ");
			std::cin >> escolhaLoja;
			switch(escolhaLoja){
				case '1':
					if (jogador.getOuro() >= 50) {
						escreverLento("Compraste o item misterioso!\n");
						escreverLento("O lojista entrega-te uma pocao de vida poderosa!\n");
						escreverLento("O lojista desaparece na escuridao, deixando-te com o item misterioso.\n");
						escreverLento("- 50 ouro\n");
						jogador.removerOuro(50);
						inventario.adicionar(std::make_unique<PocaoVida>(70));
					}
					else {
						escreverLento("Nao tens ouro suficiente.\n");
					}
					break;
				case '2':
					escreverLento("Decidiste nao comprar o item. O lojista fica desapontado e desaparece na escuridao.\n");
					break;
				default:
					escreverLento("Escolha Invalida\n");

			}
		}
		else if (sala == Salas::Boss) {
			std::vector<Char> inimigos;
			inimigos.push_back(Char(150, 40, 10, Raca::Ogro, Inimigos));
			mudarCor(12);//Vermelho
			escreverLento("O Boss da dungeon aparece no teu caminho!\n");
			iniciarCombate(jogador, inimigos, inventario, nome, jogador.getOuro());

			if (jogador.getVida() <= 0) {
				mudarCor(14);
				break;
			}

		}
		numeroSalas++;
	}
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
