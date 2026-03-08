#include <iostream>
#include "Combat.h"
#include "Menu.h"      // escreverLento, mudarCor, mostrarMenuEReceberEscolha
#include "Char.h"
#include <vector>

#include <string>
#include <thread>
#include <chrono>

bool haInimigosVivos(const std::vector<Char>& inimigos) {
    for (int i = 0; i < inimigos.size(); i++) {
        if (inimigos[i].getVida() > 0) {
            return true;
        }
    }
    return false;
}

int escolherAlvo(const std::vector<Char>& inimigos) {
    int escolherI;

    do {
        escreverLento("Escolhe um inimigo para atacar:\n");

        for (int i = 0; i < inimigos.size(); i++) {
            if (inimigos[i].getVida() > 0) {
                escreverLento("[" + std::to_string(i + 1) + "] " +
                    inimigos[i].getNomeRaca() +
                    "   HP: " +
                    std::to_string(inimigos[i].getVida()) +
                    "/" +
                    std::to_string(inimigos[i].getVidaMax()) + "\n");
            }
        }
        escreverLento("\n");
        std::cin >> escolherI;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            escolherI = -1;
        }

    } while (escolherI < 1 || escolherI > inimigos.size() || inimigos[escolherI - 1].getVida() <= 0);

    return escolherI - 1;
}
    
void mostrarEstadoCombate(const Char& jogador, const std::vector<Char>& inimigos, const std::string& nome) {
    mudarCor(11);
    escreverLento("\nJogador: " + nome + " (" + jogador.getNomeRaca() + ") " + "   HP: " + std::to_string(jogador.getVida()) + "/" + std::to_string(jogador.getVidaMax()) + "\n");
    mudarCor(12);
    for (int i = 0; i < inimigos.size(); i++) {
        if (inimigos[i].getVida() > 0) {
            escreverLento(inimigos[i].getNomeRaca() + "   HP: " + std::to_string(inimigos[i].getVida()) + "/" + std::to_string(inimigos[i].getVidaMax()) + "\n");
        }
    }
}

char turnoJogador(Char& jogador, std::vector<Char>& inimigos, const std::string& nome) {

    char escolha = mostrarMenuEReceberEscolha();

    switch (escolha) {
        case '1': {
            int escolherI; // escolher inimigo
            mudarCor(11);// cor azul
            escreverLento(nome + " tu escolheste atacar\n");

            escolherI = escolherAlvo(inimigos);
            jogador.ataque(inimigos[escolherI]);
            escreverLento(nome + " tu deste " + std::to_string(jogador.getDano()) + " de Dano\n");
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
    return escolha;
}

void turnoInimigos(Char& jogador, std::vector<Char>& inimigos, char escolhaJogador) {
    if (escolhaJogador == '3') {
        mudarCor(12);
        escreverLento("O inimigo nao pensa o mesmo\n");
    }

    for (int i = 0; i < inimigos.size(); i++) {
        if (inimigos[i].getVida() > 0) {
            int danoInimigo = inimigos[i].getDano();
            int danoFinalInimigo = danoInimigo - jogador.getDefesa();
            if (danoFinalInimigo < 0) {
                danoFinalInimigo = 0;
            }
            if (escolhaJogador == '2') {

                int reduzido = danoInimigo - danoFinalInimigo;

                if (danoFinalInimigo < 0) { danoFinalInimigo = 0; }
                mudarCor(12);

                inimigos[i].ataque(jogador);
                escreverLento(inimigos[i].getNomeRaca() + " atacou!\n");
                escreverLento("O inimigo deu " + std::to_string(danoFinalInimigo) + " de Dano\n");

                mudarCor(11);
                escreverLento("(Defesa) reduziu " + std::to_string(reduzido) + "\n");

            }
            else {

                inimigos[i].ataque(jogador);
                mudarCor(12);

                if (inimigos[i].getRaca() == Raca::Esqueleto) {
                    escreverLento("O " + inimigos[i].getNomeRaca() + " deu " + std::to_string(2 * inimigos[i].getDano()) + " de dano\n");
                }
                else {
                    escreverLento("O " + inimigos[i].getNomeRaca() + " deu " + std::to_string(inimigos[i].getDano()) + " de dano\n");
                }
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
}

void iniciarCombate(Char& jogador, std::vector<Char>& inimigos, const std::string& nome) {
    
    while (jogador.getVida() > 0 && haInimigosVivos(inimigos)) {
   
        mostrarEstadoCombate(jogador, inimigos, nome);
   
        char escolha = turnoJogador(jogador, inimigos, nome);
        
        turnoInimigos(jogador, inimigos, escolha);
        
        jogador.fimTurno();

        if (jogador.getVida() == 0) {
            mudarCor(14);
            escreverLento(nome + "... a escuridao da dungeon consumiu-te.\n");
        }
        if (!haInimigosVivos(inimigos)) {
                mudarCor(14);
                escreverLento("O inimigo cai.\nO silencio volta... mas algo ainda se move na escuridao.\n");
        }
        mudarCor(7);
    }
}