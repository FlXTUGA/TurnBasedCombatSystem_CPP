#include "Raca.h"

DadosRaca getDadosRaca(Raca r) {
    switch (r) {
    case Raca::Humano: return { 0, false, "Humano", 0 };
    case Raca::Ogro: return { 20, false, "Ogro", 0 };
    case Raca::Esqueleto: return { -20, true, "Esqueleto", -5 };
    }
    return { 0, false, "Desconhecida", 0 };
}

