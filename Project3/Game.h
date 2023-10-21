// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 114 - Paulissen
// Project 3
#include "Computer.h"
#include "Player.h"
#include "Hacker.h"
#include "Map.h"
#ifndef GAME_H
#define GAME_H

using namespace std;

class Game
{

    public:
    //constructors
    Game();


    //accessors
    int getServerRoom();
    int getVirus();
    int getCarmenProgress();
    int getHackersDefeated();
    int getTotalHackersDefeated();
    int getTurns();


    //mutators
    void setVirus(int v);
    void setServerRoom(int s);
    void setCarmenProgress(int c);
    void setHackersDefeated(int h);
    void setTotalHackersDefeated(int h);
    void setTurns(int t);

    //other functions
    void incServerRoom();
    void quitGame();
    void browseStack(Computer &p1C, Player &player1);
    void displayUpdate();
    void bestBuy(Player &player, Computer &computer);
    void incVirus(int v);
    void incCarmenProgress(int c);
    void decCarmenProgress(int c);
    void useAntivirus(Player &player);
    int readHackerInfo();
    void battleHacker(Player &player, Computer &computer);
    void setMap(Map &map);
    void travelMap(Map &map);
    void checkSpace(Player &player, Map &map, Computer &computer);
    void progressServerRoom(Map &map);
    void incTurns();

    


    private:
    int virus;
    int serverRoom;
    int carmenProgress;
    Hacker hackers[20];
    int hackersDefeated;
    int totalHackersDefeated;
    int turns;





};

#endif