//Abdullah Alshaikh
//Program 3 - CS202
//application management 
/*
 * the main .h file the string.h, this program will help the user manage his or her
 * applications and it will mix things between reading from external file and get user input 
 * to add applications and it will organize the applications based on how frequent 
 * the applications been used and it will display them to the user all of them or
 * by display just the top based on the avg freuency for each category 
 */
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

const int SIZE = 200; // const size for all arrays so that the user can input whatever

//const char for each file 
const char games[] = "games.txt"; 
const char edu []= "edu.txt";
const char social [] = "social.txt";

class String 
{
    public:
        String();
        ~String();
        String(const String &);

        //operators for the string class
        String & operator =(const String &);
        String & operator =(const char *);
        bool operator ==(const String &) const;
        bool operator ==(const char *)const;
        bool operator > (const String &) const;
        bool operator < (const String &)const;
        friend ostream & operator <<(ostream &,const String &);
        friend istream & operator >>(istream &,String &);

        //test function 
        void test();


    protected:
        char * name;
        int len;

        //the operators functions 
        int oper_char(const char *);
        int op_check(const String &) const;
        int op_check_char(const char *)const;
        int oper_string(const String &);
};

class apps
{
    public:
        apps();
        ~apps();
        apps(const apps&);
        bool check(const apps &);
        void copy(const apps&);
        void create(String*,int &);
        void display();
        int get_count();
        int show_top(int);
        bool check_same(String &);
        //apps & operator =(const apps &);
    protected:
        String app_name;
        String date;
        String info;
        int count;//the frequency 
        String length; // session length
};

bool again(); //function for check user for a repeatation 
