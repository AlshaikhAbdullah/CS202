//Abdullah Alshaikh
//program 2 - CS202
//the .h file for types of communications and the abstract classes 
////all functions explanations are here in the abstract class
#include "address.h"

class comms
{
    public:
        comms();
        virtual ~comms();
        virtual int send() =0; // to send texts through a type of communications
        virtual int add() =0;//to add someone to the address book
        virtual void display_all()=0;//to display the address book
        virtual void remove_one()=0;//to remove on contact from the address book
        virtual void remove_contacts() =0;// to remove everyone from address book
        virtual void clear() =0;//to deallocate memory
    protected:
        address people;
};

class facebook:public comms
{
    public:
        facebook();
        ~facebook();
        int send();
        int add();
        void display_all();
        void remove_one();
        void remove_contacts();
        void clear();
    protected:
};

class snapchat:public comms
{
    public:
        snapchat();
        ~snapchat();
        int send();
        int add();
        void display_all();
        void remove_one();
       void remove_contacts();
        void clear();
        void text_gone();
    protected:
};

class phone:public comms
{
    public:
        phone();
        ~phone();
        int send();
        int add();
        void display_all();
        void remove_one(); 
       void remove_contacts();
        void clear();
    protected:
};

class instagram:public comms
{
    public:
        instagram();
        ~instagram();
        int send();
        int add();
        void display_all();
        void remove_one();
       void remove_contacts();
        void clear();

    protected:
};
