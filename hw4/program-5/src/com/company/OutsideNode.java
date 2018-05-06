//Abdullah Alshaikh
//Program 4-5 - CS202
//Pizza order application

/*
    this file is for the outside tree which will be the restaurant with its zip code for the area.
    this class will read from an external file the days and it will create nodes for each day so each restaurant
    will have 7 days of inside nodes and each node will have an array of pizzas specials
 */
package com.company;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by Budi on 5/28/2017.
 */

class OutsideNode extends place{
    //variables
    protected InsideNode root;
    protected OutsideNode left;
    protected OutsideNode right;
    protected String [] pizzas;
    protected Random rand;
    protected int random = 0;
    protected int count_lines =0;
    protected Scanner input = new Scanner(System.in);
    //constructor
    public OutsideNode()
    {
        left = null;
        right = null;
        root = null;
        rand = null;
    }
    public OutsideNode goLeft() { return this.left; }
    public OutsideNode goRight() { return this.right; }
    public void setRight(OutsideNode current)
    {
       this.right = current;
    }
    public void setLeft(OutsideNode current)
    {
        this.left = current;
    }
    //this function will get te lines from the external file so i can create an array of strings based on that
    protected int lines() throws IOException
    {
        try
        {
            BufferedReader in = null;
            in = new BufferedReader(new FileReader("pizzas.txt"));
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
    //this function will read from the file into the array of pizzas days
     public boolean load_days() throws IOException
   {

        lines();
        Scanner read;
        pizzas = new String [count_lines];
        int index = 0;

        try {
            File FileIn = null;
            FileIn = new File("pizzas.txt");

            read = new Scanner(FileIn);
            read.useDelimiter(";");
            while (index < count_lines) {
                pizzas[index] = read.next().replaceAll("\\r\\n", "");
                create_pizza(pizzas[index]);
                ++index;
            }
            read.close();
            return true;
        }
            catch(Exception e){
            return false;
            }

   }

   //this function will create the nodes for each day
    //the wrapper function
    public void create_pizza(String to_add)
    {
       //rand = new Random();
       //random = rand.nextInt(7) + 2;
       //for(int i = 0; i < random; ++i)
           this.root = create_pizza(root,to_add);
    }
    //the recursive function for the creating the nodes od days it will check and go left and right based on that
    //then it will add the node at the correct spot
    private InsideNode create_pizza(InsideNode root,String to_add)
    {
        if(root == null)
        {
            root = new InsideNode();
            root.store(to_add);
            //root.create_pizza();
            return root;
        }
        if(root.check(to_add) == false)
            root.setLeft(create_pizza(root.goLeft(),to_add));
        else
            root.setRight(create_pizza(root.goRight(),to_add));
        return root;
    }
    //the wrapper function for the display it will check if theres something and return 0 if there's not
    //or call recursive function
    public int display_spec()
    {
        if(root == null) return 0;
        else
            return display_spec(root);
    }
    //recursive function to display the days and create the pizzas specials and display them right away
    private int display_spec(InsideNode root)
    {
        if(root == null) return 1;
        display_spec(root.goLeft());
        root.display_day();
        root.create_pizza();
        return display_spec(root.goRight());
    }
    //function to remove all nodes of days of specials
    protected void remove_all()
    {
        root = null;
    }
    //wrapper to remove a day specials
    public int remove(String to_check)
    {
        if(root == null)
            return 0;
        else {
            this.root = remove(root,to_check);
            return 1;
        }
    }
    //the recursive function to remove a day specials from a restaurant it will check if found and then it will check
    //for all removal cases from a BST then it will delete
    private InsideNode remove(InsideNode root, String to_check)
    {
       if(root == null) return root;

       if(root.checking(to_check))
       {
           if(root.goLeft() == null && root.goRight() == null)
               root = null;
           else if(root.goLeft() == null)
               root = root.goRight();
           else if(root.goRight() == null)
               root = root.goLeft();
           else
           {
               InsideNode temp = root.goRight();
               InsideNode left_node = root.goLeft();

               root = null;
               root = get_ios(temp);
               if(root != temp)
               {
                   temp.left = root.goRight();
                   root.right = temp;
               }
               root.left = left_node.goLeft();
           }
           return root;
       }
       else if(root.check(to_check))
           root.right = remove(root.right,to_check);
       else
           root.left = remove(root.left,to_check);
       return root;
    }
    //this function will only traverse to the last left node and return it
    private InsideNode get_ios(InsideNode root)
    {
        if(root == null) return root;
        if(root.left == null) return root;
        return get_ios(root.left);
    }
        //retrieve wrapper to find an item inside the inside tree
        public int retrieve (String check)
        {
            if(root == null) return 0;
            else
                return retrieve(check,root);
        }
        //recursive function for the retrieve function it will check if the item has been found
        //it will return 1 if it's found
        protected int retrieve(String check, InsideNode root)
        {
           if(root == null)  return 0;
           if(root.checking(check) == true)
               return 1;
           retrieve(check,root.left);
           return retrieve(check,root);
        }

}
