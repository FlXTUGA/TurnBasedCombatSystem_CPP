#pragma once

#include"Char.h"
#include"Inventario.h"
#include <string>
#include <vector>

void iniciarCombate(Char& jogador, std::vector<Char>& inimigos, Inventario& inventario, const std::string& nome);

void mostrarEstadoCombate(const Char& jogador, const std::vector<Char>& inimigos, const std::string& nome);
char turnoJogador(Char& jogador, std::vector<Char>& inimigos,Inventario& inventario, const std::string& nome);
void turnoInimigos(Char& jogador, std::vector<Char>& inimigos, char escolhaJogador);
void executarInventario(Char& jogador, Inventario& inventario);

bool haInimigosVivos(const std::vector<Char>& inimigos);
int escolherAlvo(const std::vector<Char>& inimigos);