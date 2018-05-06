//Abdullah Alshaikh
//program 4 - CS202
//Pizza Orders

//this file will hae the node class which will be the doubly liked list that will be the orders of the user
//it will be responsible of adding an array of pizzas for each order and also randomly generate special pizzas
//and it will return next pointer and previous pointers
package com.company;

import com.sun.org.apache.xpath.internal.SourceTree;

import java.util.Scanner;
import java.util.Random;

/**
 * Created by Budi on 5/26/2017.
 */
public class Node {
    //variables
    private Node next;
    private Node previous;
    protected Pizza [] pizzas;//to hold the user's pizzas
    protected Random rand;
    protected Pizza [] temp; // to hold the special pizzas
    protected int s = 0;//to save number of special pizzas
    private int  num;
    private float price;
    protected  Scanner input;

    //constructor
    public Node()
    {
        this.next = null;
        this.previous = null;
        this.input = new Scanner(System.in);
        this.pizzas = null;
        this.temp =null;
        num =0;
        price = 9.00f;
    }
    //copy constructor
    public Node(Pizza to_copy) { }
    // return the previous pointer
    public Node goPrevious() { return this.previous;}
    //to return the next pointer
    public Node goNext(){ return this.next;}
    //next setter
    public void setNext(Node current){
        this.next = current;
    }
    // previous setter
    public void setPrevious(Node current){
        this.previous = current;
    }
    //this function will be responsible of creating the array of pizzas
    //it will ask the user first how many pizzas and it will created that based on the user answer
    //but before that it will show the user specials for an order and if the user wants that special it will copy
    //the special to users order
    public int make_pizza()
    {
        char go;
        do {
            System.out.print("\nHow Many Pizza Would You Like(Numbers Only): ");
            num = input.nextInt();
        }while(num < 0);
        pizzas = new Pizza[num];
 //       if(temp == null)
            special();
        System.out.println("\n\nWould You Like To Choose One Of The Specials(y/n): ");
        go = input.next().charAt(0);
        if(go == 'y' || go == 'Y')
        {
            int choice = 0;
            do {
                System.out.println("\nWhich Special Would You Like To Choose " +
                        " (1 - " + s +  "): ");
                choice = input.nextInt();
            }while(choice > s || s < 0);
            pizzas[0] = new Pizza(temp[choice-1]);
            System.out.println("\n\nToday's Special Was Added Successfully.");

             for(int i =1; i<num;++i)
            {
                System.out.println("\n\nTo Your Next Pizza.. Enter Any Key To Continue: ");
                go = input.next().charAt(0);
                System.out.println("\nOrder Number  " + (i+1) + ": ");
                pizzas[i] = new Pizza();
                pizzas[i].toppings();
                System.out.print("\nYour Done With This One...Enter Any Key To Continue: ");
                go = input.next().charAt(0);
            }
            return 1;
        }

        for(int i =0; i<num;++i)
        {
            System.out.println("Order Number: " + (i+1));
            pizzas[i] = new Pizza();
            pizzas[i].toppings();
            System.out.print("Your Done With This One...Enter Any Key To Continue: ");
            go = input.next().charAt(0);
        }

        return 1;
    }
    //this function will be responsible of display all pizzas for an order of the user
    public void display()
    {
       for(int i =0; i<num; ++i)
       {
           System.out.println("\n" + (i+1) + "- Pizza:");
           pizzas[i].displayPizza();
       }
    }

    //this function will be taking care of creating the special pizzas
    //and then display them
    public int special()
    {
        rand = new Random();
        s = rand.nextInt(3) + 1;
        temp = new Pizza[s];
        for(int i = 0; i < s; ++i) {
            temp[i] = new Pizza();
            temp[i].create_spec();
        }
        System.out.println("\nThese Are Today's Specials: ");
        for(int i =0; i<s; ++i) {
            price = 9.00f;
            System.out.println("\n" + (i + 1) + "- Pizza:");
            temp[i].displayPizza();
            price= price + temp[i].the_price();
            System.out.printf("\nThe Total Priec For This Special IS : $"+ "%.2f",price);
        }
       return 1;
    }
    //this function will get the total for each pizza order and display the total price
    public void final_price()
    {
        for(int i =0; i < num;++i)
        {
            price= price +pizzas[i].the_price();
        }
        System.out.printf("\nThe Total Price For This Order is: $" + "%.2f",price);

    }
}
