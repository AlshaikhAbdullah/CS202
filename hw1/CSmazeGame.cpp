//Abdullah Alshaikh
//program-1 Maze Game
//CS 202

//this .cpp file will have the mazeGame class functions implamentations 
//constructor and destructors
//these functions will help operate the game all the way from the top

#include "CSmazeGame.h"
//the constructor using the intialzition list 
mazeGame::mazeGame():teamOne(NULL),teamTwo(NULL),mazes(NULL){}
mazeGame::mazeGame(const mazeGame &){}
//the destructor will dellaocate memory thats been used in the class by checking if there was something to delete first
mazeGame::~mazeGame()
{
	if(teamOne)
	{
		delete [] teamOne;
		teamOne = NULL;
	}
	if(teamTwo)
	{
		delete [] teamTwo;
		teamTwo = NULL;
	}
	if(mazes)
	{
		delete [] mazes;
		mazes = NULL;
	}
}

//this function will get from the user the names of the teams that are going to play and based on that
//then it will create the mazes if there were two or just one maze if there were one teams only
void mazeGame::create_teams()
{
	char temp [SIZE];
	int len =0;
	int teams =0;
		cout << "How many teams are going to play(1-2): ";
		cin >> teams; cin.ignore(100,'\n');
		
		if(teams == 1)
		{
			mazes = new maze [1];
			cout << "What is the name of the team: ";
			cin.get(temp,SIZE,'\n'); cin.ignore(100,'\n');
			len = strlen(temp);
			teamOne = new char [len+1];
			strcpy(teamOne,temp);
		}
		else
		{
			mazes = new maze [2];
			cout << "What is the first team's name: ";
			cin.get(temp,SIZE,'\n'); cin.ignore(100,'\n');
			len = strlen(temp);
			teamOne = new char [len+1];
			strcpy(teamOne,temp);
			cout << "What is the second team's name: ";
			cin.get(temp,SIZE,'\n'); cin.ignore(100,'\n');	
			len = strlen(temp);
			teamTwo = new char [len+1];
			strcpy(teamTwo,temp);
		}
}


//this function will call the functions that will create the maze and the players for each team
//and the it will be taking care of running the game and know which player from which team won the game
//also it will give the user choice after 5 turns to end the game if the user wanted to
void mazeGame::start()
{
	bool end = false;
	int ask =0;
	if(teamTwo) // if there were multiple teams
	{
		for(int i= 0;i<2;++i)
		{
			if(i==0)
				cout << "\n::Team " << teamOne << " Players::" << endl;
			if(i==1)
				cout << "\n::Team " << teamTwo << " Players::" << endl;
			mazes[i].create();
			mazes[i].insertEdge();
		}
		while(!end)
		{
			if(ask > 5) ask =0;
			cout << "\n::: " <<  teamOne << " Turn:::" << endl;
			if(mazes[0].movingBoth())
			{
				end = true;
				cout << " of Team::: " << teamOne << " ::: Won!!!!" << endl;
			}
			cout << "\n::: " << teamTwo << " Turn :::" << endl; 
			if(mazes[1].movingBoth())
			{
				end = true;
				cout << "of Team::: " << teamTwo << " ::: Won!!!!" << endl;
			}
			if(again()) 
			{
				cout << "You Have Ended The Game\n\nGood Bye\n";
				end = true;
			}
			++ask;
		}
	}
	else // if there were one team playing only
	{
		cout << "::Team " << teamOne << " Players::" << endl;
		mazes[0].create();
		mazes[0].insertEdge();
		while(!end)
		{
			if(ask >5) ask =0;
			if(mazes[0].movingBoth())
			{
				cout << " Won The Game !!!" <<endl;
				end = true;
			}
			if(again())
			{
				cout << "You Have Ended The Game\n\nGood Bye\n";
				end = true;
			}
			++ask;
		}
	}
}
