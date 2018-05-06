/*
 * Mishal Alajmi
 * CS 202
 * Homework #2
 * 02/15/2017
 */


#include"transit.h"


transit::transit():experience(NULL),status(false),price(0),delay(0),stars(0){}

transit::transit(const transit & to_copy)
{
    copy_exper(to_copy);
}

transit::~transit()
{
    if(experience)
    {
        delete [] experience;
        experience = NULL;
    }

    experience = NULL;
    status = false;
    price = 0;
    delay = 0;
    stars = 0;

}



int transit::copy_exper(char * feedback,int rating,int prc,int dly,bool stat)
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


    status = stat;
    price = prc;
    delay = dly;
    stars = rating;
    return 1;
}

int transit::copy_exper(const transit & to_copy)
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
