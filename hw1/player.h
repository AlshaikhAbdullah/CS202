//Abdullah Alshaikh 
//program 1 Maze Game 
//CS 202

//.h file that will have all libraries needed for the program plus const variables 
//and the again function prototype 
//also, the classes that will be taking care of the player which are, reward,node,names and player
//player will be derived from names and it will have a head pointer to node and node will
//contain reward

#include <iostream>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int TABLE = 20;
const int SIZE = 50;

bool again();

class reward
{
	public:
		reward();
		int createReward();
	protected:
		int  prize;

};
class node
{
	public:
		node();
		~node();
		node *& goNext();
		reward & get_reward();
		void connect(node * Next);
		void createRe();
		int  set_reward(int i);
	protected:
		reward * rewards;
		node * next;
};

class names
{
	public:
		names();
		~names();
		names(const names & id);
		names(char *first_name);
		void to_name(char f_name[]);
		void display_player();
	protected:
		char * name;
		
};

class player:public names
{

	public:
		player();
		~player();
		void copyin( player &temp,node * source);
	//	player(char * playername);
		int spin();
		bool check();
		int ask();
		node *& copy(player & to_copy);
	protected:
		node * head;
		int i;
		int trav(node *&head);
		void delete_all(node *&head);
		void copy_head(node * &dest,node * source);
};

