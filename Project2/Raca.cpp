#include "Raca.h"

DadosRaca getDadosRaca(Raca r) {
    switch (r) {
    case Raca::Humano: return { 0, false, "Humano", 0 }; // VIda Bonus| Atacar 2x|Nome| Dano Bonus
    case Raca::Ogro: return { 10, false, "Ogro", 5 };
    case Raca::Esqueleto: return { -10, true, "Esqueleto", -3 };
    case Raca::Goblin: return{ -5, true, "Goblin", 0 };
    case Raca::Golem: return{ 30, false, "Golem", 10 };
    }
    return { 0, false, "Desconhecida", 0 };
}

