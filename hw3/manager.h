//Abdullah Alshaikh
//Program 3 - CS202
//application management
/*
 * this is the manager.h file which will contain the manager class which will be the class 
 * that contorls my whole program by creating the linked list and that will create 
 * the red black tree, so baiscly it will 
 */
#include "tree.h"

class manager
{
    public:
        manager();
        ~manager();
        manager(const manager &);
        int insert();
        int reading();
        int  display()const;
        int display_top();
        int sort();
        manager & operator =(const manager&);
        friend ostream & operator <<(ostream &,const manager &);
        friend istream & operator >>(istream &,manager &);

    protected:
       l_node * head; 
       int display_top(l_node *,String&);
       int display(l_node*)const;
       int sort(l_node *&head);
       l_node * insert(l_node * head,String &);
       void clear(l_node *&);
       void copy_list(l_node *&, l_node *);
};
