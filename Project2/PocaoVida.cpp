#include"PocaoVida.h"
#include "Char.h"

PocaoVida::PocaoVida(int cura)
    : Item("Pocao de Vida", TipoItem::Consumivel), cura(cura) {
}

void PocaoVida::usar(Char& jogador) {
    jogador.curar(cura);
}

bool PocaoVida::consomeAoUsar() const {
    return true;
}