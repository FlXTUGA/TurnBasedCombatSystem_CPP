#include "Menu.h"
#include "Char.h"
#include"Classe.h"

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

Classe escolherClasse() {

	char escolhaClasse;

	do {
		mudarCor(7);
		escreverLento("Escolha uma Classe: \n[1] Guerreiro  | +30 Hp | +5 Hit |\n[2] Arqueiro   | +10 Hp | +3 Hit |\n[3] Mago       | +0 Hp  | +10 Hit |\n> ");
		std::cin >> escolhaClasse;
		if (escolhaClasse != '1' && escolhaClasse != '2' && escolhaClasse != '3') {
			mudarCor(7);
			escreverLento("Opcao invalida. Tenta novamente.\n\n");
		}
	} while (escolhaClasse != '1' && escolhaClasse != '2' && escolhaClasse != '3');

	if (escolhaClasse== '1') return Classe::Guerreiro;
	if (escolhaClasse == '2') return Classe::Arqueiro;

	return Classe::Mago;
}

char mostrarMenuEReceberEscolha() {
	char escolha;

	do {
		mudarCor(7);
		escreverLento("Escolhe UMA opcao\n[1] Atacar \n[2] Defender\n[3] Inventario\n[4] Esperar\n> ");
		std::cin >> escolha;

		if (escolha != '1' && escolha != '2' && escolha != '3') {
			mudarCor(7);
			escreverLento("Opcao invalida. Tenta novamente.\n\n");
		}


	} while (escolha != '1' && escolha != '2' && escolha != '3');
	
	mudarCor(7);

	return escolha;

}