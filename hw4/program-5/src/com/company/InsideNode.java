//Abdullah Alshaikh
//Program 4-5 - CS202
//Pizza Order Application

//This file is the class that will create the pizza special for each day in each pizzeria
//it will be extended from the name class to store the day
package com.company;

import org.omg.PortableInterceptor.INACTIVE;

/**
 * Created by Budi on 5/28/2017.
 */
public class InsideNode extends Name{
    //variables
    protected InsideNode left;
    protected InsideNode right;
    protected Node pizzas;

    //constructor
    public InsideNode()
    {
        left = null;
        right = null;
        pizzas = null;
        pizzas = new Node();
    }
    public InsideNode goLeft()
    {
        return this.left;
    }
    public InsideNode goRight()
    {
        return this.right;
    }
    public void setLeft(InsideNode current)
    {
        this.left = current;
    }
    public void setRight(InsideNode current)
    {
        this.right = current;
    }
    //This function will only call the special function that will create the pizza
    public void create_pizza()
    {
        pizzas.special();
    }
}
