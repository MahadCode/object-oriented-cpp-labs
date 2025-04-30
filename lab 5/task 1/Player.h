#pragma once
#include<iostream>
#include<string>
#include"Stats.h"
using namespace std;

class Player
{
    int playerID;
    string name;
    int score;
    int health;
    int level;
    Stats playerStats;
public:
    Player();
    Player(int,string);
    ~Player();
    
    Player* fight(Player);
    void train();

    bool operator < (const Player&);
    bool operator == (const Player&);

    friend ostream& operator << (ostream& os,Player& curr);
    friend istream& operator >> (istream& is,Player& curr);
    friend bool arePlayersCompatible(const Player& p1, const Player& p2);

    Stats getStats();

};

