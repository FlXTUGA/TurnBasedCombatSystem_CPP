#pragma once

#include"Char.h"
#include <string>
#include <vector>

void iniciarCombate(Char& jogador, std::vector<Char>& inimigos, const std::string& nome);

bool haInimigosVivos(const std::vector<Char>& inimigos);
int escolherAlvo(const std::vector<Char>& inimigos);