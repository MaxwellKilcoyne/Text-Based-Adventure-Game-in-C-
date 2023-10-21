// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 114 - Paulissen
// Project 3

#include "Player.h"
#include "Computer.h"
#include <iostream>
#include <string>

using namespace std;

//constructors
Player::Player()
{
    name = "";
    dogecoin = 200;
    vpn = 0;
    ip_lvl = 1;
    antivirus = 0;
    frustration = 0;
}

//accessors
string Player::getName()
{
    return name;
}
int Player::getDogecoin()
{
    return dogecoin;
}
int Player::getFrustration()
{
    return frustration;
}
int Player::getAntivirus()
{
    return antivirus;
}
int Player::getVPN()
{
    return vpn;
}
int Player::getIPlvl()
{
    return ip_lvl;
}

//mutators
void Player::setName(string n)
{
    name = n;
}
void Player::setDogecoin(int d)
{
    dogecoin = d;
}
void Player::setFrustration(int f)
{
    frustration = f;
}
void Player::setAntivirus(int a)
{
    antivirus = a;
}
void Player::setVPN(int v)
{
    vpn = v;
}
void Player::setIPlvl(int i)
{
    ip_lvl = i;
}

//other functions
void Player::incFrustration()
{
    frustration += 10;
}
void Player::decFrustration()
{
    frustration -= 5;
}
void Player::statusUpdate() //display the status update at the beginning of each turn
{
    cout << "===Status Update===" << endl;
    cout << "Dogecoin Coin: " << dogecoin << endl;
    cout << "Number of VPN's: " << vpn << endl;
    cout << "Internet Provider level: " << ip_lvl << endl;
    cout << "Number of antivirus sticks: " << antivirus << endl;
    cout << "Frustration Level: " << frustration << endl;
    
}


double Player::buyCPU(double cart_total, double costper, Computer &comp)
{

    string items; 
    double cost;
    cout << "Enter number of CPUs you would like to purchase: " << endl; //player enter number of cpus player would like to purchase
    getline(cin,items);
    cost = stod(items) * costper; //calculate cost
    if (3 >= (stoi(items) + comp.getCPU()) && dogecoin >= cost)
    {
        dogecoin -= cost; //subtrat cost from dogecoin 
        comp.addCPU(stoi(items)); //add items to inventory
        cart_total += cost;
        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
        cout << "Remaining Dogecoins: " << dogecoin << endl; //display total and remaining dogecoin
        return cart_total;
    }
    else
    {
        cout << "Puchase Declined. Please make a different purchase." << endl;
        return cart_total;
    }

}
double Player::buyGPU(double cart_total, double costper, Computer &comp)
{

    string items;
    double cost;
    cout << "Enter number of GPUs you would like to purchase: " << endl;//player enter number of gpus player would like to purchase
    getline(cin,items);
    cost = stod(items) * costper; //calculate cost
    if (3 >= (stoi(items) + comp.getGPU()) && dogecoin >= cost)
    {
        dogecoin -= cost;//subtrat cost from dogecoin 
        comp.addGPU(stoi(items));//add items to inventory
        cart_total += cost;
        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;//display total and remaining dogecoin
        cout << "Remaining Dogecoins: " << dogecoin << endl;
        return cart_total;
    }
    else
    {
        cout << "Puchase Declined. Please make a different purchase." << endl;
        return cart_total;
    }
    
}
double Player::buyPSU(double cart_total, double costper, Computer &comp) //player buys power supply units, check buyGPU function for comments
{

    string items;
    double cost;
    cout << "Enter number of Power Supply Units you would like to purchase: " << endl;
    getline(cin,items);
    cost = stod(items) * costper;
    if (3 >= (stoi(items) + comp.getPSU()) && dogecoin >= cost)
    {
        dogecoin -= cost;
        comp.addPSU(stoi(items));
        cart_total += cost;
        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
        cout << "Remaining Dogecoins: " << dogecoin << endl;
        return cart_total;
    }
    else
    {
        cout << "Puchase Declined. Please make a different purchase." << endl;
        return cart_total;
    }

}
double Player::buyCase(double cart_total, double costper, Computer &comp)//player buys cases, check buyGPU function for comments
{

    string items;
    double cost;
    cout << "Enter number of Computer Cases you would like to purchase: " << endl;
    getline(cin,items);
    cost = stod(items) * costper;
    if (3 >= (stoi(items) + comp.getCase()) && dogecoin >= cost)
    {
        dogecoin -= cost;
        comp.addCase(stoi(items));
        cart_total += cost;
        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
        cout << "Remaining Dogecoins: " << dogecoin << endl;
        return cart_total;
    }
    else
    {
        cout << "Puchase Declined. Please make a different purchase." << endl;
        return cart_total;
    }

}
double Player::buyCard(double cart_total, double costper, Computer &comp)//player buys cards, check buyGPU function for comments
{

    string items;
    double cost;
    cout << "Enter number of Internet Cards you would like to purchase: " << endl;
    getline(cin,items);
    cost = stod(items) * costper;
    if (3 >= (stoi(items) + comp.getCard()) && dogecoin >= cost)
    {
        dogecoin -= cost;
        comp.addCard(stoi(items));
        cart_total += cost;
        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
        cout << "Remaining Dogecoins: " << dogecoin << endl;
        return cart_total;
    }
    else
    {
        cout << "Puchase Declined. Please make a different purchase." << endl;
        return cart_total;
    }

}
double Player::buyKeyAndMouse(double cart_total, double costper, Computer &comp)//player buys keyboard and mouse, check buyGPU function for comments
{

    string items;
    double cost;
    cout << "Enter number of Keyboard and Mouses you would like to purchase: " << endl;
    getline(cin,items);
    cost = stod(items) * costper;
    if (3 >= (stoi(items) + comp.getKeyBoardAndMouse()) && dogecoin >= cost)
    {
        dogecoin -= cost;
        comp.addKeyAndMouse(stoi(items));
        cart_total += cost;
        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
        cout << "Remaining Dogecoins: " << dogecoin << endl;
        return cart_total;
    }
    else
    {
        cout << "Puchase Declined. Please make a different purchase." << endl;
        return cart_total;
    }

}
double Player::buyPremadeComp(double cart_total, double costper, Computer &comp) //player buys premade computer, check buyGPU function for comments
{

    string items;
    double cost;
    cout << "Enter number of Premade Computers you would like to purchase: " << endl;
    getline(cin,items);
    cost = stod(items) * costper;
    if (2 >= (stoi(items) + comp.getPremadeComp()) && dogecoin >= cost)
    {
        dogecoin -= cost;
        comp.addPreMadeComp(stoi(items));
        cart_total += cost;
        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
        cout << "Remaining Dogecoins: " << dogecoin << endl;
        return cart_total;
    }
    else
    {
        cout << "Puchase Declined. Please make a different purchase." << endl;
        return cart_total;
    }

}
double Player::buyAntivirus(double cart_total, double costper)//player buys antivirus, check buyGPU function for comments
{
    string items;
    double cost;
    cout << "Enter number of Antivirus USBs you would like to purchase: " << endl;
    getline(cin,items);
    cost = stod(items) * costper;
    if (dogecoin >= cost)
    {
        dogecoin -= cost;
        antivirus += stoi(items);
        cart_total += cost;
        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
        cout << "Remaining Dogecoins: " << dogecoin << endl;
        return cart_total;
    }
    else
    {
        cout << "Puchase Declined. Please make a different purchase." << endl;
        return cart_total;
    }
}
double Player::buyVPN(double cart_total, double costper)//player buys vpns, check buyGPU function for comments
{
    string items;
    double cost;
    cout << "Enter number of Virtual Private Networks you would like to purchase: " << endl;
    getline(cin,items);
    cost = stod(items) * costper;
    if (dogecoin >= cost)
    {
        dogecoin -= cost;
        vpn += stoi(items);
        cart_total += cost;
        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
        cout << "Remaining Dogecoins: " << dogecoin << endl;
        return cart_total;
    }
    else
    {
        cout << "Puchase Declined. Please make a different purchase." << endl;
        return cart_total;
    }
}
double Player::buyIPupgrade(double cart_total) //player upgrades ip level
{
    string upgrade;
    cout << "Current IP Level: " << ip_lvl << endl; //player enters what level they would like to upgrade to
    cout << "Which IP Level would you like to upgrade to?" << endl;

    switch(ip_lvl)
    {
        case 1:
            cout << "2, 3, 4, or 5?" << endl; //player enters what level they would like to upgrade to
            getline(cin,upgrade);
            switch(stoi(upgrade))
            {
                case 2:
                    if (dogecoin >= 10) //check if player can afford
                    {
                        ip_lvl = 2;
                        dogecoin -= 10;
                        cart_total += 10; //calculate cost and subtract cost
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl; 
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                case 3:
                    if (dogecoin >= 35)//check if player can afford
                    {
                        ip_lvl = 3;
                        dogecoin -= 35;
                        cart_total += 35; //caluclate cost and subtract cost
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl;
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                case 4:
                    if (dogecoin >= 75)//check if player can afford
                    {
                        ip_lvl = 4;
                        dogecoin -= 75;
                        cart_total += 75; //calculate cost and subtract cost
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl;
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                case 5:
                    if (dogecoin >= 125)//check if player can afford
                    {
                        ip_lvl = 5;
                        dogecoin -= 125;
                        cart_total += 125;//calculate cost and subtract cost
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl;
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                default:
                    cout << "Invalid Input." << endl;
            }
            break;
        case 2:
            cout << "3, 4, or 5?" << endl;//player enters what level they would like to upgrade to
            getline(cin,upgrade);
            switch(stoi(upgrade))
            {
                case 3:
                    if (dogecoin >= 25)//check if player can afford
                    {
                        ip_lvl = 3;
                        dogecoin -= 25;//calculate cost and subtract cost
                        cart_total += 25;
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl;
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                case 4:
                    if (dogecoin >= 65)//check if player can afford
                    {
                        ip_lvl = 4;
                        dogecoin -= 65;//calculate cost and subtract cost
                        cart_total += 65;
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl;
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                case 5:
                    if (dogecoin >= 115)//check if player can afford
                    {
                        ip_lvl = 5;
                        dogecoin -= 115;//calculate cost and subtract cost
                        cart_total += 115;
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl;
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                default:
                    cout << "Invalid Input." << endl;
            }
            break;
        case 3:
            cout << "4 or 5?" << endl;//player enters what level they would like to upgrade to
            getline(cin,upgrade);
            switch(stoi(upgrade))
            {
                case 4:
                    if (dogecoin >= 40)//check if player can afford
                    {
                        ip_lvl = 4;
                        dogecoin -= 40;//calculate cost and subtract cost
                        cart_total += 40;
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl;
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                case 5:
                    if (dogecoin >= 90)//check if player can afford
                    {
                        ip_lvl = 5;
                        dogecoin -= 90;//calculate cost and subtract cost
                        cart_total += 90;
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl;
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                default:
                    cout << "Invalid Input." << endl;
            }
            break;
        case 4:
            cout << "5?" << endl;//player enters what level they would like to upgrade to
            getline(cin,upgrade);
            switch(stoi(upgrade))
            {
                case 5:
                    if (dogecoin >= 50)//check if player can afford
                    {
                        ip_lvl = 5;
                        dogecoin -= 50;//calculate cost and subtract cost
                        cart_total += 50;
                        cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
                        cout << "Remaining Dogecoins: " << dogecoin << endl;
                        return cart_total;
                    }
                    else 
                    {
                        cout << "Purchase Declined. Insufficient Funds." << endl;
                    }
                    break;
                default:
                    cout << "Invalid Input." << endl;
            }
            break;
        case 5:
            cout << "Can not upgrade any further." << endl;
            break;
        default:
            break;
    }
    cout << "Updated Cart Total: " << cart_total << " Dogecoins." << endl;
    cout << "Remaining Dogecoins: " << dogecoin << endl;
    return cart_total;
    
}

void Player::addDogecoin(double d)
{
    dogecoin += d;
}
void Player::decAntivirus(int a)
{
    antivirus -= a;
}