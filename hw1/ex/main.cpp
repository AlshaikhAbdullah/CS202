/*
 * Name: Mishal Alajmi
 * Homework#1
 * CS202
 * 2/1/2017
*/


#include"line.h"

int main()
{
    line ns_line;
    loop a_loop;
    streetcar a_car;
    garage hold;

    char res;
    int id=0;
    int choice = 0;

    hold.read_file();
    ns_line.read_line_file();
    a_loop.read_loop_file();    
    
    cout << "This program was designed to monitor streetcars on a given track, you can add a streetcar to an existing track by inputting its #ID\n" 
                     << "To make a selection enter the number that appears infront of the option you want\n" << endl;
    
    do {
            cout << "1-view available Streetcars:\n"
                 << "2-view stops in NS Line:\n"  
                 << "3-View stops in A Loop:\n" 
                 << "4-Add a car to a line:\n" 
                 << "5-Add a car to a loop:\n"
                 << "6-remove a car from a line:\n"
                 << "7-remove a car from a loop:\n" << endl;
             
            cin >> choice;
            cin.ignore(100,'\n');

            if(choice == 1)
                hold.display_garage();

            else if(choice == 2)
                ns_line.display_line();
        

            else if(choice == 3)
                a_loop.display_loop();

            else if(choice == 4)
            {
                id = 0;
                cout << "\n\nstreetcar id:" << endl;
                cin >> id;
                cin.ignore(100,'\n');
                ns_line.place_car(a_car,id,hold);
            }

            else if(choice == 5)
            {
                id = 0;
                cout << "\n\nstreetcar id:" << endl;
                cin >> id;
                cin.ignore(100,'\n');
                a_loop.place_car(a_car,id,hold);

            }

            else if(choice == 6)
            {
                id = 0;
                cout << "\n\nstreetcar id:" << endl;
                cin >> id;
                cin.ignore(100,'\n');
                ns_line.remove_car(id);
            }

            else if(choice == 7)
            {
                id = 0;
                cout << "\n\nstreetcar id:" << endl;
                cin >> id;
                cin.ignore(100,'\n');
                a_loop.remove_car(id);
            }

            cout << "Would you like to go again(y/n)?" << endl;
            cin >> res;
            cin.ignore(100,'\n');

    }while(res != 'n');
        

    return 0;
};
