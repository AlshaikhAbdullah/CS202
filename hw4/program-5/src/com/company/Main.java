//Abdullah Alshaikh
//Program 4-5- CS202
//Pizza Orders
/*
    This program will help the user order from a pizza restaurant and give the user the option to choose toppings by reading the toppings from an external file
    so that the restaurant can have multiple specials for all days of the week and it will also give managers options which are
    adding a restaurant or deleting one, also it will create random pizzas for each day of the week for every restaurant
 */
package com.company;
import sun.security.krb5.SCDynamicStoreConfig;

import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Manager obj = new Manager();
        String temp;
        int choice = 0;
        do
        {
            System.out.print("\n\nWelcome To Pizza Pijja !!!\nMENU:" +
                    "\n1- Create An Order." +
                    "\n2- Display Orders." +
                    "\n3- Remove An Order." +
                    "\n4- Remove All Orders." +
                    "\n5- Display Restaurant Near Your Zip Code." +
                    "\n6- Remove a Branch. (Managers Only)" +
                    "\n7- To Remove All Restaurants. (Managers Only)" +
                    "\n8- To Search For a Restaurant." +
                    "\nChoose(1-8): ");
            choice = obj.input.nextInt();

            if (choice == 1)
                obj.create();
            if (choice == 2)
                if (obj.display() == 0)
                    System.out.println("There Are No Orders To Display!!");
            if (choice == 3)
                if(obj.remove_order()== 0)
                    System.out.println("There Are No Orders To Remove");
                else
                    System.out.println("Order Was Removed Successfully.");
            else if(choice == 4)
                if(obj.delete_all() == 0)
                    System.out.println("There Are No Orders To Remove");
                else
                    System.out.println("Orders Have Been Removed");
            if( choice == 5) {
                obj.load();
                int user_zip = 0;
                System.out.println("What Is Your Zip Code: ");
                user_zip = obj.input.nextInt();
                obj.display_near(user_zip);
            }
            if(choice == 6)
            {
                temp = new String();
                System.out.println("Here Is The List Of Branches:\n");
                obj.display_rest();
                System.out.print("What's the name of the branch: ");
                temp = obj.input.nextLine();
                if(obj.retrieve(temp) == 1)
                {
                    obj.remove(temp);
                    System.out.println("\nBranch Has Been Removed.");
                }
                else
                    System.out.println("Branch Couldn't Be Found");
            }
            if(choice == 7)
            {
                obj.remove_all();
                System.out.println("All Restaurants Have Been Removed.");
            }
            if(choice == 8)
            {
                temp = new String();
                System.out.print("Enter The Name of The Branch: ");
                temp = obj.input.nextLine();
                if(obj.retrieve(temp) == 1)
                    System.out.println("The Branch Has Been Found.");
                else
                    System.out.println("The Branch Hasn't Been Found.");
            }
        }while(Repeat());
        System.out.println("Here's Your Orders: ");
        if(obj.display() == 0)
            System.out.println("\nNo Orders!!!\n\nGood Bye");
        else
            System.out.println("\nYour Orders Will Be Delivered In 45-60 Mins"
                    + "\nThank You For Ordering From Pizza Pijja\nGoodBye .... ");
    }
    private static boolean Repeat(){
        char resp;
        Scanner input = new Scanner(System.in);
        System.out.println("\n\nWould you like to See The MENU AGAIN?(Y/N):");
        resp = input.next().charAt(0);
        if (resp == 'Y' || resp == 'y') {
            return true;
        }
        else if (resp == 'N' || resp == 'n') {
            return false;
        }
        else { // if the user enters something other than Y or N
            System.out.println("\nEnter lower or upper n/N or y/Y Please!!!!!!!!!!\n");
            Repeat();
        }
        return false;
    }
}
