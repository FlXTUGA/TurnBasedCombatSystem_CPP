#include "Menu.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

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
	mudarCor(7);
	escreverLento("Inisira o seu Nome: ");
	std::this_thread::sleep_for(std::chrono::milliseconds(900)); //delay de texto de cima

	std::getline(std::cin, nome); // Escreveres o Teu nome
	return nome;
}

char mostrarMenuEReceberEscolha() {
	char escolha;

	do {
		mudarCor(7);
		escreverLento("Escolhe UMA opcao\n1) Atacar \n2) Defender\n3) Esperar\n> ");
		std::cin >> escolha;

		if (escolha != '1' && escolha != '2' && escolha != '3') {
			mudarCor(7);
			escreverLento("Opcao invalida. Tenta novamente.\n\n");
		}


	} while (escolha != '1' && escolha != '2' && escolha != '3');
	
	mudarCor(7);

	return escolha;

}