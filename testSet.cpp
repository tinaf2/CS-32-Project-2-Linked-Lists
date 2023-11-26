//
//  testSet.cpp
//  Homework 1
//
//  Created by Tina Fotouhi on 1/23/23.
//


#include "Set.h"
 #include <string>
 #include <iostream>
 #include <cassert>
 using namespace std;

 void test()
 {
     Set ss; //creating empty set
     assert(ss.size()==0); //test size function on empty set
     assert(ss.empty()); //test empty function
     assert(!ss.erase("pita")); //check that erase fails on an empty set
     
     assert(ss.insert("roti")); //test insert on empty set
     assert(ss.size() == 1); //test size on function of size 1
     assert(!ss.empty()); //make sure empty doesn't work on function of size 1
     assert(ss.erase("roti") && (ss.size() == 0)); //check if erase works on size 1 function
     assert(ss.empty()); //make sure erase worked properly
     assert(!ss.erase("roti")); //make sure erase still fails on empty set
     
     assert(ss.insert("roti")); //test reinserting 1 item
     assert(ss.insert("pita")); //test insertion of 2nd item
     assert(ss.size() == 2); //test size function works properly on 2-item set
     assert(ss.contains("pita")); //test that contains function works
     ItemType x = "laobing";
    assert(ss.get(0, x)  &&  x == "pita"); //test that get works for empty set
     assert(ss.get(1, x)  &&  x == "roti"); //test that get works for 1-item set
     assert(!ss.insert("roti")); //make sure insert doesn't allow same item twice
     
     assert(ss.insert("croissant")); //test insertion of third item
     
     Set ss2(ss); //call copy constructor
     assert(ss2.contains("roti"));
     assert(ss2.contains("pita"));
     assert(ss2.contains("croissant")); //make sure all elements were copied into ss2
     
     assert(ss2.get(0,x) && x == "croissant"); //test if get works for object element 1
     assert(ss2.get(1,x) && x == "pita"); //test if get works for object element 2
     assert(ss2.get(2,x) && x == "roti"); //test if get works for object element 3
     assert(ss2.insert("sourdough")); //make sure insert works on object
     
     assert(!ss2.empty()); //test if empty works on object
     assert(ss2.erase("croissant")); //test if erase works on object
     assert(!ss.contains("sourdough")); //make sure ss and ss2 are not the same list
     assert(ss.contains("croissant")); //make sure ss and ss2 are not the same list
     
     Set ss3 = ss2; //call assignment operator
     assert(ss3.contains("pita"));
     assert(ss3.contains("roti"));
     assert(ss3.contains("sourdough")); //make sure elements of ss2 were copied into ss3
     
     assert(ss3.get(0,x) && x == "pita");
     assert(ss3.get(1,x) && x == "roti");
     assert(ss3.get(2,x) && x == "sourdough"); //make sure get works for all object elements
     
     assert(ss3.size() == 3); //test if size works on object
     assert(ss3.erase("sourdough") && !ss3.contains("sourdough")); //check erase on object
     assert(!ss.contains("sourdough")); //make sure ss3 and ss are not the same list
     
     Set result; //create empty set to store united values
     unite(ss2,ss,result); //test unite function
     assert(result.get(0,x) && x == "croissant");
     assert(result.get(1,x) && x == "pita");
     assert(result.get(2,x) && x == "roti");
     assert(result.get(3,x) && x == "sourdough"); //make sure unite stored all elements of ss and ss2 in result and that get still works
     
     Set res; //create empty set to store leftover value
     butNot(ss2, ss, res);
     assert(res.size() == 1); //make sure function only includes the different value
     assert(res.contains("sourdough")); //make sure function left the correct ss2 value
     assert(res.get(0,x) && x == "sourdough"); //make sure get still works
 }

 int main()
 {
     test();
     cout << "Passed all tests" << endl;
 }


