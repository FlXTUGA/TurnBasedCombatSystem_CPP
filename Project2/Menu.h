#pragma once
#include <string>
#include "Char.h"

//Mostra o menu de combate e devolve a escolha do jogador
char mostrarMenuEReceberEscolha();

//Muda a cor do texto na consola
void mudarCor(int cor);

// escreve texto lentamente para efeitos narrativos
void escreverLento(const std::string& texto, int delayMs = 45);

std::string escolherNome();

Classe escolherClasse();

void linha(int tamanho, char simbolo = '=');