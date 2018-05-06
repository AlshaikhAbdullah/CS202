// Abdullah Alshaikh 
//Program-1 Maze project
//CS 202
//this .h file will have only the mazeGame class all functions comments in .cpp 
#include "maze.h"

class mazeGame
{
	public:
		mazeGame();
		mazeGame(const mazeGame &);
		~mazeGame();
		void create_teams();
		void start();
	protected:
		char * teamOne;
		char * teamTwo;
		maze * mazes;
};


