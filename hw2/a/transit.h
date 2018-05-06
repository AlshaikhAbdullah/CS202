/*
 * Mishal Alajmi
 * Homework #2
 * CS 202
 * 02/15/2017
 */

#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
const int SIZE = 150;


class transit
{
    public:
        transit();
        transit(const transit & to_copy);
        virtual ~transit();
        virtual void display() = 0;
        virtual void get_exper(char * feedback) = 0;
        virtual int copy_exper(char * feedback, int rating,int prc,int dly,bool stat);
        virtual int copy_exper(const transit & to_copy);
    protected:
        char * experience;
        bool status;
        int price;
        int delay;
        int stars;
};

