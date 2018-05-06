//Abdullah Alshaikh
//Program 4-5 _ CS202
//Pizza Orders Application

//this file will have the cheese class which will be derived from the toppings class and it will be responsible of
//creating the cheese toppings for a pizza and it will have multiple functions to help do that
package com.company;

import java.io.IOException;

/**
 * Created by Budi on 5/26/2017.
 */
class Cheese extends Toppings {
    Cheese()
    {
        obj = new Kind();
    }
    public Cheese(Toppings to_copy)
    {
        this.obj = new Kind(to_copy.obj);
    }
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
    public int displayToppings()
    {
        System.out.print("Cheese Toppings: ");
        return obj.display();
    }

    public void rand_toppings() {

        int which =2;
        try{
            obj.load(which);
            obj.randomly();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public float price()
    {
        float i = 1.10f;
        return obj.get_price(i);
    }
}
