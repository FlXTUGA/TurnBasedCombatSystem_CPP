#pragma once
#include <string>

//Mostra o menu de combate e devolve a escolha do jogador
char mostrarMenuEReceberEscolha();

//Muda a cor do texto na consola
void mudarCor(int cor);

// escreve texto lentamente para efeitos narrativos
void escreverLento(const std::string& texto, int delayMs = 45);

std::string escolherNome();