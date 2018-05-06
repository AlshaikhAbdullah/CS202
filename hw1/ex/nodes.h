/**
 * Mishal Alajmi
 * CS 202
 * Homework #1
 * 02/06/2017
*/

#include"stop.h"



class DLL_node: public stop
{
    public:
        DLL_node();
        DLL_node(const DLL_node & copy_from);
        ~DLL_node();
        DLL_node *& go_next();
        DLL_node *& go_previous();
        int connect_next(DLL_node * nxt);
        int connect_prev(DLL_node * prv);
    private:
        DLL_node * next;
        DLL_node * previous;
};


class CLL_node: public stop
{
    public:
        CLL_node();
        CLL_node(const CLL_node & copy_from);
        ~CLL_node();
        CLL_node *& go_next();
        int connect_next(CLL_node * nxt);
    private:
        CLL_node * next;

};
