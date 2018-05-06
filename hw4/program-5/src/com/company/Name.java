//Abdullah Alshaikh
//program 4-5 - CS202
//Pizza Order Application


//this file for the name class which will be used with multiple class as the parent that holds the data for a data structure
//the lnode is going to be derived from it and the inside node also
package com.company;

import javax.print.attribute.standard.MediaSize;
import java.util.Scanner;

/**
 * Created by Budi on 5/26/2017.
 */
public class Name
{
    //variables
    protected String name;
    protected Scanner input;
    //constructor
    public Name()
    {
        name = null;
        input = new Scanner(System.in);
    }
    //copy constructor
    public Name(Name to_copy)
    {
       this.name = new String(to_copy.name);
    }

    //function to the name from the passed agrs
    public int store(String toStore)
    {
        this.name = new String(toStore);
        return 1;
    }
    //this function will check if the passed arg bigger, equals or smalled that whats stored and return true and false based on that
    public boolean check(String to_check)
    {
        if(name.compareTo(to_check) > 0 )
            return true;
        if(name.equals(to_check) == true )
            return true;
        else if(name.compareTo(to_check) < 0)
            return false;
        return false;
    }
    //this function to display the toppings
    public void display() {
        System.out.print(" " + name + " | ");
    }
    //this function will be responsible of displaying the day
    public void display_day()
    {
        System.out.println("\n\nThe Day:" + name);
    }
    //this function will check for equality and it will return true if there were equal and false if they were not
    public boolean checking(String to_check)
    {
        if(name.equals(to_check) == true) return true;
        else return false;
    }
}
