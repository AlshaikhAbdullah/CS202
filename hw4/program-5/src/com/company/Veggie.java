//Abdullah Alshaikh
//Program 4 - CS202
//Pizza Orders Application

//This file will have the veggie class which will be derived from the abstract class toppings
//it will create a new obj which will be in the abstract class data members
//it will have a multiple functions to help adding veggie toppings for the pizza

package com.company;

import java.io.IOException;

/**
 * Created by Budi on 5/26/2017.
 */
class Veggie extends Toppings {
    public Veggie()
    {
        obj = new Kind();
    }
    //copy constructor to copy the veggies
    public Veggie(Toppings to_copy)
    {
        this.obj = new Kind(to_copy.obj);
    }
    //this function will be taking care of putting toppings for a pizza by calling the load file which will read from external file
    //and then call the get toppings function which will get user's choice from these toppings
    public void put_toppings()
    {
        System.out.println("\nChoice Of Vegetables:\nPrice: $1 Each");
        int which = 0;
        try {
            obj.load(which);
            obj.get_toppings();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //this function will display the veggie toppings by calling the display inside the kind class
    //and it will return it's value
    public int displayToppings()
    {
        System.out.print("Veggie Toppings: ");
        return obj.display();
    }

    //this function will be taking care of randomly adda topping for the special pizzas
    //it will read from the external files by calling the load file and the it will call the randomly to add the topping
    public void rand_toppings()
    {
        int which =0;
        try{
            obj.load(which);
            obj.randomly();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //this function will get the price for toppings by calling get price function and return it's value
    public float price()
    {
        int i = 1;
        return obj.get_price(i);
    }
}
