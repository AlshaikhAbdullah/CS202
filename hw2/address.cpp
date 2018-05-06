//Abdullah Alshaikh
//program 2 - CS202
//this .cpp will have the functions of two classes
//1- node class. 2- address class
//these functions will basically be taking care of adding someone to the address book and everything related 
#include "address.h"
/// node functions ///

node::node():head(NULL){}
node::node(const node &){}
node::~node()
{
    if(head)
        clear_all(head);
}
//just a recursive function to deallocate memory for the linked list 
void node::clear_all(l_node *&head)
{
    if(!head) return;
    clear_all(head->go_next());
    if(head)
    {
        delete head;
        head=NULL;
    }
}

node *& node::go_left()
{
    return this->left;
}
node *& node::go_right()
{
    return this->right;
}
//this function will be taking care of adding dupes to the linked list 
int node::extra(name &temp)
{
    l_node * hold = new l_node;
    hold->create(temp);
    hold->go_next() = head;
    return 1;
}
//the wrapper function for displaying dupes
int node:: displayDupe()
{
    if(!head) return 0;
    return displayDupe(head);
}
//the recursive function that will display head data "duplications"
//by traversing and displaying
int node::displayDupe(l_node * head)
{
    if(!head) return 0;
    head->display();
    return displayDupe(head->go_next());
}
int node::check(name & temp)
{
    if(!head) return 0;
    return check(temp,head);
}
//the recursive function that will check head's data for what's 
//the user input and return if there was a match
//else returns 0
int node::check(name & temp, l_node * head)
{
    if(!head) return 0;
    if(head->check_both(temp))
        return 1;
    else
        return check(temp,head->go_next());
}
//this function will be taking care of checking if head has something if
//it does it will copy it's data and return 1 
//else if there's no head it will return 0
int node::get_head(name & temp)
{
    if(head)
    {
        head->get(temp);
        l_node * temp = head->go_next();
        delete head;
        head= NULL;
        head= temp;
        return 1;
    }
    else 
        return 0;
}
//the wrapper function for the remove text for the snapchat 
int node::remove_text(name & temp)
{
    if(!head) return 0;
    return remove_text(temp,head);
}
//the recursive function that will go through the list 
//to find a match for the names stroed then it will call the clear text 
//function if there was a match
int node::remove_text(name & temp, l_node * head)
{
    if(!head) return 0;
    if(head->check_both(temp))
    {
        head->clear_text();
        return 1;
    }
    else
        return check(temp,head->go_next());
}
//the wrapper function to remove a contact from the duplications it will check
//first if there's data then it will 
//call the recursive function
int node::remove_contact(name & temp)
{
    if(!head) return 0;
    return remove_contact(temp,head);
}
//this function will look for the match from the user inut stored in temp
//then it will delete it and return 1
int node::remove_contact(name & temp,l_node *&head)
{
    if(!head) return 0;
    if(head->check_both(temp))
    {
       l_node * temp = head->go_next();
       delete head;
       head=NULL;
       head = temp;
       return 1;
    }
    return remove_contact(temp,head->go_next());
}
/// address Functions ///

address::address():root(NULL){}
address::address(const address &){}
address::~address()
{
    if(root)
        clear_all(root);
}
//a wrapper for the function that will deallocate memory
void address::clear_all()
{
    clear_all(root);
}
//just a recursive function to deallocate memory
void address::clear_all(node *& root)
{
    if(!root) return;
    clear_all(root->go_left());
    clear_all(root->go_right());
    if(!root->go_left() && !root->go_right())
    {
        if(root)
        {
            root->~node();
            delete root;
            root=NULL;
        }
    }
}
//this function will be taking care of getting the user input of whats the person first and last name that should be added to the BST
//then it will call the trav function to travrse and add that person in the correct place
int address::insert()
{
    char tempfirst [SIZE];
    char templast [SIZE];
    char response;
    name temp;
        do{
            cout << "What is the first name: ";
            cin.get(tempfirst,SIZE,'\n'); cin.ignore(100,'\n');
            cout << "What is the last name: ";
            cin.get(templast,SIZE,'\n'); cin.ignore(100,'\n');
            temp.create(tempfirst,templast);
            if(trav(root,temp))
                cout << "\n\nThe person has been added." << endl;
           cout << "Would you like to add another person(y/n): ";
           cin >> response; cin.ignore(100,'\n');
        }while(response == 'y');
        return 1;
}
//the display function wrapper,it will check if there's something first then it will call the reh
void address::display()
{
    if(!root)
    {
        cout << "The Address Book is empty" << endl;
        return;
    }
    else
        display(root);
}
//the recursive function of the display, it will go through the address book
//and it will display all data by calling the display in the person 
//and it will call the linked list to display the dupe names
void address::display(node * root)
{
    if(!root)
        return;
    display(root->go_left());
    root->display();
    root->displayDupe();
    display(root->go_right());
}
//the texting function that will display the contacts for the user first then it 
//will get the user input,stored it in a name object then it will call the recursive
//function that will look through the BST and get that person 
int address::texting()
{
    char tempfirst[SIZE];
    char templast[SIZE];
    char response;
    name temp;
    display();
        do{
            cout << "Contact's first name: ";
            cin.get(tempfirst,SIZE,'\n'); cin.ignore(100,'\n');
            cout << "Contact's last name: ";
            cin.get(templast,SIZE,'\n'); cin.ignore(100,'\n');
            temp.create(tempfirst,templast);
            
            if(!texting(root,temp))
                cout << "Error!!! Person not found!!" << endl;
            cout << "Would you like to text someone else(y/n): ";
            cin >> response; cin.ignore(100,'\n');
        }while(response == 'y');
        return 1;
}
// a recursive function to travrse through the BST and look for a match with the user input
// and then call the get text function that will allow the user to send a message to a friend
int address::texting(node * root, name & temp)
{
    if(!root) return 0;
    texting(root->go_left(),temp);
    if(root->check_both(temp))
    {
        root->get_text();
        return 1;
    }
    if(!root->check_both(temp))
    {
            if(root->check(temp))
                return 1;
    }
    else return texting(root->go_right(),temp);
    return 0;
}
//this function will be taking care of traversing and finding the right spot to insert a node in the BST
//by calling the check function in the name class to check 
//and go right or left or add a linked list based on that 
int address::trav(node *&root,name &temp)
{
    if(!root)
    {
        root = new node;
        root->create(temp);
        root->go_left() = NULL;
        root->go_right() = NULL;
        return 1;
    }
    if(root->name::check(temp))
        trav(root->go_right(),temp);
    else if(!root->name::check(temp))
        trav(root->go_left(),temp);
    else if(root->name::check(temp) == 2)
    {
        root->extra(temp);
        return 1;
    }
    return 0;
}
//this function will be taking care of deleting a person fro the BST it will get the user 
//it will display the address book for the user and get user choice and then call the recursive function that will be taking care of the 
//removing 
int address::remove()
{

    char tempfirst [SIZE];
    char templast [SIZE];
    char response;
    name compare;
    display();
        do{
            cout << "What is the first name: ";
            cin.get(tempfirst,SIZE,'\n'); cin.ignore(100,'\n');
            cout << "What is the last name: ";
            cin.get(templast,SIZE,'\n'); cin.ignore(100,'\n');
            compare.create(tempfirst,templast);
            if(remove(root,compare))
                cout << "The person has been deleted from the address book." << endl;
            else
                cout << "Error !!! There's no such name saved." << endl;
           cout << "Would you like to delete another person(y/n): ";
           cin >> response; cin.ignore(100,'\n');
        }while(response == 'y');
    return 1;
}     
//this function will be taking care of deleting a contact from the BST if found 
//or the linked list inside it the BST if found first
//it will check each case possible 
//first if its at a leaf
//or if its only has one child
//then if i have to find the IOS to replace it but it will not replace until it
//checks if theres a head first so it just replaces what head has with the IOS
//other than that it will delete it and copy the data to the node that was found
int address::remove(node *& root,name & temp)
{
    if(!root) return 0;
    if(root->remove_contact(temp))
        return 1;
    if(root->check_both(temp))
    {
        name get;
        if(root->get_head(get)) //to check if the bst node has a LLL and get the info
        {
            root->copy(get);
            return 1;
        }
        if(!root->go_left() && !root->go_right()) //if its a leaf
        {
            delete root;
            root=NULL;
            return 1;
        }
        if(!root->go_left())//if it has one child
        {
            node * current = root;
            root=root->go_right();
            delete current;
            current =NULL;
            return 1;
        }
        if(!root->go_right())//if it has one child
        {
            node * current = root;
            root= root->go_left();
            delete current;
            current = NULL;
            return 1;
        }
        else//to find the ios
        {
            name get;
            node * current = root->go_right();
            if(!current->go_left())
            {
                current->name::get(get);
                root->name::copy(get);
                if(current->go_right())
                {
                    if(current->get_head(get)) //check if the ios also has a linked list and copy the info if it does
                    {
                        current->copy(get);
                        return 1;
                    }
                    else//to just connect and then delete 
                    {
                        root->go_right() = current->go_right();
                        delete current;
                        return 1;
                    }
                }
                else
                {
                    if(current->get_head(get)) //to check if the ios has a linked list and copy the info if it does
                    {
                        current->copy(get);
                        return 1;
                    }
                    else // else just delete the ios
                    {
                        delete current;
                        return 1;
                    }
                }
            }
            else
            {
                current = get_left(current);
                current->name::get(get);
                root->name::copy(get);
                delete current;
                return 1;
            }
        }
    }
        remove(root->go_left(),temp);
        return remove(root->go_right(),temp);
}
//just a function to travarse all the way to the left and return that pointer 
node *& address::get_left(node *& root)
{
    if(!root) return root;
    if(!root->go_left())
        return root;
    return get_left(root->go_left());
}
//this function will be taking care of the deleting a text for the snapchat form
//it will get teh user input and save in a temp name object
//and then it will call the recursive function 
//to look for that node taht has the same data
int address::gone_text()
{
    char tempfirst[SIZE];
    char templast[SIZE];
    char response;
    name temp;
    display();
        do{
            cout << "Contact's first name: ";
            cin.get(tempfirst,SIZE,'\n'); cin.ignore(100,'\n');
            cout << "Contact's last name: ";
            cin.get(templast,SIZE,'\n'); cin.ignore(100,'\n');
            temp.create(tempfirst,templast);
            
            if(!gone_text(root,temp))
                cout << "Error!!! Person not found!!" << endl;
            cout << "Would you like to delete another person's message(y/n): ";
            cin >> response; cin.ignore(100,'\n');
        }while(response == 'y');
        return 1;
}
//the recursive function that will go through the BST to get the node that matches
//the user input and then it will call the function that will let the user
//delete a message 
int address::gone_text(node * root,name & temp)
{
    if(!root) return 0;
    gone_text(root->go_left(),temp);
    if(root->check_both(temp))
    {
        root->clear_text();
        return 1;
    }
    if(!root->check_both(temp))
    {
            if(root->remove_text(temp))
                return 1;
    }
    else return gone_text(root->go_right(),temp);
    return 0;
}
