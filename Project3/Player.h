// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 114 - Paulissen
// Project 3

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Computer.h"
using namespace std;

class Player
{

    public:
    //constructors
    Player();
    
    //accessors
    string getName();
    int getDogecoin();
    int getFrustration();
    int getAntivirus();
    int getVPN();
    int getIPlvl();

    //mutators
    void setName(string n);
    void setDogecoin(int d);
    void setFrustration(int f);
    void setAntivirus(int a);
    void setVPN(int v);
    void setIPlvl(int i);

    //other functions
    void incFrustration();
    void decFrustration();
    void statusUpdate();

    double buyCPU(double cart_total, double costper, Computer &comp);
    double buyGPU(double cart_total, double costper, Computer &comp);
    double buyPSU(double cart_total, double costper, Computer &comp);
    double buyCase(double cart_total, double costper, Computer &comp);
    double buyCard(double cart_total, double costper, Computer &comp);
    double buyKeyAndMouse(double cart_total, double costper, Computer &comp);
    double buyPremadeComp(double cart_total, double costper, Computer &comp);
    double buyAntivirus(double cart_total, double costper);
    double buyVPN(double cart_total, double costper);
    double buyIPupgrade(double cart_total);
    void addDogecoin(double d);
    void decAntivirus(int a);
    




    private:
    string name;
    int dogecoin;
    int vpn;
    int ip_lvl;
    int antivirus;
    int frustration;




};

#endif