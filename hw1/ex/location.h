/*
 * Mishal Alajmi 
 * Homework #1
 * CS202
 * 2/1/2017
*/


#include<iostream>
#include<fstream>
#include<cstring>
#include<cctype>
using namespace std;
const int LOC_SIZE = 50;

class location
{
    public:
        location();
        location(const location & address);
        ~location();
        void edit_location();
        void display_location();
        int copy_location(const location & to_copy);
    protected:
        int zip_code;
        int street_number;
        char * street_name;
};


class streetcar: public location
{
    public:
        streetcar();
        streetcar(const streetcar & to_copy);
        ~streetcar();
        int copy_streetcar(char loc[],char dire[],int car_id,char stt,int sense);
        int copy_streetcar(const streetcar & copy_info);
        void display_car();
        bool compare_name(char strt_name[]);
        bool compare_id(int str_id);
    protected:
        bool condition;
        int sensor;
        int id;
        char stat;
        char * current_location;
        char * direction;
};
