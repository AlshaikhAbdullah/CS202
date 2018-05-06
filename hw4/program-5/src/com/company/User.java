package com.company;

import com.sun.org.apache.regexp.internal.RE;

import java.util.Scanner;

/**
 * Created by Budi on 5/26/2017.
 */
public class User {
    private String name;
    private Node head;
    private int order_count =0;
    protected Node tail;
    protected int num;
    protected int i=0;
    protected Scanner input;

    public User()
    {
        name = null;
        head = null;
        num = 0;
        tail =null;
        input = new Scanner(System.in);
    }
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
    private int displayOrders(Node head)
    {
        if(head == null)
            return 1;
        ++i;
        System.out.println("\nOrder Numeber: " + i );
        head.display();
        head.final_price();
        return displayOrders(head.goNext());
    }
    private void doubly()
    {
        head = doubly(head);
    }
    private Node doubly(Node head)
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

    private Node delete_order(Node head, int choice)
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
    public int removeAll(){
        if(head == null)
            return 0;
        else {
            head = null;
            return 1;
        }
    }


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
