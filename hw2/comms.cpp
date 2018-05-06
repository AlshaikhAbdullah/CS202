//Abdullah Alshaikh
//program 2 - CS202
//the .cpp file for the comms class which is the abstract class and 
//it's derived classes 
//facebook 
//snapchat
//phone
//instagram
//all functions explantions are in .h file in abstract class
#include "comms.h"

comms::comms(){}
comms::~comms()
{
}

/// Facebook Functions ///
facebook::facebook(){}
facebook::~facebook()
{
}
int facebook::send()
{
    return people.texting();
}
int facebook::add()
{
    return people.insert();
}
void facebook::display_all()
{
    people.display();
}
void facebook::remove_one()
{
    people.remove();
}
void facebook::remove_contacts()
{
    people.clear_all();
}
void facebook::clear()
{
    people.~address();
}
/// Snapchat Functions ///
snapchat::snapchat(){}
snapchat::~snapchat()
{
}
int snapchat::send()
{
    return people.texting();
}
int snapchat::add()
{
    return people.insert();
}
void snapchat::display_all()
{
    people.display();
}
void snapchat::remove_one()
{
    people.remove();
}
void snapchat::remove_contacts()
{
    people.clear_all();
}
void snapchat::clear()
{
    people.~address();
}
void snapchat::text_gone()
{
    people.gone_text();
}
/// phone ///
phone::phone(){}
phone::~phone()
{
}
int phone::send()
{
    return people.texting();
}
int phone::add()
{
    return people.insert();
}
void phone::display_all()
{
    people.display();
}
void phone::remove_one()
{
    people.remove();
}
void phone::remove_contacts()
{
    people.clear_all();
}
void phone::clear()
{
    people.~address();
}
/// Instagram ///
instagram::instagram(){}
instagram::~instagram()
{
}
int instagram::send()
{
    return people.texting();
}
int instagram::add()
{
    return people.insert();
}
void instagram::display_all()
{
    people.display();
}
void instagram::remove_one()
{
    people.remove();
}
void instagram::remove_contacts()
{
    people.clear_all();
}
void instagram::clear()
{
    people.~address();
}
