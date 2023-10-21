// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 114 - Paulissen
// Project 3

#include "Computer.h"
#include <iostream>
#include <string>

using namespace std;

/*
Function to generate a random number between a high and a low number,
This function is used to generate percentages for all the random outcomes in the game.
It utilizes the srand function and the time function.
*/

int randNumber(int high, int low)
{
    int num;
    srand(time(0));

    num = (rand()%(high - low + 1) + low);
    return num;
}

Computer::Computer() //default constructor
{
    CPU = 0;
    GPU = 0;
    PSU = 0;
    Case = 0;
    card = 0;
    keyAndMouse = 0;
    preMadeComp = 1;
    maintenanceLevel = 100;
}
Computer::Computer(int G, int C, int P, int Cs, int cd, int K, int pMC, int mL, int totalParts) // default constructor
{
    GPU = G;
    CPU = C;
    PSU = P;
    Case = Cs;
    card = cd;
    keyAndMouse = K;
    preMadeComp = pMC;
    maintenanceLevel = mL;

}

    int Computer :: getGPU() // getter
    {
        return GPU;
    }
    int Computer :: getCPU() // getter
    {
        return CPU;
    }
    int Computer :: getPSU() // getter
    {
        return PSU;
    }
    int Computer :: getCase() // getter
    {
        return Case;
    }
    int Computer :: getCard()//getter
    {
        return card;
    }
    int Computer :: getKeyBoardAndMouse() // getter
    {
        return keyAndMouse;
    }

    int Computer :: getTotalNumParts() //getter
    {
        int totalNumParts = GPU + CPU + PSU + Case + card + keyAndMouse; // adds all the computer parts up adn returns the total number
        return totalNumParts;
    }
    int Computer:: getMaintenanceLevel() // getter
    {
        return maintenanceLevel;
    }
    int Computer:: getPremadeComp() //getter
    {
        return preMadeComp;
    }





    void Computer :: addRandomComputerPart() //adds a random computer part to the players inventory
    {
        int num;
        num = randNumber(6, 1); // generates a random number 1 -6 in order to randmoize whichever computer part they get.
        cout << "Random number " << num << endl;
        if(num == 1)
        {
            GPU = GPU + 1; // adds one to the total count of whatever computer part and then saves the new total.
        }
        if(num == 2)
        {
            CPU = CPU + 1;
        }
        if(num == 3)
        {
            PSU = PSU + 1;
            //subtract PSU
        }
        if(num == 4)
        {
            Case =  Case + 1;
            //subtract case
        }
        if(num == 5)
        {
            card = card + 1;
            //subtract card
        }
        if(num == 6)
        {
            keyAndMouse = keyAndMouse + 1;
            //subtract keyboard mouse
        }
    }
    void Computer :: takeRandomComputerPart() // takes away one random computer part as long as there is more tha zero computer parts
    {
    
        int num;
        num = randNumber(6, 1); // random number generator
        if (GPU + CPU + PSU + Case + card + keyAndMouse == 0) // checks if there are no computer parts
        {
            cout << "You have no computer parts to take. " << endl;
        }
        else
        {
            if(num == 1)
            {
                if(GPU > 0)
                {
                GPU = GPU - 1;
                }
                else
                {
                    num = 2;// moves onto the next computer part if there are none of that specific one so there are no negative numbers
                }
            }
            if(num == 2)
            {
                if(CPU > 0)
                {
                    CPU = CPU - 1;
                }
                else
                {
                    num = 3;
                }
            }
            if(num == 3)
            {
                if(PSU > 0)
                {
                    PSU = PSU - 1;
                }
                else
                {
                    num = 4;
                }
            }
            if(num == 4)
            {
                if(Case > 0)
                {
                    Case = Case -1;
                }
                else
                {
                    num = 5;
                }
            }
            if(num == 5)
            {
                if(card > 0)
                {
                    card = card - 1;
                }
                else 
                {
                    num = 6;
                }
            }
            if(num == 6)
            {
                if(keyAndMouse > 0)
                {
                    keyAndMouse = keyAndMouse - 1;
                }
                else
                {
                    num = 1;
                }        
            }
        }
    }
void Computer :: setMaintenceLevel(int mL) //set maintenace level
{
    maintenanceLevel = mL;  
}
void Computer::displayInventory() // displays the players current inventory
{
    cout << "1: GPU: " << GPU << endl;
    cout << "2: CPU: " << CPU << endl;
    cout << "3: Power Supply Unit: " << PSU << endl;
    cout << "4: Case: " << Case << endl;
    cout << "5: Card: " << card << endl;
    cout << "6: Keyboard and Mouse: " << keyAndMouse << endl;
    cout << "Premade Computer: " << preMadeComp << endl;
    cout << "Maintenance Level: " << maintenanceLevel << endl;
    cout << "Total Number of Parts: " << GPU + CPU + PSU + Case + card + keyAndMouse<< endl;
}
void Computer::decMaintenanceLevel(int m) // takes some away from maintence level
{
    maintenanceLevel -= m;
}
void Computer :: setGPU(int numGPU) // sets the gpu to a specific value
{
    GPU = numGPU;
}
void Computer :: setCPU(int numCPU) // set CPU to specifi value
{
    CPU = numCPU;
}
void Computer :: setPSU(int numPSU) // setter
{
    PSU = numPSU;
}
void Computer :: setCase(int numCase)// setter
{
    Case = numCase;
}
void Computer :: setCard(int numCard) //setter
{
    card = numCard;
}
void Computer :: setKeyBoardAndMouse(int numKBM)//setter
{
    keyAndMouse = numKBM;
}



void Computer :: addGPU(int G) // adds some value to GPU
{
    GPU =+ G;  
}
void Computer :: addCPU(int C) // adds some value to CPU
{
    CPU += C; 
}
void Computer :: addPSU(int P) // adds some value to PSU
{
    PSU += P;
}
void Computer :: addCase(int c)// adds some value to case
{
    Case += c;  
}
void Computer :: addCard(int c) // adds some value to card
{
    card += c;
}
void Computer :: addKeyAndMouse(int k) // adds some value to keyboard and mouse
{
    keyAndMouse += k;
}
void Computer :: addPreMadeComp(int p) // adds soome number to premade computer
{
    preMadeComp += p;
}
void Computer::forfeit() //takes away all the players computer parts if the lose to the hacker
{
    GPU = 0;
    CPU = 0;
    PSU = 0;
    Case = 0;
    card = 0;
    keyAndMouse = 0;
}
void Computer::subGPU(int G) // subtracts some value form GPU
{
    GPU -= G;
}
void Computer::subCPU(int C)// subtracts some value form CPU
{
    CPU -= C;
}
void Computer::subPSU(int P)//subtracts some value from PSU
{
    PSU -= P;
}
void Computer::subCase(int c)//subtracts some value form Case
{
    Case -= c;
}
void Computer::subCard(int c) // subtracts some vale from card
{
    card -= c;
}
void Computer::subKeyAndMouse(int K) // subtracts some value form keyboard and mouse
{
    keyAndMouse -= K;
}
