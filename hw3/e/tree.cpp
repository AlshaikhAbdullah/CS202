/*
   Rupika Dikkala
   CS 202
   Program #3 
   File name: tree.cpp

   In this program, we will construct a 
   contact system where the user can view
   various contacts in the emergency address
   book. This cpp file primarily concerns 
   the functionality of the LLL in each tree node.
 */

// ************* CITATION *************** //
// My algorithm for the implementation of the 
// red and black tree was based off the ideas 
// presented in the wikipedia article for 
// balanced trees!

#include "LLL.h"
#include "tree.h"

// Default constructor for tree class
tree::tree(): root(NULL)
{

}

// Destructor for tree class
tree::~tree()
{
   w_remove();


   if(root)
      delete root;
   root = NULL;
}

// Default constructor for tree_node class
tree_node::tree_node(): left(NULL), right(NULL), parent(NULL), f_head(NULL), is_red(true)
{

}

// tree_node constructor w/ args
tree_node::tree_node(family & data)
{
   f_head = new family(data);
   f_head->copy_wrapper(data);
}

// Destructor for tree_node class
tree_node::~tree_node()
{
   remove_data();
   
   if(parent)
      delete parent;
   parent = NULL;

   if(f_head)
      delete f_head;
   f_head = NULL;

   left = NULL;
   right = NULL;
}

// Get left function
tree_node *& tree_node::get_left()
{
   return left;
}

// Get right function
tree_node *& tree_node::get_right()
{
   return right;
}

// Get parent function
tree_node *& tree_node::get_parent()
{
   return parent;
}

// Set parent function
tree_node *& tree_node::set_parent(tree_node * val)
{
   parent = val;
}

// Get grandparent function
tree_node *& tree_node::get_gparent()
{
   return parent->get_parent();
}

// Get great grandparent function
tree_node *& tree_node::get_ggp()
{
   return parent->parent->get_parent();
}

// Get uncle function
tree_node *& tree_node::get_uncle()
{
   tree_node * gparent = get_gparent();

   if(gparent->get_left() == parent)
      return gparent->get_right();

   else
      return gparent->get_left();
}

// Get the bool pointer
bool tree_node::get_isred()
{
   return is_red;
}

// Set the bool pointer
bool tree_node::set_isred(bool set)
{
   is_red = set;
}

// Compare function for input in main
int tree_node::compare(const char * input)
{
   // returns the compare function in family class
   return f_head->w_compare_name(input);
}

// Wrapper for the insert function
int tree::wrapper_insert(char * input, family & data)
{
   // Return the func in tree_node class
   return insert(root, NULL, input, data);
}

// Insert a node into red black tree!
int tree::insert(tree_node *& root, tree_node * parent, char * input, family & data)
{
   // If there's no root
   if(!root) 
   {
      // Create a new node
      root = new tree_node(data); 

      // Set pointers to null
      root->get_left() = NULL; 
      root->get_right() = NULL; 

      // If there's no get_parent(),
      // set root to the get_parent()
  //    if(!root->get_parent()) 
//	 root->get_parent() = get_parent(); 

      // else, set parent to this
  //    else 
//	 get_parent() = this; 

      root->set_parent(parent);

      // set the flag to red 
      root->set_isred(true); 

      // Check the root
      return case1(root); 
   }

   // Compare last names, if lesser then go
   // to get_left()
   if(root->compare(input) < 0) 
      return insert(root->get_left(), parent, input, data);

   // Keep traversing
   else 
      return insert(root->get_right(), parent, input, data);
}

// When root is red, set it to black
int tree::case1(tree_node * root)
{
   // Set to black if no parent
   if(!root->get_parent())
   {
      root->set_isred(false); 
      return 1;
   }

   // else go to case 2
   else
      return case2(root);
}

// Check if the get_parent() is black
int tree::case2(tree_node * root)
{
   // Return if it's black
   if(root->get_parent()->get_isred() == false)
      return 0; 

   // Else go to case 3
   else
      return case3(root); 
}

// If get_parent() and uncle are red, make them black
// and have grandget_parent() become red
int tree::case3(tree_node * root)
{
   // If the uncle is parent, set uncle to 
   // the right
   if(root->get_uncle() == root->get_parent()) 
      root->get_uncle() = root->get_parent()->get_parent()->get_right(); 

   // If uncle is red, set parent & uncle to black
   // and grandparent to red
   if(root->get_uncle() != NULL && root->get_uncle()->get_isred() == true)
   {
      root->get_parent()->set_isred(false); 
      root->get_uncle()->set_isred(false); 
      root->get_gparent()->set_isred(true); 

      // check if there's a root
      return case1(root); 
   }

   // Go on to next case
   else
      return case4(root); 
}

// If uncle is a red leaf, parent is red, and uncle is
// black added inside
int tree::case4(tree_node * root)
{
   // Find where the parent is
   if(root == root->get_parent()->get_right() && root->get_parent() == root->get_parent()->get_parent()->get_left())
   {
      // pass it in for left rotation
      rotate_left(root); 

      // child's left
      return case5(root->get_left()); 
   }

   // Else, rotate right.
   else
   {
      if(root == root->get_parent()->get_left() && root == root->get_parent()->get_parent()->get_right())
      {
	 rotate_right(root); 
	 return case5(root->get_right()); 
      }   
   }

   // Use the current to check rotation
   return case5(root);
}

// If uncle is a black leaf, parent is red, and uncle is
// red added outside
int tree::case5(tree_node * root)
{
   // Set parent to black and grandparent
   // to red
   root->get_parent()->set_isred(false); 
   root->get_parent()->get_parent()->set_isred(true); 

   // If uncle, rotate right
   if(root == root->get_parent()->get_left()) 
      return rotate_right(root); 

   // Else rotate left
   else
      return rotate_left(root); 
}

// Case that factors in a grandparent
// and rotates left
int tree::rotate_left(tree_node * root)
{
   // Temp pointer
   tree_node * temp; 

   // Rotation for case 4
   if(root->get_parent()->get_parent()->get_left() == root->get_parent()) 
   {
      // rotating left logic
      temp = root->get_left(); 
      root->get_left() = root->get_parent(); 
      root->get_parent()->get_right() = temp; 
      root->get_parent() = root->get_gparent(); 
      root->get_left()->get_parent() = root; 
      root->get_parent()->get_left() = root; 
   }

   // Rotation for case 5
   else 
   {
      // If ggp right is a grandparent, set ggp right to 
      // parent
      if(root->get_ggp()->get_right() == root->get_gparent())
	 root->get_ggp()->get_right() == root->get_parent(); 

      // else set ggp left to get_parent()
      else
	 root->get_ggp()->get_left() == root->get_parent(); 

      // rotating left logic
      temp = root->get_parent()->get_left(); 
      root->get_parent()->get_left() = root->get_gparent(); 
      root->get_gparent() = root->get_ggp(); 
      root->get_parent()->get_left()->get_parent() = root->get_parent(); 
      temp->get_parent() = root->get_parent()->get_left(); 
      root->get_parent()->get_left()->get_right() = temp; 
   }

   return 1;
}

// Case that factors in a grandparent
// and rotates left
int tree::rotate_right(tree_node * root)
{
   // Temp pointer
   tree_node * temp;

   // Rotation for case 4
   if(root->get_parent()->get_parent()->get_right() == root->get_parent()) 
   {
      // rotating right logic
      temp = root->get_right(); 
      root->get_right() = root->get_parent(); 
      root->get_parent()->get_left() = temp; 
      root->get_parent() = root->get_gparent(); 
      root->get_right()->get_parent() = root; 
      root->get_parent()->get_right() = root; 
   }

   // Rotation for case 5
   else 
   {
      // If ggp right is a grandparent, set ggp right to 
      // parent
      if(root->get_ggp()->get_right() == root->get_gparent())
	 root->get_ggp()->get_right() == root->get_parent(); 

      // else set ggp left to get_parent()
      else
	 root->get_ggp()->get_left() == root->get_parent(); 

      // rotating right logic
      temp = root->get_parent()->get_right(); 
      root->get_parent()->get_right() = root->get_gparent(); 
      root->get_gparent() = root->get_ggp(); 
      root->get_parent()->get_right()->get_parent() = root->get_parent(); 
      temp->get_parent() = root->get_parent()->get_right(); 
      root->get_parent()->get_right()->get_left() = temp; 
   }

   return 1;
}

// Wrapper for display function
void tree::wrapper_display() 
{
   // call the disp func
   display_tree(root);
}

// Display the data function
int tree::display_tree(tree_node * root)
{
   // If there's no root, return 
   if(!root)
      return 0;

   // Traverse left
   display_tree(root->get_left());

   node_disp(root);

   // Traverse right
   display_tree(root->get_right());
}

// Wrapper for the traversing func
int tree::node_disp(tree_node * root)
{
   if(!root)
      return 0;

   // Use root to call the displaying data
   return root->display(root);
}

// Getting the display function
int tree_node::display(tree_node * root)
{
   // Call disp from the family class
   f_head->w_display();
   return 1;
}

// remove tree wrapper
int tree::w_remove()
{
   if(!root)
      return 0;

   return remove_tree(root);
}

// Remove all nodes in tree function
int tree::remove_tree(tree_node *& root)
{
   // If root is NULL, return
   if(!root) 
      return 0; 

   // Traverse
   remove_tree(root->get_left()); 
   remove_tree(root->get_right()); 

   // Remove the LLL data, delete root
   root->remove_data();  
   delete root; 

   // set pointers to NULL
   root->get_left() = NULL; 
   root->get_right() = NULL; 
   root = NULL; 
}

// Removing data in the tree node
int tree_node::remove_data()
{
   // calling the remove func for LLL
   return f_head->remove_all_family();
}

// Wrapper for retrieve function
int tree::w_retrieve(const char * match)
{
   if(!root)
      return 0;

   // call the retrieve match func
   return root->retrieve_match(root, match);
}

// Function to retrieve match from user
int tree_node::retrieve_match(tree_node * root, const char * match)
{
   // If there's no root, return
   if(!root)
      return 0;

   // If there's a match, then display
   // data in that node
   if(compare(match) == 0)
      return display(root);

   // else check for matches
   else
   {
      // if match is greater than 0, go left
      if(compare(match) > 0)
	 return retrieve_match(root->left, match);

      // if match is less than 0, go left
      else
	 return retrieve_match(root->right, match);
   }
}


/*// NOT WORKING!!!!

// extraction << operator for display
ostream & operator << (ostream & display, tree & t)
{
   t.wrapper_display();
   return display;
}*/

