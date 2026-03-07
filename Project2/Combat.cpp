#include <iostream>
#include "Combat.h"
#include "Menu.h"      // escreverLento, mudarCor, mostrarMenuEReceberEscolha
#include <string>
#include <thread>
#include <chrono>



void iniciarCombate(Char& jogador, Char& inimigo, const std::string& nome) {
  

    while (jogador.getVida() > 0 && inimigo.getVida() > 0) {
        mudarCor(11);
        escreverLento("\nJogador: " + nome + "   HP: " + std::to_string(jogador.getVida()) + "/" + std::to_string(jogador.getVidaMax()) + "\n" );
        mudarCor(12);
        escreverLento("Inimigo: Rogerio   HP: " + std::to_string(inimigo.getVida()) + "/" + std::to_string(inimigo.getVidaMax()) + "\n");

        // em vez de std::cin >> escolha;
        char escolha = mostrarMenuEReceberEscolha();

        switch (escolha) {
        case '1': {
            jogador.ataque(inimigo);
            mudarCor(11);
            escreverLento(nome + " tu escolheste atacar\n");
            escreverLento(nome + " tu deste " + std:: to_string(jogador.getDano()) + " de Dano\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
            break;
        }
        case '2': {
            jogador.defender();
            mudarCor(11);
            escreverLento(nome + " tu estas em modo Defesa!\n");
            break;
        }
        case '3': {
            mudarCor(11);
            escreverLento(nome + " tu escolheste um caminho diferente\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
            break;
        }
        }

        if (escolha == '3') {
            mudarCor(12);
            escreverLento("O inimigo nao pensa o mesmo\n");
        }
        
        int danoInimigo = inimigo.getDano();
        int danoFinalInimigo = danoInimigo - jogador.getDefesa();



        if (escolha == '2') {
            
            int reduzido = danoInimigo - danoFinalInimigo;

            if (danoFinalInimigo < 0) { danoFinalInimigo = 0; }
            mudarCor(12);
            inimigo.ataque(jogador);
            escreverLento("O inimigo atacou!\n");
            escreverLento("O inimigo deu " + std::to_string(danoFinalInimigo) + " de Dano\n");

            mudarCor(11);
            escreverLento("(Defesa) reduziu " + std::to_string(reduzido) + "\n");
        }
        else {
            inimigo.ataque(jogador);
            mudarCor(12);
            escreverLento("O inimigo atacou!\n");
            escreverLento("O inimigo deu " + std::to_string(inimigo.getDano()) + " de dano\n");
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        jogador.fimTurno();

        if (jogador.getVida() == 0) {
            mudarCor(14);
            escreverLento(nome + "... a escuridao da dungeon consumiu-te.\n");
        }
        if (inimigo.getVida() == 0) {
            mudarCor(14);
            escreverLento("O inimigo cai.\nO silencio volta... mas algo ainda se move na escuridao.\n");
        }

        mudarCor(7);
    }
}