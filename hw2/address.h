//Abdullah Alshaikh
//program 2 - CS202
//this .h file will the node and the address classes these will basically will be 
//creating my BST
#include "name.h"

class node: public person
{
    public:
        node();
        node(const node &);
        ~node();
        node *&go_left();
        node *&go_right();
        int extra(name & temp);
        int displayDupe();
        int check(name & temp);
        int get_head(name & temp);
        int remove_text(name & temp);
        int remove_contact(name & temp);
    protected:
        l_node * head;
        node * left;
        node * right;
        int displayDupe(l_node * head);
        int check(name & temp,l_node * head);
        void clear_all(l_node *&head); 
        int remove_text(name & temp, l_node * head);
        int remove_contact(name &temp,l_node *&head);
};

class address
{
    public:
        address();
        address(const address &);
        ~address();
        int insert();
        void display();
        int texting(); 
        int remove();
        void clear_all();
        int gone_text();
    protected:
        node * root;
        void display(node * root);
        int trav(node *&root,name & temp);
        int texting(node * root,name & temp);
        void clear_all(node *& root);
        int remove(node *& root,name & temp);
        node *& get_left(node *& root);
        int gone_text(node * root, name & temp);
};
