//Abdullah Alsahikh
//program 2 - CS202
//this .cpp file will have the name, person and LLL l_node classes
//it will basically only stor data for the address book
#include "name.h"

name::name():first(NULL),last(NULL){}
name::name(const name&){}
name::~name()
{
    if(first)
    {
        delete [] first;
        first =NULL;
    }
    if(last)
    {
        delete [] last;
        last = NULL;
    }
}
//this function will basically get the user input and save it 
//in order it can be used later 
void name::create(char st [], char nd [])
{
    if(first)
    {
        delete [] first;
        first = NULL;
    }
    if(last)
    {
        delete [] last;
        last = NULL;
    }
    int len = 0;
    len = strlen(st); first = new char [len +1];
    strcpy(first,st);
    len = strlen(nd); last = new char [len +1];
    strcpy(last,nd);
}
//this function will be copy data from the passed object of name
//to the one i created
void name::copy(name &source)
{
    if(first)
    {
        delete [] first;
        first = NULL;
    }
    if(last)
    {
        delete [] last;
        last =NULL;
    }
    int len =0;
    len = strlen(source.first); first = new char [len+1];
    strcpy(first,source.first);
    len = strlen(source.last); last = new char [len+1];
    strcpy(last,source.last);
}
//this function will check if the compaing is less it will return 0
//if it's bigger it will return 1
//if it's the same it will return 2
//so i can make a linked list for that case
//other than taht it will retrun 11 for no reason 
int name::check(name & source)
{
    if(strcmp(source.last,last) <0)
        return 0;
    else if(strcmp(source.last,last) > 0)
        return 1;
    else if(strcmp(last,source.last) ==0)
        return 2;
return 11;
}
//this function will be taking care of comapring the first 
//and the last names with whats coming in the args list
int name::check_both(name & temp)
{
    if(strcmp(first,temp.first) == 0 && strcmp(last,temp.last) ==0)
        return 1;
    else
        return 0;
}
//this function will be taking care of getting the name stored 
//to this object passed in the args to use it later 
void name::get(name & to_copy)
{
    int len =0; 
    len = strlen(first);
    to_copy.first = new char[len+1]; strcpy(to_copy.first,first);
    len = strlen(last);
    to_copy.last = new char[len+1]; strcpy(to_copy.last,last);
}
///// Person Functions /////

person::person():message(NULL){}
person::person(const person &){}
person::~person()
{
    if(message)
    {
        delete [] message;
        message =NULL;
    }
}
//this function will only call the copy function in it's parent class to copy data
void person::create(name & temp)
{
    copy(temp);
}
//this function will only display the first and last name of a person and the message if the person has one
void person::display()
{
    cout << "\nThe First Name is: " << first;
    cout << ". Last Name is: " << last << endl;
    if(message)
        cout << "Texts: ( " << message << " ). " << endl;
    cout << endl;
}
//this function will be taking care of saving a text for a person 
void person::get_text()
{
    char temp [TEXT];
    int len = 0;

        cout << "Texting: " << first << " " << last << "..." <<endl;
        cout << "What's the text(200 words): ";
        cin.get(temp,TEXT,'\n'); cin.ignore(100,'\n');
        len = strlen(temp);
        message = new char[len +1]; strcpy(message,temp);
        
return;
}
//this function will be taking care of removing a message from a person 
//for the snap chat app,
void person::clear_text()
{
    if(message)
    {
        delete [] message;
        message = NULL;
        cout << "The message has disappered." << endl;
        return;
    }
    else
        cout << "There are no messages..." << endl;
}
///// l_node Functions /////

l_node::l_node(){}
l_node::l_node(const l_node &){}
l_node::~l_node(){}

l_node *& l_node::go_next()
{
    return this->next;
}
//basically just a function to ask the user if he or she wants to repeat a phase
bool again()
{
    char response;
    cout << "Would You like to start over(y/n): ";
    cin >> response; cin.ignore(100,'\n');
    if(response == 'n')
        return false;
    else 
        return true;
}
