/*
 * Mishal Alajmi
 * CS 202
 * Homework #1
 * 02/06/2017
*/


#include"nodes.h"


DLL_node::DLL_node():next(NULL),previous(NULL){}


DLL_node::DLL_node(const DLL_node & copy_from):stop(copy_from),next(NULL),previous(NULL){}


DLL_node::~DLL_node(){}



DLL_node *& DLL_node::go_next()
{
    return this->next;
}

DLL_node *& DLL_node::go_previous()
{
    return this->previous;
}

int DLL_node::connect_next(DLL_node * nxt)
{
    this->next = nxt;
}


int DLL_node::connect_prev(DLL_node * prv)
{
    this->previous = prv;
}




CLL_node::CLL_node():next(NULL){}

CLL_node::CLL_node(const CLL_node & copy_from):stop(copy_from),next(){}

CLL_node::~CLL_node(){}


CLL_node *& CLL_node::go_next()
{
    return this->next;
}

int CLL_node::connect_next(CLL_node * nxt)
{
    this->next = nxt;
}
