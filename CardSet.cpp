//
//  CardSet.cpp
//  Homework 1
//
//  Created by Tina Fotouhi on 1/24/23.
//

#include "CardSet.h"
#include <iostream>
using namespace std;

CardSet::CardSet()
{
    
}

bool CardSet::add(ItemType cardNumber)
{
    return cardset.insert(cardNumber);
}

int CardSet::size() const
{
    return cardset.size();
}

void CardSet::print() const
{
    for (int i=0; i<cardset.size(); i++)
    {
        ItemType val;
        cardset.get(i,val);
        cout << val << endl;
    }
}
