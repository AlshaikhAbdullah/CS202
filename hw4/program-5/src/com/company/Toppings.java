package com.company;

/**
 * Created by Budi on 5/26/2017.
 */
abstract class Toppings
{
    protected Kind obj;
    abstract public void put_toppings();

    public abstract int displayToppings();

    public abstract void rand_toppings();

    public abstract float price();
}
