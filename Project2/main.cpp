#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>

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
			valor -= valorDefesa;
		}
		if (valor < 0) { valor = 0; }
		vidaAtual -= valor;
		if (vidaAtual < 0) { vidaAtual = 0; }
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

void mudarCor(int cor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

int main() {
	std::cout << std::string(50, '\n');
	char escolha;
	std::string nome;
	Char jogador(100, 60, 15),
		 inimigo(60, 20, 0);
	//Calcular dano de defesa
	int danoOrigina = inimigo.getDano();
	int danoFinal = inimigo.getDano() - jogador.getDefesa();
	int reduzido = danoOrigina - danoFinal;

	escreverLento("Inisira o seu Nome: ");
	std::this_thread::sleep_for(std::chrono::milliseconds(900)); //delay de texto de cima

	std::getline(std::cin, nome); // Escreveres o Teu nome

	while (jogador.getVida() > 0 && inimigo.getVida() > 0) {
		escreverLento(
			"\nJogador: " + nome + "   HP: " + std::to_string(jogador.getVida()) + "/" + std::to_string(jogador.getVidaMax()) + "\n" +
			"Inimigo: Rogerio   HP: " + std::to_string(inimigo.getVida()) + "/" + std::to_string(inimigo.getVidaMax()) + "\n" +
			"Escolhe UMA opcao\n1) Atacar \n2) Defender\n3) Esperar\n> "
		);
		std::cin >> escolha;
		switch (escolha) {
		case'1': {
			jogador.ataque(inimigo);
			mudarCor(9);//Azul
			escreverLento("O jogador atacou!\n");
			std::this_thread::sleep_for(std::chrono::milliseconds(800));
			break;
		}
		case'2': {
			jogador.defender();
			mudarCor(9);//Azul
			escreverLento(nome+" tu estas em modo Defesa!\n");
			break;
		}
		case'3': { // Não faz nada só manda mensagem
			mudarCor(9);//Azul
			escreverLento(nome + " tu escolheste um caminho diferente\n");
			std::this_thread::sleep_for(std::chrono::milliseconds(800));
			break;
		}
		default: break;
		}

		if (escolha == '3') {
			mudarCor(12);//vermelho
			escreverLento("O inimigo nao pensa o mesmo\n");
		}
		inimigo.ataque(jogador); //futuramente adicionar um if de se o jogador esperou então o inimigo diz uma frase contraria ao que o jogador escolheu a cima
		mudarCor(12);//vermelho
		escreverLento("O inimigo atacou!\n");
		if (escolha == '2') {
			mudarCor(9);//Azul
			escreverLento("(Defesa) reduziu " + std::to_string(reduzido) + "\n");
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
		
		jogador.fimTurno();

		if (jogador.getVida() == 0) {
			mudarCor(12);//vermelho
			escreverLento(nome + "... a escuridao da dungeon consumiu-te.\n");
		}
		if (inimigo.getVida() == 0) {
			mudarCor(9);//Azul
			escreverLento("O inimigo cai. \nO silencio volta... mas algo ainda se move na escuridao.\n");
		}
		mudarCor(7);
	}
}
