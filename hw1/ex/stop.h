/*
 * Mishal Alajmi
 * CS 202
 * Homework #1
 * 02/01/2017
 */


#include"garage.h"


class stop
{
    public:
        stop();
        ~stop();
        void display_stop();
        int copy_stop(const stop & copy_from);
        int copy_stop(char s_name[],int s_number,char resp);
        bool is_occu();
        bool check_id(int car_id);
        void insert_car(streetcar & insert,int car_id,garage & put);
        void remove_stop();
    protected:
        bool occupied;
        int stop_number;
        char * stop_name;
        streetcar * car;
};
