package com.company;

import javax.print.attribute.standard.MediaSize;
import java.util.Scanner;

/**
 * Created by Budi on 5/26/2017.
 */
public class Name
{
    protected String name;
    protected Scanner input;
    public Name()
    {
        name = null;
        input = new Scanner(System.in);
    }
    public Name(Name to_copy)
    {
       this.name = new String(to_copy.name);
    }
    public int store(String toStore)
    {
        this.name = new String(toStore);
        return 1;
    }
    public void display() {
        System.out.print(" " + name + " | ");
    }
}
