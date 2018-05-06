/*
 * Mishal Alajmi
 * CS 202
 * Homework #1
 * 02/01/2017
*/


#include"garage.h"


node::node():next(NULL){}


node::node(const node & copy_from):streetcar(copy_from),next(NULL){}


node::~node(){}



node *& node::move_next()
{
    return this->next;
}


int node::connect_next(node * nxt)
{
    this->next = nxt;
}


garage::garage():num_cars(8),head(NULL){}




garage::~garage()
{
    remove_all(head);
    head = NULL;
    num_cars = 0;
}



int garage::read_file()
{
    ifstream f_in;
    f_in.open("streetcar_info.txt",ios::in);

    node  dummy;
    char name_temp[num_cars][LOC_SIZE];
    char direct_temp[num_cars][LOC_SIZE];
    char status_temp[num_cars];
    int id_temp[num_cars];
    int sensor_temp[num_cars];
    
    int count = 0;

    for(int i=0;i<num_cars;++i)
    {
        status_temp[i] = 0;
        id_temp[i] = 0;
        sensor_temp[i] = 0;
    }

    if(!f_in)
    {
        cout << "couldn't reach file!" << endl;
        return 0;
    }

    while(!f_in.eof() && count <= num_cars)
    {
        f_in.get(name_temp[count],LOC_SIZE,':');
        f_in.ignore(100,':');

        f_in.get(direct_temp[count],LOC_SIZE,':');
        f_in.ignore(100,':');

        f_in >> status_temp[count];
        f_in.ignore(100,':');

        f_in >> id_temp[count];
        f_in.ignore(100,':');

        f_in >> sensor_temp[count];
        f_in.ignore(100,'\n');
        
        if(!f_in.eof())
        {
            dummy.copy_streetcar(name_temp[count],direct_temp[count],id_temp[count],status_temp[count],sensor_temp[count]);
            build_garage(head,dummy);
        }
 
        
        ++count;

    }


    f_in.clear();
    f_in.close();
}


void garage::build_garage(node *& head, node & to_copy)
{
   if(!head)
    {
        head = new node(to_copy);
        return;
    }
    
    build_garage(head->move_next(),to_copy); 
   
}



int garage::display_garage(node *& head)
{
    if(!head)
        return 0;

    head->display_car();

    return display_garage(head->move_next())+1;
}

void garage::display_garage()
{
    display_garage(head);
}

int garage::search_garage(node * head,int car_id) 
{
    if(!head)
        return 0;

    else if(head->compare_id(car_id))
    {
        head->display_car();
        return 1;
    }

    search_garage(head->move_next(),car_id);
}

int garage::search_garage(int car_id)
{
    search_garage(head,car_id);
}

int garage::retrieve_car(node *& head,int car_id,streetcar & ret)
{
    node * temp = NULL;
    if(!head)
        return 0;

    else if(head->compare_id(car_id))
    {
        ret.copy_streetcar(*(head));
        return 1;
    }

    retrieve_car(head->move_next(),car_id,ret);
}

void garage::retrieve_car(int car_id,streetcar & copy)
{
    retrieve_car(head,car_id,copy);
}


void garage::remove_all(node *& head)
{
    if(!head)
        return;
    
    remove_all(head->move_next());
    delete head;
    head = NULL;

}

int garage::remove_car(node *& head,int car_id)
{
    node * temp = NULL;
    if(!head)
        return 0;

    else if(head->compare_id(car_id))
    {
        temp = head;
        head = head->move_next();
        delete temp;
        return 1;
    }

    remove_car(head->move_next(),car_id);
}

void garage::remove_car(int strc_id)
{
    remove_car(head,strc_id);
}
