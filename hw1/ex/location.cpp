/*
 * Mishal Alajmi
 * CS 202
 * Homework #1
 * 2/1/2017
 */


#include"location.h"


location::location():zip_code(0),street_number(0),street_name(NULL){}


location::location(const location & address)
{
    copy_location(address);
}


location::~location()
{
    if(street_name)
    {
        delete [] street_name;
        street_name = NULL;
    }

    street_name = NULL;
    street_number = 0;
    zip_code = 0;
}


void location::display_location()
{
    cout << "Street Name: " << street_name << " street" << '\n'
         << "Street Number: " << street_number << '\n'
         << "Zipcode: " << zip_code << endl;
}


void location::edit_location()
{
    char name_temp[LOC_SIZE];
    int temp_len = 0;


    cout << "Please enter a streetname: " << endl;
    cin.get(name_temp,LOC_SIZE,'\n');
    cin.ignore(100,'\n');

    temp_len = strlen(name_temp)+1; 
    street_name = new char[temp_len];
    strcpy(street_name,name_temp);
    
    cout << "Please enter a streetnumber: " << endl;
    cin >> street_number; 
    cin.ignore(100,'\n');

    cout << "Please enter a zipcode: " << endl;
    cin >> zip_code;
    cin.ignore(100,'\n');
}


int location::copy_location(const location & to_copy)
{
    int name_len = 0;
    if(!to_copy.street_name)
        return 0;
    
    name_len = strlen(to_copy.street_name)+1;
    street_name = new char[name_len];
    strcpy(street_name,to_copy.street_name);

    zip_code = to_copy.zip_code;
    street_number = to_copy.street_number;

    return 1;
}


streetcar::streetcar():stat(0),sensor(0),id(0),condition(false),current_location(NULL),direction(NULL){}



streetcar::streetcar(const streetcar & to_copy):location(to_copy),stat(0),condition(false),sensor(0),id(0),current_location(NULL),direction(NULL)
{
    copy_streetcar(to_copy);
}


void streetcar::display_car()
{
    cout << "location: " << current_location << " Street" << '\n'
         << "Heading: " << direction <<  '\n'
         << "ID#: " << id << '\n'
         << "Sensor: " << sensor << '\n' << endl;
         
         if(stat == 'y')
         {
             condition = false;
             cout << "Maintenance Scheduled!\n" << endl;
         }

         else if(stat == 'n')
         {
             condition = true;
             cout << "No Maintenance Scheduled!\n" << endl;
         }
        
}



int streetcar::copy_streetcar(const streetcar & copy_info)
{
    int loc_len = 0;
    int direc_len = 0;

    if(!copy_info.current_location || !copy_info.direction)
        return 0;


    if(current_location || direction)
    {
        delete [] current_location;
        current_location = NULL;

        delete [] direction;
        direction = NULL;
    }

    loc_len = strlen(copy_info.current_location)+1;
    direc_len = strlen(copy_info.direction)+1;

    current_location = new char[loc_len];
    strcpy(current_location,copy_info.current_location);

    direction = new char[direc_len];
    strcpy(direction,copy_info.direction);

    id = copy_info.id;
    stat = copy_info.stat;
    condition = copy_info.condition;
    sensor = copy_info.sensor;

    return 1;
    
}

int streetcar::copy_streetcar(char loc[],char direct[],int car_id,char stt,int sense)
{
    int loc_len,direct_len=0;

    if(!loc || !direct)
        return 0;

    if(current_location || direction)
    {
        delete [] current_location;
        current_location = NULL;

        delete [] direction;
        direction = NULL;
    }
    
    loc_len = strlen(loc)+1;
    current_location = new char[loc_len];
    strcpy(current_location,loc);

    direct_len = strlen(direct)+1;
    direction = new char[direct_len];
    strcpy(direction,direct);

    id = car_id;
    stat = stt;
    sensor = sense; 

    if(stat == 'y')
        condition = true;

    else if(stat == 'n')
        condition = false;


    return 1;
}

bool streetcar::compare_name(char strt_name[])
{
    if(strcmp(current_location,strt_name)==0)
        return true;

    else
        return false;
}

bool streetcar::compare_id(int str_id)
{
    if(id == str_id)
        return true;
    
    else 
        return false;
}


streetcar::~streetcar()
{
    if(current_location)
    {
        delete [] current_location;
        current_location = NULL;
    }
       
    if(direction)
    {
        delete [] direction;
        direction = NULL;
    }

    current_location = NULL;
    direction = NULL;
    stat = 0;
    condition = false;
    sensor = 0;
    id = 0;

}
