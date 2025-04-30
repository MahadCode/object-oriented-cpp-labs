#include<iostream>
#include"Player.h"
#include"Game.h"
#include"Stats.h"
using namespace std;

ostream& operator << (ostream& os,Player& curr) {
	os << "Player's ID: " << curr.playerID << endl;
	os << "Player's Name: " << curr.name << endl;
	os << "Player's Score:" << curr.score << endl;
	os << "Player's Health: " << curr.health << endl;
	os << "Player's Level: " << curr.level << endl;
	cout << "Player's States: " << endl;
	curr.getStats().displayStats();
	return os;
}

istream& operator >> (istream& is, Player& curr) {
	cout << "Enter Players'ID:" << endl;
	is >> curr.playerID;
	cout << "Enter Player's Name" << endl;
	is >> curr.name;
	cout << endl;
	return is;
}

bool arePlayersCompatible(const Player& p1, const Player& p2) {
	int diff = (p1.score - p2.score);
	if (diff < 0) {
		diff = -diff;
	}
	if (diff<20) {
		return true;
	}
	return false;
}

int main() {
	int n;
	cout << "Enter how many Players you want to create(atleast 2): " << endl;
	while (true) {
		cin >> n;
		if (n >= 2) {
			break;
		}
	}

	Player* list = new Player[n];
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	Game g1(123, n);

	cout << "Adding Players " << endl << endl;

	for (int i = 0; i < n; i++) {
		g1.addPlayer(&list[i]);
	}

	while (true) {
		cout << "1 for StartGame:" << endl;
		cout << "2 for Train Player:" << endl;
		cout << "3 for Description of Player" << endl;
		cout << "other for end" << endl;
		int count;
		cin >> count;
		if (count == 1) {
			g1.startGame();
			cout << "All players has fighted" << endl;
			cout << endl;
		}
		else if (count == 2) {
			cout << "Players list " << endl;
			for (int i = 0; i < n; i++) {
				cout << i + 1 << endl;
			}
			while (true) {
				int curr;
				cout << "Enter player number" << endl;
				cin >> curr;
				if (curr >= 1 && curr <= n) {
					list[curr - 1].train();
					cout << "player " << curr << "has trained" << endl;
					break;
				}
				else {
					cout << "invalid player " << endl;
				}	
			}
			cout << endl;
		}
		
		else if (count == 3) {
			for (int i = 0; i < n; i++) {
				cout << i + 1 << endl;
			}
			while (true) {
				int curr;
				cout << "Enter player number" << endl;
				cin >> curr;
				if (curr >= 1 && curr <= n) {
					cout << list[curr - 1];
					break;
				}
				else {
					cout << "invalid player " << endl;
				}
			}
			cout << endl;
		}
		else {
			break;
		}
	}



}