#include "Game.h"

Game::Game(int id, int maxPlayers) {
	gameID = id;
	capacity = maxPlayers;
	players = new Player * [capacity];
	playerCount = 0;
}

Game::~Game() {
	delete[] players;
}

void Game::addPlayer(Player* player) {
	players[playerCount] = player;
	playerCount++;
}

void Game::startGame() {
	for (int i = 0; i < (playerCount-1); i++) {
		
			players[i]->fight(*(players[i + 1]));
		
	}
}
