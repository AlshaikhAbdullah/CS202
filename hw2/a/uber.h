/*
 * Mishal Alajmi
 * CS 202
 * Homework #2
 * 02/15/2016
*/

#include"transit.h"


class uber: public transit
{
    public:
        uber();
        uber(const uber & to_copy);
        uber(const transit & to_copy);
        ~uber();
        void display();
        void get_exper(char * feedback);
        int copy_exper(char * feedback,int rating,int prc,int dly,bool stat);
        int copy_exper(const uber & to_copy);
    private:
        char * experience;
        bool status;
        int delay;
        float price;
        int stars;
};
