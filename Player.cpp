#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
   using namespace std;



//int intelligence, time, money, score;

   class Player
   {
   public:
      Player(string nameIn);
      
      string name;
      int intelligence;
      int time;
      int money;
   	
      string toString();
      int score();
      void move();
      void search();
      void read();
   	
   	
   
   
   
   };
   
	int main()
	{
		srand (time(NULL));
	}

   Player::Player(string nameIn)
   {
   	
      name = nameIn;
      intelligence = rand() % 17 + 8;
      time = rand() % 17 + 8;
      money = rand() % 17 + 8;
   }
	
   int Player::score()
   {
      return time * intelligence * money;
   }
	
   void Player::move()
   {
   	
      int num = rand() % 11 + 1;
      if (num > 5) //Move forward
      {
         //position change
      }
      else if (num == 1) //Encounter professor
      {
         int num = rand() % 5;
         time = time - num;
         
         num = rand() % 5;
         intelligence = intelligence + num;
      }
      else if (num == 2) //Encounter Grad Student
      {
         int num = rand() % 5;
         time = time - num;
      }
      else if (num == 3) //grade papers
      {
         int num = rand() % 5;
         time = time - num;
      
         num = rand() % 5;
         money = money + num;
      }
      else //grunt work
      {
         int num = rand() % 5;
         time = time - num;
      
         num = rand() % 5;
         intelligence = intelligence - num;
      }
   }
	
   void Player::read()
   {
      int num = 2;
      time = time - num;
   
      num = rand() % 7;
      intelligence = intelligence + num;
   }
	
   void Player::search()
   {
      int num = 1;
      time = time - num;
   
      num = rand() % 7;
      money = money + num;
   }

   string Player::toString()
   {
      cout << name << " has: \n" << "intelligence: " << intelligence << "\ntime: ";
      cout << time << "\nmoney: " << money; //<< "\nYou are " << stepsAway << "from the goal.";
   }