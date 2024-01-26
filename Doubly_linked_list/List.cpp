//========================================================
// Ritika, Max, Allyson
// Jan 2024
// List.cpp
// This file contains all the method implementation in List class
//========================================================
#include "List.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


//=================================================
// default constructor
// PARAMETERS: none
// Creates a List object/ List with no elements (all
// pointers are NULL, they point to nothing)
//=================================================
template <class T>
List<T>::List(void){
    head = NULL;
	tail = NULL;
	current = NULL; 
	size = 0;
}

//=================================================
// parameterized/copy constructor
// PARAMETERS: 
// &mylist: a reference parameter to a pre-existing 
// linked list
// Creates a new linked list that is an exact copy 
// of a pre-existing linked list
//=================================================
template <class T>
List<T>::List( const List<T> &mylist ){
	// Creating two pointer to keep track of the item to copy
	Node* from;
	Node* to;

	Node* temp= NULL;

	// If the mylist(the list to copy) is empty then head pointer will be null
	// and do nothing
	if (mylist.head == NULL){
		head = NULL;
		return;
	}

	// Assigning the mylist first element pointer to the from pointer
	from = mylist.head;

	// Creating new dynamic linked list / a new node
	head = new Node;

	// Copying mylist first item to the list
	head->item = from->item;

	// Assigning the created list to `to` pointer
	to = head;

	// Reasigning from to next element in the mylist
	from = from->next;

	// Repeating until the last node/element points to null (until the list is empty)
	while(from != NULL){
		// Creating dynamic data for each item and copying element from the mylist
        to->next = new Node;
		to->previous = temp;
		temp = to;
        to = to->next;
        to->item = from->item;

		// And changing from to next element in the linked list
        from = from->next;
    }

	// Asigning tail to last element and pointer the last pointer next to null 
	// indicating the end of the linked list
    to->next = NULL;
    tail = to;

	size = mylist.size;

}


//=================================================
// destructor
// PARAMETERS: 
// none
// Deletes the dynamically allocated memory to prevent memory leaks
// In other words, it deletes all nodes from a linked list
//=================================================
template <class T>
List<T>::~List( void ){
	// Creating a temporary pointer
	Node* temp;
	current = head; 	// Setting the current pointer to the first element in the list

	while (current != NULL)
	{
		temp = current;
		
		// Changing current pointer to next element
		current = current->next;
		delete temp;
	}

}

//=================================================
// prepend 
// PARAMETERS: 
// &item: constant reference params of template type variable
// It represents an element to append to the end of the list.
// This method allows you to add an item to the front of the list.
//=================================================
template <class T>
void List<T>::prepend( const T &item	) {
	// Creating a node
	Node* newNodeptr = new Node;
    newNodeptr->item = item;
    newNodeptr->next = NULL; 
	newNodeptr->previous = NULL; 

	// If the list is empty
    if (head == NULL){
        head = newNodeptr; 
		tail = head;       
    }
	// otherwise place the node at the start (head) of the list
    else{
      	Node* temp;
		temp = head;

		head = newNodeptr; 
		head->next = temp; 
		temp->previous = head;
    }

	size++;

}

//=================================================
// append This method allows you to add an item to the front of the list.
// PARAMETERS: 
// &item: constant reference params of template type variable.
// It represents an element to append to the end of the list.
// This method allows you to add an item to the end of the list.
//=================================================
template <class T>
void List<T>::append( const T &item	) {
	// Creating a dynamic data / node linked list
	Node* newNodeptr = new Node;
    newNodeptr->item = item;
    newNodeptr->next = NULL; 
	newNodeptr->previous = NULL; 
    
	// If the list is empty
    if (head == NULL){
        head = newNodeptr;        
    }
	// If the list is not empty then making it next item on the list  
    else{
        tail->next = newNodeptr;
		newNodeptr->previous= tail;
    }

	// Linking the item to the end of the linked list
    tail = newNodeptr;

	size++;
}


//=================================================
// insert
// PARAMETERS: 
// &item: constant reference params of template type variable.
// It is an element to insert at a specific index
// index: integer. It is the index at which we want 
// to insert the new item.
// This method allows you to add an item the specified location (indices start at position 0). 
// Else throw out of range exception.
//=================================================
template <class T>
void List<T>::insert( const T &item, int index ) {
	//index less than 0 or exceed length of the list
	if (index < 0 || index > length()){
		throw out_of_range("List<T>::insert( const T &item, int index ) : index is out of range");
	}
	int counter=0;

	// Initializing to the first item in the list
	current = head;

	// Creating a new node to insert the item
	Node* newNodeptr = new Node;
	newNodeptr->item = item;

	//if the list is empty 
	if (head == NULL || index == length()){
		append(item);
		return;
	}
	//if the index is 0, insert item at the head
	if (index == 0){
		head -> previous = newNodeptr;
		newNodeptr->next = head; 
		newNodeptr->previous = NULL; 
		head = newNodeptr;
		return;
	}

	// Looping throught the list until the node with the index is found and checking the current to check 
	// there is items in the list
	while(current != NULL && counter < index){
		current = current->next;	
		counter ++;

	}		

	// Changing the next node of previous node to the new node with the inserted item and pointing
	// the next of the new node to the current node
	newNodeptr->next = current; 
	newNodeptr->previous = current->previous;
	current->previous->next= newNodeptr;
	//check
	size++;
}

//=================================================
// remove
// PARAMETERS: 
// index: integer. The index at which we want to 
// delete the item
// Removes the item in the linked list in the given index
//=================================================
template <class T>
void List<T>::remove( int index ) {
	//index less than 0 or exceed length of the list
	if (index < 0 || index > length()){
		throw out_of_range("List<T>::insert( const T &item, int index ) : index is out of range");
	}

	Node* temp;
	int counter = 0;
	
	//if the item is at index 0 (the head)
    if (index == 0){
		temp = head;
        head = head -> next;
		head->previous= NULL;
        delete temp;
    }
	else{
		Node* to_remove = head;
		while(index > 1){
			index--;
			to_remove = to_remove->next;
		}
		temp= to_remove->next;
		to_remove->next = temp->next;
		if (temp->next != NULL) {
			temp->next->previous = to_remove;
        }
		
		delete temp;

	}

	size--;

}

//=================================================
// search
// PARAMETERS: 
// &item: Reference parameter to the element being searched for
// This method finds the first instance of a specified item in the list.
// returns -1 if item is not in the list
//=================================================
template <class T>
int List<T>::search( const T &item ) const{
	Node* temp;
	temp = head;
	int counter=0;

	while( temp != NULL){
		if (temp->item == item){
			return counter;
		}
		temp = temp->next;
		counter++;
	}

	return -1;

}

//=================================================
// length
// PARAMETERS: 
// None
// This method returns the number of items in the list.
//=================================================
template <class T>
int List<T>::length( void ) const {
	return size;
}

//=================================================
// empty
// PARAMETERS: None
// RETURN VALUE: returns a bool value 
// This method returns true if the list is empty, false otherwise.
//=================================================
template <class T>
bool List<T>::empty	( void ) const {
	return size == 0;
}

//=================================================
// concat
// PARAMETERS: 
// &mylist: constant reference params of List object. 
// This is the list we want to concatenate to the end
// of the first list.
// RETURN VALUE: returns a List class object
// This method concatenates two existing lists to return the newly created list.
//=================================================
template <class T>
List<T> List<T>::concat( const List<T> &mylist ) const {

	// Creating list obj using copy constructor and passing this class list
	List<T> listNew(*this);

	Node* temp;
	temp = mylist.head;

	while( temp != NULL){
		listNew.append(temp->item);
		temp = temp->next;
	}

	return listNew;

}

//=================================================
// [] operator overloading
// PARAMETERS: 
// index: integer, the index in the linked list at which we want
// to the know the value of the item
// RETURN VALUE: returns the item in the linked list at the index
//=================================================
template <class T>
T& List<T>::operator[]	( int index ) {
	//index less than 0 or exceed legth of the list
	if (index < 0 || index > (length()-1)){
		throw out_of_range("List<T>::insert( const T &item, int index ) : index is out of range");
	}
	int counter = 0;
	current = head;
	
	// Transversing throught the list until the node with index is found
	while(current != NULL && counter < index){
		current = current->next;	
		counter ++;

	}

	// Returning the item in the node with the index
	return current->item;
}

//=================================================
// = operator overloading
// PARAMETERS: 
// &mylist: constant reference params of List object.
// This is the list that we want to set another list 
// equal to.
// RETURN VALUE:
// a linked list that is an exact copy of the list we
// want to set it equal to.
//=================================================
template <class T>
List<T> List<T>::operator=( const List<T> &mylist ){
	// Pointer to point to the the head node of the mylist which is to be copied
	Node* temp;
	temp = mylist.head;

	// Looping throught mylist and appending each item to this list 
	while( temp != NULL){
		//appending to the current
		append(temp->item);
		temp = temp->next;
	}

	//the keyword "this" is a pointer that refers to the current object of the class.
	// returning the current list of the List class
	return *this;
}