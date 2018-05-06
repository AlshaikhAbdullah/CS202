//Abdullah Alshaikh 
//program 1 Maze Game
//CS 202


//this .cpp file will contain the functions for the following classes, "maze,vertex,dll and checkpoints"
//I grouped them all togther following the instructor's instructions of not using a lot of files for the project
//these functions will basically will be controling the maze it self and how it will function
#include "maze.h"
checkpoints::checkpoints():many(0),place(0),players(NULL){}
checkpoints::checkpoints(const checkpoints &obj)
{}
//the destructor will check if there was data to delete, if ther was its going to delete it
checkpoints::~checkpoints()
{
	if(players)
	{
		delete [] players;
		players = NULL;
	}
}

//this function will basiclly set the checkpoint name passed from vertex
void checkpoints::setName(int cpName)
{
		place = cpName;
}
////testing function
void checkpoints::display()
{
	cout << place << " ";
}

//this function will create the players it will get the name of each player and passed to the player class and set it in the name class
int checkpoints::createPlayers()
{
	player temp;
	char gamer [SIZE];
	
	cout << "\nHow many players(1-2): ";
	cin >> many; cin.ignore(100,'\n');
	players = new player [many];
	
	if(many >= 2)
	{
		for(int i=0;i<many;++i)
		{
			cout << "Player " << i+1 << "  name: ";
			cin.get(gamer,SIZE,'\n'); cin.ignore(100,'\n');
			players[i].to_name(gamer);
		}
		return many;
	}
	else
	{
		cout << "Player's name: ";
		cin.get(gamer,SIZE,'\n'); cin.ignore(100,'\n');
		players[0].to_name(gamer);
		return many;
	}	
}

//this function will basically return the checkpoint number so i can which checkpoint is the last one
int checkpoints::get_place()
{
	return place;
}

////// Vertex functions ////////

//create the seed here along with initalizting each member to NULL
vertex::vertex():count(0),plays(0),head(NULL)
{
	srand(time(0));
}


//copy constructor 
vertex::vertex(const vertex &source)
{}
//the destructor for vertex will check if there was head first and then will recursive function to deallocate memory
vertex::~vertex()
{
	if(head) remove_all(head);
}

//a recursive funtion to deallocate memory for the double linked list
//it will do taht by tail recursion
void vertex::remove_all(dll *&head)
{
	if(!head) return;
	remove_all(head->get_next());
	if(head)
	{
		delete head;
		head = NULL;
	}
}

//this function will create the double linked list checkpoints and it will only create one 0 location which is the end there
//and the rest will be randomly generated numbers from 1 to 19
void vertex::createDll(vertex *element,int & count)
{
	int spots [TABLE];

	int save =0;
	if(place > 0 )
	{
		for(int i =0;i<3;++i)
		{
			for(int i=0;i<TABLE;++i)
				spots[i] = i;
			random_shuffle(&spots[0],&spots[20]); 
			save = spots[0];
			save = spots[save];
			if(count >= 1)
			{
				do
				{
					random_shuffle(&spots[0],&spots[20]); 
					save = spots[0];
					save = spots[save];
				}while(save ==0);
				++count;
				dll * current = newDLL(element->head);
				if(!element->head)
				{
					element->head = new dll(*element);
					element->head->connect_next(NULL);
					element->head->connect_prev(NULL);
					element->head->setName(save);
				}
				else
				{
					current->get_next() = new dll(*element);
					current->get_next()->setName(save);
					current->get_next()->get_prev() = current;
					current->get_next()->get_next() = NULL;
				}
			}
			else
			{
				if(save == 0)
					++count;
				//random_shuffle(&save[0],&save[3]);
				//int connect = save;
				dll * current = newDLL(element->head);
				if(!element->head)
				{
					element->head = new dll(*element);
					element->head->connect_next(NULL);
					element->head->connect_prev(NULL);
					element->head->setName(save);
				}
				else
				{	
					current->get_next() = new dll(*element);
					current->get_next()->setName(save);
					current->get_next()->get_prev() = current;
					current->get_next()->get_next() = NULL;
				}
			}
		}
	}		
		random_shuffle(&spots[0],&spots[20]);
}
/*void vertex::createDll(vertex * element, dll *&head)
{
	int spots [TABLE];
	for(int i=0;i<TABLE;++i)
		spots[i] = i;
	random_shuffle(&spots[0],&spots[20]);
	int save [3];
	for(int i =0;i<3;++i)
	{ 
		for(int i=0;i<3;++i)
			save[i]= spots[i];	
		random_shuffle(&save[0],&save[3]);
		int connect = save[0];
		dll * current = newDLL(element->head);
		if(!element->head)
		{
			element->head = new dll(*element);
			element->head->connect_next(NULL);
			element->head->connect_prev(NULL);
			element->head->setName(save[0]);
			return;
		}
		else if(!element->head->get_prev())
		{
			//current->get_next() = new dll(*element);
			dll * temp = new dll(*element);
			temp->setName(save[0]);
			temp->connect_prev(element->head);
			temp->connect_next(NULL);
			
		}
		else
		{
			dll * temp = new dll(*element);
			temp->setName(save[0]);
			temp->connect_prev(element->head);
			element->head->connect_next(temp);
		}
	}		
	createDll(element,head->get_next());

}
*/

//a recursive function to traverse through nodes and return that pointer so i can add a node
dll * vertex::newDLL(dll*head)
{
	if(!head) return head;
	if(!head->get_next())
			return head;
	return newDLL(head->get_next());
}

// display function which will call a recursive function to display the maze
void vertex::display()
{	
		display(head);
}
//a recursive funtion that will display a visual graph of the spot with the E letter to indicate the finish spot in the maze
void vertex::display(dll * head)
{
	if(!head) return;
	if(head->get_place() == 0)
		cout << "E ";
	else
		cout << "# ";
	return display(head->get_next());
}

//this function will only call a recursive funcion to check where's the end 
int vertex::check_end()
{
	return check_end(head);
}

//a recursive function that will traverse through the doubly linked list to check if the end is near
//as part of my reward system for the user
int vertex::check_end(dll * head)
{
	if(!head) return 0;
	if(head->get_place() == 0)
		return 1;
	else
		return 0;
	return check_end(head->get_next());
}


//this function will be taking care of moving player 2 through out the maze 
// it will get from the user the direction the user wants to take 
// and based on that it will call a function that will traverse through the DLL
//it will make some of these checkpoints blocks based on the mod 3 ==0 of the number of the place
int vertex::movingp2(vertex * location, int & new_location,player & to_copy,node * &source)
{
	int go =0; 
	int stop =0;
	int block =0;
			cout << "\nPlayer " << 2 << " Turn ( ";
			players[1].display_player();
			cout << " )\n1-Right.\n2-Left.\n3-Stright." << endl;
			cout << "Which way would you like to move(1-3): ";
			cin >> go; cin.ignore(100,'\n');
		//	source = players[1].copy(to_copy);
		//	players[1].~player();
			get_info(1,source,to_copy);
			block = location->get_place();
			//to traverse to get the directions 
			//one traversal for right, 2 traversals for left, three for staight
			dll *current = trav_player(location->head,go,stop);			
	//		current->display();
			// i can instead of traverse back i can just dont get the new 
			// location and return -1 to indicate that its bloced
			if(current)
			{
				if(current->get_place() % 3 == 0 && current->get_place()<16)
				{
					cout << "\nThis Turn is BLOCKED !! You will be returned to previous spot"  << endl;
					new_location = block;
					return -1;
				}
					
				new_location = current->get_place();
			//if(new_location % 3 !=0 && new_location >15)
			}
			
	return many;
}


//this function will do the same as the function above but for player 1 
int vertex::moving(vertex * location, int & new_location,player & to_copy,node * &source)
{
	int go =0; 
	int stop =0;
	int block =0;
		if(plays == many)
			plays=0;	
			cout << "\nPlayer " << 1 << " Turn ( ";
			players[0].display_player();
			cout << " )\n1-Right.\n2-Left.\n3-Stright." << endl;
			cout << "Which way would you like to move(1-3): ";
			cin >> go; cin.ignore(100,'\n');
			//source = players[0].copy(to_copy);
			//players[0].~player();
			get_info(0,source,to_copy);
			block = location->get_place();
			//to traverse to get the directions 
			//one traversal for right, 2 traversals for left, three for staight
			dll *current = trav_player(location->head,go,stop);			
	//		current->display();
			// i can instead of traverse back i can just dont get the new 
			// location and return -1 to indicate that its bloced
			++plays;
			if(current)
			{
				if(current->get_place() % 3 == 0 && current->get_place()<16)
				{
					cout << "\nThis Turn is BLOCKED !! You will be returned to previous spot"  << endl;
					new_location = block;
					return -1;
				}
					
			new_location = current->get_place();
			}
			
	return many;
}

//this function will be taking care of coping the information for a player into a instance of player that is temp
// so i can replace it into the new place
void vertex::get_info(int whos, node *&source, player & to_copy)
{
	source = players[whos].copy(to_copy);
	players[whos].~player();
}

// a traverse recursive function which will travers until how many times the user picked to turn
//and then return that place pointer
dll* vertex::trav_player(dll * head,int go,int &stop)
{
	if(!head) return head;
	if(stop == go)
		return head;
	return trav_player(head->get_next(),go,++stop);
}

// this function will basically take care of copying the player into a new spot and call the function that will spin the user for a reward unless 
//the user hit a block checkpoint
//it will always create too instances in case the other player jumper to the another player spot
int vertex::to_go(player & temp,node *source,int to_spin,int the_player)
{
		if(!players)
		{
			players = new player[2];
			players[the_player].copyin(temp,source);
				
			if(to_spin != -1)
			{
				cout << "\nYou will spin for a reward!!" << endl;
				cout << "\nYou got: ";
				return players[the_player].spin();
			}
		}
		else
		{
				players[the_player].copyin(temp,source);
				
			if(to_spin != -1)
			{
				cout << "\nYou will spin for a reward!!" << endl;
				cout << "\nYou got: ";
				return 	players[the_player].spin();
			}
		}
return 0;
}

//this function will baisaclly will be taking care of asking a friend as part of my rewarding system for this game
//it will go the player element that is passed into the function and based on that it will ask the correct player
//and catch the value that is returned and tell the other player what his friend suggested 
void vertex::to_ask(int the_player)
{
	int way =0;
	//char response;
	cout << "\nAsking Your Friend For directions... ";
	way = players[the_player].ask();
	if(way == 1)
		cout << "Right\n" << endl; 
	if(way == 2)
		cout << "Left\n" << endl;
	if(way == 3)
		cout << "Straight\n" << endl;
}

//this function will return the head pointer of the class
dll *& vertex::get_head()
{
	return this->head;
}
///// dll /////

//constructor to initialize values to null
dll::dll():adjacent(NULL),next(NULL),prev(NULL)
{
}

//the copy constructor that will make adjacent point to the element in the graph
dll::dll( class vertex & copy)
{
	this->adjacent = &copy;
}

//it will connect the next pointer of this class to the one passed in the args
void dll::connect_next(dll * nxt)
{
	this->next =nxt;
}

//it will connect the next pointer of this class to the one passed in the args
void dll::connect_prev(dll * prv)
{
	this->prev = prv;
}
//it will return the adjacent of this class
vertex *& dll::get_adjacent()
{
	return this->adjacent;
}
//it will return the next of this class
dll*& dll::get_next()
{
	return this->next;
}
//it will return the previous of this class to the calling routine 
dll*& dll::get_prev()
{
	return this->prev;
}

///// maze functions ////

//creating the table and  initialzing the head pointers to null and call the seed function 
maze::maze():size(TABLE),many(0)
{
	adjacency_list = new vertex [TABLE];
	for(int i=0;i<TABLE;++i)
	adjacency_list[i].get_head() = NULL;
	srand(time(0));	
}

maze::maze(const maze &source){}

//a destructor to deallocate memory and call the vertex destructor for every element in the table 
//and then delete the table itself
maze::~maze()
{
	if(adjacency_list)
	{
		for(int i=0;i<TABLE;++i)
		{
			adjacency_list[i].~vertex();
		}
		delete [] adjacency_list;
		adjacency_list =NULL;
	}
}

//this function will basically will display the maze with a P letter that refers to the player
//and # for an empty checkpoints, it will call vertex display to traverse there and display
//the checkpoints there 
void maze::display(int &locate)
{
	for(int i=0;i<TABLE;++i)
	{	
		if(i==locate)
			cout << "P ";
		else
			cout << "# ";
		adjacency_list[i].display();
		if( i % 2 == 0 && i < 20)
			cout << endl;
		/*
		adjacency_list[i].checkpoints::display();
		adjacency_list[i].display();
		cout <<endl;*/
	}
}

//this function will be taking care of setting a name for each checkpoint i have in the maze
//it will save numbers from 0 to 19 in an array of integers 
//then it will shuffle the array, then it will go throgh each vertex and set the name
//based on each element in the array 
void maze::create()
{
	int check [TABLE];
	for(int i=0;i<TABLE;++i)
		check[i]=i;

	random_shuffle(&check[0],&check[20]);
	for(int i=0;i<TABLE;++i)
		adjacency_list[i].setName(check[i]);
}
//this function will be creating edge into the graphs 
//it will put the players into a random location in the maze everytime it will put both
//players in the same location ,it will go into a for a loop to through each index 
//and create the edges, then it will catch the how many players will be playing
//then it will set the locations
void maze::insertEdge()
{
	int count =0;
	random = rand()%20;
	position =random;
	for(int i=0;i<TABLE;++i)
		adjacency_list[i].createDll(&adjacency_list[i],count);
	
	many =adjacency_list[random].createPlayers();
	display(random);
	position = random;
}

//this function will basically will be responsiable of call the players functions 
//based on how many players are playing the game
int maze::movingBoth()
{
	if(many ==1)
		moving_player1();
	else
	{
		moving_player1();
		moving_player2();
	}
	if(position == 0)
	{
		cout << "\n\nPlayer 2";
		return 1;
	}
	else if(random == 0)
	{
		cout << "\n\nPlayer 1";
		return 1;
	}
	else return 0;
} 
///this function will be helping in moving player 2 in the maze,
///it will start with creating an object of player and node source so it can copy the
///and store it,then it will go to the player spot get the info from DLL
///and then stor the player in the new location and also get the prize 
///then it will display the maze with the player location
void maze::moving_player2()
{
	node * source=NULL;
	int player2 =1;
	int there =0;
	int thePrize2 =0;
	player temp;
	do{
		there=adjacency_list[position].movingp2(&adjacency_list[position],position,temp,source);
		position= check(position);
		thePrize2 =adjacency_list[position].to_go(temp,source,there,player2);
		display(position);
	}while(useReward(thePrize2,player2,source));

}
///this function will be helping in moving player 1 in the maze,
///it will start with creating an object of player and node source so it can copy the
///and store it,then it will go to the player spot get the info from DLL
///and then stor the player in the new location and also get the prize 
///then it will display the maze with the player location
void maze::moving_player1()
{
	
	node * source=NULL;
	int player1 =0;
	int there =0;
	int thePrize1 =0;
	player temp;
	do{
		there=adjacency_list[random].moving(&adjacency_list[random],random,temp,source);
		random= check(random);
		thePrize1 = adjacency_list[random].to_go(temp,source,there,player1);
		display(random);
	}while(useReward(thePrize1,player1,source));

}
///this function is baisclly is going to look for the player in the graph and return that spot
///else it will return 1 if theres no one there, so if the player playing single mode
int maze::check(int found)
{
	for(int i =0;i<TABLE;++i)
	{
		if(adjacency_list[i].get_place() == found)
			return i;
	}
	return 1;
}


///This Function will be taking care of using the reward for players
///It will check the reward that it's passed in the argument and it will 
///check which player to do use the reward for.
///based on the player and the reward number, it will get the player place
///in the maze and then from there it will apply that reward for the player
///it will return true if the reward is a repeatable reward to rerun the do while loop
bool maze::useReward(int which,int playerFor,node * source)
{
	player temp;
	char response;
	if(which > 0)
	{
		cout << "\nWould You Like To Use it(y/n): ";
		cin >> response; cin.ignore(100,'\n');
		if(response == 'n')
			return false;
	}
	if(which == 1 && playerFor == 0)
	{
		if(random >= position)
		{
			cout << "\n\nThere Are No Friends Ahead\n" << endl;
			return false;
		}
		adjacency_list[random].get_info(playerFor,source,temp);
		random = position;
		adjacency_list[random].to_go(temp,source,-1,playerFor);
		cout << "\n\nYou were taken to PLAYER " << 2 << " spot ahead." << endl;
		return false;
	}
	else if(which == 1 && playerFor == 1)
	{
		if(position >= random)
		{
			cout << "\n\nThere Are No Friends Ahead\n" << endl;
			return false;
		}
		adjacency_list[position].get_info(playerFor,source,temp);
		position = random;
		adjacency_list[position].to_go(temp,source,-1,playerFor);
		cout << "\n\nYou were taken to PLAYER " << 1 << " spot ahead." << endl;
		return false;
	}	
	if(which == 2 && playerFor == 0)
	{
		if(random <= position)
		{
			cout << "\n\nThere Are No Friends Behind\n" << endl;
			return false;
		}
		adjacency_list[random].get_info(playerFor,source,temp);
		random = position;
		adjacency_list[random].to_go(temp,source,-1,playerFor);
		cout << "\n\nYou were taken to PLAYER " << 2 << " spot ahead." << endl;
		return false;
	}
	else if(which == 2 && playerFor == 1)
	{
		if(position <= random)
		{
			cout << "\n\nThere Are No Friends Behind\n" << endl;
			return false;
		}
		adjacency_list[position].get_info(playerFor,source,temp);
		position = random;
		adjacency_list[position].to_go(temp,source,-1,playerFor);
		cout << "\n\nYou were taken to PLAYER " << 1 << " spot ahead." << endl;
		return false;
	}
	if(which == 3)
	{
		cout << "\n\nYou Will Take Another Turn\n\n";
		return true;
	}
	if(which == 4)
	{
		cout << "\n\nYou Got Two Turns!!!LUCKY!!!\n\n";
		if(playerFor == 0)
			moving_player1();
		else
			moving_player2();
		return true;
	}
	if(which == 5)
	{
		if(playerFor == 0)
		{
			if(adjacency_list[random].check_end())
				cout << "\n\nThe End Is Really Close!!!!!\n\n";
			else
				cout << "\n\nThe End is Not Close.\n\n";	
		}
		else if(playerFor == 1)
		{
			if(adjacency_list[position].check_end())
				cout << "\n\nThe End Is Really Close!!!!!\n\n";
			else
				cout << "\n\nThe End is Not Close.\n\n";	
		}			
		return false;
	}
	if(which == 6)
	{
		if(playerFor == 0)
			adjacency_list[position].to_ask(playerFor+1);
		else
			adjacency_list[random].to_ask(playerFor-1);
		return false;
	}
	return false;
}
