/*
 * Mishal Alajmi
 * CS 202
 * Homework #1
 * 02/01/2017
*/


#include"location.h"


class node:public streetcar
{
    public:
        node();
        node(const node & copy_from);
        ~node();
        node *& move_next();
        node *& move_pre();
        int connect_next(node * nxt);
        int connect_prev(node * prv);
    private:
        node * next;
        node * previous;
};


class garage
{
    public:
        garage();
        ~garage();
        void retrieve_car(int car_id,streetcar & copy);
        void display_garage();
        void remove_car(int strc_id);
        int search_garage(int car_id);
        int read_file();
    private:
        int display_garage(node *& head);
        void build_garage(node *& head,node & to_copy);
        int retrieve_car(node *& head,int car_id,streetcar & ret);
        int search_garage(node * head,int car_id);
        int remove_car(node *& head,int car_id);
        void remove_all(node *& head);
        int num_cars;
        node * head;
};
