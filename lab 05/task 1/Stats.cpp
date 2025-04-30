#include "Stats.h"

Stats::Stats() {
	wins = 0;
	losses = 0;
	matchPlayed = 0;
}

void Stats::recordWin() {
	wins++;
	matchPlayed++;
}
void Stats::recordLoss() {
	losses++;
	matchPlayed++;
}
void Stats::displayStats() const {
	cout << "Matches Played: " << matchPlayed << endl;
	cout << "Wins: " << wins << endl;
	cout << "Losses: " << losses << endl;

}