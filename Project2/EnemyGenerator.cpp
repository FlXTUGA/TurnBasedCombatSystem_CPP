#include "EnemyGenerator.h"

#include <cstdlib>

std::vector<Char> enemyGenerator(int numeroSalas, Dificuldade dificuldadeAtual) {
    std::vector<Char> inimigos;

    int quantidadeInimigos = numeroSalas * getMultiplicador(dificuldadeAtual);

    for (int i = 0; i < quantidadeInimigos; i++) {
        Raca racaRandom = static_cast<Raca>(rand() % 3);

        int vida = 40;
        int dano = 10;

        inimigos.emplace_back(vida, dano, 0, racaRandom, Classe::Inimigos);
    }

    return inimigos;
}