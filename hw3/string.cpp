//Abdullah alshaikh
//program 3 - CS202
//applicatin management 
//this file is the string.h, its going to have the functions for the String class which will be taking care of all of the string class operators overloading
//and it will have the apps functions that will be taking care of saving and displaying data for the apps class
#include "string.h"

//initialzition list 
String::String():name(NULL),len(0){}
String::~String()
{
    if(name)
    {
        delete [] name;
        name = NULL;
    }
}
String::String(const String & obj){
    //oper_string(obj);
}
//the = operator function for an object it will only call the oper string function 
String & String::operator =(const String & obj)
{
    if(this == &obj)
        return *this;
    oper_string(obj);
        return *this;
}
//the function that will do the work for the = operator for a class object 
//it will check if there's data first and delete it if there is 
//then it will get the length and then create a new char based on that and then copy into it 
int String::oper_string(const String & obj)
{
        if(this->name)
            delete [] this->name;
        this->len = strlen(obj.name);
        this->name = new char [this->len +1];
        strcpy(this->name,obj.name);
        return 1;
}
//the wrapper for the == operator it will return the op check function and that it 
bool String::operator ==(const String & obj) const
{
    return op_check(obj);
}
//the the check function for the == operator for an obj 
//it will check the name memebers by using str compare and return false and treu based on that 
int String::op_check(const String & obj) const
{
    if(strcmp(this->name,obj.name) == 0)
        return 1;
    else 
        return 0;
}

//the wrapper function for the assgin operator that will call the oper char function to do the work
String & String::operator =(const char * temp)
{
    if(this->name == temp)
        return *this;
    oper_char(temp);
    return *this;
}
//the = operator second function that will be doing the work for the wrapper 
//it will get len of the char and make a new name and then copy the data to it from the char 
int String::oper_char(const char * temp)
{
        if(this->name)
            delete [] this->name;
        this->len = strlen(temp);
        this->name = new char [len+1];
        strcpy(this->name,temp);
        return 1;
}
//the == operator which will only call the op check function to do the work
bool String::operator ==(const char * temp) const
{
    return op_check_char(temp);
}
//the check function that will compare a string class with a char and return false or true based on that 
//also it will check first before comaring if both are not NULL
int String::op_check_char(const char * temp) const
{
    if(!temp || !this->name)
        return 0;
    if(strcmp(temp,this->name) == 0)
        return 1;
    else
        return 0;
}

//the extraction operator that will cout whatever inside the string class which is the name char
ostream & operator <<(ostream & out,const String & obj)
{
    if(obj.name)
        out << obj.name;
    return out;
}
//the insertion operator for the string class that will make insert thing dierctly into the class which will make my program much easier;
istream & operator >>(istream & in, String & obj)
{
    if(obj.name)
        delete [] obj.name;
    char temp [SIZE];
    in.get(temp,SIZE,'\n');
    cin.ignore(100,'\n');
    obj.len = strlen(temp);
    obj.name = new char[obj.len+1];
    strcpy(obj.name,temp);
    return in;
}
//the less than operator which will basically will take care of comparing both names and return true and false based on that 
bool String::operator <(const String & source) const
{
    if(strcmp(this->name,source.name) < 0)
        return false;
    else
        return true;
}
//the bigger than operator which will be taking care of doing strcmp for both names and return true and false based on that 
bool String::operator >(const String &source) const
{
    if(strcmp(this->name,source.name) > 0 || strcmp(this->name,source.name) ==0)
        return true;
    else
        return false;
}
/// Apps Functions ///
apps::apps():count(0){}
apps::apps(const apps & copy)
{
    //app_name.oper_string(copy.app_name);
    /*
    date = copy.date;
    info = copy.info;
    count = copy.count;
    length = copy.length;
    */
}
//
apps::~apps() {}
//this function will basically copy from an app object, and it will be used for copying a tree
void apps::copy(const apps & to_copy)
{
    app_name = to_copy.app_name;
    date = to_copy.date;
    info = to_copy.info;
    if(to_copy.count == -1)
        ++count;
    else
        count = to_copy.count;
    length = to_copy.length;
}
bool apps::check(const apps & to_check)
{
        return to_check.app_name < app_name;
}
//this function will be taking care of saving the data passed in the array of strings into the app 
//the first index will be for the name the second one will be for the date,the third one will be for the information 
//the fourth one for the length, and there's the file count which has the frequency read from the file 
void apps::create(String * source,int & file_count)
{
    app_name = source[0];
    date = source[1];
    info = source[2];
    length = source[3];
    count = file_count;
}
//just a display function for the info that apps has
void apps::display()
{
    cout << "\nThe Name of The App: " << app_name << endl;
    cout << "Date of Last Usage: " << date <<endl;
    cout << "Info: " << info << endl;
    cout << "The Length of The Session: " << length << endl;
    cout << "It's Been Used For: " << count << " Times" << endl;

}
//this function will only return the count`
int apps::get_count()
{
    return count;
}
//this function will display if the app has a frequency avgerage and above 
int apps::show_top(int avg)
{
    if(count >= avg)
    {
        cout << "\nThe Name of The App: " << app_name << endl;
        cout << "Date of Last Usage: " << date <<endl;
        cout << "Info: " << info << endl;
        cout << "The Length of The Session: " << length << endl;
        cout << "It's Been Used For: " << count << " Times" << endl;
        return 1;
    }
    return 0;
}
//it will return true if its the same name or false if it's not
bool apps::check_same(String & to_check)
{
    return app_name == to_check;
}
//just a function to ask yuser for repeatation and return true or false based on that 
bool again()
{
    char response;
    cout << "\n\nWould You Like To See The MENU AGAIN(y- Yes/n- Quit): ";
    cin >> response; cin.ignore(100,'\n');
    if(response == 'y' || response == 'Y')
        return true;
    else
        return false;
}
