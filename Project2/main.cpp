#include <iostream>
#include <string>
#include <thread>
#include <chrono>

class Char {

private:
	int const vidaMax;
	int  vidaAtual;

	int  const dano;
	bool estaDefendendo;
	int valorDefesa;

	int bonusDano;
	
public:
	Char(int vida, int dano, int defesa) : vidaMax(vida), dano(dano), valorDefesa(defesa), estaDefendendo(false), vidaAtual(vidaMax), bonusDano(0) {}
	
	void fimTurno() {
		estaDefendendo = false;
	}
	void defender() {
		estaDefendendo = true;
	}

	void ataque(Char& alvo) {
		alvo.receberDano(getDano());
	}
	void receberDano(int valor) {

		if (estaDefendendo) {
			if (valor < 0) { valor = 0; }
			valor -= valorDefesa;
		}
		vidaAtual -= valor;
		if (vidaAtual < 0) {vidaAtual = 0;}
	}

	int getVida() const { return vidaAtual; }
	int getDano() const { return dano + bonusDano; }
	int getVidaMax() const { return vidaMax; }
	int getDefesa() const { return valorDefesa; }
};

void escreverLento(const std::string& texto, int delayMs = 45) {
	for (char c : texto) {
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
	}
}

int main() {
	std::cout << std::string(50, '\n');
	char escolha;
	std::string nome;
	Char jogador(100, 20, 15), 
		 inimigo(100, 10, 0);

	int danoOrigina = inimigo.getDano();
	int danoFinal = inimigo.getDano() - jogador.getDefesa();
	int reduzido = danoOrigina - danoFinal;

	escreverLento("Inisira o seu Nome: ");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));
	std::getline(std::cin, nome);
	while(jogador.getVida()>0 && inimigo.getVida() > 0){
		escreverLento(
			"\nJogador: " + nome + "   HP: " + std::to_string(jogador.getVida()) + "/" + std::to_string(jogador.getVidaMax()) + "\n" +
			"Inimigo: Rogerio   HP: " + std::to_string(inimigo.getVida()) + "/" + std::to_string(inimigo.getVidaMax()) + "\n" +
			"Escolhe UMA opcao\n1) Atacar \n2) Defender\n3) Esperar\n> "
		);
		std::cin >> escolha;
		switch (escolha) {
			case'1': {
				jogador.ataque(inimigo);
				escreverLento("O jogador atacou!\n");
				std::this_thread::sleep_for(std::chrono::milliseconds(800));
				break;
			}
			case'2': {
				jogador.defender();
				escreverLento("(Defesa) reduziu " + std::to_string(reduzido) + "\n");
				break;
			}
			case'3': {
				escreverLento(nome + " tu nao tens inimgios, ninguem tem inimigos\n");
				std::this_thread::sleep_for(std::chrono::milliseconds(800));
				break;
			}
			default: break;
		}
		inimigo.ataque(jogador);
		escreverLento("O inimigo atacou!\n");
		std::this_thread::sleep_for(std::chrono::milliseconds(900));
		jogador.fimTurno();
		
	}
}