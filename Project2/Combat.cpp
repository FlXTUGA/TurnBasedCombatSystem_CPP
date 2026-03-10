#include "Combat.h"
#include "Menu.h"
#include <iostream>
#include <thread>
#include <chrono>

std::string criarTextoDano(const Char& personagem) {
        DadosRaca dados = getDadosRaca(personagem.getRaca());

        if (dados.ataqueDuplo) {
            return std::to_string(personagem.getDano()) + " x2";
        }

        return std::to_string(personagem.getDano());
}

void executarInventario(Char& jogador, Inventario& inventario) {
    if (inventario.vazio()) {
        mudarCor(14);
        escreverLento("O inventario esta vazio.\n");
        return;
    }
    mudarCor(11);
    escreverLento("Inventario:\n");
    inventario.mostrar();

    int escolhaItem;
    std::cout << "> ";
    std::cin >> escolhaItem;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        mudarCor(14);
        escreverLento("Opcao invalida.\n");
        return;
    }

    inventario.usarItem(escolhaItem - 1, jogador);

}

void executarAtaqueJogador(Char& jogador, std::vector<Char>& inimigos, const std::string& nome) {
    int escolherI; // escolher inimigo
    mudarCor(11);// cor azul
    escreverLento(nome + " tu escolheste atacar\n");

    escolherI = escolherAlvo(inimigos);

    int vidaAntes = inimigos[escolherI].getVida();
    jogador.ataque(inimigos[escolherI]);
    int danoCausado = vidaAntes - inimigos[escolherI].getVida();

    mudarCor(11);
    escreverLento(nome + " tu deste " + std::to_string(danoCausado) + " de dano\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    if (inimigos[escolherI].getVida() <= 0) {
        escreverLento(inimigos[escolherI].getNomeRaca() + " morreu\n");
    }
}
void executarDefesaJogador(Char& jogador, const std::string& nome) {

    jogador.defender();
    mudarCor(11);
    escreverLento(nome + " tu estas em modo Defesa!\n");

}
void executarEsperaJogador(const std::string& nome) {
    mudarCor(11);
    escreverLento(nome + " tu escolheste um caminho diferente\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
}

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
    mudarCor(7);//Branco
    do {
        escreverLento("Escolhe um inimigo para atacar:\n");
        mudarCor(12);//Vermelho
        for (int i = 0; i < inimigos.size(); i++) {
            if (inimigos[i].getVida() > 0) {
       

                escreverLento("[" + std::to_string(i + 1) + "] " +
                    inimigos[i].getNomeRaca() +
                    "   HP: " +
                    std::to_string(inimigos[i].getVida()) +
                    "/" +
                    std::to_string(inimigos[i].getVidaMax()) +
                    "   Dano: " + criarTextoDano(inimigos[i]) + "\n");
            }
        }
        mudarCor(11);
        std::cout << "> ";
        std::cin >> escolherI;
        mudarCor(7);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            escolherI = -1;
        }

    } while (escolherI < 1 || escolherI > inimigos.size() || inimigos[escolherI - 1].getVida() <= 0);

    return escolherI - 1;
}
    
void mostrarEstadoCombate(const Char& jogador, const std::vector<Char>& inimigos, const std::string& nome) {
    mudarCor(11);//azul
    escreverLento("\nJogador: " + nome + 
        " (" + jogador.getNomeRaca() + ") " + 
        "   HP: " + std::to_string(jogador.getVida()) +
        "/" + std::to_string(jogador.getVidaMax()) +
        "   Dano: "+ criarTextoDano(jogador) + "\n");
    mudarCor(12);//vermelho
    for (int i = 0; i < inimigos.size(); i++) {
        if (inimigos[i].getVida() > 0) {
         
            escreverLento(inimigos[i].getNomeRaca() +
                "   HP: " + std::to_string(inimigos[i].getVida()) + 
                "/" + std::to_string(inimigos[i].getVidaMax()) +
                "   Dano: " + criarTextoDano(inimigos[i]) + "\n");
        }
    }
}

char turnoJogador(Char& jogador, std::vector<Char>& inimigos,Inventario& inventario, const std::string& nome) {

    char escolha = mostrarMenuEReceberEscolha();

    switch (escolha) {
        case '1': {
            executarAtaqueJogador(jogador, inimigos, nome);
            break;
        }
        case '2': {
            executarDefesaJogador(jogador, nome);
            break;
        }
        case '3': {
            executarInventario(jogador, inventario);
            break;
        }

        case '4': {
            executarEsperaJogador(nome);
            break;
        }
        default:
            mudarCor(14);
            escreverLento("Opcao invalida.\n");
            break;
    }
    return escolha;
}

void turnoInimigos(Char& jogador, std::vector<Char>& inimigos, char escolhaJogador) {
    if (escolhaJogador == '4') {
        mudarCor(12);
        escreverLento("O inimigo nao pensa o mesmo\n");
    }

    for (int i = 0; i < inimigos.size(); i++) {
        if (inimigos[i].getVida() > 0) {
            DadosRaca dados = getDadosRaca(inimigos[i].getRaca());

            int danoBruto = inimigos[i].getDano();
            if (dados.ataqueDuplo) {
                danoBruto *= 2;
            }

            int vidaAntes = jogador.getVida();
            inimigos[i].ataque(jogador);
            int danoRecebido = vidaAntes - jogador.getVida();

            mudarCor(12);
            escreverLento(inimigos[i].getNomeRaca() + " atacou!\n");
            escreverLento("O inimigo deu " + std::to_string(danoRecebido) + " de dano\n");

            if (escolhaJogador == '2') {
                int reduzido = danoBruto - danoRecebido;
                if (reduzido < 0) {
                    reduzido = 0;
                }

                mudarCor(11);
                escreverLento("(Defesa) reduziu " + std::to_string(reduzido) + "\n");
            }
        }
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(800));
}

void iniciarCombate(Char& jogador, std::vector<Char>& inimigos, Inventario& inventario, const std::string& nome) {
    
    while (jogador.getVida() > 0 && haInimigosVivos(inimigos)) {
   
        mostrarEstadoCombate(jogador, inimigos, nome);
   
        char escolha = turnoJogador(jogador, inimigos, inventario, nome);
        
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