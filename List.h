//========================================================
// Ritika, Max, Allyson
// Jan 2024
// List.h
// This file contains the Doubly Linked List class declaration.  
//========================================================

#include <iostream>
#include <string>

using namespace std;

#ifndef LIST_H
#define LIST_H

#define DEFAULT_LIST_CAPACITY 10



template <class T> 
class List
{
private:
	// struct for Node for linked list
	struct Node
	{
		T	item;
		Node* next;
	};
	
	Node* head;		// Head pointer of the linked list

	// ADDED PRIVATE VARS
	int size; 			// Length of the linked list
	Node* tail;			// the pointer to the last node 
	Node* current;		//pointer to thr current node 
	
public:
			List		( void );
			List		( const List<T> &mylist );
		   ~List		( void );
void		prepend		( const T &item	);
void		append		( const T &item	);
T &			operator[]	( int index );
void		insert		( const T &item, int index );
void		remove		( int index );
List<T>		concat	( const List<T> &mylist ) const;
int 		search( const T &item ) const;
int			length		( void ) const;
bool		empty		( void ) const;

//not
void		clear		( void );
List<T>		operator=	( const List<T> &mylist );
string		to_string	( void ) const;	


friend ostream & operator<< ( ostream &os, List<T> &mylist )
{
	Node *ptr = mylist.head;
	while ( ptr != NULL )
	{
		if ( ptr->next != NULL )
			os << ptr->item << " ";
		else
			os << ptr->item;
		ptr = ptr->next;
	}
		
	return os;	
}


};

#include "List.cpp"

#endif


