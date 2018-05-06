//Abdullah Alshaikh
//CS 202 Program-1
//MAZE-GAME
#include "player.h"
///// reward /////
reward::reward():prize(0)
{
	srand(time(0));
}

//this function will basically randomly generetae a reward for the player with the best reward has a little chance to get 
//by using a for loop for it 3 times 
//and based on the number from 0 to 6 it will display for the user the reward and return it to the calling routine 
int reward::createReward()
{
	if(prize == 0)
	{
		int a_num =0;
		a_num = rand() % 7;
		for(int i =0; i < 3;++i) // so that the best reward becomes harder to get
		{
			if(a_num == 4)
				a_num = rand() % 7;
		}
		prize = a_num;
		if(prize == 0)
			cout << "You didn't get a reward :(\n" <<endl;
		if(prize ==1)
			cout << "Join a friend ahead.\n" << endl;
		if(prize == 2)
			cout << "Join a friend behind.\n" << endl;
		if(prize == 3)
			cout << "Take another turn.\n" << endl;
		if(prize == 4)
			cout << "Take Two Turns.\n" << endl;
		if(prize == 5)
			cout << "Check If You're a Turn Away From the End.\n" << endl;
		if(prize == 6)
			cout << "Ask a Friend For Directions.\n" << endl;
	}
	return prize;
}


///// node /////
node::node():next(NULL)
{}
// a destructor for the node to deallocate the array of rewards
node::~node()
{
	if(rewards)
	{
		delete [] rewards;
		rewards = NULL;
	}
}

// a function that it will return the reward array to the calling routine so it can be copied 
reward & node::get_reward()
{
	return rewards[0];
}
//it will return the next pointer for this class node
node *& node::goNext()
{
	return this->next;
}
//this function will connect the next pointer of this class to the pointer passed in the args
void node::connect(node * Next)
{
	this->next = Next;
}

//this function will create an array of rewards with one element
void node::createRe()
{
	rewards = new reward [1];
}

//this function will return whatever the prize is from the create reward function back to the calling routine
int node::set_reward(int i)
{
	return rewards[i].createReward();
}
///// names /////
names::names():name(NULL)
{}

//the destructor for names class that will check if there was data and the it will delete it if there was
names::~names()
{
	if(name)
	{
		delete [] name;
		name = NULL;
	}
}
names::names(const names & id)
{}
names::names(char * first_name){}

//this function will set the name of the player to the class char 
//by getting the length of the array passed and create new char for the data member
void names::to_name(char f_name[])
{	
	int len =0;
	len = strlen(f_name);
	name = new char [len+1];
	strcpy(name,f_name);
}

//this function will baisclly will display play the name member 
void names::display_player()
{
	if(name)
	cout << name;
}
///// player /////

player::player():head(NULL){}

//a destructor that will call a recursive function only
player::~player()
{
	if(head) delete_all(head);
}

//a recursive function that will do tail recursion to deallocate memory of the linear linked list of arrays of rewards
void player::delete_all(node *&head)
{
	if(!head) return;
	else delete_all(head->goNext());
	if(head)
	{
		delete head;
		head = NULL;
	}
}

//this function will be coping the players name from a temp player object into this class memeber and it will call the copy head funtion to do the rest
void player::copyin( player & temp, node * source)
{
	if(name)
	{
		delete [] name;
		name = NULL;
	}
	int len =0;
//	cout << temp.name << endl;
	len = strlen(temp.name);
	name = new char[len+1];
	strcpy(name,temp.name);	
//	copy_head(head,source);	 // to copy the linear linked list of arrays but since im not giving the user the option to use i commented it out
}

//this function will copy the source linked list of rewards for the player to the dest head which is the one in the classs recursively 
//so it store multiple rewards for a player 
void player::copy_head(node * &dest,node *source)
{
	if(!source) return;
	head = new node;
	head->get_reward() = source->get_reward();
	copy_head(dest->goNext(),source->goNext());
}
//this function will baiscally created the linear linked list of arrays to spin a reward for the player and return that reward to 
//the calling routine so it can be used if there was noting else it will call a recursive function
int player::spin()
{
	if(!head)
	{
		int the_reward =0;
		head = new node;
		head->createRe();
		the_reward =head->set_reward(i);
		head->connect(NULL); 
		
		return the_reward;
	}
	else
	return 	trav(head);
}

//a recursive function that will traverse untill the end of the list to create a new node to stroe teh reward by calling the reward functions
int player::trav(node *&head)
{
	if(!head)
	{
		int the_reward =0;
		node * temp = new node;
		temp->createRe();
		the_reward =temp->set_reward(i);
		temp->connect(NULL);
		head->connect(temp);
		return the_reward;
	}
	return trav(head->goNext());
}

//a function to store the players inforamtion to a temp player object and return the head pointer
//so it can be used for the movng process of the players
node *& player::copy(player & to_copy)
{
	if(to_copy.name)
	{
		delete [] to_copy.name;
		to_copy.name = NULL;
	}

	int len = 0;
	len = strlen(name);
	to_copy.name = new char [len+1];
	strcpy(to_copy.name,name);
	to_copy.i = i;
	return head;
}

//just a test function to check if there was a player
bool player::check()
{
	if(head) return true;
	else return false;
}

//a function that will ask the user for a direction as part of my rewarding system for the game
//and it will return the player's answer to tje calling routine 
int player::ask()
{
	int q =0;
	cout << "\n\n::::" << name << ":::: Which way Your Friend Should Take\n(1-Right,2-Left,3-Straight): ";
	cin >> q; cin.ignore(100,'\n'); 	
	cout << "Your Friend " << name << " Says You Should Go ";
	return q;
}


//just a function to see if the user would to continue or not and returns false if yes
//true if not
bool again()
{
	char response;
	cout << "Would You Like To Continue Playing(y/n): ";
	cin >> response; cin.ignore(100,'\n');
	if(response == 'n') return true;
	else return false;
}
