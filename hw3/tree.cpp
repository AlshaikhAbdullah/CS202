//Abdullah Alsahikh
//Program 3 - CS202
//application mangement program
/*
 * this tree.cpp is going to have the functions for the node class which is 
 * the red black tree class that will be taking care of inserting applications into the tree
 * secnd class functions is the genre fucntions that will be the parent of the l_node class just to
 * save the category name of the application and it will check it if needed
 * third class functions is the node class functions which will be the linked list node that will have the root pointer to the tree node
 * in order to save the applications iformation it will have the cases functions for 
 * the red black tree and it will read from the file
 */
#include "tree.h"
///////////////////
///node Functons///
//////////////////
node::node():right(NULL),left(NULL),parent(NULL),flag(true){}
node::~node() { }
node::node(const node & to_copy)
{
    flag = to_copy.flag;
}
node::node(const apps & obj){}
node *& node::go_left()
{
    return this->left;
}
node *&node::go_right()
{
    return this->right;
}
node *&node::get_parent()
{
    return this->parent;
}
node *& node::get_grand()
{
    return this->parent->get_parent();
}
node *& node::get_gGrand()
{
    return this->parent->parent->get_parent();
}
//function to get the uncle 
node *& node::get_uncle()
{
    node * gparent = get_grand();
    if(gparent->go_left() == parent)
        return gparent->go_right();
    else
        return gparent->go_left();
}
//function will return the flag for the tree
bool node::get_flag()
{
    return this->flag;
}
//function to set the flag 
void node::set_red(bool set)
{
    this->flag = set;
}
//function to check app names for two nodes it will return the boolen value of that operation 
bool node::to_check(const node * to_check)
{
    return app_name > to_check->app_name;
}
//the extraction operator for the node class it will basically display what the node has 
//it will check if there's something to display then it will 
ostream & operator << (ostream & out, const node &obj)
{
        out << "\nThe Name of The App: " << obj.app_name << endl;
        out << "Date of Last Usage: " << obj.date <<endl;
        out << "Info: " << obj.info << endl;
        out << "The Length of The Session: " << obj.length << endl;
        out << "It's Been Used For: " << obj.count << " Times" << endl;
    return out;
}

///////////////////////
/// Genre Functions ///
//////////////////////
genre::genre():sum_count(0){}
genre::~genre() { }
//it will only create the type name by assgining it to the string passed to the function 
int genre::create(String & source)
{
    type = source;
    return 1;
}
//the checking for the genre it will return the bool value of the operator 
int genre::checking(String & check)
{
    return type == check;
}
void genre::display_type()
{
    cout << "Adding For: " <<  type << endl;
}

/// l_node Functions ///
//initializtion list 
l_node::l_node():next(NULL),root(NULL),sum(0),nodes(0),avg(0){}
//the l_node destructor that will check if theres root the it will call clear function if there was 
l_node::~l_node()
{
    if(root) clear(root);
}
//the recursive function to deallocate memory from the l_node class it will delete all nodes by deleteing leafs and then go up 
//by tail recusrsion 
void l_node::clear(node *& root)
{
    if(!root) return;
    clear(root->go_left());
    clear(root->go_right());
    if(root)
    {
        if(!root->go_left() && !root->go_right())
        {
           // root->~node();
            delete root;
            root =NULL;
        }
    }
}
//the copy constructor for the l_node class that will basically copy the data from the obj 
//and call the copy_new function passsing that object to copy the whole tree it has
l_node::l_node(const l_node & obj)
{
    type = obj.type;
    sum = obj.sum;
    nodes = obj.nodes;
    avg = obj.avg;    
    //this->root = obj.root;
    copy_new(root,obj.root);
}
//this function will only return the next pointer 
l_node *& l_node::go_next()
{
    return this->next;
}
//the wrapper function for the insert it will only return the recusrive function call 
int l_node::insert(const apps &obj)
{
    /*
    if(!root)
    {
        root = new node(obj);
        root->set_red(false);
        ++nodes;
        sum+=root->get_count();
        return 1;
    }
    else 
    */
        return insert(obj,root);
}
//the recusrive function for the insert it will look for an empty spot to insert and it will save how many times we insert a node so the number of nodes
//and the the node frequency number for me to keep so i can display top without having to have multiple extra functions 
//then it will call the case 1 function to check all case for inseration for a red black tree
int l_node::insert(const apps & obj, node *& root)
{
    if(!root)
    {
        root = new node;
        root->copy(obj);
        ++nodes;
        sum+=root->get_count();
        return case1(root);
    }
    if(!root->check(obj))
        return insert(obj,root->go_left());
    else
        return insert(obj,root->go_right());
}

//reading from the file into the tree nodes
//it will create an array of strings to pass multiple inputs and pass one pointer to apps object"source" and save it there and then call the insert function to 
//insert data into the tree
int l_node::reading(const char the_file[])
{
        ifstream in;
        String * read = NULL;
        apps source;
        read = new String [4];
        char temp [SIZE];
        int file_count =0;
        in.open(the_file);
        if(!in)
        {
            return 0;
        }
        if(in)
        {
            while(!in.eof() && in.get(temp,SIZE,':'))
            {
                in.ignore(100,':'); read[0] = temp;
                in.get(temp,SIZE,':'); in.ignore(100,':');
                read[1] = temp;
                in.get(temp,SIZE,':'); in.ignore(100,':');
                read[2]= temp;
                in.get(temp,SIZE,':'); in.ignore(100,':');
                read[3] = temp;
                in >> file_count; in.ignore(100,'\n');
                source.create(read,file_count);
                insert(source);
            }
        }
        in.clear();
        in.close();

        if(read)
            delete [] read;
        return 1;
}
int l_node::case1(node * &root)
{
    //set black if there were no parent
    //so its the first node ever
    if(!root->get_parent())
    {
        root->set_red(false);
        return 1;
    }
    //other than that it will go to the second case
    else
        return case2(root);
}
int l_node::case2(node * &root)
{
    // return if it's already black
    if(root->get_parent()->get_flag() == false)
        return 0;
    //other than that it will go to case 3
    else
        return case3(root);
}
int l_node::case3(node * &root)
{
    //if the uncle is parent, set the uncle to the right
    if(root->get_uncle() == root->get_parent())
        root->get_uncle() = root->get_parent()->get_parent()->go_right();

    //if the uncle is red, it will set the parent and the uncle to black
    //and grandparent to red
    if(root->get_uncle() != NULL && root->get_uncle()->get_flag() == true)
    {
        root->get_parent()->set_red(false);
        root->get_uncle()->set_red(false);
        root->get_grand()->set_red(true);
        //then check if there's a root
        return case1(root);
    }

    //other than that go to the next case
    else
        return case4(root);
}
int l_node::case4(node *&root)
{
    //find where the parent is located
    if(root == root->get_parent()->go_right() && root->get_parent() == root->get_parent()->get_parent()->go_left())
    {
        //pass it in for left rotation 
        rotate_left(root);
        
        //child's left side
        return case5(root->go_left());
    }
    //else rotate to the right side
    else
    {
        if(root==root->get_parent()->go_left() && root==root->get_parent()->get_parent()->go_right())
        {
            rotate_right(root);
            return case5(root->go_right());
        }
    }
    //use the current root to check rotation
    return case5(root);
}

//if uncle is a black leaf, parent is a red parent, and uncle is red that was added outside
int l_node::case5(node * &root)
{
    //set parent to black and grandparent to red
    root->get_parent()->set_red(false);
    root->get_parent()->get_parent()->set_red(true);

    //if uncle, rotate right
    if(root==root->get_parent()->go_left())
        return rotate_right(root);
    //other than that just rotate left
    else
        return rotate_left(root);
}
//the rotate function to the left for the red black tree
int l_node::rotate_left(node *& root)
{
    node * temp = NULL;

    //rotate for case 4
    if(root->get_parent()->get_parent()->go_left() == root->get_parent())
    {
        //rotating left logic
        temp = root->go_left();
        root->go_left() = root->get_parent();
        root->get_parent()->go_right() = temp;
        root->get_parent() = root->get_grand();
        root->go_left()->get_parent() = root;
        root->get_parent()->go_left() = root;
    }
    //rotate for case 5
    else
    {
        //if the great grand parent right is a grandparent, set great grand parent 
        //to parent
        if(root->get_gGrand()->go_right() == root->get_grand())
            root->get_gGrand()->go_right() =root->get_parent();

        //else set great grand parent left to the parent
        else
            root->get_gGrand()->go_left() =root->get_parent();

        //rotating left logic
        temp = root->get_parent()->go_left();
        root->get_parent()->go_left()=root->get_grand();
        root->get_grand() = root->get_gGrand();
        root->get_parent()->go_left()->get_parent() = root->get_parent();
        temp->get_parent() = root->get_parent()->go_left();
        root->get_parent()->go_left()->go_right() =temp;
    }
    return 1;
}
//the rotate function to the right for the red balck tree 
int l_node::rotate_right( node *&root)
{
    node * temp = NULL;

    //rotate for case 4
    if(root->get_parent()->get_parent()->go_right() == root->get_parent())
    {
        //rotate right logic 
        temp = root->go_right();
        root->go_right() = root->get_parent();
        root->get_parent()->go_left() = temp;
        root->get_parent() = root->get_grand();
        root->go_right()->get_parent() = root;
        root->get_parent()->go_right() = root;
    }
    //rotate for case 5
    else
    {
        //if the great grand parent is a grand parent, it will set the great grand parent
        //to the parent 
        if(root->get_gGrand()->go_right() == root->get_grand())
            root->get_gGrand()->go_right() = root->get_parent();

        //else set the great grand parent left to the parent
        else
            root->get_gGrand()->go_left() =root->get_parent();

        //rotating to the right
        temp = root->get_parent()->go_right();
        root->get_parent()->go_right() = root->get_grand();
        root->get_grand() = root->get_gGrand();
        root->get_parent()->go_right()->get_parent() = root->get_parent();
        temp->get_parent() = root->get_parent()->go_right();
        root->get_parent()->go_right()->go_left() =temp;
    }
    return 1;
}

//the wrapper function for the display all it will check first if we have something then 
//it will display the category and the frequency total if there is
//then it will call recursive function 
int l_node::display() const
{
    if(!root)
        return 0;
    else
    {
        cout << "\n\nCategory: " << type << "\nFrequency: " << sum <<"\n*\n*";
        return display(root);
    }
}
//the recursive function for the display all 
//it will display alphabitaclly by calling the display function inside the parent of node which is the apps 
//and travarse 
int l_node::display(node*root)const
{
    if(!root)
        return 1;
   display(root->go_left());
   root->display();
   return display(root->go_right());
}
//the wrapper function for the display top it will get the average and then pass it to the recursive function 
int l_node::display_top()
{
    avg = sum/nodes;
    cout <<"Displaying Average Frequency: " <<  avg << " And Above.\n";
    if(avg == 0)
        return 2;
    if(!root)
        return 0;
    else
        return display_top(root,avg);
}
//this function will be going through the tree recursively and display all applications with a frequency above the average frequency
int l_node::display_top(node *root,int check_avg)
{
    if(!root)
        return 1;
    display_top(root->go_left(),check_avg);
    root->show_top(check_avg);
    return display_top(root->go_right(),check_avg);
}
//this function will call parent function check_type passing a class object to check it 
int l_node::check_type(String & check)
{
    return checking(check);
}
//it will return the sum to check it and order the lsit based on that 
int l_node::get_sum()
{
    return sum;
}
//the user insert function will be taking care of geting user input and save them all in a temp apps object by calling the create function 
//and then it will call the insert function passing that apps object that was created 
//and then it will delete the tep streing array of classes thats been made for the process
int l_node::user_insert(apps & to_add,String & name,int update)
{
    /*
    String * temp = new String[4];
    apps to_add;
    int freq =1;
    node * current = NULL;
    char response;
    
        cout << "\nYour Adding For: " << type << endl <<endl;


        cout << "What Is The Name Of The Application: ";
        cin >> temp[0];
        current = retrieve(root,temp[0]);

        if(current)
        {
            cout << "The application has been found!!\n\n";
            cout << "Would You Like To Update It(y- Yes/n- NO): ";
            cin >> response; cin.ignore(100,'\n');
            if(response == 'y'|| response == 'Y')
            {
 
                cout << "What Is The Date: ";
                cin >> temp[1];
                cout << "What Is The Information: ";
                cin >> temp[2];
                cout << "How Much Time Was Spent(For Example, 45 minutes): ";
                cin >> temp[3];
                freq = -1;
                to_add.create(temp,freq);
                current->copy(to_add);
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
        
*/
    node * current = NULL;
    current = retrieve(root,name);
    if(current)
    {
        if(update) //to check if the the number is 1 to replace the info of the current data
        {
             current->copy(to_add);
             return 1;
        }
        if(current)
                return 5;
            else
                return 0;
    }
    return 0;
}
node * l_node::retrieve(node * root,String &name_check)
{
    if(!root) return root;
    if(root->check_same(name_check))
        return root;
    node * temp =  retrieve(root->go_left(),name_check);
    if(temp)
        return temp;
    return retrieve(root->go_right(),name_check);
}
//the assgin operator function it will check if theres something it will delete all and then copy
l_node & l_node::operator =(const l_node & obj)
{
    if(root) clear(root);
    copy_new(root,obj.root);
    return *this;
} 
//this function will be used for the = operator to copy the whole tree into a new one 
int l_node::copy_new(node *& dest,node * source)
{
    if(!source)
        return 0;
    dest = new node(*source);
    dest->copy(*source);
    return copy_new(dest->go_left(),source->go_left())+ copy_new(dest->go_right(),source->go_right());
}
//the not equal operator will call the check function 
bool l_node::operator !=(const l_node & obj) const 
{
       return check(root,obj.root); 
}
//this function will go through each node and compare it's data with the other one in the red black tree
bool l_node::check(node * source, node * other)const
{
    if(!source || !other)
        return true;
    if(!source->to_check(other))
        return false;
    return check(source->go_left(),other->go_left()) + check(source->go_right(),other->go_right());
}
//this extraction operator it will display the whole tree if there was data 
//it will display all applications 
ostream & operator << (ostream & out,const l_node & obj)
{
    //
    //out << obj.type << endl;
    if(!obj.root)
        cout << "Error!! There's No Applications!!" << endl;
    else 
        obj.display();
    return out;
}
//the insertion operator will call the user_insert function that will get user input
istream & operator >>(istream & in,l_node & obj)
{
//    obj.user_insert();

    String * temp = new String[4];
    apps to_add;
    int freq =1;
    node * current = NULL;
    char response;
    
        cout << "What Is The Name Of The Application: ";
        cin >> temp[0];
        current = obj.retrieve(obj.root,temp[0]);

        if(current)
        {
            cout << "The application has been found!!\n\n";
            cout << "Would You Like To Update It(y- Yes/n- NO): ";
            cin >> response; cin.ignore(100,'\n');
            if(response == 'y'|| response == 'Y')
            {
 
                cout << "What Is The Date: ";
                cin >> temp[1];
                cout << "What Is The Information: ";
                cin >> temp[2];
                cout << "How Much Time Was Spent(For Example, 45 minutes): ";
                cin >> temp[3];
                freq = -1;
                to_add.create(temp,freq);
                current->copy(to_add);
                return in;
            }
            else
                return in;
        }
        

        cout << "What Is The Date: ";
        cin >> temp[1];
        cout << "What Is The Information: ";
        cin >> temp[2];
        cout << "How Much Time Was Spent(For Example, 45 minutes): ";
        cin >> temp[3];
        
        to_add.create(temp,freq);
        obj.insert(to_add);
    return in;
}
//this operator will check the nodes in the pass has more nodes than the otehr one
bool l_node::operator <(const l_node& obj) const
{
    if(this->nodes < obj.nodes)
        return true;
    else
        return false;
}
//this operator will check if the tree passed has less nodes than the other one
bool l_node::operator >(const l_node&obj) const
{
    if(this->nodes > obj.nodes)
        return true;
    else
        return false;
}
//+operator it will add each node of another tree one by one by calling the connect function
//it will return temp by value which is the temporary object the + operator will be saved
//in
l_node l_node::operator +(const l_node & obj) const
{
    l_node temp;
    if(type == obj.type)
    {
        temp.copy_new(temp.root,this->root);
        temp.connect(obj.root,temp.root);
        return temp;
    } 
    return temp;
}
//the += operator which will do the same as the + operator but it will deal 
//with the current object and it will return it by refreance 
l_node &l_node::operator +=(const l_node & obj)
{
    if(type == obj.type)
    {
        connect(obj.root,this->root);
        return *this;
    } 
    return *this;
}
//the first function that will go through node of the tree we are trying to add
//to the temp tree and then it will call the connect each passing that node
//and the connect each will take care of the rest
int l_node::connect(node *to_connect,node*&root)
{
    if(!to_connect) return 0;
    connect(to_connect,root);
    return connect(to_connect->go_left(),root)+ connect(to_connect->go_right(),root);
}
//recursive function that will find a spot to the node pass by the connect function to the correct 
//spot, then it will add that node by it flag 
int l_node::connect_each(node * to_connect,node *& root)
{
    if(!root)
    {
        root = new node(*to_connect);
        root->copy(*to_connect);
        return case1(root);
    }
     if(root->to_check(to_connect))
        return connect(to_connect,root->go_left());
    else
        return connect(to_connect,root->go_right());
}
//this the >= operator which will check the number of nodes 
//then it will return true if the number of nodes is bigger or the same
//else it will return false
bool l_node::operator >=(const l_node & obj)const
{
    if(this->nodes > obj.nodes || this->nodes == obj.nodes)
        return true;
    else
        return false;
}
//this is the <= operator which will check if the number of nodes 
//if it's less or same as the one passed and and it will return true if that happens 
//else it will return false
bool l_node::operator <=(const l_node&obj) const
{
    if(this->nodes < obj.nodes || this->nodes == obj.nodes)
        return true;
    else
        return false;
}
//the == operator function it will do the regular check however it will reuturn 
//using the double negation so if its not (not the same ) that will mean its the same
//thus it will return true 
bool l_node::operator == (const l_node & obj) const
{
       return !check(root,obj.root); 
}

