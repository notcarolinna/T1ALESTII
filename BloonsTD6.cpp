#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include "Partida.h"
#include "Reader.h"

void Jogo(const std::string arquivo, std::vector<std::pair<int, int>>& vencedores) {
	auto start = std::chrono::high_resolution_clock::now();

	Reader* dados = new Reader(arquivo);
	dados->Dados();

	std::cout << "Caso " << dados->getTotalMacaquinhos() << ": ";

	Macaquinho** macaquinhos = dados->getMacaquinhos();
	Partida partida(macaquinhos, *dados);
	partida.IniciarPartida();

	Macaquinho* vencedor = partida.Vencedor();
	vencedores.push_back(std::make_pair(vencedor->getMacacoVencedor(), vencedor->getCocos()));

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

	std::cout << std::fixed << std::setprecision(1) << duration.count() << " segundos." << std::endl;
}


int main()
{
	std::vector<std::pair<int, int>> vencedores;

	Jogo("caso0050.txt", vencedores);
	Jogo("caso0100.txt", vencedores);
	Jogo("caso0200.txt", vencedores);
	Jogo("caso0400.txt", vencedores);
	Jogo("caso0600.txt", vencedores);
	Jogo("caso0800.txt", vencedores);
	Jogo("caso0900.txt", vencedores);
	Jogo("caso1000.txt", vencedores);

	std::cout << "\nVencedores de cada caso:" << std::endl;
	for (auto& vencedor : vencedores) {
		std::cout << "Macaquinho #" << vencedor.first << " com " << vencedor.second << " cocos." << std::endl;
	}

	return 0;
}
