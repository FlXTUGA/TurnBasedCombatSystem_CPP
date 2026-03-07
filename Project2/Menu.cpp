#include "Menu.h"
#include "Char.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

void linha(int tamanho, char simbolo ) {
	for (int i = 0; i < tamanho; i++) {
		std::cout << simbolo;
	}
	std::cout << "\n";
}

void escreverLento(const std::string& texto, int delayMs)  {
	for (char c : texto) {
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
	}
}

void mudarCor(int cor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

std::string escolherNome() {
	
	std::cout << std::string(50, '\n'); // Serve para o texto começar na parte de baixo do terminal
	
	std::string nome;
	mudarCor(11);
	linha(40);
	std::cout << "         CRIACAO DE PERSONAGEM\n";
	linha(40);

	mudarCor(7);
	escreverLento("Inisira o seu nome: ");
	std::this_thread::sleep_for(std::chrono::milliseconds(900)); //delay de texto de cima

	std::getline(std::cin, nome); // Escreveres o Teu nome
	return nome;
}

Raca escolherRaca() {

	char escolhaRaca;

	do {
		mudarCor(7);
		escreverLento("Escolha uma raca: \n[1] Humano  - equilibrado\n[2] Ogro   +20 vida\n[3] Esqueleto  -20 vida, ataque duplo\n> ");
		std::cin >> escolhaRaca;
		if (escolhaRaca != '1' && escolhaRaca != '2' && escolhaRaca != '3') {
			mudarCor(7);
			escreverLento("Opcao invalida. Tenta novamente.\n\n");
		}
	} while (escolhaRaca != '1' && escolhaRaca != '2' && escolhaRaca != '3');

	if (escolhaRaca == '1') return Raca::Humano;
	if (escolhaRaca == '2') return Raca::Ogro;

	return Raca::Esqueleto;
}

char mostrarMenuEReceberEscolha() {
	char escolha;

	do {
		mudarCor(7);
		escreverLento("Escolhe UMA opcao\n[1] Atacar \n[2] Defender\n[3] Esperar\n> ");
		std::cin >> escolha;

		if (escolha != '1' && escolha != '2' && escolha != '3') {
			mudarCor(7);
			escreverLento("Opcao invalida. Tenta novamente.\n\n");
		}


	} while (escolha != '1' && escolha != '2' && escolha != '3');
	
	mudarCor(7);

	return escolha;

}