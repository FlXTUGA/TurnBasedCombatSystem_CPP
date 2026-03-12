#include "Raca.h"

DadosRaca getDadosRaca(Raca r) {
    switch (r) {
    case Raca::Humano: return { 0, false, "Humano", 0 };
    case Raca::Ogro: return { 20, false, "Ogro", 0 };
    case Raca::Esqueleto: return { -20, true, "Esqueleto", -5 };
    case Raca::Goblin: return{ -10, true, "Goblin", 0 };
    case Raca::Golem: return{ 30, false, "Golem", 10 };
    }
    return { 0, false, "Desconhecida", 0 };
}

