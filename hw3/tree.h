//Abdullah Alshaikh
//program 3 - CS202
//application management 
/*
 * this file is the tree.h file which will have the node class interface 
 * which will have multiple functions that will help create the red black tree
 * and it will be derived from apps so node is an app
 * another class is the genre class which will be the parent of the l_node class
 * it will only keep the type of application 
 * third class is the l_node class which will be the holder of the tree node class
 * it will create tree and it will read from the external files 
 */
#include "string.h"

//tree node class
class node: public apps
{
    public:
        node();
        ~node();
        node(const node &);
        node(const apps &);

        //returning pointers functions 
        node *& go_left();
        node *& go_right();
        node *& get_parent();
        node *& get_grand();
        node *& get_gGrand();
        node *& get_uncle();

        //////
        void set_red(bool set);
        bool get_flag();

        /////
        bool to_check(const node *);
        friend ostream & operator <<(ostream &,const node &);
    protected:
        node * right;
        node * left;
        node * parent;
        bool flag;
};

class genre 
{
    public:
        genre();
        ~genre();

        /////
        int create(String &);
        int checking(String &);
        void display_type();
    protected:
        String type;
        int sum_count;
};
//liinked list class
class l_node:public genre
{
    public:
        l_node();
        ~l_node();
        l_node(const l_node &);
        l_node *& go_next();

        //functions that will manage the program
        int insert(const apps &);
        int display()const;
        int reading(const char the_file []); 
        int check_type(String &);
        int display_top();
        int get_sum();
        int user_insert(apps &, String &,int);

        //tree operators 
        l_node & operator =(const l_node &);
        bool operator !=(const l_node &) const;
        bool operator ==(const l_node &) const;
        friend ostream & operator <<(ostream &,const l_node &);
        friend istream & operator >>(istream &,l_node &);
        bool operator <(const l_node &) const;
        bool operator >(const l_node &) const;
        bool operator >=(const l_node &) const;
        bool operator <=(const l_node&obj) const;
        l_node operator +(const l_node &)const;
        l_node & operator +=(const l_node &);

    protected:
        //root pointer and a next pointer 
        l_node * next;
        node * root;

        //the variables to save the sum of the frequencies 
        //and the number of nodes and the avarage of the frequencies 
        int sum;
        int nodes;
        int avg;

        //tree management functions 
        int insert(const apps &, node *&);
        int display(node *)const;
        int display_top(node *,int );
        node * retrieve(node*,String&);
        
        //reb black tree cases function
        int case1(node *&);
        int case2(node *&);
        int case3(node *&);
        int case4(node *&);
        int case5(node *&);

        //rotation for red black tree
        int rotate_left(node *&);
        int rotate_right(node *&);

        //destructor for the tree
        void clear(node*&);
        
        //the operator functions
        int copy_new(node *& dest, node * source);
        bool check(node * source, node * other)const;
        int connect( node *to_connect,node *&);
        int connect_each(node *,node *&);
};
