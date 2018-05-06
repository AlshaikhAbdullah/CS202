/*
 * Mishal Alajmi
 * CS 202
 * Homework #1
 * 02/06/2017
*/


#include"line.h"

line::line():head(NULL),max_cars(0),num_strcars(4),num_stops(20){}





void line::read_line_file()
{
    ifstream file_in;
    file_in.open("stop_info.txt",ios::in);

    DLL_node plc;
    char temp_name[num_stops][LOC_SIZE];
    char res[num_stops];
    int temp_num[num_stops];

    int counter = 0;

    for(int i=0;i<num_stops;++i)
    {
        res[i] = 0;
        temp_num[i] = 0;
    }

    if(!file_in)
    {
        cout << "Couldn't Reach File!" << endl;
        return;
    }

    while(!file_in.eof() && counter <= num_stops)
    {
        file_in.get(temp_name[counter],LOC_SIZE,':');
        file_in.ignore(100,':');

        file_in >> res[counter];
        file_in.ignore(100,':');

        file_in >> temp_num[counter];
        file_in.ignore(100,'\n');

        if(!file_in.eof())
        {
            plc.copy_stop(temp_name[counter],temp_num[counter],res[counter]);
            start_line(head,plc);
        }

        ++ counter;
    }

    file_in.clear();
    file_in.close();
    
}

void line::start_line(DLL_node *& head,DLL_node & place)
{
    DLL_node * temp = NULL;
    if(!head)
    {
        head = new DLL_node;
        head->copy_stop(place);
        head->connect_prev(NULL);
        head->connect_next(NULL);
        return;
    }

    else if(!head->go_previous())
    {
        temp = new DLL_node;
        temp->copy_stop(place);
        temp->connect_prev(head);
        temp->connect_next(NULL);
    }

    else
    {
        temp = new DLL_node;
        temp->copy_stop(place);
        temp->connect_prev(head);
        head->connect_next(temp);
    }

    start_line(head->go_next(),place);
}



void line::display_line(DLL_node * head)
{
    if(!head)
        return;

    head->display_stop();

    display_line(head->go_next());
}

void line::display_line()
{
    display_line(head);
}

int line::place_car(DLL_node *& head,streetcar & to_place,int car_id,garage & put)
{
    if(!head || max_cars >= num_strcars)
        return 0;

    else if(head->is_occu())
    {
        head->insert_car(to_place,car_id,put);
        ++max_cars;
        return 1;
    }

    return place_car(head->go_next(),to_place,car_id,put);
}

void line::place_car(streetcar & to_place,int car_id,garage & put)
{
    place_car(head,to_place,car_id,put);
}


int line::remove_car(DLL_node *& head,int strc_id)
{
    if(!head)
        return 0;

    else if(head->check_id(strc_id))
    {
       head->remove_stop(); 
       return 1;
    }

    remove_car(head->go_next(),strc_id);
}

void line::remove_car(int strc_id)
{
    remove_car(head,strc_id);
}

int line::remove_line(DLL_node *& head)
{
    if(!head)
        return 0;
    remove_line(head->go_next());
    delete head;
    head = NULL;
    max_cars = 0;
    num_strcars = 0;
    num_stops = 0;
}


line::~line()
{
    if(head)
        remove_line(head);

    head = NULL;
}


loop::loop():rear(NULL),num_stops(20),num_cars(4),max_cars(0){}


loop::~loop()
{
    CLL_node * cur = rear->go_next();
    rear->connect_next(NULL);
    if(rear)
        remove_loop(cur);
    
    rear = cur = NULL;
    max_cars = 0;
    num_cars = 0;
    num_stops = 0;

}


void loop::read_loop_file()
{
    ifstream file_in;
    file_in.open("stop_info.txt",ios::in);

    CLL_node plc;
    char temp_name[num_stops][LOC_SIZE];
    char res[num_stops];
    int temp_num[num_stops];

    int counter = 0;

    for(int i=0;i<num_stops;++i)
    {
        res[i] = 0;
        temp_num[i] = 0;
    }

    if(!file_in)
    {
        cout << "Couldn't Reach File!" << endl;
        return;
    }

    while(!file_in.eof() && counter <= num_stops)
    {
        file_in.get(temp_name[counter],LOC_SIZE,':');
        file_in.ignore(100,':');

        file_in >> res[counter];
        file_in.ignore(100,':');

        file_in >> temp_num[counter];
        file_in.ignore(100,'\n');

        if(!file_in.eof())
        {
            plc.copy_stop(temp_name[counter],temp_num[counter],res[counter]);
            start_loop(rear,plc);
        }

        ++ counter;
    }

    file_in.clear();
    file_in.close();

}


int loop::start_loop(CLL_node *& rear,CLL_node & place)
{
    CLL_node * temp = NULL;
    if(!rear)
    {
        rear = new CLL_node;
        rear->copy_stop(place);
        rear->connect_next(rear);
        return 1;
    }

    else if(rear->go_next() == rear)
    {
        temp = new CLL_node;
        temp->copy_stop(place);
        rear->connect_next(temp);
        temp->connect_next(rear);
        rear = temp;
        return 1;
    }

    else
    {
        temp = new CLL_node;
        temp->copy_stop(place);
        temp->connect_next(rear->go_next());
        rear->connect_next(temp);
        rear = temp;
        return 1;
    }

    start_loop(rear->go_next(),place);

}


void loop::display_loop(CLL_node * rear)
{
    if(!rear)
        return;

    rear->display_stop();

    display_loop(rear->go_next());
}


void loop::display_loop()
{
    CLL_node * cur = rear->go_next();
    CLL_node * temp = NULL;
    rear->connect_next(temp);

    temp = rear;
    rear = cur;
    display_loop(rear);
   
    rear = temp;
    rear->connect_next(cur);
}


int loop::place_car(CLL_node *& rear,streetcar & to_place,int car_id,garage & put)
{
    if(!rear || max_cars >= num_cars)
        return 0;

    else if(rear->is_occu())
    {
        rear->insert_car(to_place,car_id,put);
        ++max_cars;
        return 1;
    }

    return place_car(rear->go_next(),to_place,car_id,put);
}


void loop::place_car(streetcar & to_place,int car_id,garage & put)
{
    CLL_node * cur = rear->go_next();
    CLL_node * temp = NULL;
    rear->connect_next(temp);

    temp = rear;
    rear = cur;
    place_car(rear,to_place,car_id,put);
    
    rear = temp;
    rear->connect_next(cur);
}

int loop::remove_car(CLL_node *& rear,int strc_id)
{
    if(!rear)
        return 0;

    else if(rear->check_id(strc_id))
    {
       rear->remove_stop(); 
       return 1;
    }

    remove_car(rear->go_next(),strc_id);
}


void loop::remove_car(int strc_id)
{
    CLL_node * cur = rear->go_next();
    CLL_node * temp = NULL;
    rear->connect_next(temp);

    temp = rear;
    rear = cur;
    remove_car(rear,strc_id);

    rear = temp;
    rear->connect_next(cur);
}

int loop::remove_loop(CLL_node *& rear)
{
    if(!rear)
        return 0;

    remove_loop(rear->go_next());
    delete rear;

}
