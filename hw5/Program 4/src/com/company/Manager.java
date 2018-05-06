//Abdullah Alshaikh
//program 4 - CS202
//this is the manager file which will have the manager functions and te class
//the manager class will not do a lot for this program but i need because i will need it for program 5
//which is a continues for this program
package com.company;

import java.util.Scanner;

/**
 * Created by Budi on 5/26/2017.
 */
public class Manager
{
   protected Scanner input = new Scanner(System.in);
   protected User one;
   //protected String user_name;
   public Manager()
   {
      one = new User();
   }
   //it will call the create order
   public void create()
   {
      one.create_order();
   }
   //it will call the display function in the user class and it will return it's return
   public int display()
   {
      return one.displayOrders();
   }
   //it will call the remove function and return its value
   public int remove() { return one.delete_order(); }
   //it will call the remove all in the user class and return its value
   public int removeAll() { return one.removeAll(); }


}
