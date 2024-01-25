//========================================================
// Ritika, Max ,Allyson
// Jan 2023
// main.cpp
// This file tests the List class.
//========================================================

#include <iostream>
#include "List.h"

using namespace std;

int main (void)
{
	try{
		List<int> list1;
		cout << "list1 = " << list1 << endl;
		list1.prepend(-10);
		cout << "list1 = " << list1 << endl;

		//Adding elements to the list1
		for ( int i = 1; i <= 10; i++ )
			list1.append(i);

		cout << "list1 = " << list1 << endl;
		cout << "\nlist1.prepend(1000);\n";
		list1.prepend(1000);
		cout << "list1 = " << list1 << endl;

		//Using copy constructor
		List<int> list2(list1);
		cout << "list2 = " << list2 << endl;

	    cout << "length list1 =  " << list1.length() << endl;
		cout << "\nlist1.insert(50,10);\nlist1.insert(0,0)\nlist1.insert(50,-12);\nlist1.insert(50,12);\n";

		try{
			list1.insert(50,10);
			list1.insert(50,5);
			list1.insert(0,0);
			list1.insert(50,12);
			list1.insert(50,-12);
			
		}
		catch(...){
			cout << "List<T>::insert( const T &item, int index ) : index is out of range" << endl;
		}

		cout << "list1 = " << list1 << endl;
		cout << "list2 = " << list2 << endl;

		cout << "list1.remove(1);\n"; 
		list1.remove(0);
		list1.remove(1);
		list1.remove(6);
		list1.remove(10);
		cout << "list2 = " << list2 << endl;
		cout << "list1 = " << list1 << endl;

		cout << "\nlist3 new empty\n";
		List<int> list3;
		cout << "list3 size = " << list3.length() << endl;
		if ( list3.empty() )
			cout << "list3 empty\n";
		else
			cout << "list3 not empty\n";

		cout << "\nlist3 = list1.concat(list2)\n";
		list3 = list1.concat(list2);
		cout << "list3 = " << list3 << endl;

		cout << "list2 = " << list2 << endl;
		cout << "list1 = " << list1 << endl;
		
		cout << "list3 size = " << list3.length() << endl;
		if ( list3.empty() )
			cout << "list3 is empty\n";
		else
			cout << "list3 is not empty\n";

		cout << "list1.search(-10), index:" << list1.search(-10) << endl;
		cout << "list2.search(10), index:" << list2.search(10) << endl;	
		cout << "list3.search(1000), index:" << list3.search(1000) << endl;	
		cout << "list3.search(-1000), index:" << list3.search(-1000) << endl;
		cout << "list2.search(9000), index:" << list2.search(9000) << endl;		

		cout << "list1 length= " << list1.length() << endl;

		try{
			list1.remove(1);
			list1.remove(2);
			list1.remove(3);
			list1.remove(4);
		}
		catch(...){
			cout << "Error removing..." << endl;
		}

		cout << "list1 length= " << list1.length() << endl;
		cout << "list1 = " << list1 << endl;
		if ( list1.empty() )
			cout << "list1 is empty\n";
		else
			cout << "list1 is not empty\n";
				

		cout << "list2[2] = 100;\n";
		list2[2] = 100;
		list1[5] = -1000;
		cout << "list1 = " << list1 << endl;
		cout << "list2 = " << list2 << endl;

		cout << "list2 = " << list2 << endl;
		cout << "list2[1] = " << list2[1] << endl;
		cout << "list2[0] = " << list2[0] << endl;
		cout << "list2[10] = " << list2[10] << endl;
		cout << "list2[-10] = " << list2[-10] << endl;	
	}
	catch(...){
		cout << "List<T>::insert( const T &item, int index ) : index is out of range" << endl;
	}
	return 0;
}

