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
		Node* next;			//pointer to the next node 
		Node* previous;			//pointer to the previous node 
	};
	
	int size;		// size of the linked list
	Node* head;		// Head pointer of the linked list
	Node* tail;			// the pointer to the last node 
	Node* current;		//pointer to the current node 
	
	
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
List<T>		operator=	( const List<T> &mylist );

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


