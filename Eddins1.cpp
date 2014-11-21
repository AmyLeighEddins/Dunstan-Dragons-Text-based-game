/*
* Amy Eddins - ale0010
* Assignment 1B - "Dunstan and Dragons"
* June 21, 2011
* Eddins1B
**/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <fstream>
   using namespace std;
   
   class Menu;
   class Player;
   class Position;

	/*
	* POSITION CLASS
	* This class has an int for the col and row of a position,
	* methods to move North, South, East or West, a method for 
	* the steps away from the finish point, and it also contains
	* the maps.
	**/
    class Position
   {
     public: 
     
      Position(); //constructor
   	
      int col; //int for the column value
      int row; //int for the row value
      
      int getCol(); //returns col
      int getRow(); //returns row
      void setCol(int); //sets col
      void setRow(int); //sets row
      int getStepsAway(); //returns the number of steps away from finish
      bool moveWest(); //returns if you can move west
      bool moveEast(); //returns if you can move east
      bool moveNorth(); //returns if you can move north
      bool moveSouth(); //returns if you can move south
   
      int hall[7][7]; //map array
      int stepsArray[7][7]; //array of distances away
   };
	/*
	* PLAYER CLASS
	* This class holds the player's name, money, time, intelligence,
	* position, calculates his or her score, and can make the
	* player move, read or search.
	**/
    class Player
   {
   public:
   
      Player(); //constructor
      
      string name; //name of player
      int intelligence; //attributes
      int time;
      int money;
      
      Position position; //position object
      
      void toString(); //prints players stats
      int score(); //calculates score
      bool move(char); //moves the character
      void search(); //searches for loose change
      void read(); //read technical papers
      void setName(string); //sets the player's name
   };
   /*
	* MENU CLASS
	* This class holds the Main menu and the Action menu.
	* It also writes and reads the High Scores text file.
	**/
    class Menu
   {
   public:
    
      Menu(); //constructor
      void importScore(string, int); //import the new score
      void showMain(); //show main menu
      string getChoice(); //get main menu choice
      void showActionMenu(); //show action menu
      string getAction(); // get action menu choice
   };
   /*
	* MENU FUNCTIONS
	*
	*
	**/
    Menu::Menu()
   {
   }
   
    void Menu::importScore(string nameIn, int scoreIn)
   {
      ofstream outStream;
      outStream.open("HighScores.txt", ios::app);
      outStream << nameIn << " " << scoreIn << endl;
      outStream.close();
   }
   
    void Menu::showMain()
   {
      cout << "\nMAIN MENU:" << endl;
      cout << "1) Start a New Game of Dunstan and Dragons" << endl;
      cout << "2) View top 5 High Scores" << endl;
      cout << "3) Quit" << endl;
   }

    string Menu::getChoice()
   {
      string choice;
      cout << "\nPlease choose an option (1 - 3): ";
      cin >> choice;
      return choice;
   }

    void Menu::showActionMenu()
   {
      cout << "1) Move (takes time and sometimes more)" << endl;
      cout << "2) Read technical papers(boost intelligence, takes time)" << endl;
      cout << "3) Search for loose change (boost money, takes time)" << endl;
      cout << "4) View character" << endl;
      cout << "5) Quit the game" << endl;
   }

    string Menu::getAction()
   {
      string choice;
      cout << "Please choose an action (1 - 5): " << endl;
      cin >> choice;
      return choice;
   }
   
	/*
	* PLAYER FUNCTIONS
	*
	*
	**/
    Player::Player()
   {
      name = "<no name>";
      intelligence = rand() % 17 + 9;
      time = rand() % 17 + 9;
      money = rand() % 17 + 9;
   }
    void Player::setName(string nameIn)
   {
      name = nameIn;
   }
	
    int Player::score()
   {
      return time * intelligence * money;
   }
	
    bool Player::move(char charIn)
   {
      bool valid;
      do
      {
         if ((charIn == 'n' || charIn == 'N') && (position.moveNorth()))
         {
            position.setCol(position.getCol() - 1);
            valid = true;
         }
         else if (charIn == 's' || charIn == 'S' && (position.moveSouth()))
         {
            position.setCol(position.getCol() + 1);
            valid = true;
         }
         else if (charIn == 'w' || charIn == 'W' && (position.moveWest()))
         {
            position.setRow(position.getRow() - 1);
            valid = true;
         }
         else if (charIn == 'e' || charIn == 'E' && (position.moveEast()))
         {
            position.setRow(position.getRow() + 1);
            valid = true;
         }
         else
         {
            valid = false;
         }
      } while (!valid);
      int num = rand() % 10 + 1;
      if (num > 5) //Move forward
      {
         cout << "\nYou didn't run into anything. Good job!" << endl;
      }
      else if (num == 1) //Encounter professor
      {
         cout << "\nYou encountered a professor!" << endl;
         int num = rand() % 4;
         time = time - num;
         cout << "You lost " << num << " time and ";
         num = rand() % 5;
         intelligence = intelligence + num;
         cout << "gained " << num << " intelligence!" << endl;
      }
      else if (num == 2) //Encounter Grad Student
      {
         cout << "\nYou encountered a Grad Student!" << endl;
         int num = rand() % 2;
         time = time - num;
         cout << "You lost " << num << " time!" << endl;
      }
      else if (num == 3) //grade papers
      {
         cout << "\nYou had to grade papers!" << endl;
         int num = rand() % 2;
         time = time - num;
         cout << "You lost " << num << " time and ";
         num = rand() % 5;
         money = money + num;
         cout << "gained " << num << " money!" << endl;
      }
      else //grunt work
      {
         cout << "\nYou encountered grunt work!" << endl;
         int num = rand() % 2;
         time = time - num;
         cout << "You lost " << num << " time and ";
         num = rand() % 5;
         intelligence = intelligence - num;
         cout << "gained " << num << " intelligence!" << endl;
      }
      return valid;
   }
	
    void Player::read()
   {
      cout << "\nYou read strangely insightful papers left on the floor!" << endl;
      int num = 1;
      time = time - num;
      cout << "You lost " << num << " time and ";
      num = rand() % 5;
      intelligence = intelligence + num;
      cout << "gained " << num << " intelligence!" << endl;
   }
	
    void Player::search()
   {
      cout << "\nYou found some loose change!" << endl;
      int num = 1;
      time = time - num;
      cout << "You lost " << num << " time and ";
      num = rand() % 5;
      money = money + num;
      cout << "gained " << num << " money!" << endl;
   }

    void Player::toString()
   {
      cout << "\n" << name << " has: " << endl;
      cout << "intelligence: " << intelligence << endl;
      cout << "time: " << time << endl;
      cout << "money: $" << money << ".00 "<< endl;
   }
   
	/*
	* POSTITION FUNCTIONS
	*
	*
	**/
    Position::Position()
   {
   	
      int num = rand() % 3 + 1;
      if (num == 1)
      {
         int staticMap[7][7] = {
            { 2, 1, 0, 1, 1, 1, 1 },
            { 0, 1, 1, 1, 0, 0, 1 },
            { 0, 0, 1, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1, 1, 1 },
            { 0, 1, 1, 1, 1, 0, 0 },
            { 0, 0, 1, 0, 0, 0, 0 },
            { 1, 1, 1, 1, 1, 3, 0 }
            };
         int staticArray[7][7] = {
            { 21, 20, 0, 16, 15, 14, 13 },
            { 0, 19, 18, 17, 0, 0, 12 },
            { 0, 0, 19, 0, 0, 0, 11 },
            { 0, 0, 0, 0, 8, 9, 10 },
            { 0, 6, 5, 6, 7, 0, 0 },
            { 0, 0, 4, 0, 0, 0, 0 },
            { 5, 4, 3, 2, 1, 0, 0 }
            };
         for (int x = 0; x < 7; x++)
            for (int y = 0; y < 7; y++)
               hall[x][y] = staticMap[x][y];
         for (int x = 0; x < 7; x++)
            for (int y = 0; y < 7; y++)
               stepsArray[x][y] = staticArray[x][y];
      }
      else if (num == 2)
      {
         int staticMap[7][7] = {
            { 2, 1, 0, 1, 1, 1, 0 },
            { 0, 1, 0, 1, 0, 1, 1 },
            { 0, 1, 1, 1, 0, 0, 1 },
            { 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 1, 1, 1, 0, 0 },
            { 0, 0, 1, 0, 1, 0, 0 },
            { 0, 0, 0, 0, 1, 1, 3 }
            };
         int staticArray[7][7] = {
            { 20, 19, 0, 13, 12, 11, 0 },
            { 0, 18, 0, 14, 0, 10, 9 },
            { 0, 17, 16, 15, 0, 0, 8 },
            { 0, 0, 0, 0, 5, 6, 7 },
            { 0, 0, 6, 5, 4, 0, 0 },
            { 0, 0, 7, 0, 3, 0, 0 },
            { 0, 0, 0, 0, 2, 1, 0 }
            };
         for (int x = 0; x < 7; x++)
            for (int y = 0; y < 7; y++)
               hall[x][y] = staticMap[x][y];
         for (int x = 0; x < 7; x++)
            for (int y = 0; y < 7; y++)
               stepsArray[x][y] = staticArray[x][y];
      }
      else
      {
         int staticMap[7][7] = {
            { 2, 0, 0, 0, 0, 0, 0 },
            { 1, 0, 0, 1, 1, 1, 0 },
            { 1, 0, 1, 1, 0, 1, 0 },
            { 1, 1, 1, 0, 1, 1, 1 },
            { 0, 0, 0, 1, 1, 0, 0 },
            { 0, 1, 1, 1, 0, 0, 0 },
            { 0, 0, 0, 1, 1, 1, 3 }
            };
         int staticArray[7][7] = {
            { 20, 0, 0, 0, 0, 0, 0 },
            { 19, 0, 0, 12, 11, 10, 0 },
            { 18, 0, 14, 13, 0, 9, 0 },
            { 17, 16, 15, 0, 7, 8, 9 },
            { 0, 0, 0, 5, 6, 0, 0 },
            { 0, 6, 5, 4, 0, 0, 0 },
            { 0, 0, 0, 3, 2, 1, 0 }
            };
         for (int x = 0; x < 7; x++)
            for (int y = 0; y < 7; y++)
               hall[x][y] = staticMap[x][y];
         for (int x = 0; x < 7; x++)
            for (int y = 0; y < 7; y++)
               stepsArray[x][y] = staticArray[x][y];
      }
      row = 0;
      col = 0;	
   }
	
    int Position::getCol()
   {
      return col;
   }
    int Position::getRow()
   {
      return row;
   }
   
    void Position::setCol(int colIn)
   {
      col = colIn;
   }
	
    void Position::setRow(int rowIn)
   {
      row = rowIn;
   }
   
    int Position::getStepsAway()
   {
      int num = stepsArray[col][row];
      return num;
   }
 
    bool Position::moveWest()
   {
   //is it out of bounds
      if (row - 1 < 7 && row - 1 >= 0)
      {
      //is there a 1, 2, or 3 there
         if (hall[col][row - 1] == 3 
            || hall[col][row - 1] == 1
         	|| hall[col][row - 1] == 2) 
         {
            return true;
         }
         else 
         { 
            return false;
         }
      }
      else
      {
         return false;
      }
   }
    bool Position::moveEast()
   {
   //is it out of bounds
      if (row + 1 < 7 && row + 1 >= 0)
      {
      //is there a 1, 2, or 3 there
         if (hall[col][row + 1] == 3 
            || hall[col][row + 1] == 1
         	|| hall[col][row + 1] == 2)
         {
            return true;
         }
         else 
         { 
            return false;
         }
      }
      else
      {
         return false;
      }
   
   }
    bool Position::moveNorth()
   {
   //is it out of bounds
      if (col - 1 < 7 && col - 1 >= 0)
      {
      //is there a 1, 2, or 3 there
         if (hall[col - 1][row] == 2 
            || hall[col - 1][row] == 1
         	|| hall[col - 1][row] == 3)
         {
            return true;
         }
         else 
         { 
            return false;
         }
      }
      else
      {
         return false;
      }
   }
    bool Position::moveSouth()
   {
   //is it out of bounds
      if (col + 1 < 7 && col + 1 >= 0)
      {
      //is there a 1, 2, or 3 there
         if (hall[col + 1][row] == 3 
            || hall[col + 1][row] == 1
         	|| hall[col + 1][row] == 2)
         {
            return true;
         }
         else 
         { 
            return false;
         }
      }
      else
      {
         return false;
      }
   }

	/*
	* MAIN
	*
	*
	**/
    int main()
   {
      bool type;
      string name;
      srand (time(NULL));
      Player newPlayer;
      Menu Menu;
      Position Position;
      
      do
      {
         Menu.showMain();
         string choice = Menu.getChoice();
         if (choice == "1")
         {		
            cout << "\nWhat's your name? ";
            cin >> name;
            newPlayer.setName(name);
            newPlayer.toString();
            do
            {
               if (newPlayer.position.getStepsAway() == 0 && newPlayer.position.hall[newPlayer.position.getCol()][newPlayer.position.getRow()] == 3)
               {
                  cout << "\nYOU WON!!!!" << endl;
                  cout << "Your score is " << newPlayer.score() << endl;
                  Menu.importScore(newPlayer.name, newPlayer.score());
                  type = true;
                  break;
               }
               if (newPlayer.intelligence <= 0 || newPlayer.time <= 0 || newPlayer.money <= 0)
               {
                  cout << "\nYOU JUST LOST THE GAME AND THE DUNSTAN AND DRAGONS GAME TOO!" << endl;
                  type = true;
                  break;
               }
               if (newPlayer.position.getStepsAway() == 0 && newPlayer.position.hall[newPlayer.position.getCol()][newPlayer.position.getRow()] != 3)
               {
                  cout << "You went off the path!\n";
               }
               else
               {
                  cout << "You are " << newPlayer.position.getStepsAway() << " steps away from the finish point." << endl;
               }
               cout << "You can move: " << endl;
               if (newPlayer.position.moveNorth())
               {
                  cout << "(N)orth " << endl;
               }
               if (newPlayer.position.moveSouth())
               {
                  cout << "(S)outh " << endl;
               }
               if (newPlayer.position.moveEast())
               {
                  cout << "(E)ast " << endl;
               }
               if (newPlayer.position.moveWest())
               {
                  cout << "(W)est " << endl;
               }
               Menu.showActionMenu();
               string action = Menu.getAction();
               if (action == "1")
               {
                  char dir;
                  do
                  {
                     cout << "Which direction do you want to move (single character): ";
                     cin >> dir;
                     
                  } while(!newPlayer.move(dir));
                  newPlayer.toString();
                  type = false;
               //move
               }
               else if (action == "2")
               {
                  newPlayer.read();
                  newPlayer.toString();
                  type = false;
               }
               else if (action == "3")
               {
                  newPlayer.search();
                  newPlayer.toString();
                  type = false;
               }
               else if (action == "4")
               {
                  newPlayer.toString();
                  type = false;
               }
               else if (action == "5")
               {
               //quit
                  type = true;
               }
               else
               {
                  Menu.showActionMenu();
                  string action = Menu.getAction();
                  type = false;
               }
            } while (!type);
            type = false;
         }
         else if (choice == "2")
         {
            ifstream outStream;
            outStream.open("HighScores.txt");
            char ch;
            cout << "\n The High Scores are: \n";
            if(outStream.is_open())
            {
               while (!outStream.eof())
               {
               	
                  outStream >> ch;
                  cout << ch;
               }
            }
            else
            {
               cout << "No High Scores";
            }
            outStream.close();
            type = true;
         }
         else if (choice == "3")
         {
            type = true;
         }
         else
         {
            Menu.showMain();
            string choice = Menu.getChoice();
            type = false;
         }
      } while (!type);
      return 0;
   }