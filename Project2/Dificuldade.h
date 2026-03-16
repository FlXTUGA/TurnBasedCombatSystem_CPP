#pragma once

enum class Dificuldade {
    Facil,
    Medio,
    Dificil
};

int getMultiplicador(Dificuldade d);
Dificuldade obterDificuldade();