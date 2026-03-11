#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

#include "Char.h"
#include "Combat.h"
#include "Menu.h"
#include "PocaoVida.h"


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

std::string criarMensagemInimigos(const std::vector<Char>& inimigos) {
	if (inimigos.empty()) {
		return "Nao ha inimigos no caminho.\n";
	}

	if (inimigos.size() == 1) {
		return "Um " + inimigos[0].getNomeRaca() + " aparece no teu caminho.\n";
	}

	std::string mensagem;

	for (size_t i = 0; i < inimigos.size(); i++) {
		if (i == 0) {
			mensagem += "Um " + inimigos[i].getNomeRaca();
		}
		else if (i == inimigos.size() - 1) {
			mensagem += " e um " + inimigos[i].getNomeRaca();
		}
		else {
			mensagem += ", um " + inimigos[i].getNomeRaca();
		}
	}

	mensagem += " aparecem no teu caminho.\n";
	return mensagem;
}

void textoInicial() {
	escreverLento(std::string(50, '\n'));
	mudarCor(14);
	escreverLento("\n\n\n\nA entrada da dungeon fecha-se atras de ti...\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	escreverLento("O ar e frio... e o silencio pesa nos corredores de pedra.\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	escreverLento("Das alguns passos na escuridao.\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	escreverLento("De repente...\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(1200));

	escreverLento("Algo move-se nas sombras.\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

}

int main() {
	int ouro = 0;

	Inventario inventario;

	inventario.adicionar(std::make_unique<PocaoVida>(40));
	inventario.adicionar(std::make_unique<PocaoVida>(50));

	std::string nome = escolherNome();
	Classe classeJogador = escolherClasse();

	Char jogador(100, 30, 15, Raca::Humano, classeJogador );

	//textoInicial();
	int numeroSalas = 1;

	for (Salas sala : salas) {
		escreverLento("\nSala " + std::to_string(numeroSalas) + "\n");
		if (sala == Salas::Combate) {

			std::vector<Char> inimigos;

			if (numeroSalas == 1) {
				inimigos.push_back(Char(30, 10, 0, Raca::Esqueleto, Inimigos));
			}
			else if (numeroSalas == 2) {
				inimigos.push_back(Char(40, 10, 0, Raca::Esqueleto, Inimigos));
				inimigos.push_back(Char(40, 10, 0, Raca::Esqueleto, Inimigos));
			}

			if(numeroSalas == 1){
				ouro += 20;
			}
			else if (numeroSalas == 2) {
				ouro += 40;
			}

			mudarCor(12);//Vermelho
			escreverLento(criarMensagemInimigos(inimigos));

			mudarCor(7); // branco
			escreverLento("Prepara-te para lutar " + nome + "\n");

			iniciarCombate(jogador, inimigos, inventario, nome);

			if (jogador.getVida() <= 0) {
				break;
			}

		}
		else if (sala == Salas::Loja) {
			char escolhaLoja;
			mudarCor(2);// Verde
			escreverLento("Encontraste uma loja secreta no meio da dungeon!\n");
			escreverLento("O lojista oferece-te um item misterioso em troca de 50 de ouro\n");
			escreverLento("Queres comprar o item?   Tu tens " + std::to_string(ouro) + " ouro\n");
			escreverLento("1 - Sim\n");
			escreverLento("2 - Nao\n");
			escreverLento("> ");
			std::cin >> escolhaLoja;
			switch(escolhaLoja){
				case '1':
					if (ouro >= 50) {
						escreverLento("Compraste o item misterioso!\n");
						escreverLento("O lojista entrega-te uma pocao de vida poderosa!\n");
						escreverLento("O lojista desaparece na escuridao, deixando-te com o item misterioso.\n");
						escreverLento("- 50 ouro\n");
						ouro -= 50;
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
			iniciarCombate(jogador, inimigos, inventario, nome);

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
