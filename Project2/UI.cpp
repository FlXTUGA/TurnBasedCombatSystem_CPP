#include "UI.h"
#include "Character.h"
#include"PlayerClass.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

void linha(int tamanho, char simbolo ) {
	for (int i = 0; i < tamanho; i++) {
		std::cout << simbolo;
	}
	std::cout << "\n";
}
//escreve estilo undertale
void escreverLento(const std::string& texto, int delayMs)  {
	for (char c : texto) {
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
	}
}
// seleciono um numero dentro do terminal e mudo a cor do texto
void mudarCor(int cor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

std::string escolherNome() {
	
	std::cout << std::string(50, '\n'); // Serve para o texto começar na parte de baixo do terminal
	
	std::string nome;
	mudarCor(11);
	linha(40);
	std::cout << "         CRIACAO DE PERSONAGEM\n";
	linha(40);

	mudarCor(7);
	escreverLento("Inisira o seu nome: ");
	std::this_thread::sleep_for(std::chrono::milliseconds(900)); //delay de texto de cima

	std::getline(std::cin, nome); // Escreveres o Teu nome
	return nome;
}

Classe escolherClasse() {

	char escolhaClasse;

	do {
		mudarCor(7);
		escreverLento("Escolha uma Classe: \n[1] Guerreiro  | +30 Hp | +5 Hit |\n[2] Arqueiro   | +10 Hp | +3 Hit |\n[3] Mago       | +0 Hp  | +10 Hit |\n> ");
		std::cin >> escolhaClasse;
		if (escolhaClasse != '1' && escolhaClasse != '2' && escolhaClasse != '3') {
			mudarCor(7);
			escreverLento("Opcao invalida. Tenta novamente.\n\n");
		}
	} while (escolhaClasse != '1' && escolhaClasse != '2' && escolhaClasse != '3');

	if (escolhaClasse== '1') return Classe::Guerreiro;
	if (escolhaClasse == '2') return Classe::Arqueiro;

	return Classe::Mago;
}

char mostrarMenuEReceberEscolha() {
	char escolha;

	do {
		mudarCor(7);
		escreverLento("Escolhe UMA opcao\n[1] Atacar \n[2] Defender\n[3] Inventario\n[4] Esperar\n> ");
		std::cin >> escolha;

		if (escolha != '1' && escolha != '2' && escolha != '3' && escolha != '4') {
			mudarCor(7);
			escreverLento("Opcao invalida. Tenta novamente.\n\n");
		}


	} while (escolha != '1' && escolha != '2' && escolha != '3' && escolha!= '4');
	
	mudarCor(7);

	return escolha;

}

std::string criarTextoDano(const Char& personagem) {
	DadosRaca dadosRaca = getDadosRaca(personagem.getRaca());

	if (dadosRaca.ataqueDuplo) {
		return std::to_string(personagem.getDano()) + " x2";
	}

	return std::to_string(personagem.getDano());
}

int escolherItemInventario(const Inventario& inventario) {

	if (inventario.vazio()) {
		mudarCor(14);
		escreverLento("O inventario esta vazio.\n");
		return -1;
	}

	while (true) {

		int escolhaItem;

		mudarCor(11);
		escreverLento("Inventario:\n");

		inventario.mostrar();

		std::cout << "> ";
		std::cin >> escolhaItem;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			mudarCor(14);
			escreverLento("Opcao invalida.\n");
			continue;
		}

		if (escolhaItem == 0)
			return -1;

		int indice = escolhaItem - 1;

		if (indice < 0 || indice >= inventario.getQuantidadeItens()) {

			mudarCor(14);
			escreverLento("Item invalido. Tenta outra vez.\n");
			continue;
		}

		return indice;
	}
}

int escolherAlvo(const std::vector<Char>& inimigos) {
	int escolha;

	while (true)
	{
		mudarCor(11);
		escreverLento("Escolhe um inimigo para atacar:\n");

		for (int i = 0; i < inimigos.size(); i++)
		{
			std::cout << "[" << i + 1 << "] "
				<< inimigos[i].getNomeRaca()
				<< " (" << inimigos[i].getVida() << " HP)\n";
		}

		std::cout << "> ";
		std::cin >> escolha;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			mudarCor(14);
			escreverLento("Opcao invalida.\n");
			continue;
		}

		int indice = escolha - 1;

		if (indice < 0 || indice >= inimigos.size())
		{
			mudarCor(14);
			escreverLento("Inimigo invalido.\n");
			continue;
		}

		return indice;
	}
}

void mostrarResultadoAtaque(const ResultadoAtaque& resultado,const std::vector<Char>& inimigos,const std::string& nomeJogador)
{
	mudarCor(11);

	escreverLento(nomeJogador + " causou "
		+ std::to_string(resultado.danoCausado) + " de dano\n");

	if (resultado.alvoMorreu)
	{
		escreverLento(inimigos[resultado.indiceAlvo].getNomeRaca() + " morreu\n" );
	}
}

void textoInicial() {
	escreverLento(std::string(50, '\n'));
	mudarCor(14);
	escreverLento("\n\n\n\nA entrada da dungeon fecha-se atras de ti...\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	escreverLento("O ar e frio... e o silencio pesa nos corredores de pedra.\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	escreverLento("Das alguns passos na escuridao.\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

	escreverLento("De repente...\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(1200));

	escreverLento("Algo move-se nas sombras.\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));

}

std::string criarMensagemInimigos(const std::vector<Char>& inimigos) {
	if (inimigos.empty()) {
		return "Nao ha inimigos no caminho.\n";
	}

	if (inimigos.size() == 1) {
		return "Um " + inimigos[0].getNomeRaca() + " aparece no teu caminho.\n";
	}

	std::string mensagem;

	for (size_t i = 0; i < inimigos.size(); i++) {
		if (i == 0) {
			mensagem += "Um " + inimigos[i].getNomeRaca();
		}
		else if (i == inimigos.size() - 1) {
			mensagem += " e um " + inimigos[i].getNomeRaca();
		}
		else {
			mensagem += ", um " + inimigos[i].getNomeRaca();
		}
	}

	mensagem += " aparecem no teu caminho.\n";
	return mensagem;
}

void textoDefesa(const std::string& nomeJogador) {
	mudarCor(11);
	escreverLento(nomeJogador + " esta a defender-se!\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(900));
}

void executarEsperaJogador(const std::string& nome) {
	mudarCor(11);
	escreverLento(nome + " tu escolheste um caminho diferente\n");
	std::this_thread::sleep_for(std::chrono::milliseconds(800));
}

void mostrarEstadoCombate(const Char& jogador, const std::vector<Char>& inimigos, const std::string& nome, int ouro) {
	mudarCor(11);//azul
	ouro = 0;
	escreverLento("\nJogador: " + nome +
		" (" + jogador.getNomeRaca() + ") " +
		"   HP: " + std::to_string(jogador.getVida()) +
		"/" + std::to_string(jogador.getVidaMax()) +
		"   Dano: " + criarTextoDano(jogador) +"   "  + std::to_string(jogador.getOuro()) + " Gold" + "\n");
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

void mensagemDeInimigosMortos() {
	mudarCor(14);
	escreverLento("O inimigo cai.\nO silencio volta... Tu segues para a proxima sala e....\n");
}

void mostrarResultadoTurnoInimigos(const std::vector<ResultadoAtaqueInimigo>& resultados, char escolhaJogador) {
	if (escolhaJogador == '4') {
		mudarCor(12);
		escreverLento("O inimigo nao pensa o mesmo\n");
	}

	for (const auto& resultado : resultados) {
		mudarCor(12);
		escreverLento(resultado.nomeInimigo + " atacou!\n");
		escreverLento("O inimigo deu " + std::to_string(resultado.danoRecebido) + " de dano\n");

		if (resultado.houveReducao) {
			mudarCor(11);
			escreverLento("(Defesa) reduziu " + std::to_string(resultado.danoReduzido) + "\n");
		}
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(800));
}

