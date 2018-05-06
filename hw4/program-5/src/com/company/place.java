//Abdullah Alshaikh
//program 4-5 _ CS202
//Pizza Order Application

/*
    this file for the place class which will be the parent of the outside node to save the restaurants
    name it will have functions to check, to create, to display and to get the closest sip code
 */
package com.company;

/**
 * Created by Budi on 5/28/2017.
 */
public class place {
    protected String name;
    protected int zip;

    //constructor
    public place()
    {
        name = null;
        zip = 0;
    }

    //the function that will copy and stored to the protected member and copy the zip code from variables passed
    public void create_rest(String to_copy, int to_code)
    {
       name = new String(to_copy) ;
       zip = to_code;
    }

    //this function will only display the name and the zip
    public void display()
    {
        System.out.println("\n\n******** The Restaurant Name: " + name + " *********" + " \nZip Code: " + zip);
    }

    //to check if the passed argument is bigger than the one saved
    public boolean check(String to_check)
    {
        if(name.compareTo(to_check) > 0 )
            return true;
        else if(name.equals(to_check) == true )
            return true;
        else if(name.compareTo(to_check) < 0)
            return false;
        return false;
    }

    //this function will check for equality and return true if it is false if its not
    public boolean checking(String to_check)
    {
        if(name.equals(to_check) == true)
            return true;
        else
            return false;
    }
    //this function will return the subtraction of the zip i have
    public int get_near(int user_zip)
    {
        //to get the absolute value of the subtraction
        return Math.abs(user_zip - zip);
    }
}
