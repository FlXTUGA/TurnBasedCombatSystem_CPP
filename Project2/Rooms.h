#pragma once

#include <vector>
#include <string>

#include "Character.h"
#include "Inventario.h"
#include "Dificuldade.h"

enum class Rooms {
    Combate,
    Loja,
    Boss
};

void createRooms(Char& jogador,
    Inventario& inventario,
    const std::string& nome,
    Dificuldade dificuldadeAtual);