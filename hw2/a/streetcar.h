/*
 * Mishal Alajmi
 * CS 202
 * Homework #2
 * 02/15/2017
*/


#include"bus.h"


class streetcar: public transit
{
    public:
        streetcar();
        streetcar(const transit & to_copy);
        streetcar(const streetcar & to_copy);
        ~streetcar();
        void display();
        void get_exper(char * feedback);
        int copy_exper(char * feedback,int rating,int prc,int dly,bool stat);
        int copy_exper(const streetcar & to_copy);
    private:
        char * experience;
        bool status;
        int delay;
        float price;
        int stars;
};
