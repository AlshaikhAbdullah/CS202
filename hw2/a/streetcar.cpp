/*
 * Mishal Alajmi
 * CS 202
 * Homework #2
 * 02/15/2017
*/

#include"streetcar.h"

// default constructor
streetcar::streetcar():experience(NULL),status(false),stars(0),price(2.5)
{
    srand(time(NULL));
    delay = 5+(rand() % (15-5+1));
}


streetcar::streetcar(const transit & to_copy):transit(to_copy),experience(NULL),status(false),stars(0),price(2.5)
{
    srand(time(NULL));
    delay = 5+(rand() % (15-5+1));
}

streetcar::streetcar(const streetcar & to_copy)
{
    copy_exper(to_copy);
}

streetcar::~streetcar()
{
    if(experience)
    {
        delete [] experience;
        experience = NULL;
    }

    experience = NULL;
    status = false;
    delay = 0;
    price = 0;
    stars = 0;
}


void streetcar::display()
{
    if(status)
        cout << "Sorry, streetcar is full!" << endl;

    if(delay > 0)
        cout << "Sorry, the streetcar will be little bit late: " << delay << " min" << endl;

    else if(delay == 0)
        cout << "streetcar is scheduled to arrive on time!" << endl;

    cout << "Price to destination: " <<  price << '$'<< endl;

    cout << "Rating:\t";
    for(int i=0;i<stars;++i)
        cout << " * ";
    
    cout << "\nHere's what the last rider thought about uber: " << experience <<'\n' << endl;
    return;

}


void streetcar::get_exper(char * feedback)
{
   int feed_len = 0;

   cout << "Please tell us about your experience: " << endl;
   cin.get(feedback,SIZE,'\n' );
   cin.ignore(100,'\n');


   feed_len = strlen(feedback)+1;
   experience = new char[feed_len];
   strcpy(experience,feedback);

   cout << "How would you rate your experience(lowest:1-highest:5): " << endl;
   cin >> stars;
   cin.ignore(100,'\n');
   return;
}

int streetcar::copy_exper(char * feedback,int rating,int prc,int dly,bool stat)
{
    int feed_len = 0;
    if(!feedback)
        return 0;

    if(experience)
    {
        delete [] experience;
        experience = NULL;
    }

    feed_len = strlen(feedback)+1;
    experience = new char[feed_len];
    strcpy(experience,feedback);

    stars = rating;
    price = prc;
    delay = dly;
    status = stat;
    
    return 1;
}


int streetcar::copy_exper(const streetcar & to_copy)
{
    int exper_len = 0;
    if(!to_copy.experience)
        return 0;

    if(experience)
    {
        delete [] experience;
        experience = NULL;
    }

    exper_len = strlen(to_copy.experience)+1;
    experience = new char[exper_len];
    strcpy(experience,to_copy.experience);

    status = to_copy.status;
    delay = to_copy.delay;
    price = to_copy.price;
    stars = to_copy.stars;
    return 1; 
}
