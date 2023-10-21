// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 114 - Paulissen
// Project 3

#ifndef COMPUTER_h
#define COMPUTER_h
#include <iostream>
#include <string>


using namespace std;

class Computer
{
    public:

    Computer();
    Computer(int G, int C, int P, int Cs, int cd, int K, int pMC, int mL, int totalParts);

    int getGPU();
    int getCPU();
    int getPSU();
    int getCase();
    int getCard();
    int getKeyBoardAndMouse();
    
    void setGPU(int numGPU);
    void setCPU(int numCPU);
    void setPSU(int numPSU);
    void setCase(int numCase);
    void setCard(int numCard);
    void setKeyBoardAndMouse(int numKBM);
    
    int getTotalNumParts();
    int getMaintenanceLevel();
    int getPremadeComp();


    void takeRandomComputerPart();
    void addRandomComputerPart();
    void setMaintenceLevel(int mL);
    void displayInventory();

    void addGPU(int G); //add value
    void addCPU(int C); //add value
    void addPSU(int P);//add value
    void addCase(int Case); //add value
    void addCard(int card); //add value
    void addKeyAndMouse(int K); //add value
    void addPreMadeComp(int p); //add value
    void subGPU(int G); //subtract value
    void subCPU(int C); //subtract value
    void subPSU(int P); //subtract value
    void subCase(int Case); //subtract value
    void subCard(int card); //subtract value
    void subKeyAndMouse(int K); //subtract value
    void decMaintenanceLevel(int m); //subtract value
    void forfeit(); // sets all computer [parts to zero]
   


    private:
    
    int GPU; // private data member
    int CPU;
    int PSU;
    int Case;
    int card;
    int keyAndMouse;
    int preMadeComp;
    int maintenanceLevel;
    
    

};

#endif
