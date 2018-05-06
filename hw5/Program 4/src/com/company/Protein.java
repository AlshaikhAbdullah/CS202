
//This file will have the protein class which will be derived from the abstract class toppings
//it will create a new obj which will be in the abstract class data members
//it will have a multiple functions to help adding protein toppings for the pizza

package com.company;

import java.io.IOException;

/**
 * Created by Budi on 5/26/2017.
 */
class Protein extends Toppings
{
    //constructor
    public Protein()
    {
        obj = new Kind();
    }

    //the copy constructor
    public Protein(Toppings to_copy)
    {
        this.obj = new Kind(to_copy.obj);
    }

     //this function will display the protein toppings by calling the display inside the kind class
    //and it will return it's value
    public void put_toppings()
    {
        System.out.println("\nChoice Of Protein:\nPrice: $0.80 Each");
        int which = 3;
        try {
            obj.load(which);
            obj.get_toppings();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //this function will display the protein toppings by calling the display inside the kind class
    //and it will return it's value
    public int displayToppings()
    {
        System.out.print("Protein Toppings: ");
        return obj.display();
    }

    //this function will be taking care of randomly adda topping for the special pizzas
    //it will read from the external files by calling the load file and the it will call the randomly to add the topping
    public void rand_toppings()
    {
        int which =3;
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
        float i = 0.80f;
        return obj.get_price(i);
    }
}
