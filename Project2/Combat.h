#pragma once

#include"Character.h"
#include"Inventario.h"

#include <string>
#include <vector>

struct ResultadoAtaque {
    int danoCausado;
    bool alvoMorreu;
    int indiceAlvo;
};

struct ResultadoAtaqueInimigo {
    std::string nomeInimigo;
    int danoRecebido;
    int danoReduzido;
    bool houveReducao;
};

void iniciarCombate(Char& jogador, std::vector<Char>& inimigos, Inventario& inventario, const std::string& nome);

void mostrarEstadoCombate(const Char& jogador, const std::vector<Char>& inimigos, const std::string& nome);
char turnoJogador(Char& jogador, std::vector<Char>& inimigos,Inventario& inventario, const std::string& nome);
std::vector<ResultadoAtaqueInimigo> turnoInimigos(Char& jogador, std::vector<Char>& inimigos, char escolhaJogador);

ResultadoAtaque executarAtaqueJogador(Char& jogador, std::vector<Char>& inimigos, int indiceAlvo);
void executarInventario(Char& jogador, Inventario& inventario);

bool haInimigosVivos(const std::vector<Char>& inimigos);
int escolherAlvo(const std::vector<Char>& inimigos);

