// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 112 - Maria Stull
// Project 3


#include "Game.h"
#include "Player.h"
#include "Computer.h"
#include "Hacker.h"
#include <iostream>
using namespace std;

int main()
{

    //testing game class
    cout << "TESTING GAME CLASS" << endl;
    Game game1 = Game();
    cout << "Server Room: " << game1.getServerRoom() << endl;
    cout << "Viruses: " << game1.getVirus() << endl;
    game1.setServerRoom(3);
    game1.setVirus(2);
    cout << "Server Room: " << game1.getServerRoom() << endl;
    cout << "Viruses: " << game1.getVirus() << endl;
    game1.incServerRoom();
    game1.useAntivirus();
    cout << "Server Room: " << game1.getServerRoom() << endl;
    cout << "Viruses: " << game1.getVirus() << endl;
    cout << endl << endl << endl;



    //testing player class
    cout << "TESTING PLAYER CLASS" << endl;
    Player player1 = Player();
    cout << "Name: " << player1.getName() << endl;
    cout << "Dogecoin: " << player1.getDogecoin() << endl;
    cout << "VPN: " << player1.getVPN() << endl;
    cout << "Frustration Level: " << player1.getFrustration() << endl;
    cout << "Antivirus: " << player1.getAntivirus() << endl;
    cout << "Internet Provider Level: " << player1.getIPlvl() << endl;
    player1.setName("Bryce Harper");
    player1.setDogecoin(150);
    player1.setFrustration(45);
    player1.setAntivirus(2);
    player1.setVPN(1);
    player1.setIPlvl(4);
    cout << "Name: " << player1.getName() << endl;
    cout << "Dogecoin: " << player1.getDogecoin() << endl;
    cout << "VPN: " << player1.getVPN() << endl;
    cout << "Frustration Level: " << player1.getFrustration() << endl;
    cout << "Antivirus: " << player1.getAntivirus() << endl;
    cout << "Internet Provider Level: " << player1.getIPlvl() << endl;
    player1.incFrustration();
    cout << "Frustration Level: " << player1.getFrustration() << endl;
    player1.decFrustration();
    cout << "Frustration Level: " << player1.getFrustration() << endl;
    player1.buyAntivirus(1);
    cout << "Dogecoin: " << player1.getDogecoin() << endl;
    cout << "Antivirus: " << player1.getAntivirus() << endl;
    player1.buyVPN(1);
    cout << "Dogecoin: " << player1.getDogecoin() << endl;
    cout << "VPN: " << player1.getVPN() << endl;
    player1.incIPlvl(5);
    cout << "Internet Provider Level: " << player1.getIPlvl() << endl;
    cout << endl << endl << endl;



    //testing computer class
    cout << "TESTING COMPUTER CLASS" << endl;
    Computer comp1 = Computer();
    cout << "GPU: " << comp1.getGPU() << endl;
    cout << "CPU: " << comp1.getCPU() << endl;
    cout << "Power Supply Unit: " << comp1.getPSU() << endl;
    cout << "Case: " << comp1.getCase() << endl;
    cout << "Card: " << comp1.getCard() << endl;
    cout << "Keyboard and Mouse: " << comp1.getKeyBoardAndMouse() << endl;
    cout << "Premade Computer: " << comp1.getPremadeComp() << endl;
    cout << "Maintenance Level: " << comp1.getMaintenanceLevel() << endl;
    cout << "Total Number of Parts: " << comp1.getTotalNumParts() << endl;
    Computer comp2 = Computer(4, 2, 3, 1, 2, 4, 1, 80, 17);
    comp2.displayInventory();
    comp2.buyGPU(3);
    comp2.buyCPU(2);
    comp2.buyPSU(1);
    comp2.buyCase(3);
    comp2.buyCard(2);
    comp2.buyKeyBoardAndMouse(1);
    comp2.buyPreMadeComp(1);
    comp2.setMaintenceLevel(60);



    //testing hacker class
    Hacker hacker1 = Hacker();
    cout << "Name: " << hacker1.getName() << endl;
    cout << "Server Room: " << hacker1.getServerRoom() << endl;
    hacker1.setName("Joel Embidd");
    hacker1.setServerRoom(3);
    cout << "Name: " << hacker1.getName() << endl;
    cout << "Server Room: " << hacker1.getServerRoom() << endl;
    hacker1.forfeit();
    hacker1.battle();




}