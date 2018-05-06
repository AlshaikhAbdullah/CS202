//Abdullah Alshaikh
//Program 4 - CS 202
//Pizza Orders Application

//this file will have the pizza class and it's functions this pizza class will be responsible of creating toppings for the pizza
//by using dynamic binding and it will be responsible of getting the price of the toppings
package com.company;
import com.sun.org.apache.regexp.internal.RE;

import java.security.PublicKey;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;
/**
 * Created by Budi on 5/26/2017.
 */
public class Pizza
{
    protected Toppings [] type;
    protected Scanner input;
    //the constructor
    public Pizza()
    {
        input = new Scanner(System.in);
        type = null;
    }
    //copy constructor to copy a pizza
    public Pizza(Pizza To_copy)
    {
        this.type = new Toppings[4];
        this.type[0] = new Veggie(To_copy.type[0]);
        this.type[1] = new Crust(To_copy.type[1]);
        this.type[2] = new Cheese(To_copy.type[2]);
        this.type[3] = new Protein(To_copy.type[3]);
    }
    //the function that will create the pointers to the derived class using dynamic binding to add toppings
    //and it will keep adding toppings which is an array of linked list as much as the user wants
    public int toppings()
    {
        type = new Toppings [4];
        type[0] = new Veggie();
        type[1] = new Crust();
        type[2] = new Cheese();
        type[3] = new Protein();


        do {
            for (int i = 0; i < 4; ++i) {
                type[i].put_toppings();
            }
        }while(Repeat());
        return 1;
    }
    //this function will be responsible of displaying the toppings
    //by calling the display toppings function for each element
    public void displayPizza()
    {
        for(int i =0; i < 4;++i)
        {
            if(type[i].displayToppings() == 0)
                System.out.print("\nNo Toppings Were Added.\n");
        }
    }
    //a repeat function that will basically return true if the user wants to add a topping otherwise returns false
    public boolean Repeat(){
        char resp;
        Scanner input = new Scanner(System.in);


        System.out.println("\nWould You Like To Add Another Toppings For Current Pizza?(Y/N):");
        resp = input.next().charAt(0);

        if (resp == 'Y' || resp == 'y') {
            return true;
        }
        else if (resp == 'N' || resp == 'n') {
            return false;
        }
        else if(resp != 'Y' || resp != 'y' || resp != 'N' || resp != 'n'){ // if the user enters something other than Y or N
            System.out.println("\nEnter lower or upper n/N or y/Y PLEASE!!!!!!!!!!!!!\n");
            Repeat();
        }
        return false;
    }

    //this function will be responsible of adding toppings to the randomly generated pizzas
    //by using dynamic binding to get to the right class and call the rand_toppings
    public void create_spec() {
    type = new Toppings [4];
        type[0] = new Veggie();
        type[1] = new Crust();
        type[2] = new Cheese();
        type[3] = new Protein();


            for (int i = 0; i < 4; ++i) {
                type[i].rand_toppings();
            }
    }
    //this function will be responsible of getting the price of the toppings added to a pizza and return that price
    public float the_price()
    {
        float get_price = 0.0f;
        for(int i =0; i<4; ++i)
        {
           get_price+= type[i].price();
        }
        return get_price;
    }
}
