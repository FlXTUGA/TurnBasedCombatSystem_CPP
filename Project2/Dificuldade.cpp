#include "Dificuldade.h"

int getMultiplicador(Dificuldade d) {
    switch (d) {
    case Dificuldade::Facil:   return 1;
    case Dificuldade::Medio:   return 2;
    case Dificuldade::Dificil: return 3;
    }
    return 1;
}