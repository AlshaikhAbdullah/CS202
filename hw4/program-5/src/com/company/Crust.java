//Abdullah Alshaikh
//Program 4 - CS202
//Pizza Orders Application

//This file will have the crust class which will be derived from the abstract class toppings
//it will create a new obj which will be in the abstract class data members
//it will have a multiple functions to help adding crust toppings for the pizza

package com.company;

import java.io.IOException;

/**
 * Created by Budi on 5/26/2017.
 */
class Crust extends Toppings {
    //constructor
    public Crust()
    {
        obj = new Kind();
    }
    //copy constructor
    public Crust(Toppings to_copy)
    {
        this.obj = new Kind(to_copy.obj);
    }

     //this function will display the crust toppings by calling the display inside the kind class
    //and it will return it's value
    public void put_toppings()
    {
        System.out.println("Crust Toppings:\nPrice: $1.25 Each ");
        int which = 1;
        try {
            obj.load(which);
            obj.get_toppings();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //this function will display the crust toppings by calling the display inside the kind class
    //and it will return it's value
    public int displayToppings()
    {
        System.out.print("Crust Toppings: ");
        return obj.display();
    }

    //this function will be taking care of randomly adda topping for the special pizzas
    //it will read from the external files by calling the load file and the it will call the randomly to add the topping
    public void rand_toppings() {

        int which =1;
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
        float i = 1.25f;
        return obj.get_price(i);
    }
}
