//Abdullah Alshaikh
//Program 4 - CS202
//Pizza Orders Application

//This  file will have the user class and functions in this class where the user name will be taken and
//the doubly linked list will be created and also it will be responsible of deleting form the doubly list
package com.company;

import com.sun.org.apache.regexp.internal.RE;

import java.util.Scanner;

/**
 * Created by Budi on 5/26/2017.
 */
public class User {
    //variables
    private String name;
    private Node head;
    private int order_count =0;
    protected Node tail;
    protected int num;
    protected int i=0;
    protected Scanner input;

    //constructor
    public User()
    {
        name = null;
        head = null;
        num = 0;
        tail =null;
        input = new Scanner(System.in);
    }
    //copy constructor
    public User(User to_copy) {}

    //this function will get the user name and then create the double linked list for each order
    //and it will keep adding orders if the user answer yes for the repeat function question
    public void create_order()
    {
        System.out.println("\nWhat Is The Name Of The User: ");
        this.name = input.nextLine();
        do{
            doubly();
            head.make_pizza();
            ++order_count;
        }while(Repeat());



    }

    //wrapper function this function will be taking care of displaying the orders it will return 0 if there was no orders otherwise
    // it will call
    //the recursive function to display
    public int displayOrders()
    {
        if(head == null)
            return 0;
        else
        {
            System.out.println("( "+ name + " ) Order/s: ");
            return displayOrders(head);
        }
    }

    //the recursive function for displaying it will display each order with its number by incrementing the i variable
    //then it will return 1
    protected int displayOrders(Node head)
    {
        if(head == null)
            return 1;
        ++i;
        System.out.println("\nOrder Numeber: " + i );
        head.display();
        head.final_price();
        return displayOrders(head.goNext());
    }
    //this function will be the wrapper of the function that will create the double linked list
    protected void doubly()
    {
        head = doubly(head);
    }

    //this function will be creating node for the order at the head always
    //and it will for first case adding
    protected Node doubly(Node head)
    {
        Node temp = new Node ();
         temp.setNext(head);
        //temp.goNext() = head;
        if(head != null)
        {
            head.setPrevious(temp);
            tail = head;
        }
        head = temp;
        return head;
    }

    //this function will be the wrapper for removing from the doubly linked list
    //it will get user choice of which order to delete and then pass it to the recursive function
    public int delete_order()
    {
        if(head == null)
            return 0;
        else
        {
            int choice = 0;
            System.out.println("****These Are The Orders****");
            displayOrders();
            do {
                System.out.println("\n\nWhich One Would You Like To Remove(1 - " + order_count + " ): ");
                choice = input.nextInt();
            }while(choice < 0 || choice > order_count);
            i = 0;
            this.head = delete_order(head,choice);
           // Node temp = head.goNext();
            //head= null;
            //this.head= temp;
            return 1;
        }
    }

    //the recursive function to delete an order for the user
    //it will check last node case so it updates tail
    //other than that it will delete based on the user choice of the order number
    protected Node delete_order(Node head, int choice)
    {
        ++i;
        Node temp;
        if(head == null)
            return head;
        if(i == choice) {
            if(head.goNext() == null) {
                tail = head.goPrevious();
                head = null;
            }
            else {
                temp = head.goNext();
                if(head.goPrevious() != null) {
                    head.goPrevious().setNext(temp);
                    temp.setPrevious(head.goPrevious());
                }
                head = null;
                head = temp;//update head
            }
            return head;
        }
        else
           return  delete_order(head.goNext(),choice);
    }
    //this function will be taking care of deleting all orders
    public int removeAll(){
        if(head == null)
            return 0;
        else {
            head = null;
            return 1;
        }
    }


    //just a repeat function for repetitive cases it will return true if the user answers y otherwise false
    private boolean Repeat(){
        char resp;
        Scanner input = new Scanner(System.in);


        System.out.println("\nWould you like to make another order?(Y/N):");
        resp = input.next().charAt(0);

        if (resp == 'Y' || resp == 'y') {
            return true;
        }
        else if (resp == 'N' || resp == 'n') {
            return false;
        }
        else{ // if the user enters something other than Y or N
            System.out.println("\nEnter lower or upper n/N or y/Y Please!!!!!!!!!!!!!!\n");
            Repeat();
        }
        return false;
    }
}
