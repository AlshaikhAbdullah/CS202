//Abdullah Alshaikh
//program 2 - CS202
/*
        the purpose of this program is to help the user organize the social networks
        that she or he has and help them text someone in the provieded 
        soical networks accounts the user will be able to make multiple managers 
        but each manager can have one type of an account and based on that the user
        will be able to interact
 */
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int SIZE = 50;
const int TEXT = 200;
bool again();
class name
{
    public:
        name();
        name(const name &);
        ~name();
        void create(char st [], char nd []);
        void copy(name &source);
        int check(name & source);
        int check_both(name & temp);
        void get(name & to_copy);
    protected:
        char * first;
        char * last;
        int num;
};

class person:public name
{
    public:
        person();
        person(const person &);
        ~person();
        void create(name & temp);
        void display();
        void get_text();
        void clear_text();
    protected:
        char * message;
};

class l_node:public person
{
    public:
        l_node();
        l_node(const l_node &);
         ~l_node();
        l_node *& go_next();
    protected:
        l_node * next;
};

