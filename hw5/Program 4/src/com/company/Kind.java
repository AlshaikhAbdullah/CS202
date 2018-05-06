//Abdullah Alshaikh
//Program 4 - CS202
//Pizza Orders Application

//this file will have the kind class and its functions which will be taking care of reading from the external
//files and it will be responsible of creating the linear linked list of toppings based on the user's choice
//and it will get the price based on the number of nodes
package com.company;

import javax.swing.plaf.ViewportUI;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by Budi on 5/26/2017.
 */
public class Kind
{
    //variables
    protected Lnode head;
    protected String [] topp;
    protected int count_lines = 0;
    protected Scanner input;
    protected int random;

    //constructor
    public Kind()
    {
        head = null;
        topp = null; // to save lines from file
        input = new Scanner(System.in);
        random = 0;
    }

    //copy constructor
    public Kind(Kind to_copy)
    {
        this.head = new Lnode(to_copy.head);
    }

    //this function will be taking care of getting the user's choice of the read from file toppings
    public void get_toppings()
    {
        int choice = 0;
        System.out.println("\nThese Are The Toppings: " + " \n0- To Add Nothing.");
        for(int i = 0; i < count_lines; ++i)
        {
            System.out.println((i+1)+ "- " + topp[i]);
        }
        System.out.print("\nWhat Would You Like To Add(1 - " + (count_lines) + "): ");
        choice = input.nextInt();
        if(choice == 0)
            return;
        else
            insert(choice-1);

    }

    //this function will be taking care of reading the files lines, so i can create the array of strings
    //based on that
    protected int lines(int which) throws IOException
    {
        try
        {
            BufferedReader in = null;
            if (which == 0)
                in = new BufferedReader(new FileReader("veggies.txt"));
            if(which == 1)
                in = new BufferedReader(new FileReader("crust.txt"));
            if(which == 2)
                in = new BufferedReader(new FileReader("cheese.txt"));
            if(which == 3)
                in = new BufferedReader(new FileReader("protein.txt"));
            while (in.readLine() != null)
                ++count_lines;
            in.close();
        }
        catch (IOException e)
        {
            System.err.println("Could not reach file!");
        }
        return 0;
    }

    //this function will be taking care of reading from the file based on the number based to which will tell
    //which file to open
    protected boolean load(int which) throws IOException
    {
        if(topp != null)
            return false;
        lines(which);
        Scanner read;
        topp = new String [count_lines];
        int index = 0;
        try{
            File FileIn= null;
            if(which == 0)
                FileIn= new File("veggies.txt");
            if(which == 1)
                FileIn= new File("crust.txt");
            if(which == 2)
                FileIn= new File("cheese.txt");
            if(which == 3)
                FileIn= new File("protein.txt");

            read = new Scanner(FileIn);
            read.useDelimiter(";");
            while(index < count_lines)
            {
                topp[index] = read.next().replaceAll("\\r\\n","");
                ++index;
            }
            read.close();
            return true;

        }
        catch(Exception e){
            return false;
        }
    }

    //the wrapper function to insert the topping into the linked list
    public int insert(int i)
    {
        head = insert(this.head,i);
        head.store(topp[i]);
        return 1;
    }

    //the recursive function to insert into the linked list of toppings it will always add at head
    public Lnode insert(Lnode head,int i)
    {
        Lnode temp = new Lnode();
       // temp.store(topp[i]);
        temp.setNext(head);
        head = temp;
        return head;
    }

    //the wrapper function for displaying the toppings
    public int display()
    {
        if(head == null)
            return 0;
        else
            return display(head);
    }

    //the recursive function for display the toppings for the linked list
    private int display(Lnode head)
    {
        if(head == null)
            return 1;
        head.show_name();
        return display(head.go_next());
    }

    //this function will take care of creating a randomly generate a number to add a random topping for the special pizza
    public void randomly() {
        Random rand = new Random();
        random = rand.nextInt(count_lines -1) + 1;
        insert(random);
    }

    //a wrapper function, this function will get the total price of the toppings added it will return the type price
    //times how many nodes
    public float get_price(float type)
    {
        int times =1;
        get_price(head,times);
        return type * times;
    }

    //the recursive function to get the total price for all toppings
    private int get_price(Lnode head, int times) {
        if(head == null)
            return 1;
        ++times;
        return get_price(head.go_next(),times);
    }

}
