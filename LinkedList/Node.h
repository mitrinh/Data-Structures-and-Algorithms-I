//  Michael Trinh CS110C
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.h 
    Listing 4-1 */
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   Node<ItemType>* prev;
   
public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* prevPtr); 
   void setPrev(Node<ItemType>* prevPtr);
   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);
   Node<ItemType>* getPrev();
   ItemType getItem() const ;
   Node<ItemType>* getNext() const ;
}; // end Node

#endif
