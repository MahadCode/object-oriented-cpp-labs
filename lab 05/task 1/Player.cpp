#include "Player.h"

Player::Player() {
	playerID = 0;
	name = "null";
	score = 0;
	level = 1;
	health = 100;

}
Player::Player(int id,string n) {
	playerID = id;
	name = n;
	score = 0;
	level = 1;
	health = 100;

}

Player::~Player() {
	
	cout << "Player has deleted" << endl;
}

Player* Player::fight(Player oponent) {
	if (this->score > oponent.score) {
		score = score + 5;
		health = health - 5;
		playerStats.recordWin();
		oponent.playerStats.recordLoss();
		return (this);
		
	}
	else if (oponent.score > this->score) {
		score = score + 5;
		health=health-5;
		playerStats.recordLoss();
		oponent.playerStats.recordWin();
		return (&oponent);
	}
	else {
		if (this->health > oponent.health) {
			score = score + 5;
			health = health - 5;
			playerStats.recordWin();
			oponent.playerStats.recordLoss();
			return (this);

		}
		else if (oponent.health > this->health) {
			score = score + 5;
			health = health - 5;
			playerStats.recordLoss();
			oponent.playerStats.recordWin();
			return &oponent;
		}
		else {
			playerStats.matchPlayed++;
			oponent.playerStats.matchPlayed++;
			return nullptr;
		}
	}
}

void Player::train() {
	score = score +5;
	level++;
}


bool Player::operator < (const Player& temp) {
	if (this->score < temp.score) {
		return true;
	}
	return false;
}

bool Player::operator == (const Player& temp) {
	if (this->playerID == temp.playerID) {
		return true;
	}
	return false;
}

Stats Player::getStats() {
	return playerStats;
}