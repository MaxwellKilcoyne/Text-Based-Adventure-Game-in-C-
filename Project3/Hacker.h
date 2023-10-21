// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 114- Paulissen
// Project 3

#ifndef HACKER_H
#define HACKER_H

#include <iostream>
using namespace std;

class Hacker
{

    public:
    //constructors
    Hacker();

    //accessors
    string getName();
    int getServerRoom();


    //mutators
    void setName(string n);
    void setServerRoom(int s);
    

    //other functions
    void forfeit();
    void battle();



    private:
    string name;
    int serverRoom;
    int defeats;



};

#endif