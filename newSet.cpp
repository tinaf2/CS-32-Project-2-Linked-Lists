//
//  newSet.cpp
//  Homework 1
//
//  Created by Tina Fotouhi on 1/24/23.
//

#include "newSet.h"
using namespace std;

Set::Set(int arrmax)
{
    if (arrmax < 0)
        exit(-1);
    arrlen = 0;
    maxsize = arrmax;
    itemlist = new ItemType[arrmax];
}

Set::Set(const Set &other)
{
    maxsize = other.maxsize;
    arrlen = other.arrlen;
    
    itemlist = new ItemType[maxsize];
    
    for (int i=0; i<maxsize; i++)
    {
        itemlist[i] = other.itemlist[i];
    }
}

Set &Set::operator=(const Set &src)
{
    if (&src == this)
        return *this;
    Set temp(src);
    this->swap(temp);
    return *this;
}

Set::~Set()
{
    delete [] itemlist;
}

bool Set::empty() const
{
  if (arrlen == 0)
    return true;
  else
    return false;
}

int Set::size() const
{
    return arrlen;
}

bool Set::insert(const ItemType& value)
{
  if (arrlen >= maxsize)
    return false;
    
if (arrlen == 0)
    {
        arrlen = 1;
        itemlist[0] = value;
        return true;
    }

  for (int i=0; i<arrlen; i++)
    {
      if (itemlist[i] == value)
        return false;
    }
  
  for (int i=0; i<arrlen; i++)
    {
      if (itemlist[i] > value)
        {
          for (int j = arrlen; j > i; j--) //move everything after i one stepover and insert value after position i -- would be before i if j>=i bc i would move too
            {
                  itemlist[j] = itemlist[j - 1];
            }
            itemlist[i] = value;
            arrlen++;
            return true;
            }
    }
    return false;
}

bool Set::erase(const ItemType& value)
{
  for (int i=0; i<arrlen; i++)
    {
      if (itemlist[i] == value)
      {
        for (int j=arrlen; j < arrlen-1; j++)
          {
            itemlist[j] = itemlist[j+1];
          }
        arrlen--;
        return true;
      }
    }
  return false;
}

bool Set::contains(const ItemType& value) const
{
  for (int i=0; i<arrlen; i++)
    {
      if (itemlist[i] == value)
        return true;
    }
  return false;
}

bool Set::get(int i, ItemType& value) const
{
  if (i<0 || i>=arrlen)
    return false;
  else
    value = itemlist[i];
      return true;
}

void Set::swap(Set &other)
{
    int tempmax = other.maxsize;
    other.maxsize = this->maxsize;
    this->maxsize = tempmax;
    
    int templen = other.arrlen;
    other.arrlen = this->arrlen;
    this->arrlen = templen;
    
    ItemType *temp = other.itemlist;
    other.itemlist = this->itemlist;
    this->itemlist = temp;
}
