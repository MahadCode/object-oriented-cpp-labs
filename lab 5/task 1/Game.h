#pragma once
#include"Player.h"



class Game
{
	int gameID;
	Player** players;
	int playerCount;
	int capacity;

public:
	Game(int id, int maxPlayers);
	~Game();
	void addPlayer(Player* player);
	void startGame();

};

