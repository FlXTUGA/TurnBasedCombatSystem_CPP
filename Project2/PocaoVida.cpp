#include"PocaoVida.h"
#include "Char.h"
#include <string>
PocaoVida::PocaoVida(int cura)
    : Item("Pocao de Vida", TipoItem::Consumivel), cura(cura) {
}

int PocaoVida::usar(Char& jogador) {
    return jogador.curar(cura);
}

bool PocaoVida::consomeAoUsar() const {
    return true;
}

std::string PocaoVida::getDescricao() const {
    return " (cura " + std::to_string(cura) + " HP)";
}
