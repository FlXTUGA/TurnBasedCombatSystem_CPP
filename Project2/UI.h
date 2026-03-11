#pragma once
#include "Character.h"
#include "Combat.h"

#include <string>
#include<vector>

//Mostra o menu de combate e devolve a escolha do jogador
char mostrarMenuEReceberEscolha();

//Muda a cor do texto na consola
void mudarCor(int cor);

// escreve texto lentamente para efeitos narrativos
void escreverLento(const std::string& texto, int delayMs = 45);

std::string escolherNome();

Classe escolherClasse();

void linha(int tamanho, char simbolo = '=');

std::string criarTextoDano(const Char& personagem);

int escolherItemInventario(const Inventario& inventario);

int escolherAlvo(const std::vector<Char>& inimigos);

void mostrarResultadoAtaque(const ResultadoAtaque& resultado, const std::vector<Char>& inimigos, const std::string& nomeJogador);

void textoInicial();

std::string criarMensagemInimigos(const std::vector<Char>& inimigos);

void textoDefesa(const std::string& nomeJogador);

void executarEsperaJogador(const std::string& nome);

void mostrarEstadoCombate(const Char& jogador, const std::vector<Char>& inimigos, const std::string& nome);

void mensagemDeInimigosMortos();

void mostrarResultadoTurnoInimigos(const std::vector<ResultadoAtaqueInimigo>& resultados, char escolhaJogador);
