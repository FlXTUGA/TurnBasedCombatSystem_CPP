#include "Dificuldade.h"
#include "UI.h"

#include <iostream>
#include <limits>

int getMultiplicador(Dificuldade d) {
    switch (d) {
    case Dificuldade::Facil:   return 1;
    case Dificuldade::Medio:   return 2;
    case Dificuldade::Dificil: return 3;
    }
    return 1;
}

Dificuldade obterDificuldade() {
    Dificuldade dificuldadeAtual = escolherDificuldade();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return dificuldadeAtual;
}