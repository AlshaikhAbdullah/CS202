//Abdullah Alshaikh
//program 2 - CS 202
//this .h file will have the manager class and the CLL class 
//which they are the main classes for this program
//this file is call forms because i had another function called forms but i got rid of 
//it because it was needed very much
#include "comms.h"
//this function will be derived from name so i can store the form of communication in 
//the integer 
class c_node:public name
{
    public:
        c_node();
        ~c_node();
        c_node *& go_next();
        int create(int choice); 
        int add_to();
        int check(int choice);
        void text();
        void display();
        void show_people();
        void remove_contact();
        void remove_contacts();
        int snap();
    protected:
        comms * type;
        c_node * next;
};

class manager
{
    public:
        manager();
        manager(const manager &);
        ~manager();
        int create(int i);
        void start(); 
        int find(int choice);
        void text(int choice);  
        int which();
        int remove(int choice);
        void delete_contacts(int choice);
        int snap_text();
    protected:
        c_node * rear;
        c_node * first;
        //void create(c_node *first, c_node *&rear,int i);
        int find(c_node * first,int choice);
        void text(int choice, c_node * first);
        void display(c_node * first);
        void show(c_node * first, int choice);//to display spesfic form address book
        int remove(int choice, c_node *&temp); //to remove a form of communication
        void delete_one(int choice, c_node * first);
        void delete_contacts(int choice, c_node * first);
        void clear_all(c_node *& first);
        int snap_text(c_node * first);
};
