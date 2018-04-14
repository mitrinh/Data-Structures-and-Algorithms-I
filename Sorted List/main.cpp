//  Michael Trinh CS110C
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "SortedListHasA.h" // ADT sorted list operations

using namespace std;

void displayList(SortedListInterface<string>* listPtr)
{
	cout << "High Scores:" << endl << endl;
   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      cout << listPtr->getEntry(pos) << endl;
   } // end for
	cout << endl << endl;
}  // end displayList

void listOpsTester(SortedListInterface<string>* listPtr)
{
   string first = "999";
   string second = "888";
   string third = "777";
   string fourth = "666";
   string fifth = "555";
   string sixth = "111";
   
   listPtr->insertSorted(first);
   listPtr->insertSorted(second);
   listPtr->insertSorted(third);
   listPtr->insertSorted(fourth);
   listPtr->insertSorted(fifth);
   listPtr->insertSorted(sixth);

   displayList(listPtr);

   string myscore;
   cout << "Type your score (Type -1 to quit)" << endl;
  
   while (true)
   {
     cout << "Enter score:" << endl;
     getline(cin, myscore);
     if (myscore == "-1")
     {
	return;
     }
     listPtr->insertSorted(myscore);
     displayList(listPtr);
   }   
}   
int main()
{
   SortedListInterface<int>* intList = new SortedListHasA<int>();
   SortedListInterface<string>* listPtr = new SortedListHasA<string>();
   listOpsTester(listPtr);
   return 0;
}  // end main
