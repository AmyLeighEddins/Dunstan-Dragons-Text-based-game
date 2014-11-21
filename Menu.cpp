#include <iostream>
#include <cstdlib>
using namespace std;

class Menu
{
public:

	Menu();
	void showMain();
	int getChoice();
	void showActionMenu();
	int getAction();
	
			 
};

int main()
{
	
}

Menu::Menu()
{
	
}


void Menu::showMain()
{
	cout << "MAIN MENU:";
	cout << "\n1) Start a New Game of Dunstan and Dragons";
	cout << "\n2) View top 5 High Score";
	cout << "\n3) Quit";
}

int Menu::getChoice()
{
	int choice;
	cout << "Please choose and option (1 - 3):";
	cin >> choice;
	return choice;
}

void Menu::showActionMenu()
{
	cout << "\n1) Move (takes time and sometimes more)";
	cout << "\n2) Read technical papers(boost intelligence, takes time)";
	cout << "\n3) Search for loose change (boost money, takes time)";
	cout << "\n4) View character";
	cout << "\n5) Quit the game";
}

int Menu::getAction()
{
	int choice;
	cout << "Please choose and action (1 - 5):";
	cin >> choice;
	return choice;
}
