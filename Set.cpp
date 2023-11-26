//
//  Set.cpp
//  Project 2
//
//  Created by Tina Fotouhi on 1/23/23.
//

#include <iostream>
#include "Set.h"
using namespace std;

Set::Set()
{
    m_items = 0;
    head = nullptr;
    tail = nullptr;
}

Set::~Set()
{
    Node* p;
    p = head;
    while (p != nullptr)
    {
        Node* n;
        n = p->next;
        delete p;
        p = n;
    }
}

Set::Set(const Set& other)
{
    m_items = other.m_items; //set size of copy equal to size of original set
    if (m_items == 0) //check if the set is empty
    {
        head = nullptr;
        tail = nullptr;
        return;
    }
    //if set is not empty
    head = new Node; //create a new node and assign head to point to it
    head->prev = nullptr; //make head's previous a nullptr
    head->data = other.head->data; //fill the head's data with the other head's data
    Node* current = head; //create a new pointer to the current head
    
    for (Node* p = other.head->next; p != nullptr; p = p->next) //iterate through the set, if the current node is not the last node
    {
        Node* n = new Node; //create a new node
        current->next = n; //set the current pointer's next to this node n
        n->prev = current; //set n's previous to the current node to connect them
        n->data = p->data; //fill this node's data with the other set's respective data
        current = n; //update current to point to the new current node to keep track
    }
    current->next = nullptr; //set current's next to nullptr to indicate the final node
    tail = current; //set the tail pointer to current
}

Set& Set::operator=(const Set& src)
{
    if (this != &src)
    {
        Set temp(src);
        swap(temp);
    } //temp will be deleted after if statement, runs destructor
    return *this;
}

bool Set::empty() const
{
    return (m_items == 0);
}

int Set::size() const
{
    return m_items;
}

bool Set::insert(const ItemType& value)
{
  if (contains(value)==true)
  {
      return false;
  }
    
    if (m_items == 0)
    {
        Node* n = new Node;
        n->data = value;
        n->prev = nullptr;
        n->next = nullptr;
        tail = n;
        head = n;
        m_items++;
        return true;
    }
    
    Node* n = new Node;
    n->data = value;
    n->prev = tail;
    n->next = nullptr;
    tail->next = n;
    tail = n;
    
    m_items++;
    return true;
    
}

bool Set::erase(const ItemType& value)
{
  if (contains(value) == false)
  {
      return false;
  }
    
    Node* n = head;
    for (;n != nullptr; n = n->next)
    {
        if (n->data == value) //find value to be deleted
            break;
    }
    
    if (n->prev != nullptr) //link value above to value below
        n->prev->next = n->next;
    else
        head = n->next; //if removing head, make the next node the new head
    if (n->next != nullptr) //link value below to value above (must do it both ways)
        n->next->prev = n->prev;
    else
        tail = n->prev; //if removing tail, make the previous node the new tail
    
    m_items--;
    delete n;
    return true;
}

bool Set::contains(const ItemType& value) const
{
    for (Node* n = head; n != nullptr; n = n->next)
    {
        if (n->data == value)
            return true;
    }
    return false;
}

bool Set::get(int i, ItemType& value) const
{
    if (i >= m_items || i < 0) //make sure i is in range
        return false;
    
    Set setcopy(*this); //making a copy of this set using copy constructor
    for (int j=0; j<i; j++) //delete the minimum value of the set i times
    {
        ItemType min = setcopy.head->data;
        for (Node* n = setcopy.head; n != nullptr; n = n->next)
        {
            min = (n->data < min) ? n->data : min;
        }
        setcopy.erase(min);
    }
    
    ItemType min = setcopy.head->data; //find minimum out of remaining items in set
    for (Node* p = setcopy.head; p != nullptr; p = p->next)
    {
        min = (p->data < min) ? p->data : min;
    }
    
    value = min; //min is now strictly greater than exactly i items in the set, so set to value
    return true;
}

void Set::swap(Set& other)
{
    int tempitems = m_items;
    m_items = other.m_items;
    other.m_items = tempitems;
    
    Node* temphead = head;
    head = other.head;
    other.head = temphead;
    
    Node* temptail = tail;
    tail = other.tail;
    other.tail = temptail;
}

void unite(const Set& s1, const Set& s2, Set& result)
{
    result = s1; //assigns values of s1 into result
    for (int i=0; i < s2.size(); i++) //iterate through s2 to add those values to result
    {
        ItemType insertThis; //variable to store item that is to be inserted
        s2.get(i,insertThis); //storing s2 item in insertThis for every iteration
        result.insert(insertThis); //insert each item into result
    }
}

void butNot(const Set& s1, const Set& s2, Set& result)
{
    if (&s1 == &s2) //checks if s1 and s2 contain the same values
    {
        Set emptySet; //create an empty set
        result = emptySet; //set result equal to the empty set
        return; //exit the function
    }
    //if s1 and s2 are different sets
    result = s1; //assigns values of s1 into result
    for (int i = 0; i < s2.size(); i++) //iterates through every node in s2
    {
        ItemType toErase; //creates temp variable to designate each value to erase
        s2.get(i, toErase); //assigns each value of s2 to that variable
        result.erase(toErase); //erases each of those values from result
    }
}
