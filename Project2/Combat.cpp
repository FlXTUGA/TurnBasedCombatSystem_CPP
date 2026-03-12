#include "Combat.h"
#include "UI.h"

#include <iostream>
#include <thread>
#include <chrono>

void executarInventario(Char& jogador, Inventario& inventario) {

    int indice = escolherItemInventario(inventario);

	//ao inserir um numero invalido, a funcao retorna -1, entao so continuamos se for diferente disso
    if (indice == -1)
        return;

    inventario.usarItem(indice, jogador);
}
// O jogador ataca o inimigo selecionado e retorna o resultado do ataque
ResultadoAtaque executarAtaqueJogador(Char& jogador, std::vector<Char>& inimigos, int indiceAlvo) {
    int vidaAntes = inimigos[indiceAlvo].getVida();
    jogador.ataque(inimigos[indiceAlvo]);
    int danoCausado = vidaAntes - inimigos[indiceAlvo].getVida();
    bool morreu = inimigos[indiceAlvo].getVida() <= 0;

    return { danoCausado, morreu, indiceAlvo };
}

void executarDefesaJogador(Char& jogador, const std::string& nome) {

    jogador.defender();
	textoDefesa(nome);

}

char turnoJogador(Char& jogador, std::vector<Char>& inimigos, Inventario& inventario, const std::string& nome) {
    char escolha;
    while (true) {

        escolha = mostrarMenuEReceberEscolha();

        switch (escolha) {
        case '1': {
            int indiceAlvo = escolherAlvo(inimigos);

            ResultadoAtaque resultado = executarAtaqueJogador(jogador, inimigos, indiceAlvo);

            mostrarResultadoAtaque(resultado, inimigos, nome);
            return escolha;
        }
        case '2': {
            executarDefesaJogador(jogador, nome);
            return escolha;
        }
        case '3': {
            executarInventario(jogador, inventario);
            continue;
        }

        case '4': {
            executarEsperaJogador(nome);
            return escolha;
        }
        default:
            mudarCor(14);
            escreverLento("Opcao invalida.\n");
            continue;
        }
    }
    return escolha;
}

// Verifica se ainda há inimigos vivos
bool haInimigosVivos(const std::vector<Char>& inimigos) {
    for (int i = 0; i < inimigos.size(); i++) {
        if (inimigos[i].getVida() > 0) {
            return true;
        }
    }
    return false;
}
// Os inimigos atacam o jogador e retorna um vetor com os resultados de cada ataque
std::vector<ResultadoAtaqueInimigo> turnoInimigos(Char& jogador, std::vector<Char>& inimigos, char escolhaJogador) {
    std::vector<ResultadoAtaqueInimigo> resultados;

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

            int reduzido = 0;
            bool houveReducao = false;

            if (escolhaJogador == '2') {
                reduzido = danoBruto - danoRecebido;
                if (reduzido < 0) {
                    reduzido = 0;
                }

                houveReducao = true;
            }

            resultados.push_back({
                inimigos[i].getNomeRaca(),
                danoRecebido,
                reduzido,
                houveReducao
                });
        }
    }

    return resultados;
}

void iniciarCombate(Char& jogador, std::vector<Char>& inimigos, Inventario& inventario, const std::string& nome, int ouro) {
    
    while (jogador.getVida() > 0 && haInimigosVivos(inimigos)) {
   
        mostrarEstadoCombate(jogador, inimigos, nome, ouro);
   
        char escolha = turnoJogador(jogador, inimigos, inventario, nome);
        
        std::vector<ResultadoAtaqueInimigo> resultadosInimigos =
            turnoInimigos(jogador, inimigos, escolha);

        mostrarResultadoTurnoInimigos(resultadosInimigos, escolha);
        
        jogador.fimTurno();

        if (!haInimigosVivos(inimigos)) {
			mensagemDeInimigosMortos();
        }
        mudarCor(7);
    }
}