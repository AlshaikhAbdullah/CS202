//abdullah Alshaikh
//Program 4-5 - CS202
//Pizza order application

//the linked list node class
package com.company;

/**
 * Created by Budi on 5/26/2017.
 */

class Lnode extends Name
{
    protected Lnode next;
    public Lnode()
    {
        next = null;
    }
    public Lnode(Name to_copy){super(to_copy);}
    public Lnode go_next()
    {
        return this.next;
    }
    public void setNext(Lnode current)
    {
        this.next = current;
    }
    public void show_name()
    {
        display();
    }
}
