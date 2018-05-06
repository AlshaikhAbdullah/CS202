//Abdullah Alshaikh
//Program 3 - CS202
//Application management 
//this is the manager.cpp file
/*
 * this file will have the manager class functions only and this class will be the class that controls my program by creating the 
 * linked list and organizing it by the category that have the most frequently used apps 
 */
#include "manager.h"

//initializtion list 
manager::manager():head(NULL){}
manager::~manager()
{
    if(head) clear(head);
}
//the clear function that will deallocate the linked list by using tail recursion 
void manager::clear(l_node *& head)
{
    if(!head) return;
    clear(head->go_next());
    if(head)
    {
        delete head;
        head = NULL;
    }
}
manager::manager(const manager &obj){}
//this function will read from the files and it will add nodes at the head always 
//it will create an array of string class
//assgin each one to an category char 
//then it will pass that to the node so it can create a type for the node
//then it will for each loop it will open a file 
//and read the data there 
int manager::reading()
{
    String * obj = new String [3];
    obj[0] = "Social";
    obj[1] = "Games";
    obj[2] = "Education";
    for(int i =0; i < 3; ++i)
    {
        //adding at head everytime so i dont have to travarse 
        l_node * hold = new l_node;
        hold->create(obj[i]);
        if(i ==0)
            if(!hold->reading(social))
                cout << "\nError!! Couldn't Open Soical.txt" <<endl;
        if(i==2)
            if(!hold->reading(edu))
                cout << "\nError!! Couldn't Open Edu.txt" <<endl;
        if(i==1)
            if(!hold->reading(games))
                cout << "\nError!! Couldn't Open Games.txt" <<endl;
        hold->go_next() =head;
        head = hold;
    }
    if(obj)
    {
        delete [] obj;
        obj = NULL;
    }
    return 1;
}
//the wrapper function for the inseration 
//it will get the user choice for which category would like to add to
//the it will call the recursive function 
int manager::insert()
{
    int response =0;

    String temp1;
    do{
       cout << "\nFor Which Category Would You Like To Add:"
       << "\n1- Games.\n2- Social.\n3- Education.\nChoice(1-3): ";
       cin >> response; cin.ignore(100,'\n');

       if(response == 1)
           temp1 = "Games";
       else if(response == 2)
           temp1 = "Social";
       else if(response == 3)
           temp1 = "Education";
       else
           cout << "\nError!! Enter Valid Number!!!!!!!!!" <<endl;
    }while(response > 3 || response < 1); 

        l_node * current = NULL;
        current = insert(head,temp1);

    String * temp = new String[4];
    apps to_add;
    int freq =1;
    char response2;
    int update =0;
    
        current->display_type(); // to display the type the user is adding to 

        cout << "What Is The Name Of The Application: ";
        cin >> temp[0];
        if(current->user_insert(to_add,temp[0],update) == 5)
        {
            cout << "The application has been found!!\n\n";
            cout << "Would You Like To Update It(y- Yes/n- NO): ";
            cin >> response2; cin.ignore(100,'\n');
            if(response2 == 'y'|| response2 == 'Y')
            {
                update = 1; 
                cout << "What Is The Date: ";
                cin >> temp[1];
                cout << "What Is The Information: ";
                cin >> temp[2];
                cout << "How Much Time Was Spent(For Example, 45 minutes): ";
                cin >> temp[3];
                freq = -1;
                to_add.create(temp,freq);//to save the user input into the app object
                current->user_insert(to_add,temp[0],update);//to insert it 
                delete [] temp;
                temp = NULL;
                return 5;
            }
            else
                return 0;
        }

        cout << "What Is The Date: ";
        cin >> temp[1];
        cout << "What Is The Information: ";
        cin >> temp[2];
        cout << "How Much Time Was Spent(For Example, 45 minutes): ";
        cin >> temp[3];

        to_add.create(temp,freq); 
        current->insert(to_add);
        delete [] temp;
        temp = NULL;
        return 1;
}
//the recusrive function for the inseration it will look for the category the user chose 
//then it will call the insert function in the l_node class 
l_node *manager::insert(l_node * head, String & check)
{
    if(!head) return head;
    if(head->check_type(check))
    {
        return head;
    }
    return insert(head->go_next(),check);
}
//the wrapper function for the display all it will first check if theres data if there's 
//then it will call the recursive function 
int manager::display()const 
{
    if(!head)
        return 0;
    else
        return display(head);
}
// the recursive function for displaying all 
// it will call the display in the l_node 
// then it will travarse 
int manager::display(l_node * head)const 
{
    if(!head) return 1;
    head->display();
    return display(head->go_next());
}
//the wrapper function for the display top 
//it will check if theres data first then it will get the user choice to display 
//then it will call the recursive function to display top for that category the user chose 
int manager::display_top()
{
   if(!head)
       return 0;
   else
   {
       String choice;
       int response =0;

       cout << "\nWhich Category Would You Like To Display It's Top Frequency: ";
       cout << "\n1-Soical.\n2-Games.\n3-Education.\n(1-3): ";
       cin >> response; cin.ignore(100,'\n');
       if(response == 1)
           choice = "Social";
       if(response == 2)
           choice = "Games";
       else if(response== 3)
           choice = "Education";
       return display_top(head,choice);
   }
   return 1;
}
//the display top function that will check which category is the user input by calling the check type function 
//then it will call the idsplay top in the l_node to display the top applications been used 
int manager::display_top(l_node * head,String & choice)
{
    if(!head)
        return 1;
    if(head->check_type(choice))
    {
        cout << "\nCategory: " << choice << endl;
        head->display_top();
        return 1;
    }
    return display_top(head->go_next(),choice);
}
//the wrapper function for the sort that will only call the recursive function 
int manager::sort()
{
    return sort(head);
}
//the recursive function to sort the linked list based on the highest frequency i
//it will sort every two 
int manager::sort(l_node*&head)
{
    if(!head)
        return 0;
    if(!head->go_next())
        return 0;
    l_node * temp = head->go_next();
    if(head->get_sum() < temp->get_sum())
    {
        l_node * last = temp->go_next();
        head->go_next() = last;
        temp->go_next() = head;
        head = temp;
        return sort(head->go_next());
    }
    return sort(head->go_next());
}
//the = operator that will check if there was data then it will call clear function to delete 
//and then it will call the recursive function to copy all 
manager & manager::operator =(const manager & obj)
{
    if(head) clear(head);
    copy_list(head,obj.head);
    return *this;
}
//this the recusrsive function that will copy the list and travarse it will copy the whole list 
void manager::copy_list(l_node *& dest,l_node * source)
{
    if(!source)
    {
        dest = NULL;
        return;
    }
    dest = new l_node(*source);
    copy_list(dest->go_next(),source->go_next());
}
ostream & operator <<(ostream & out, const manager & obj)
{
    if(!obj.head)
        cout << "\nError!!There's No Data Stored!!" << endl;
    else
        obj.display();
    //obj.head->display();
    return out;
}
istream & operator >>(istream & in,manager & obj)
{
        obj.insert();
        return in;
}
