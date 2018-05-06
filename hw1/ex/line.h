/*
 * Mishal Alajmi
 * CS 202
 * Homework #1
 * 02/06/2017
*/


#include"nodes.h"


class line
{
    public:
        line();
        ~line();
        void read_line_file();
        void display_line();
        void place_car(streetcar & to_place,int car_id,garage & put);
        void remove_car(int strc_id);
    private:
        void start_line(DLL_node *& head,DLL_node & place);
        int place_car(DLL_node *& head,streetcar & to_place,int strc_id,garage & put);
        int remove_car(DLL_node *& head,int strc_id);
        int remove_line(DLL_node *& head);
        void display_line(DLL_node * head);
        int max_cars;
        int num_strcars;
        int num_stops;
        DLL_node * head;

};


class loop
{
    public:
        loop();
        ~loop();
        void read_loop_file();
        void display_loop();
        void place_car(streetcar & to_place,int car_id,garage & put);
        void remove_car(int strc_id);
    private:
        int start_loop(CLL_node *& rear,CLL_node & place);
        void display_loop(CLL_node * rear);
        int place_car(CLL_node *& rear,streetcar & to_place,int strc_id,garage & put);
        int remove_car(CLL_node *& rear,int strc_id);
        int remove_loop(CLL_node *& rear);
        int max_cars;
        int num_cars;
        int num_stops;
        CLL_node * rear;
};
