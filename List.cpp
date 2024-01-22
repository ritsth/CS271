#include "List.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;


//=================================================
// default constructor
// PARAMETERS: none
// Creates a List object/ List with no elements
//=================================================
template <class T>
List<T>::List(void){
    head = NULL;
	tail = NULL;
	current = NULL;
}

//=================================================
// parameterized/copy constructor
// PARAMETERS: mylist
// paramas type: constant reference params of List object 
//=================================================
template <class T>
List<T>::List( const List<T> &mylist ){
	// Creating two pointer to keep track of the item to copy
	Node* from;
	Node* to;

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
        to = to->next;
        to->item = from->item;

		// And changing from to next element in the linked list
        from = from->next;
    }

	// Asigning tail to last element and pointer the last pointer next to null 
	// indicating the end of the linked list
    to->next = NULL;
    tail = to;

}


//=================================================
// destructor
// PARAMETERS: none
// Deletes the dynamically allocated memory to prevent memory leaks
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
// PARAMETERS: item
// paramas type: constant reference params of template type variable
// This method allows you to add an item to the front of the list.
//=================================================
template <class T>
void List<T>::prepend( const T &item	) {



}

//=================================================
// append This method allows you to add an item to the front of the list.
// PARAMETERS: item
// paramas type: constant reference params of template type variable
// This method allows you to add an item to the end of the list.
//=================================================
template <class T>
void List<T>::append( const T &item	) {
	// Creating a dynamic data / node linked list
	Node* newNodeptr = new Node;
    newNodeptr->item = item;
    newNodeptr->next = NULL; 
    
	// If the list is empty
    if (head == NULL){
        head = newNodeptr;        
    }
	// If the list is not empty then making it next item on the list  
    else{
        tail->next = newNodeptr;
    }

	// Linking the item to the end of the linked list
    tail = newNodeptr;
}


//=================================================
// insert
// PARAMETERS: item and index
// paramas type: constant reference params of template type variable and integer 
// This method allows you to add an item the specified location (indices start at position 0). 
// Else throw out of range exception.
//=================================================
template <class T>
void List<T>::insert( const T &item, int index ) {
	Node* prev;  // Pointer to the previous item 
	int counter=0;

	// Initializing to the first item in the list
	current = head;
	prev = head;

	// Creating a new node to insert the item
	Node* newNodeptr = new Node;
	newNodeptr->item = item;

	if (head == NULL){
		append(item);
		return;
	}
	if (index == 0){
		newNodeptr->next = head; 
		head= newNodeptr;
		return;
	}

	// Looping throught the list until the node with the index is found and checking the current to check 
	// there is items in the list
	while(current != NULL && counter < index){
		prev = current;
		current = current->next;	
		counter ++;

	}		

	// Changing the next node of previous node to the new node with the inserted item and pointing
	// the next of the new node to the current node
	newNodeptr->next = current; 			
	prev->next= newNodeptr;
	
}

//=================================================
// remove
// PARAMETERS: index
// paramas type: integer 
// Removes the item in the linked list in the given index
//=================================================
template <class T>
void List<T>::remove( int index ) {
	Node* prev;  // Pointer to the previous item 
	int counter = 0;
	current = head;
	
	while(current != NULL && counter < index){
		prev = current;
		current = current->next;	
		counter ++;
	}

	// Change the previous node next pointer to next pointer of the current node which is to be removed 		
	prev->next = current->next;

}

//=================================================
// search
// PARAMETERS: item 
// This method finds the first instance of a specified item in the list.
//=================================================
template <class T>
int List<T>::search( const T &item ) const{



}

//=================================================
// length
// PARAMETERS: None
// This method returns the number of items in the list.
//=================================================
template <class T>
int List<T>::length( void ) const {
	int count=0;
	Node* temp;
	temp = head;

	// Loop through every item in the list and increase the counter
	while(temp != NULL){
		count++;
		temp = temp->next;
	}

	return count;
}

//=================================================
// empty
// PARAMETERS: None
// RETURN VALUE: returns a bool value 
// This method returns true if the list is empty, false otherwise.
//=================================================
template <class T>
bool List<T>::empty	( void ) const {
	return length() == 0;
}

//=================================================
// concat
// PARAMETERS: mylist
// paramas type: constant reference params of List object
// RETURN VALUE: returns a List class object
// This method concatenates two existing lists to return the newly created list.
//=================================================
template <class T>
List<T> List<T>::concat( const List<T> &mylist ) const {
	// Creating list obj using copy constructor and passing this class list
	List<T> list(*this);

	Node* temp;
	temp = mylist.head;

	while( temp != NULL){
		list.append(temp->item);
		temp = temp->next;
	}

	return list;

}







//Extras


//=================================================
// = operator overloading
// PARAMETERS: mylist
// paramas type: constant reference params of List object
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

//=================================================
// to_string
// PARAMETERS: none
// RETURN VALUE: linked list as string
// a string containing all the items in the list.
//=================================================
template <class T>
string List<T>::to_string( void ) const {
	stringstream stream;
	current = head; 

	if (length() == 0){
		stream << 0;
	}
	else{
		while (current != NULL)
		{
			stream << current->item << " ";
			current = current->next;
		}
	}
	return stream.str();
}

//=================================================
// clear
// PARAMETERS: None
// Removes all the items from the linked list
//=================================================
template <class T>
void List<T>::clear( void ) {
	// pointing the head pointer to null 
	head = NULL;
}
