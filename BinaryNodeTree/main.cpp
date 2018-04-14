//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinaryNodeTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>

using namespace std;

void display(string& anItem)
{
   cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success)
{
   if (success)
      cout << "Done." << endl;
   else
      cout << " Entry not in tree." << endl;
}  // end check

int main()
{
   srand (time(NULL)); //creates a different random value each time the program is run by using current time

   BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();
   
   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");

   BinaryTreeInterface<string>* tree2 = new BinaryNodeTree<string>();

   tree2->add("10");
   tree2->add("20");
   tree2->add("30");
   tree2->add("40");
   
   cout<<"Tree 1 Inorder: \n";
   tree1->inorderTraverse(display);
       
   cout << "Tree 1 height: " << tree1->getHeight() << endl;
   cout << "Tree 1 number of nodes: " << tree1->getNumberOfNodes() << "\n" << endl;
   
   cout <<"Tree 2 Inorder: \n";
   tree2->inorderTraverse(display);
   
   cout << "Tree 2 height: " << tree2->getHeight() << endl;
   cout << "Tree 2 number of nodes: " << tree2->getNumberOfNodes() << endl;
 
   return 0;
}  // end main

/* SAMPLE OUTPUT
 Tree 1 Preorder: Should be 10 20 40 70 60 30 50 80
 Displaying item - 10
 Displaying item - 20
 Displaying item - 40
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Displaying item - 50
 Displaying item - 80
 Tree 1 Inorder: Should be 70 40 20 60 10 50 30 80
 Displaying item - 70
 Displaying item - 40
 Displaying item - 20
 Displaying item - 60
 Displaying item - 10
 Displaying item - 50
 Displaying item - 30
 Displaying item - 80
 Tree 1 Postorder: Should be 70 40 60 20 50 80 30 10
 Displaying item - 70
 Displaying item - 40
 Displaying item - 60
 Displaying item - 20
 Displaying item - 50
 Displaying item - 80
 Displaying item - 30
 Displaying item - 10
 Tree 1 height: 4
 Tree 1 number of nodes: 8
 Remove the leaf 80: Done.
 Try to remove the leaf 80 again:  Entry not in tree.
 Remove the leaf 50: Done.
 Tree 1 Preorder: Should be 10 20 40 70 60 30
 Displaying item - 10
 Displaying item - 20
 Displaying item - 40
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Tree 1 Inorder: Should be 70 40 20 60 10 30
 Displaying item - 70
 Displaying item - 40
 Displaying item - 20
 Displaying item - 60
 Displaying item - 10
 Displaying item - 30
 Tree 1 Postorder: Should be 70 40 60 20 30 10
 Displaying item - 70
 Displaying item - 40
 Displaying item - 60
 Displaying item - 20
 Displaying item - 30
 Displaying item - 10
 Tree 1 height: 4
 Tree 1 number of nodes: 6
 Remove the node 40 that has only a left child: Done.
 Tree 1 Preorder: Should be 10 20 70 60 30
 Displaying item - 10
 Displaying item - 20
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Tree 1 Inorder: Should be 70 20 60 10 30
 Displaying item - 70
 Displaying item - 20
 Displaying item - 60
 Displaying item - 10
 Displaying item - 30
 Tree 1 Postorder: Should be 70 60 20 30 10
 Displaying item - 70
 Displaying item - 60
 Displaying item - 20
 Displaying item - 30
 Displaying item - 10
 Tree 1 height: 3
 Tree 1 number of nodes: 5
 Remove the root 10 that has both left and right subtrees: Done.
 Tree 1 Preorder: Should be 20 60 70 30
 Displaying item - 20
 Displaying item - 60
 Displaying item - 70
 Displaying item - 30
 Tree 1 Inorder: Should be 70 60 20 30
 Displaying item - 70
 Displaying item - 60
 Displaying item - 20
 Displaying item - 30
 Tree 1 Postorder: Should be 70 60 30 20
 Displaying item - 70
 Displaying item - 60
 Displaying item - 30
 Displaying item - 20
 Tree 1 height: 3
 Tree 1 number of nodes: 4
 */
