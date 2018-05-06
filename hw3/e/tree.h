/*
   Rupika Dikkala
   CS 202
   Program #3 
   File name: tree.h

   In this program, we will construct a 
   contact system where the user can view
   various contacts in the emergency address
   book. This .h file primarily concerns 
   the functionality of the balanced tree.
 */

// ************* CITATION *************** //
// My algorithm for the implementation of the 
// red and black tree was based off the ideas 
// presented in the wikipedia article for 
// balanced trees!

#include <iostream> 
#include <cstring> 
#include <fstream> 
using namespace std; 

#ifndef TREE
#define TREE

// This is the tree class. This class primarily
// manages the whole tree and is the base class 
// for the entire hierarchy. NOTE: Implementing
// a red black tree for this program.
class tree
{
   public:
      tree();					// constructor
      ~tree();					// deconstructor
      int w_remove();				// remove wrapper
      int remove_tree(class tree_node *& root);	// removes the tree
      int compare(const char * input);		// compare input func
      int wrapper_insert(char *, class family &); // wrapper insert
      void wrapper_display();			// wrapper display
      int display_tree(class tree_node * root);	// display wrapper
      int node_disp(class tree_node * root);	// display from node
      int w_retrieve(const char * match);	// wrapper retrieve
      int insert(class tree_node *&, class tree_node *, char *,class family &); // insert func
      int case1(class tree_node *); 		// check if root is red
      int case2(class tree_node *); 		// check for black parent
      int case3(class tree_node *); 		// making parent and uncle black
      int case4(class tree_node *); 		// check case if node added inside
      int case5(class tree_node *); 		// check case if node added outside
      int rotate_left(class tree_node *); 	// rotates the tree left
      int rotate_right(class tree_node *); 	// rotates the tree right
//      friend ostream & operator << (ostream & display, tree & t);

   protected:
	 tree_node * root;				// root pointer
};

// This is the tree_node class. A tree HAS
// a tree_node. The tree_node also HAS a family
// class. NOTE: This is a node for a red-black
// tree.
class tree_node
{
   public:
      tree_node();				// constructor
      tree_node(class family & data);	// constructor w args
      ~tree_node();				// deconstructor
      tree_node *& get_left(); 			// get left func
      tree_node *& get_right(); 		// get right func
      tree_node *& set_parent(tree_node * val); // parent setter
      tree_node *& get_parent();		// parent getter
      bool set_isred(bool set);			// is_red setter
      bool get_isred();				// is_red getter
      tree_node *& get_gparent();		// grandparent getter
      tree_node *& get_ggp();			// great grandparent getter
      tree_node *& get_uncle();			// uncle getter
      int compare(const char * input);		// compare func
      int display(tree_node * root);		// display func
      int remove_data();			// remove the data in node
      int retrieve_match(tree_node *, const char *); // retrieve func

   protected:
      tree_node * left; 			// left pointer
      tree_node * right; 			// right pointer
      tree_node * parent; 			// parent pointer
      class family * f_head; 			// head pointer for LLL
      bool is_red; 				// flag to check if red or black
};

#endif
