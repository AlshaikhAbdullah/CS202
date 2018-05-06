//Abdullah Alshaikh
//program 1 Maze Game
//CS 202

//.h file that will have the classes that will basiclly contorl the whole maze
//checkpoints,dll,vertex and maze
//dll will be derived from checkpoints as same as vertex, so checkpoint will be base class
//for both of the
//checkpoints will have a player class, and maze will have a pointer to vertex 

#include "player.h"

class checkpoints
{
	public:
		checkpoints();
		checkpoints(const checkpoints &obj);
		~checkpoints();
		void setName(int cpName);
		void display();
		int createPlayers();
		int get_place();
	protected:
		int many;
		int place;
		player * players; 
};
class dll:public checkpoints
{

	public:
		dll();
		dll( class vertex &);
		dll *& get_next();
		dll *& get_prev();
		class vertex *& get_adjacent();
		void connect_next(dll * nxt);
		void connect_prev(dll * prv);
	protected:
		class vertex * adjacent;
		dll * next;
		dll * prev;	
};

class vertex:public checkpoints
{
	public:
		vertex();
		vertex(const vertex &);
		~vertex();
		void createDll(vertex *element,int & count);
		void display();
		void connectPrev();
		dll *& get_head();
		int moving(vertex * location,int & new_location,player & to_copy,node *&source);
		int movingp2(vertex * location,int & new_location,player & to_copy,node *&source);

		int to_go(player & temp, node *source,int to_spin,int the_player);
		void get_info(int whos,node *&source,player & to_copy);
		int check_end();
		void to_ask(int the_player);
	protected:
		int count;
		int plays;
		void createDll(vertex * element,dll *&head);
		dll * head;		
		dll * newDLL(dll * head);
		dll * trav_player(dll * head,int go,int & stop);
		void display(dll * head);
		int check_end(dll *head);
		void remove_all(dll *&head);
};

//Graph Class 
class maze
{

	public:
		maze();
		maze(const maze &);
		~maze();
		void create();
		void insertEdge();
		void display(int &locate); 
		void moving_player1();
		void moving_player2();
		int check(int found);
		int movingBoth();
		bool useReward(int which,int playerFor,node * source);
	protected:
		vertex * adjacency_list;
		int size;
		int many;
		int random;
		int position;
};
