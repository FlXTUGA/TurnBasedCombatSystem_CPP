#include "Rooms.h"

#include "EnemyGenerator.h"
#include "UI.h"
#include "Combat.h"

std::vector<Rooms> rooms = {
    Rooms::Combate,
    Rooms::Combate,
    Rooms::Loja,
    Rooms::Boss
};

void createRooms(Char& jogador,
    Inventario& inventario,
    const std::string& nome,
    Dificuldade dificuldadeAtual)
{
    int numeroSalas = 1;

    int ouroGanho = 0;
    int ouro = 0;

    ouro = jogador.getOuro();

    for (Rooms room : rooms) {

        escreverLento("\nSala " + std::to_string(numeroSalas) + "\n");

        if (room == Rooms::Combate) {

            std::vector<Char> inimigos =
                enemyGenerator(numeroSalas, dificuldadeAtual);

            mostrarMensagemInimigos(inimigos);

            escreverLento("Prepara-te para lutar " + nome + "\n");

            iniciarCombate(jogador, inimigos, inventario, nome, jogador.getOuro());


            if (!haInimigosVivos(inimigos)) {
                int ouroGanho = 0;

                if (numeroSalas == 1) {
                    ouroGanho = 20;
                }
                else if (numeroSalas == 2) {
                    ouroGanho = 40;
                }

                jogador.adicionarOuro(ouroGanho);

                escreverLento("Ganhaste " + std::to_string(ouroGanho) +
                    " de ouro! Agora tens " + std::to_string(jogador.getOuro()) + " de ouro.\n");
            }
        }

        else if (room == Rooms::Loja) {
            escreverLento("Encontraste uma loja misteriosa...\n");
        }

        else if (room == Rooms::Boss) {

            std::vector<Char> boss;
            boss.emplace_back(150, 40, 10, Raca::Golem, Classe::Inimigos);

            escreverLento("O Boss da dungeon aparece!\n");

            iniciarCombate(jogador, boss, inventario, nome, jogador.getOuro());
        }

        if (jogador.getVida() <= 0) {
            break;
        }

        numeroSalas++;
    }
}