#include "Inventario.h"
#include <iostream>
#include "Char.h"
#include"Menu.h"
#include <chrono>
#include <thread>

void Inventario::adicionar(std::unique_ptr<Item> item) {
    itens.push_back(std::move(item));
}

bool Inventario::vazio() const {
    return itens.empty();
}

void Inventario::mostrar() const {
    for (int i = 0; i < itens.size(); i++) {
     
      escreverLento(std::to_string(i + 1) + " - " + itens[i]->getNome()+ " - " + itens[i]->getDescricao() + "\n");
      
    }
}

void Inventario::usarItem(int indice, Char& jogador) {

    

    if (indice < 0 || indice >= itens.size()) {
        return;
    }

    int valorCurado = itens[indice]->usar(jogador);

    escreverLento("Usaste " + itens[indice]->getNome() +" (+ "+ std::to_string(valorCurado) + " HP)"  + "\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(900));
    

    if (itens[indice]->consomeAoUsar()) {
        itens.erase(itens.begin() + indice);
    }
    
}