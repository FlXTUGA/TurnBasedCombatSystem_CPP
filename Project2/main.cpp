#include <iostream>
#include <string>
#include <string>
#include <thread>
#include <chrono>

#include "Char.h"
#include "Combat.h"
#include "Menu.h"

int main() {

	Char jogador(100, 20, 15),
		 inimigo(60, 20, 0);



	std::string nome = escolherNome();

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

	mudarCor(12);
	escreverLento("Um inimigo aparece no teu caminho.\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	mudarCor(7);
	escreverLento("Prepara-te para lutar " + nome + "\n");

	iniciarCombate(jogador, inimigo, nome);
	
	return 0;
}
