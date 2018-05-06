//Abdullah Alshaikh
//CS 202 - Program-1
//MAZE-GAME

//main.cpp where an object of mazeGame will be created and the functions that will strat the game to be called 
#include "CSmazeGame.h"
using namespace std;


int main()
{
//	maze obj;
//	obj.create();	
//	obj.insertEdge();
//	obj.display();
	mazeGame obj;
	char response;

		cout << "Welcome To The Maze !!" << endl;
		cout << "In This Game You Can Play Multiplayer In Seprate Teams(2 Teams, 4 Players)\nOr You Can Play Co-op In The Same Team(1 Team, 2 Players)";
		cout << "\nOr You Can Play Single Mode(1 Team, 1 Player)" << endl;
		cout << "Enter Any Key To Contunie...";
		cin >> response; cin.ignore(100,'\n');	
		cout << "At Every CheckPoint You will Spin For One Of The Following Rewards: " << endl;
		cout << "1- Jump To Friend's Location Ahead of You.\n2- Jump To Friend's Location Behind You.";
		cout << "3- Take Another Turn.\n4- Take Two Turns.\n5- Check If The End Is Near You.";
		cout << "\nEnter Any Key To Contunie...";
		cin >> response; cin.ignore(100,'\n');
		cout << "\nCarefull: You Can Be Stuck in this Maze Forever, So You Need To Keep Tack Of Your Turns In Each Position:" << endl;
		cout << "Are You Ready? (Enter Any key To Continue): ";
		cin >> response; cin.ignore(100,'\n'); 
		obj.create_teams();
		obj.start();


return 0;
}
