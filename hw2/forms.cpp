//Abdullah Alshaikh 
//program 2 - CS202
//this .cpp file will have the functions for the manager class and the 
//CLL class c_node
//these functions will be taking care of creating everthing for this program from the top which is 
//creating the CLL that each one will be a type of communication and based on that the address books will be added
#include "forms.h"

/// c_node ///
c_node::c_node(){}
c_node::~c_node()
{
    if(type)
    {
        type->clear();
        delete type;
        type = NULL;
    }
}
c_node *& c_node::go_next()
{
    return this->next;
}
//to assign the type pointer to a class based of what the user chose 
//by using dynamic binding
int c_node::create(int choice)
{

    num = choice;
    if(choice == 1)
    {
        type = new facebook;
        return 1;
    }
    if(choice == 2)
    {
        type = new snapchat;
        return 1;
    }
    if(choice == 3)
    {
        type = new phone;
        return 1;
    }
    if(choice == 4)
    {
        type = new instagram;
        return 1;
    }
return 0;
}
//to add an address
int c_node::add_to()
{
        type->add();
        return 1;
}
// to check the intger from what is passed if it's match
int c_node::check(int choice)
{
    if(num == choice)
        return 1;
    else
        return 0;
}
void c_node::text()
{
     type->send();
}
//a function to display what is the form based on the data saved
//in the parent class name
void c_node::display()
{
    if(num ==1)
        cout << "Facebook." << endl;
    if(num ==2)
        cout << "Snapchat." << endl;
    if(num ==3)
        cout << "Phone." << endl;
    if(num ==4)
        cout << "Instagram." << endl;
}
void c_node::show_people()
{
    type->display_all();
}
void c_node::remove_contact()
{
    type->remove_one();
}
void c_node::remove_contacts()
{
    type->remove_contacts();
}
//the snap function that will be using RTTI downcasting to call the function
//that is different from the other derived classes which is the text_gone
//it will check if not null was returned then it will call the function
int c_node::snap()
{
    snapchat * ptr = dynamic_cast <snapchat*>(type);
    if(ptr)
        ptr->text_gone();
    return 1;
}
/// manager /// 
manager::manager():rear(NULL),first(NULL){}
manager::manager(const manager &){}
manager::~manager()
{
    if(rear)
    {
        clear_all(first);
            rear->~c_node();
            delete rear;
            rear = NULL;
    }
}
//recursive function to deallocate memory from the CLL
//and it will call the destrcotor of it to delete all conacted memory
void manager::clear_all(c_node *& first)
{
    if(first == rear) return;
    clear_all(first->go_next());
    if(first)
    {
        first->~c_node();
        delete first;
        first =NULL;
    }
}
//just a repeatative prompt that will get called from mutiple functions 
//and it will return the users choice 
int manager::which()
{
    int response =0;
           cout << "\nWhich form of communication:"
                << "\n1-Facebook.\n2-Snapchat.\n3-Phone.\n4-Instagram." << endl;
               cout << "Choose(1-4): ";
               cin >> response; cin.ignore(100,'\n');
               return response;
}
// the start function that will be the user interface and it will get the user 
// inputs and it will make rest of functions act based on that
// it will call a function for every choice in the menu 
void manager::start()
{
    int response = 0;

        cout << "\n\nHere is the menu:"
            << "\n1- Add a form of communication."
            << "\n2- Add someone to the address book."
            << "\n3- Text someone."
            << "\n4- Display types of communications."
            << "\n5- Display your address book for a type of communcation."
            << "\n6- Remove a form of communication."
            << "\n7- Remove a contact from the address book of a communcation."
            << "\n8- Remve all contacts for a type of communcation."
            << "\n9- To delete a message.(FOR SNAPCHAT ONLY)" 
            << "\n10- To return to main menu."
            << "\nWhat would you like to choose(1-10): ";
            cin >> response; cin.ignore(100,'\n');

           if(response  == 1)
           {
               response = which();
               if(create(response))
                   cout << "\n\nThe communication has been added." << endl;
               else
                   cout << "\n\nErorr !!!" << endl;
               response = 0;
           }
           if(response == 2)
           {
               response = which();
               if(!rear)
                   cout << "Error!!" <<endl;
               else
               {
                   find(response);
                   response =0;
               }
           }
           if(response == 3)
           {
               if(!rear)
                   cout << "Error!!" <<endl;
               else
               {
                   response = which();
                   text(response);
               }
            }
           if(response == 4)
           {
               if(!rear)
                    cout << "There's nothing to display!!" <<endl;
               else
                   display(first);
           }
           if(response == 5)
           {
               response = which();
               if(!rear)
                   cout << "There's nothing to show!!" << endl;
               else
                   show(first,response);
           }
           if(response == 6)
           {
               if(!rear) 
                   cout << "There's nothing to remove!! " <<endl;
               else
               {
                   response =which();
                   if(remove(response))
                       cout << "The Communication has been removed!!" <<endl;
                   else
                       cout << "Error!!not found!!" <<endl;
               }
           }
           if(response ==7)
           {
               if(!rear)
                   cout << "Error!!nothing was found!! " << endl;
               else
               {
                   response = which();
                   delete_one(response,first);
               }
           }
           if(response ==8)
           {
               if(!rear)
                   cout << "Error!!No communications stroed." << endl;
               else
               {
                   response = which();
                   delete_contacts(response);
               }
           }
           if(response == 9)
           {
               if(!rear)
                   cout << "There are no DATA !!! " <<endl;
               else if(!snap_text())
                   cout << "Error you dont have snapchat." <<endl;
           }
           if(response == 10)
               return;
}
//the create function that wll be taking care of adding forms of communcation
//it will always add at the beginning of the CLL
//it will check if theres nothing then add or add at the beginning 
int manager::create(int i)
{
    if(!rear)
    {
        rear = new c_node;
        rear->create(i);
        rear->go_next() = rear;
        first = rear;
        retur 1;
    }
    //rear->go_next() = NULL;
    //create(first,rear,i);
    c_node * temp = new c_node;
    temp->create(i);
    if (rear)
    {
        rear->go_next() = temp;
        temp->go_next() = first;
        first = temp;
        return 1;
    }
return 1;
}
/*
int manager::create(c_node *first, c_node *&rear,int i)
{
    if(!rear)
    {
        rear = new c_node;
        rear->go_next() = first;
    }
    create(first,rear,i);
}
*/
//the wrapper function for the adding someone to the address book of a form
//it will only call the recursiv function
int manager::find(int choice)
{
    return find(first,choice);
}
//the recursive function that will tarvrse through the CLL to find a match
//then it will call the function that will cause of a adding someone to address book
int manager::find(c_node * first,int choice)
{
    if(first == rear)
    {
        if(first->check(choice))
            return first->add_to();
        else
            return 0;
        return 0;
    }
    if(first->check(choice))
    {
        first->add_to();
        return 1;
    }
    else 
        return find(first->go_next(),choice);
}
//the wrapper function for the texting someone using a form of communication
//it will call the recursive function 
void manager::text(int choice)
{
    text(choice,first);
}
//the recursive function for the texting someone it will tarverse
//through the CLL to find a match, then it will call te function that will cause the
//texting happen
void manager::text(int choice, c_node * first)
{
    if(first == rear)
    {
        if(first->check(choice))
             first->text();
        return;
    }
    if(first->check(choice))
    {
        first->text();
        return;
    }
    text(choice,first->go_next());
}
//this function will be taking care of displaying the types of communications
//recursively and return 
void manager::display(c_node * first)
{
    if(first == rear)
    {
        first->display();
        cout << endl;
        return;
    }
    first->display();
    display(first->go_next());
}
//this function will be taking care of travrse through the list to look for a match
// for the user input and it will call the function that will cause the display of
// contacts for a form
void manager::show(c_node * first, int choice)
{
    if(first==rear)
    {
        if(first->check(choice))
            first->show_people();
        else
            return;
        return;
    }

    if(first->check(choice))
    {
        first->show_people();
        return;
    }
    show(first->go_next(),choice);
}
//the wrapper function for the delete a form it will check the none repeatative part first
//then it will call the recursive function
int manager::remove(int choice)
{
    c_node * temp= first;
    if(first->check(choice))
    {
        if(first->go_next() == first)
        {
            delete first;
            rear = NULL;
            first = NULL;
            return 1;
        }
        temp = first->go_next();
        delete first;
        first = temp;
        return 1;
    }
    else
        return remove(choice,first);
}

//this function will be taking care of traversing through the CLL to find
//a match for the user input then it will delete that form of communication 
//it will be checking every possible case for deletion 
int manager::remove(int choice, c_node *& temp)
{
    if(temp->go_next() == rear)
    {
        c_node * hold = temp->go_next();
        if(rear->check(choice))
        {
            
            delete rear;
            rear= temp;
            rear->go_next() = first;
            return 1;
        }
        if(temp->check(choice))
        {
            delete temp;
            temp = NULL;
            temp = hold;
            return 1;
        }
        return 0;
    }
    if(temp->check(choice))
    {
        c_node * hold = temp->go_next();
        delete temp;
        temp =NULL;
        temp= hold;
        return 1;
    }
   return remove(choice,temp->go_next());
}
//this function will be taking care of travresing throough the cLL and find a match
//for the user input and then it will call the function in the CLL
//that will cause of the deletion of a one contact
//and it's a recursive function
void manager::delete_one(int choice, c_node * first)
{
    if(first == rear)
    {
        if(first->check(choice))
            first->remove_contact();
        else
            cout << "Error!!Form couldn't be found!!" << endl;
        return;
    }
    if(first !=rear)
    {
        if(first->check(choice))
            first->remove_contact();
        else
            cout << "Error!!Form couldn't be found!!" << endl;
        return;
    }
    delete_one(choice,first->go_next());
}
//the wrapper function for the delete all contacts for a type
//it will check if we only have one type so we dont need to travrse 
//other than that it will call the recurisve function
void manager::delete_contacts(int choice)
{
    if(first == rear)
    {
        if(first->check(choice))
        {
            first->remove_contacts();
            return;
        }
    }
    else
        delete_contacts(choice,first);
}
//this function will be taking care of looking through the CLL for match of the user
//input and when it finds it it will call the remove contatcs in cll node
//this is the recursive function for the remove all contacts for a type
void manager::delete_contacts(int choice, c_node * first)
{
    if(first == rear)
    {
        if(rear->check(choice))
        {
            rear->remove_contacts();
            return;
        }
    }
    if(first->check(choice))
    {
        first->remove_contacts();
        return;
    }
    delete_contacts(choice,first->go_next());
}
//the wrapper function for the snap chat it will only return the function call of the 
//recursive function 
int manager::snap_text()
{
    return snap_text(first);
}
//the recursive for the snapchat function that will look for the snapchat node
//and then it will call the snap function which will do the RTTI 
int manager::snap_text(c_node * first)
{
    if(first == rear)
    {
        if(rear->check(2))
            return rear->snap();
        else
            return 0;
    }
    if(first->check(2))
        return first->snap();
    else
        return snap_text(first->go_next());
}
