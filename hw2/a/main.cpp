/*
 * Mishal Alajmi
 * CS 202
 * Homework #2
 * 02/15/2017 */


#include"history.h"


int main()
{
    char uber_feed[SIZE],bus_feed[SIZE],str_feed[SIZE];
    char resp;
    int choice,spec=0;
    history store;
    transit * car = new uber; 
    transit * buses = new bus;
    transit * strcar = new streetcar;

    do
    {
        choice = 0;
        cout << "Welcome,This program will save your riding prefrence.\n" 
             << "Please choose one of the following by inputting the number infront of it:\n" 
             << "1-Leave feedback\n"
             << "2-View last feedback left\n"
             << "3-Remove feedback\n" 
             << "4-View all stored feedback" << endl;
        cin >> choice;
        cin.ignore(100,'\n');

        if(choice == 1)
        {
            cout << "First choose your prefered method of transport or view previous experiences:\n" 
             << "1-Uber\n"
             << "2-Bus\n"
             << "3-Streetcar\n" << endl;
            cin >> spec;
            cin.ignore(100,'\n');

            
            if(spec == 1)
            {
                car->get_exper(uber_feed);
                store.insert(*(car));

            }

            if(spec == 2)
            {
                buses->get_exper(bus_feed);
                store.insert(*(buses));
            }

            if(spec == 3)
            {
                strcar->get_exper(str_feed);
                store.insert(*(strcar));
            }
        }

        if(choice == 2)
        {
            if(store.get_single())
                cout << "\nHere's the last saved feedback!\n" << endl;
            else
                cout << "No feedback to show!" << endl;
        }

        if(choice == 3)
        {
            if(store.remove_single())
                cout << "\nlatest feedback removed!" << endl;

            else
                cout << "\nNo feedback to remove!\n" << endl;
        }

        if(choice == 4)
        {
            store.display();
        }

        cout << "Would you like to leave some more feedback(y/n)?" << endl;
        cin >> resp;
        cin.ignore(100,'\n');

    }while(resp != 'n');

    return 0;
};
