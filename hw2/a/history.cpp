/*
 * Mishal Alajmi
 * CS 202
 * Homework #2
 * 02/15/2017
*/


#include"history.h"

node::node():max(5),top_index(0),next(NULL)
{
    mass_transit = new transit *[max];
    for(int i=0;i<max;++i)
        mass_transit[i] = NULL;
}

node::~node()
{
    if(mass_transit)
    {
        for(int i=0;i<max;++i)
            delete mass_transit[i];

        delete [] mass_transit;
        mass_transit = NULL;
    }

    max = 0;
    top_index = 0;
    next = NULL;
}


node *& node::go_next()
{
    return this->next;
}

int node::connect_next(node * cur)
{
    this->next = cur;
}


int node::create_group(const transit & mode)
{
    const transit * type = &mode;
    const uber * car = dynamic_cast<const uber * >(type);
    const bus * buses = dynamic_cast<const bus * >(type);
    const streetcar * strcar = dynamic_cast<const streetcar * >(type);
   
    if(top_index == max)
        top_index = 0;

    else if(car)
    {
        (*(mass_transit+top_index)) = new uber(*car);
        ++top_index;
        return top_index;
    }

    else if(buses)
    {
        (*(mass_transit+top_index)) = new bus(*buses);
        ++top_index;
        return top_index;
    }

    else if(strcar)
    {
        (*(mass_transit+top_index)) = new streetcar(*strcar);
        ++top_index;
        return top_index;
    }
}

void node::display_single()
{
    --top_index;
    if(!mass_transit[top_index])
            return;

    mass_transit[top_index]->display();
    ++top_index;
    return;

}

void node::display_group()
{
    int i = 0;
    
    while(i < top_index)
    {
        mass_transit[i]->display();
        ++i;
    }
}

int node::remove_one()
{
    --top_index;
    delete (*(mass_transit+top_index));
    (*(mass_transit+top_index)) = NULL;
    --top_index;

    return top_index;
}

history::history():head(NULL),cur_index(0),max(5){}


history::~history()
{
    if(head)
        remove_all(head);
    
    head = NULL;
    cur_index = 0;
    max = 0;
}


int history::push(transit & add)
{
    node * temp = NULL;
    if(!head)
    {
        head = new node;
        cur_index =  head->create_group(add);
        return 1;
    }

    else if(cur_index > 0 && cur_index < max || cur_index == 0)
    {
        cur_index = head->create_group(add);
        return 1;
    }

    else if(cur_index == max)
    {
        cur_index = 0;
        temp = new node;
        cur_index = temp->create_group(add);
        temp->connect_next(head);
        head = temp;
        return 1;
    }
}

int history::insert(transit & add)
{
    return push(add);
}

int history::display(node * head)
{
    if(!head)
        return 0;

    head->display_group();

    return display(head->go_next());
}

int history::display()
{
    return display(head);
}

int history::remove_all(node *& head)
{
    node * temp = NULL;
    if(!head)
        return 0;

    else if(!head->go_next())
    {
        delete head;
        head = NULL;
        return 1;
    }

    else
    {
        temp = head;
        head = head->go_next();
        delete temp;
        temp->connect_next(NULL);
        temp = NULL;
    }

    return remove_all(head->go_next());
}


int history::pop()
{
    node * current = NULL;
    if(!head)
        return 0;

    else if(cur_index == 1)
    {
        current = head->go_next();
        delete head;
        head = current;
        cur_index = max-1;
        return 1;
    }

    else if(cur_index > 0 && cur_index < max)
    {
        cur_index = head->remove_one();
        return 1;
    }
    return 0;
}

int history::remove_single()
{
    return pop();
}



int history::peek()
{
    if(!head)
        return 0;

    head->display_single();
    return 1;
}


int history::get_single()
{
    return peek();
}
