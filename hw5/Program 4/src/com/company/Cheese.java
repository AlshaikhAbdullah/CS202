//Abdullah Alshaikh
//Program 4 - CS202
//Pizza Orders Application

//this file will have the cheese class which will be derived from the toppings class and it will be responsible of
//creating the cheese toppings for a pizza and it will have multiple functions to help do that

package com.company;

import java.io.IOException;

/**
 * Created by Budi on 5/26/2017.
 */
class Cheese extends Toppings {
    //constructor
    public Cheese()
    {
        obj = new Kind();
    }
    //copy constructor to copy the toppings
    public Cheese(Toppings to_copy)
    {
        this.obj = new Kind(to_copy.obj);
    }

     //this function will display the cheese toppings by calling the display inside the kind class
    //and it will return it's value
    public void put_toppings()
    {
        System.out.println("Cheese Type:\nPrice: $1.10 Each");
        int which = 2;
        try {
            obj.load(which);
            obj.get_toppings();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //this function will display the cheese toppings by calling the display inside the kind class
    //and it will return it's value
    public int displayToppings()
    {
        System.out.print("Cheese Toppings: ");
        return obj.display();
    }

    //this function will be taking care of randomly adda topping for the special pizzas
    //it will read from the external files by calling the load file and the it will call the randomly to add the topping
    public void rand_toppings() {

        int which =2;
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
        float i = 1.10f;
        return obj.get_price(i);
    }
}
