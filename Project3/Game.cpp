// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 114 - Paulissen
// Project 3

#include "Game.h"
#include "Computer.h"
#include "Map.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>


#include "Computer.h"
using namespace std;

int split(string string1, char seperator, string arr[], int SIZE)
{
    int start_pos = 0;
    string current_substr;
    int counter = 0;
    int string_len = string1.length();

    for (int i = 0; i < string_len; i++)
    {
        if(string1[i] == seperator)
        {
            current_substr = string1.substr(start_pos, i- start_pos);
            arr[counter] = current_substr;
            start_pos = i + 1;
            counter++;
        }
        if( i == (string_len -1))
        {
            current_substr = string1.substr(start_pos);
            arr[counter] = current_substr;
            counter++;
        }
    }
    if(counter > SIZE)
    {
        return -1;
    }
    return counter;
}
/*
Function to generate a random number between a high and a low number,
This function is used to generate percentages for all the random outcomes in the game.
It utilizes the srand function and the time function.
*/

int randomNum(int high, int low)
{
    int num;
    srand(time(0));

    num = (rand()%(high - low + 1) + low);
    return num;
}
/*
Function to generate a random number between a high and a low number,
This function is used to generate percentages for all the random outcomes in the game.
It utilizes the srand function and the time function.
*/

int randNum42(int low, int high, int index)
{
    int num;
    srand(time(0));

    for(int i = 1; i <= index; i++)
    {
        num = (rand() % (high - low + 1) + low);
    }
    return num;
    
}



//constructors
Game::Game()
{
    virus = 0;
    serverRoom = 1;
    carmenProgress = 0;
    hackersDefeated = 0;
    totalHackersDefeated = 0;
    turns = 0;
}

//accessors
int Game::getServerRoom()
{
    return serverRoom;
}
int Game::getVirus()
{
    return virus;
}
int Game::getCarmenProgress()
{
    return carmenProgress;
}
int Game::getHackersDefeated()
{
    return hackersDefeated;
}
int Game::getTotalHackersDefeated()
{
    return totalHackersDefeated;
}
int Game::getTurns()
{
    return turns;
}






//mutators
void Game::setVirus(int v)
{
    virus = v;
}
void Game::setServerRoom(int s)
{
    serverRoom = s;
}
void Game::setCarmenProgress(int c)
{
    carmenProgress = c;
}
void Game::setHackersDefeated(int h)
{
    hackersDefeated = h;
}
void Game::setTotalHackersDefeated(int h)
{
    totalHackersDefeated = h;
}
void Game::setTurns(int t)
{
    turns = t;
}





//other functions
void Game::incServerRoom()
{
    serverRoom++;
}
void Game::quitGame()
{
    //player leaves game
}
void Game::useAntivirus(Player &player)
{
    player.decAntivirus(1); //decreases the number of antiviruses the player has by one 
    virus = 0; // sets the nu,ber of viruses to zero
}
void Game::browseStack(Computer &p1C, Player &player1)
{
    string line;
    
    ifstream puzzleFile;
    int high = 5;
    int low = 1;
    string textFile;
    string answer;
    string userAnswer;
    
    if(randomNum(high, low) == 1) //chooses a random puzzle file and sets the file name to the specific text file. Also sets the answer for that specific puzzle
    {
        textFile = "puzzle1.txt";
        answer = "21";
        
    }
    if(randomNum(high, low) == 2)
    {
        textFile = "puzzle2.txt";
        answer = "13";
        
    }
    if(randomNum(high, low) == 3)
    {
        textFile = "puzzle3.txt";
        answer = "B";
        
    }
    if(randomNum(high, low) == 4)
    {
        textFile = "puzzle4.txt";
        answer = "A";
        
    }
    if(randomNum(high, low) == 5)
    {
        textFile = "puzzle5.txt";
        answer = "D";
        
    }
    

    puzzleFile.open(textFile);//opens the random puzzle file
    while(!puzzleFile.eof())
    {
        getline(puzzleFile, line);
        cout << line << endl; //prints the puzzle
    }
    getline(cin, userAnswer); //saves user input
    if (userAnswer == answer) //checks to see if you got it correct
    {
        p1C.addRandomComputerPart(); // if you did then a random computer part is added to your inventory.
        cout << "Congradulations! You got it correct. A random computer part has been added to your inventory." << endl;
        p1C.displayInventory(); // then your new inventory is displayed so you cna see what got added.
    }
    else //if you got it wrong
    {
        cout << "That was incorrect. " << endl;
        player1.setFrustration(player1.getFrustration() + 10); // your frustration goes up by 10
        
        
    }


    
    // string answer;
    // string UserAnswer;
    // string realAnswer;
    // int answerLineCounter = 1;
    // int lineCounter = 1;
    // ifstream inputFile;
    // ifstream answerFile;
    // Computer player1Computer;
    // inputFile.open("puzzles.txt");
    // answerFile.open("answers.txt");
    // if(inputFile.is_open() && answerFile.is_open()) // if statment to check if the file is open 
    // {     

    //         getline(inputFile, line); // get line to take each line and store it into the string line 
    //         if(line != "---"){ // if statment to check if the string is not empty 
    //             lineCounter++;
    //             cout << line << endl;
    //         }
    //         cout << "Enter your answer: " << endl;
    //         getline(cin, UserAnswer);
    //         getline(answerFile, answer);
    //         if(answer!= "---")
    //         {
    //             realAnswer = answer;
    //             answerLineCounter++;
    //         }
    //         if(answer == UserAnswer)
    //         {
    //             player1Computer.buyRandomComputerPart(1);
    //         }

    // }
     


    puzzleFile.close(); // close the file
}
    

void Game::displayUpdate() // didnt end up getting used instead we had a display inventory
{
    //function to display all apsects of the game
}


void Game::bestBuy(Player &player, Computer &computer)
{
    
    double multiplier;
    double cost = 0;


    switch (serverRoom) //set a multiplier for the prices based on the server room the player is in
    {
        case 1:
            multiplier = 1;
            break;
        case 2:
            multiplier = 1.1;
            break;
        case 3:
            multiplier = 1.2;
            break;
        case 4:
            multiplier = 1.25;
            break;
        case 5:
            multiplier = 1.3;
            break;
        default:
            multiplier = 1;
    }
    
    string menu_input;
    double cartTot = 0; //total cost initialized as 0
    double costper;

    while (menu_input != "11") 
    {
        
        cout << "====BEST BUY MENU====" << endl; //display the menu for best buy
        cout << "Items for sale: " << endl;
        cout << "1: CPU for " << 10 * multiplier << " Dogecoins each" << endl;
        cout << "2: GPU for " << 20 * multiplier << " Dogecoins each" << endl;
        cout << "3: Power Supply Unit for " << 5 * multiplier << " Dogecoins each" << endl;
        cout << "4: Computer Case for " << 15 * multiplier << " Dogecoins each" << endl;
        cout << "5: Internet Card for " << 5 * multiplier << " Dogecoins each" << endl;
        cout << "6: Keyboard and Mouse for " << 10 * multiplier << " Dogecoins" << endl;
        cout << "7: Premade Computer for " << 100 * multiplier << " Dogecoins" << endl;
        cout << "8: Antivirus Software for " << 10 * multiplier << " Dogecoins" << endl;
        cout << "9: Virtual Private Network for " << 20 * multiplier << " Dogecoins" << endl;
        cout << "10: Upgrade Internet Provider Level" << endl;
        cout << "11: Checkout" << endl;
        
        getline(cin,menu_input);

        switch(stoi(menu_input)) 
        {
            case 1:
                costper = 10 * multiplier;
                cartTot = player.buyCPU(cartTot, costper, computer); //player buys CPU
                break;
            case 2:
                costper = 20 * multiplier;
                cartTot = player.buyGPU(cartTot, costper, computer); //player buys GPU
                break;
            case 3:
                costper = 5 * multiplier;
                cartTot = player.buyPSU(cartTot, costper, computer); //player buys power supply unit
                break;
            case 4:
                costper = 15 * multiplier;
                cartTot = player.buyCase(cartTot, costper, computer); //player buys case
                break;
            case 5:
                costper = 5 * multiplier;
                cartTot = player.buyCard(cartTot, costper, computer); //player buys card
                break;
            case 6:
                costper = 10 * multiplier;
                cartTot = player.buyKeyAndMouse(cartTot, costper, computer); //player buys keyboard and mouse
                break;
            case 7:
                costper = 100 * multiplier;
                cartTot = player.buyPremadeComp(cartTot, costper, computer); //player buys premade computer
                break;
            case 8:
                costper = 10 * multiplier;
                cartTot = player.buyAntivirus(cartTot, costper); //player buys antivirus
                break;
            case 9:
                costper = 20 * multiplier;
                cartTot = player.buyVPN(cartTot, costper); //player buys VPNs
                break; 
            case 10:
                cartTot = player.buyIPupgrade(cartTot); //player upgrades internet provider level
                break;
            case 11: 
                cout << "Checking out ..." << endl; //player checks out and leaves best buy
                break;
            default:
                cout << "Invalid Input." << endl; //player entered an invalid input
        }
    }

    cout << "Cart Total: " << cartTot << " Dogecoins" << endl; //displays the cart total and remaining dogecoins left
    cout << "Remaining Dogecoins: " << player.getDogecoin() << endl;


}

void Game::incVirus(int v) //new begin
{
    virus += v;
}
void Game::incCarmenProgress(int c)
{
    carmenProgress += c;
}
void Game::decCarmenProgress(int c)
{
    carmenProgress -= c;
}

int Game::readHackerInfo()
{
    int maxCol = 2;
    int hackersStored = 0;
    int hackerArrSize = 20;
    string filename = "hackers.txt";
    string line;
    const int k = maxCol;
    string arr[51];
    int hacker_total = hackersStored;
    int splitnum;

    if (hackersStored < hackerArrSize) //checks if hackers array is full
    {
        ifstream input_file;
        input_file.open(filename); //open file with hackers data

        if (!input_file.fail()) //checks if file opened successfully
        {
            for (int i = hackersStored; !input_file.eof() && i < hackerArrSize; i++) //loops as long data is left in file and array is not full
            {
                    getline(input_file, line); //takes the line from file
                    if (!isspace(line[0]) && line.length() > 1)
                    {
                        splitnum = split(line, ',', arr, 1 + maxCol); //gets number of splits of the line
                        hackers[i].setName(arr[0]); //take first split and save it as name
                        hackers[i].setServerRoom(stoi(arr[1]));
                        hacker_total++; //add one to the total hackers saved in array
                    }
                    else
                    {
                        i--; //if line is empty then take a line for the same index
                    }
            }
            input_file.close(); //close file
            return hacker_total; //return total hackers saved in array
        }
        else
        {
            return -1;
        }

    }
    else
    {
        return -2;
    }
}
void Game::battleHacker(Player &player, Computer &computer)
{
    int hacker_i;
    double outcome;
    string battle;
    int r1;
    int r2;
    int rand_part;
    int maint_ch;
    int virus_ch;


    switch (serverRoom) //gets the index of a random hacker based on server room the player is in
    {
        case 1:
            hacker_i = randNum42(0,3,1);
            break;
        case 2:
            hacker_i = randNum42(4,7,1);
            break;
        case 3:
            hacker_i = randNum42(8,11,1);
            break;
        case 4:
            hacker_i = randNum42(12,15,1);
            break;
        case 5:
            hacker_i = randNum42(16,19,1);
            break;
        default:
            break;
    }

    while(battle[0] != '1' && battle[0] != '2') // loop as long as player does not enter a valid choice
    {
        cout << "Would you like to battle " << hackers[hacker_i].getName() << "?" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Forfeit" << endl; //player decides to attack hacker or forfeit
        getline(cin,battle);

        if (battle.length() == 1)
        {
            switch(battle[0]) 
            {
                case '1':
                    r1 = randNum42(1,6,1);
                    r2 = randNum42(1,6,2);
                    outcome = (double(r1) * double(player.getIPlvl())) - (double(r2) * double(serverRoom) * (1/double(player.getVPN()))); //calculate outcome of hacker battle
                    if (outcome > 0) //player defeated the hacker
                    {
                        cout << "You have defeated the hacker!" << endl;
                        player.addDogecoin(50); //player wins 50 dogecoin
                        hackersDefeated++; //+1 to number of hackers defeated
                        totalHackersDefeated++;
                        rand_part = randNum42(1,6,3); //players loses a random computer part
                        switch (rand_part)
                        {
                            case 1:
                                computer.subGPU(1);
                                break;
                            case 2:
                                computer.subCPU(1);
                                break;
                            case 3:
                                computer.subPSU(1);
                                break;
                            case 4:
                                computer.subCase(1);
                                break;
                            case 5:
                                computer.subCard(1);
                                break;
                            case 6:
                                computer.subKeyAndMouse(1);
                                break;
                            default:
                                break;
                        }
                        maint_ch = randNum42(1,10,4); //3 in 10 chance of decrease in computer maintenance level
                        if (maint_ch >= 1 && maint_ch <= 3)
                        {
                            computer.decMaintenanceLevel(10);
                        }
                    }
                    else
                    {
                        cout << "You lost to the hacker!" << endl; //player lost to hacker
                        computer.decMaintenanceLevel(20); //computer maintenance level is decreased
                        virus_ch = randNum42(1,10,4); //1 in 10 chance of computer being infected by virus
                        if (maint_ch == 1)
                        {
                            virus += 1;
                        }
                        rand_part = randNum42(1,6,3); //player loses a random computer part
                        switch (rand_part)
                        {
                            case 1:
                                computer.subGPU(1);
                                break;
                            case 2:
                                computer.subCPU(1);
                                break;
                            case 3:
                                computer.subPSU(1);
                                break;
                            case 4:
                                computer.subCase(1);
                                break;
                            case 5:
                                computer.subCard(1);
                                break;
                            case 6:
                                computer.subKeyAndMouse(1);
                                break;
                            default:
                                break;
                        }
                        carmenProgress += 25; //carmen progress increased by 25
                    }
                    break;
                case '2':
                    cout << "You have forfeited to the hacker!" << endl; //player forfeited to hacker
                    computer.forfeit(); //player loses all computer parts
                    break;
                default:
                    cout << "Invalid Input" << endl; //request new selection
            }
        }
    }
}
void Game::setMap(Map &map)
{
    bool spawn;

    map.spawnBestBuy(randNum42(0,4,1),randNum42(0,8,2)); //best buy spawned at random spot on map


    for (int i = 0; i < randNum42(1,3,3); i++)  //spawns random number of NPCs at random location
    {
        spawn = map.spawnNPC(randNum42(0,4,4),randNum42(0,8,5));
        if (spawn)
        {
            continue;
        }
        else
        {
            i--;
        }
    }

    for (int i = 0; i < randNum42(1,3,6); i++) //spawns a random number of hackers at random locations
    {
        spawn = map.spawnHacker(randNum42(0,4,7),randNum42(0,8,8));
        if (spawn)
        {
            continue;
        }
        else
        {
            i--;
        }
    }
}
void Game::travelMap(Map &map) //player travels around the map
{
    string move_input;
    map.displayMoves(); //display valid moves for player
    getline(cin,move_input);
    if (move_input.length() == 1)
    {
        map.executeMove(move_input[0]); //player moves
    }
}
void Game::checkSpace(Player &player, Map &map, Computer &computer)
{
    if (map.isNPCLocation()) // speakes to npc check game driver for comments on what happens in this if statement.
    {
        Game game1;
        int NewrandomNumber;
        string npcInput;
        Computer player1Computer;
        Player player1;

        do
                    {
                        cout << "1. Take your chances." << endl; //asks what the player would liek to do if the run into npc.
                            cout << "2. Attempt a puzzle." << endl;
                            getline(cin, npcInput);
                       NewrandomNumber = randomNum(3, 1);

                        if(npcInput == "1") // if they decide to take there chances there is a 1 in 3 chance that these outcomes will happen
                        {
                            if(NewrandomNumber  == 1)
                            {
                                cout << "The npc is neutral nothing happened." << endl; // one of teh chances is nothing will happen
                            }
                            if(NewrandomNumber == 2)
                            {
                                cout << " A part has been stolen." << endl; // ine of the outcomes is a random comuter part is stolen
                                player1Computer.takeRandomComputerPart();
                                
                                
                            }
                            if(NewrandomNumber  == 3)
                            {
                                cout << " I am your friend. Here is a gift." << endl; // one of the outcomes is that a random computer part us added to your inventory
                                player1Computer.addRandomComputerPart();
                            }


                        }
                        else if(npcInput == "2") // if the choose to solve a puzzle a random puzzle will be read.
                        {
                            game1.browseStack(player1Computer, player1);
                        }
                        else
                        {
                            cout << "Invalid Input. Try again" << endl; // checks to make sure input is valid
                            
                        }

                    } while(npcInput != "1" && npcInput != "2");
    }
    else if (map.isHackerLocation())
    {
        battleHacker(player,computer); //player battles a hacker
    }
    else if (map.isBestBuyLocation())
    {
        bestBuy(player,computer);   //player visits best buy
    }
    else
    {
        return;
    }
}
void Game::progressServerRoom(Map &map) //player progresses to the next server room
{
    if (hackersDefeated >= 1)
    {
        serverRoom++;
        cout << "Welcome to Server Room " << serverRoom << "!" << endl;
        hackersDefeated = 0;
        map.resetMap(); //create a new map
        setMap(map);
    }
    else
    {
        cout << "You can not travel to the next server room yet..." << endl;
        cout << "Grow a pair and defeat a hacker first!" << endl; //player can not go to next room yet
    }

    if(serverRoom > 3)
    {
        cout <<"Congradulations you have won the game and defeated all of the hackers!" << endl;
    }
}
void Game::incTurns()
{
    turns++; //add one to turns after at each turns
}
