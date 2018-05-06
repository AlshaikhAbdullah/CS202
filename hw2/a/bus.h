/*
 * Mishal Alajmi
 * CS 202
 * Homework #2
 * 02/15/2017
 */


#include"uber.h"


class bus: public transit
{
    public:
        bus();
        bus(const transit & to_copy);
        bus(const bus & to_copy);
        ~bus();
        void display();
        void get_exper(char * feedback);
        int copy_exper(char * feedback,int rating,int prc,int dly,bool stat);
        int copy_exper(const bus & to_copy);
    private:
        char * experience;
        bool status;
        int delay;
        float price;
        int stars;
};
