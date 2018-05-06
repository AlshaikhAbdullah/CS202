//Abdullah Alshaikh 
//Program 3 - CS202
//Application management program
//this is the main.cpp file which will be the one that kick start my manager class and will have the user interface in it
//and everytime after an operator has been done , it will sort the list
#include "manager.h"

int main()
{
    manager obj;
    //manager new_obj;
    String temp;
    char response;
    int choice =0;
        cout << "\nWelcome!!\nThis Program Will Help You Manage Your Apps based on Usage Frequency"
            << "\nAnd It Will Allow You To Also Add Applications...\n(Enter Any Key To Contunie): ";
        cin >> response; cin.ignore(100,'\n');
        cout << "\nLoading Text Files..."
            << "\n(Enter Any Key To Contunie): ";
        cin >> response; cin.ignore(100,'\n');
        obj.reading();
        do{
            cout << "\nMenu:\n1- Add An Application.\n2- Display All Categories Applications.\n3- Display Top Frequency Applications For A Category."
                << "\nChoose(1-3): ";
            cin >> choice; cin.ignore(100,'\n');
            if(choice == 1)
            {
                int to_catch = obj.insert();
                if(to_catch == 1)
                    cout << "\n\nApplication Has Been Added Successfully. " << endl;
                else if(to_catch == 5)
                    cout << "\n\nApplication Has Been Updated Successfully. " << endl;
                else
                    cout << "\n\nDidn't Update The Application. " << endl;
            }
            if(choice == 2)
            {
                obj.sort();
                cout << obj << endl; 
            }
            if(choice == 3)
                if(!obj.display_top())
                    cout << "\n\nError !!! Nothing To Display!!" << endl;
            obj.sort();//To Sort The List After Every Operation 
        }while(again());
        //new_obj = obj;
        //new_obj.display();

    return 0;
}
