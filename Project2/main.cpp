#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

#include "Char.h"
#include "Combat.h"
#include "Menu.h"
#include "PocaoVida.h"

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

	std::string nome = escolherNome();
	Raca racaJogador = escolherRaca();
	std::vector<Char> inimigos;

	Char jogador(100, 30, 15, racaJogador);
		 
	inimigos.push_back(Char(40, 10, 0, Raca::Esqueleto));
	inimigos.push_back(Char(40, 10, 5, Raca::Esqueleto));
	inimigos.push_back(Char(50, 30, 0, Raca::Ogro));

	Inventario inventario;

	inventario.adicionar(std::make_unique<PocaoVida>(40));
	inventario.adicionar(std::make_unique<PocaoVida>(50));

	//textoInicial();
	mudarCor(12);//Vermelho
	escreverLento(criarMensagemInimigos(inimigos));

	mudarCor(7);
	escreverLento("Prepara-te para lutar " + nome + "\n");

	iniciarCombate(jogador, inimigos,inventario, nome);

	return 0;
}
