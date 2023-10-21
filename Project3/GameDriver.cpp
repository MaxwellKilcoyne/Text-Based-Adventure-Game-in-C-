// CSC1300 Fall 2021
// Author: Max_Kilcoyne and Ryan Mcateer
// Recitation: 114 - Paulissen
// Project 3

#include <iostream>
#include <vector>
#include <string>
#include "Computer.h"
#include "Game.h"
#include "Player.h"
#include "Hacker.h"
#include "Map.h"
#include <fstream>


using namespace std;

/*
This is a finction that will sort an array from teh smallest value to the greatest value.
It does this by using a nested for loop and an if statment. This first for loop serves as a counter for the end 
condition of the second for loop. The second foor loop travers the array and if the next number is less than the previos number it switches ther places.
By doing this through the whole loop multiple times you can sort the array. The swapped variable is used to check if the array is sorted.
if it gets all the way through the array without switching anything then it will ecit the function.
*/
static void bubbleSort(int arr[], int n)
   {
       bool swapped;
       for(int i=0;i<n;i++){
           swapped = false;
           for(int j=1;j<n-i;j++){
               if(arr[j]<arr[j-1]){
                   int temp = arr[j];
                   arr[j] = arr[j-1];
                   arr[j-1] = temp;
                   swapped = true;
               }
           }if(!swapped){
               break;
           }
       }
   }


int split2(string string1, char seperator, string arr[], int SIZE)
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
int randNum(int high, int low, int index)
{
    int num;
    srand(time(0));
    for(int i = 1; i <= index; i++)
    {
        num = (rand()%(high - low + 1) + low); 
    }
    return num;
}

int main()
{
    //all the variables used in main
    string name;
    string menu_input;
    string npcInput;
    Player player1;
    Game game1;
    Computer player1Computer;
    string repairCompInput;
    Map map;
    int partsUsed;
    int maintenceIncrease;
    int NewrandomNumber;
    int currDoge;
    int misfortuneNum;
    int misfortuneNum2;
    int currFrustration;
    int currNumVirus = 0;
    int arrSize = 4;
    string turnsStrArr[4];
    int intPlayerTurns[50];
    int numTurns;
    for (int i = 0; i < 50; i++) // sets the number of turns array to zeros
    {
        intPlayerTurns[i] = 0;
    }
    string playersNames[50];

    string resultsString;

    cout << "Enter Player's name: " << endl; // get the players name
    getline(cin, name);
    player1.setName(name);
    
    game1.bestBuy(player1,player1Computer); // start the game with visiting bestbuy and purchasing your items to begin with.
    game1.setMap(map);// set map

    while (menu_input != "8") // start the loop for the menu.
    {
        game1.incTurns();// count the turns
        player1.statusUpdate();  
        player1Computer.displayInventory(); // display the inventory of the player
        cout << endl;
        cout << endl;
        map.displayMap(); // display the map
        cout << "=====Menu=====" << endl;
        cout << "1. Fight a Hacker." << endl; // ryan
        cout << "2. Speak to NPC." << endl; // max pretty much done just need to exit loop
        cout << "3. Travel the Server Room" << endl;
        cout << "4. Repair your Computer" << endl; //max almost done
        cout << "5. Use an Antivirus USB" << endl; // ryan
        cout << "6. Browse Stack Overflow" << endl; // max and ryan done
        cout << "7. Travel to next Server Room" << endl;
        cout << "8. Quit Game" << endl;
        getline(cin,menu_input);

        if (menu_input.length() == 1) //checks if input is invalid
        {
            switch(menu_input[0]) 
            {
                case '1':
                    game1.battleHacker(player1, player1Computer); // if the choose one they will battel hacker
                    break;
                case '2':
                    
                   
                    
                   do
                    {
                        cout << "1. Take your chances." << endl; //asks what the player would liek to do if the run into npc.
                            cout << "2. Attempt a puzzle." << endl;
                            getline(cin, npcInput);
                       NewrandomNumber = randNum(3, 1, 1);

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
                        break;
                case '3':
                    game1.travelMap(map);
                    game1.checkSpace(player1,map,player1Computer);
                    break;
                case '4':
                player1Computer.displayInventory();
                cout << "Enter the name of the computer part you would like to use:" << endl; // see what computer part they would like to use
                getline(cin, repairCompInput);
                if(repairCompInput == "1") // depeending on which one they choose teh correspondong computer part will be set to zero.d
                {
                    partsUsed = player1Computer.getCPU();
                    player1Computer.setCPU(0);
                }
                if(repairCompInput == "2")
                {
                    partsUsed = player1Computer.getGPU();
                    player1Computer.setGPU(0);
                }
                if(repairCompInput == "3")
                {
                    partsUsed = player1Computer.getPSU();
                    player1Computer.setPSU(0);
                }
                if(repairCompInput == "4")
                {
                    partsUsed = player1Computer.getCase();
                    player1Computer.setCase(0);
                }
                if(repairCompInput == "5")
                {
                    partsUsed = player1Computer.getCard();
                    player1Computer.setCard(0);
                }
                if(repairCompInput == "6")
                {
                    partsUsed = player1Computer.getKeyBoardAndMouse();
                    player1Computer.setKeyBoardAndMouse(0);
                }
                maintenceIncrease = partsUsed * 20; //maintence level will be increased by the number of parts used * 20.
                player1Computer.setMaintenceLevel(maintenceIncrease);
                    break;
                case '5':
                    game1.useAntivirus(player1); //player uses antivirus to get rid of viruses
                    break;
                case '6':
                game1.browseStack(player1Computer, player1);
                    break;
                case '7':
                    game1.progressServerRoom(map); //player traveks to the next server room
                    break;
                case '8':
                    break;
                default:
                    cout << "Invalid Input." << endl;
            }
        }
        currNumVirus = game1.getVirus();
        player1Computer.setMaintenceLevel(100 - (currNumVirus * 10)); // maintence level decreases at the end of the turn if you have a virus
        misfortuneNum = randNum(3, 1, 4); // there is a 1 in 3 chance of misfortune at the end of each turn. 
        if(misfortuneNum == 1) 
        {
            misfortuneNum2 = randNum(3,1, 5);
            if(misfortuneNum2 == 1)// if you geta misfortune then there is a 1 in 3 chance you will get one of these outcomes
            {
                cout << "Oh No! Your team was robbed by Carmen's fucking hackers." << endl;
                cout << "Those bastards took all of our computer parts and antivirus sticks." << endl; // all your invenotry is wiped clean
                player1Computer.setCard(0);
                player1Computer.setCase(0);
                player1Computer.setCPU(0);
                player1Computer.setGPU(0);
                player1Computer.setKeyBoardAndMouse(0);
                player1Computer.setPSU(0);
                player1.setAntivirus(0);
            }
            if(misfortuneNum2 == 2) //mainetence level is decreased by 10
            {
                cout << "Oh no your computer was damaged!" << endl;
                player1Computer.setMaintenceLevel(10);
            }
            if(misfortuneNum2 == 3)
            {
                cout << "OH NO! Why won't code runner work. There are so many hidden test cases!" << endl;
                cout << "Your frustration was increased." << endl;
                currFrustration = player1.getFrustration() + 10; // frustration is increased by 10
                player1.setFrustration(currFrustration);
            }
        }
        else
        {
            continue;
        }
      currDoge = player1.getDogecoin() + (player1Computer.getGPU() * 5) + (5); // calculates the total doge at the end of turn based on number of gpus.
      player1.setDogecoin(currDoge); //sets dogecoin to the new total with the gpou extras added in.
  
    
      if(player1.getFrustration() >= 100)
      {
          cout << "You have lost. You are too frustrated to contune. Try again next time." << endl; // checks if teh player has lost due to too much frustration
          //return 0;
          break;
      }
      if(game1.getCarmenProgress() >= 100) // checks if the player lost due to carmens progress at teh end of each turn
      {
        cout <<"You have lost. Carmen has won." << endl;
        //return 0;
        break;
      }
      if(player1Computer.getMaintenanceLevel()== 0) // checks if the player loses due to maintence level at the edn of each turn
      {
          cout << "You have lost. You maintence level is too low to continue. Try again next time." << endl;
          //return 0;
          break;
      }
    }
    

    //store results
    cout << "writing to file" << endl;
    ofstream outfile;
    outfile.open("Results.txt", ios::app);
    if (!outfile.fail())
    {
        cout << "Your reaults have been added to results.txt" << endl;
        // cout << player1.getName() << "," << game1.getTurns() << "," << game1.getTotalHackersDefeated() << "," << player1.getDogecoin() << endl;
        outfile << player1.getName() << "," << game1.getTurns() << "," << game1.getTotalHackersDefeated() << "," << player1.getDogecoin() << endl;
        outfile.close();
    }
    
    int i = 0;
    ifstream resultsFile; // reads form the results file 
    resultsFile.open("Results.txt");
    while(!resultsFile.eof())
    {
        getline(resultsFile, resultsString ); // save each players states intoa  string
        split2(resultsString, ',', turnsStrArr, arrSize); // split the stats into an array
        numTurns = stoi(turnsStrArr[1]);
        intPlayerTurns[i] = numTurns; // save the number of turns in one array
        playersNames[i] = turnsStrArr[0]; // save the names of players in another array
        i++;
    } 

    bubbleSort(intPlayerTurns, 50); //sorts the array of number of turns for a leaderboard.
    // cout << endl;
    // cout << endl;
    // cout << endl;
    cout << "*****Leaderboard*****" << endl;
    cout <<"Losers --> winners" << endl;
    cout << endl;

    for(int i = 0; i < 50; i++) // prints the leaderboard from losers to winners with the names and number of turns they took.
    {
        cout << "Name: " << playersNames[i] << endl;
        cout << "Number of turns taken: " << intPlayerTurns[49 - i] << endl;
    }
    







    return 0;
}