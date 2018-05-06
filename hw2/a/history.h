/*
 * Mishal Alajmi
 * CS 202
 * Homework #2
 * 02/15/2017
*/


#include"streetcar.h"


class node
{
    public:
        node();
        ~node();
        node *& go_next();
        int connect_next(node * cur);
        int create_group(const transit & mode);
        void display_single();
        void display_group();
        int remove_one();
    private:
        int max;
        int top_index;
        transit ** mass_transit;
        node * next;
};


class history
{
    public:
        history();
        ~history();
        int insert(transit & add);
        int remove_single();
        int get_single();
        int display();
    private:
        int push(transit & add);
        int pop();
        int peek(); 
        int display(node * head);
        int remove_all(node *& head);
        int cur_index;
        int max;
        node * head;
};
