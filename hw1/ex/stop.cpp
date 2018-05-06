/*
 * Mishal Alajmi
 * CS 202
 * Homework #1
 * 02/06/2017
*/



#include"stop.h"



stop::stop():occupied(false),stop_number(0),stop_name(NULL),car(NULL){}



stop::~stop()
{
    if(stop_name)
        delete [] stop_name;

    if(car)
        delete car;

    stop_name = NULL;
    car = NULL;
    stop_number = 0;
    occupied = false;
}



void stop::display_stop()
{
    if(!stop_name)
        return;
        

    cout << "Stop ID: " << '#' << stop_number << '\n'
         << "Stop Name: " << stop_name << endl;

    if(occupied == true)
        cout << "Stop Available!" << endl;

    else
        cout << "Stop Occupied!" << endl;

 
    if(!car)
        cout << "\nNo streetcars currently at stop!" << endl;
    
    else
    {
        cout << "Current Streetcar at Stop:\n " << endl;
        car->display_car();
    }
}



int stop::copy_stop(const stop & copy_from)
{
    int name_len = 0;
    if(!copy_from.stop_name)
        return 0;

    if(stop_name)
    {
        delete [] stop_name;
        stop_name = NULL;
    }

    name_len = strlen(copy_from.stop_name)+1;
    stop_name = new char[name_len];
    strcpy(stop_name,copy_from.stop_name);

    stop_number = copy_from.stop_number;
    occupied = copy_from.occupied;
    return 1;
}

int stop::copy_stop(char s_name[],int s_number,char resp)
{
    int name_len = 0;
    if(!s_name)
        return 0;

    if(stop_name)
    {
        delete [] stop_name;
        stop_name = NULL;
    }

    name_len = strlen(s_name)+1;
    stop_name = new char[name_len];
    strcpy(stop_name,s_name);

    stop_number = s_number;

    if(resp == 'y')
        occupied = true;
   
    else if(resp == 'n')
        occupied = false;
    return 1;
}


void stop::insert_car(streetcar & insert,int car_id,garage & put)
{
    if(!car)
        car = new streetcar;

   put.retrieve_car(car_id,insert); 
   car->copy_streetcar(insert);

   put.remove_car(car_id);
}


bool stop::is_occu()
{
    if(occupied)
        return true;

    else 
        return false;
}


bool stop::check_id(int car_id)
{
    if(!car)
        return false;

    else if(car->compare_id(car_id))
        return true;

    else 
        return false;
}

void stop::remove_stop()
{
    if(!car)
        return;

    else
    {
        delete car;
        car = NULL;
    }
}
