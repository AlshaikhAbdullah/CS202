//Abdullah Alshaikh
//program 4-5 - CS202
//this is the manager file which will have the manager functions and te class
//the manager class will not do a lot for this program but i need because i will need it for program 5
//which is a continues for this program
package com.company;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.function.Consumer;

/**
 * Created by Budi on 5/26/2017.
 */
public class Manager
{
    //variables
   protected Scanner input = new Scanner(System.in);
   protected User one;
   protected String user_name;
   protected String [] rests;
   protected int zip =0;
   protected int count_lines =0;
   protected OutsideNode root =null;

   //this is the constructor for the manager class
   public Manager()
   {
      one = new User();
   }
   //this function for creating an order
   public void create()
   {
      one.create_order();
   }
   //function to display orders
   public int display()
   {
      return one.displayOrders();
   }
   //this function to remove an order
   public int remove_order()
   {
      return one.delete_order();
   }
   //this function to remove all orders
   public int delete_all() { return one.removeAll();}
   //this function will get te lines from the external file so i can create an array of strings based on that
    protected int lines() throws IOException
    {
        try
        {
            BufferedReader in = null;
               in = new BufferedReader(new FileReader("restaurant.txt"));
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

    //this function will load from the external data file the restaurant name and the zip code
   public boolean load() throws IOException
   {

        lines();
        Scanner read;
        rests= new String [count_lines];
        int index = 0;
        try {
            File FileIn = null;
            FileIn = new File("restaurant.txt");

            read = new Scanner(FileIn);
            read.useDelimiter(";");
            while (index < count_lines) {
                rests[index] = read.next().replaceAll("\\r\\n", "");
                zip = read.nextInt();
                insert(rests[index], zip);
                ++index;
            }
            read.close();
            return true;
        }
            catch(Exception e){
            return false;
            }

   }
    //the wrapper for insert function it will updated the root
        public void insert(String to_insert,int the_zip) throws IOException {
            root = insert(root,to_insert,the_zip);
        }
        //the recursive function it will to check and go left and right based on that and then insert at the correct place
        private OutsideNode insert(OutsideNode root,String to_insert,int the_zip) throws IOException {
            if (root == null) {
                root = new OutsideNode();
                root.load_days();
                root.create_rest(to_insert,the_zip);
                 return root;
            }

        if(root.check(to_insert) == false)
            root.setLeft(insert(root.goLeft(), to_insert, the_zip));
        if(root.check(to_insert) == true)
            root.setRight(insert(root.goRight(), to_insert, the_zip));
        return root;
        }
        //the wrapper for diaplying it will check if there's something and if there is it will call the recursive function
        public boolean display_rest()
        {
           if(root == null) return false;
           else
               return display_rest(root);
        }
        //this function is the recursive function to display the restaurants it will traverse and call the display function
        public boolean display_rest(OutsideNode root)
        {
            if(root ==null) return true;
            display_rest(root.goLeft());
            root.display();
            root.display_spec();
            return display_rest(root.goRight());
        }

        //this function is the wrapper function to display a near by restaurant
        public int display_near(int user_zip)
        {
            if(root == null) return 0;
            else
            {
               int near = 100000000;
               return display_near(user_zip,near,root);
            }
        }

        //the recursive function to display a near by restaurant it will get the closest zip code
        // and on the way back it will display the nearest ones
        private int display_near(int user_zip,int near, OutsideNode root)
        {
            int temp;
           if(root == null)  return 1;
           temp = root.get_near(user_zip);
           if(temp < near)
               near = temp;
           display_near(user_zip,near,root.goLeft());
           display_near(user_zip,near,root.goRight());
           temp = root.get_near(user_zip);
           if(temp == near){
               root.display();
               root.display_spec();
           }
           return 1;
        }

        //function to remove all restaurants
        protected void remove_all() { root = null; }

        //this function is the wrapper to remove one restaurant
        public int remove(String to_check) {
            if (root == null)
                return 0;
            else {
                this.root = remove(root, to_check);
                return 1;
            }
        }
        //this function is the recursive function to delete a specific restaurant
        //it will check if the restaurant is found and if it is it will check all cases of deletion from a tree
        //and then it will delete based on that
        private OutsideNode remove(OutsideNode root, String to_check) {
            if (root == null) return root;

            if (root.checking(to_check)) {
                if(root.left == null && root.goRight() == null)
                    root = null;
                else if(root.goLeft() == null)
                    root = root.goRight();
                else if(root.right == null)
                    root = root.goLeft();
                else
                {
                    OutsideNode temp = root.goRight();//
                    OutsideNode left_node = root.goLeft();

                    root = null;
                    root = get_ios(temp);
                         if (root != temp) {
                             temp.left = root.right;
                             root.right = temp;
                         }
                    root.left = left_node.goLeft();
                }
                return root;
            }
             else if (root.check(to_check))
                root.right = remove(root.right, to_check);
            else
                root.left = remove(root.left, to_check);
            return root;
        }

        //this function will traverse all the way left and return the last node which will be used to get the ios
        private OutsideNode get_ios(OutsideNode root) {
            if (root == null) return root;
            if (root.left == null) return root;
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
        protected int retrieve(String check, OutsideNode root)
        {
           if(root == null)  return 0;
           if(root.checking(check) == true)
               return 1;
           retrieve(check,root.left);
           return retrieve(check,root);
        }

}
