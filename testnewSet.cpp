//
//  testnewSet.cpp
//  Homework 1
//
//  Created by Tina Fotouhi on 1/24/23.
//
/*
#include <stdio.h>
#include <iostream>
#include <cassert>
#include <string>
#include "newSet.h"
using namespace std;

int main()
{
    Set a(1000);   // a can hold at most 1000 distinct items
    Set b(5);      // b can hold at most 5 distinct items
    Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
    //ItemType v[6] = { "a", "b", "c", "d", "e", "f" };
    ItemType v[6] = { 1234, 2345, 3456, 4567, 5678, 6789};
    
    // No failures inserting 5 distinct items into b
    for (int k = 0; k < 5; k++)
        assert(b.insert(v[k]));
    
    // Failure if we try to insert a sixth distinct item into b
    assert(!b.insert(v[5]));
    
    // When two Sets' contents are swapped, their capacities are swapped
    // as well:
    a.swap(b);
    assert(!a.insert(v[5])  &&  b.insert(v[5]));
    
    cout << "Passed all tests" << endl;
}
*/
