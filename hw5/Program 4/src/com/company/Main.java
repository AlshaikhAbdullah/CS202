//Abdullah Alshaikh
//Program 4 - CS202
//Pizza Orders
/*
    This program will help the user order from a pizza restaurant and give the user the option to choose toppings by reading the
    toppings from an external file, so that the restaurant can edit the txt file and add toppings without needing to hire a programmer

 */
package com.company;
import sun.security.krb5.SCDynamicStoreConfig;

import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {
        Manager obj = new Manager();
        int choice = 0;
        do
        {
            System.out.print("\n\nWelcome To Pizza Pijja !!!\nMENU:" +
                    "\n1- Create An Order." +
                    "\n2- Display Orders." +
                    "\n3- Remove An Order." +
                    "\n4- Remove All Orders." +
                    "\nChoose(1-4): ");
            choice = obj.input.nextInt();

            if (choice == 1)
                obj.create();
            if (choice == 2)
                if (obj.display() == 0)
                    System.out.println("\nThere Are No Orders To Display!!");
            if (choice == 3)
                if(obj.remove() == 0)
                    System.out.println("\nThere Are No Orders To Remove");
                else
                    System.out.println("\nOrder Was Removed Successfully.");
            else if(choice == 4)
                if(obj.removeAll() == 0)
                    System.out.println("\nThere Are No Orders To Remove");
                else
                    System.out.println("\nOrders Have Been Removed");
        }while(Repeat());
        System.out.println("\nHere's Your Orders: ");
        obj.display();
        System.out.println("\nYour Orders Will Be Delivered In 45-60 Minutes\nThank You For Ordering From Pizza Pijja\nGoodBye .... ");
    }

    //this function is for asking the user to show the menu again and return true or false based on that
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
