// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 114 - Paulissen
// Project 3

#include "Hacker.h"
#include <iostream>
#include <string>

Hacker::Hacker()
{
    name = "";
    serverRoom = 0;
    defeats = 0;
}
int Hacker::getServerRoom()
{
    return serverRoom;
}
string Hacker::getName()
{
    return name;
}
void Hacker::setName(string n)
{
    name = n;
    cout << "His name is " << name << endl;
}
void Hacker::setServerRoom(int s)
{
    serverRoom = s;
}
void Hacker::forfeit()
{
    cout << "you have forfeited." << endl;
    // this is where you will lose all your computer parts 
}
void Hacker:: battle()
{
    cout << "The battle has begun." << endl;
    // This is where the probabilty for the battle will go.
}