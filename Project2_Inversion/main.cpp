//========================================================
// Ritika, Max ,Allyson
// Jan 2023
// main.cpp
// This file uses two different methods to count the number 
// of inversions in a given array of size n where 1 <= n <= 50,000: 
// 1. Nested loops
// 2. A modified version of merge sort
// The output includes the number of inversion found with 
// each method (should be the same number). It also returns the 
// amount of time it took to complete each method.
// Additionally, there are several test cases at the end of 
// the program to make sure the code works in different 
// scenarios.
//========================================================

#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>

using namespace std;

int CountInversion(vector <int> &arr);
int MergeSortCount(vector <int> &arr, int left, int right);
int merge(vector <int> &arr, int left, int right, int mid);
void testCases();

int main ( int argc, char *argv[] ){
    int n;
    //using argv and argc to prompt the user to indicate (in the
    //command line) the size of the array 
    if ( argc > 1 )
        n = atoi(argv[1]);
    //default value of 10 if no value is written in the command line
    else
        n = 10;
    //making sure that the array size given in the command line is valid
    if (n < 1 || n > 50000){
        cout<< "Invalid Array Size !!" << endl;
        return 0;
    }

    vector <int> randArr;
    //randomly assigning values for each element in the array

    //need to use srand() becuase rand() on its own generates a 
    //psuedo-random array that will be the same every time we run the code
    srand(time(0));  //using the current time in seconds as a seed
    for (int i=0; i < n; i++){
        randArr.push_back(rand() % 10000);
    }
    if (n <= 20){
        for (auto i = randArr.begin(); i != randArr.end(); i++){
            cout << *i << " ";        
        }        
    }

    std::clock_t start, stop, start2, stop2 ;
    start = std::clock();

    // call function here
    int count1 = CountInversion(randArr);

    stop = std::clock();
    cout<< "\ncount1:       " << count1 << "        Time: " << (stop - start) / (double)(CLOCKS_PER_SEC / 1000)
    << " ms" << std::endl;


    start2 = std::clock();

    // call function here
    int count2 = MergeSortCount(randArr, 0, randArr.size()-1);
     
    stop2 = std::clock();
    cout<< "count2:       " << count2 << "        Time: " << (stop2 - start2) / (double)(CLOCKS_PER_SEC / 1000)
    << " ms" << std::endl;

    testCases(); //run test cases

    return 0;
}

//========================================================
// CountInversion
// Parameters:
// &arr: a reference parameter to an array of integers of 
// size n where 1 <= n <= 50,000
// Return value:
// This function returns the number of inversion found in 
// arr, the input array
//========================================================
int CountInversion(vector <int> &arr){
    int count=0;
    for (int i=0; i < (arr.size()-1); i++){
        int temp = 0;
        for (int j=i+1; j < arr.size(); j++){
            if (arr[i] > arr[j]){
                temp++;
            }
        }
        count = count +temp;
    }
    return count;
}

//========================================================
// MergeSortCount
// Parameters:
// &arr: a reference parameter to an array of integers of 
// size n where 1 <= n <= 50,000
// left: an integer that represents the first index in the 
// subarray 
// right: an integer that represents the last index in the 
// subarray
// Return value:
// This function uses recursion to count the number of 
// inversions in an array of size n. 
//========================================================
int MergeSortCount(vector <int> &arr, int left, int right){
    int mid,inversion = 0;
    if (left < right){
        mid = (left+right)/2;
        //using recursion to split the array into subarrays
        //calling merge to count number of inversions
        //will run recursively until it reaches base case (i.e., one elt in each subarray) 
        inversion += MergeSortCount(arr, left, mid);
        inversion += MergeSortCount(arr, mid+1, right);
        inversion += merge(arr, left, right, mid);        
    }
    return inversion;

}

//========================================================
// merge
// &arr: a reference parameter to an array of integers 
// (or subarray) of size n where 1 <= n <= 50,000
// left: an integer that represents the first index in the 
// subarray 
// right: an integer that represents the last index in the 
// subarray
// mid: an integer than represents the middle index in the 
// subarray
// Return value:
// This function rcreates two new subarrays and returns the 
// number of inversions found in them. This function is called 
// in the MergeSortCount function to count the total number
// of inversions in an array
//========================================================
int merge(vector <int> &arr, int left, int right, int mid){
    int inversion = 0;
    //Size of the sub-arrays
    int subArr1 = mid-left+1;
    int subArr2 = right- mid;

    //Create two new sub-arrays A[left: mid] and A[mid+1:right]
    int arrLeft[subArr1];
    int arrRight[subArr2];

    //copy elemnts into the sub-arrays 
    for ( int i =0; i < subArr1; i++){
        arrLeft[i] = arr[left+i];
    }
    for (int j =0; j < subArr2; j++){
        arrRight[j] = arr[(mid+1)+j];
    }

    //Create variables to maintain the current index of the sub-arrays:
    // arrLeft, arrRight and the main array(arr)
    //while transversing through the arrays

    int l = 0;      //pointing to current index of arrLeft sub-array
    int r = 0;      // arrRight sub-array
    int m = left;   //pointing to current index of main array

    //Comparing the elemnet in the sub-array and placing in the main arr 
    //until the end of any one sub-array 
    while( l < subArr1 && r < subArr2){
        if (arrLeft[l] <= arrRight[r]){
            arr[m] = arrLeft[l];
            l++;
        }
        else{
            arr[m] = arrRight[r];
            r++;
            inversion = inversion + (subArr1-l);
        }
        m++;
    }

    //If one sub-array is longer than the other then append all the remaining elements 
    //to main array(arr)
    while( l < subArr1){
        arr[m] = arrLeft[l];
        l++;
        m++;
    }

    while(r < subArr2){
        arr[m] = arrRight[r];
        r++;
        m++;
    }
    return inversion;
} 

//Test case function 
//========================================================
// testCases
// Parameters:
// none
// Return value:
// This function has no return value. It is used to test
// whether or not our algorithm works for specific cases
// (i.e., specific arrangments of integers in the array)
//========================================================
void testCases() {
    cout << "\nTEST CASES:";

	// Test case 1: Small array (size <= 20)
	cout << "\nTest Case 1: Small array (size <= 20)" << endl;
    cout << "arr1 = {8, 2, 5, 3, 9, 4}" << endl;
	vector <int> arr1;
    arr1.assign({8, 2, 5, 3, 9, 4});
	int count1_expected = 7;
	int count2_expected = 7;
	int count1_result = CountInversion(arr1);
	int count2_result = MergeSortCount(arr1, 0, arr1.size() - 1);
	assert(count1_result == count1_expected);
	assert(count2_result == count2_expected);
	cout << "Count1: " << count1_result << ", Count2: " << count2_result << endl;
	
	
	//Test case 2: Only 1 element in the array
	cout << "\nTest Case 2: Only 1 element in the array" << endl;
    cout << "arr2 = {5}" << endl;
    vector <int> arr2;
    arr2.assign({5});
	int count1_expected_one = 0;
	int count2_expected_one = 0;
	int count1_result_one = CountInversion(arr2);
	int count2_result_one = MergeSortCount(arr2,0, arr2.size() - 1);
	assert(count1_result_one == count1_expected_one);
	assert(count2_result_one == count2_expected_one);
	cout << "Count1: " << count1_result_one << ", Count2: " << count2_result_one << endl;
	
	//Test Case 3: Array with no inversion (presorted array)
	cout << "\nTest Case 3: Array with no inversion (sorted array)" << endl;
    cout << "arr3 = {1, 2, 3, 4, 5, 6}" << endl;
    vector <int> arr3;
    arr3.assign({1, 2, 3, 4, 5, 6});
	int count1_expected_sorted = 0;
	int count2_expected_sorted = 0;
	int count1_result_sorted = CountInversion(arr3);
	int count2_result_sorted = MergeSortCount(arr3, 0, arr3.size() - 1); 
	assert(count1_result_sorted == count1_expected_sorted);
	assert(count2_result_sorted == count2_expected_sorted);
	cout << "Count1: " << count1_result_sorted << ", Count2: " << count2_result_sorted << endl;
	
	//Test case 4: Array with all identical elements
	cout << "\nTest Case 4: Array with all identical elements" << endl;
    cout << "arr4 = {3, 3, 3, 3, 3, 3}" << endl;
    vector <int> arr4;
    arr4.assign({3, 3, 3, 3, 3, 3});
	int count1_expected_identical = 0;
	int count2_expected_identical = 0;
	int count1_result_identical = CountInversion(arr4);
	int count2_result_identical = MergeSortCount(arr4, 0, arr4.size() - 1);
	assert(count1_result_identical == count1_expected_identical);
	assert(count2_result_identical == count2_expected_identical);
	cout << "Count1: " << count1_result_identical << ", Count2: " << count2_result_identical << endl;
	
	//Test case 5: Sorted array followed by a single element that breaks the pattern
	cout << "\nTest Case 5: Sorted array followed by a single element that breaks the pattern" << endl;
    cout << "arr5 = {1, 2, 3, 4, 5, 6, 4}" << endl;
    vector <int> arr5;
    arr5.assign({1, 2, 3, 4, 5, 6, 4});
	int count1_expected_break = 2;
	int count2_expected_break = 2;
	int count1_result_break = CountInversion(arr5);
	int count2_result_break = MergeSortCount(arr5, 0, arr5.size() - 1);
	assert(count1_result_break == count1_expected_break);
	assert(count2_result_break == count2_expected_break);
	cout << "Count1: " << count1_result_break << ", Count2: " << count2_result_break << endl;

    //Test case 6: Empty array
    //After writing this test case, we realized that it is not really 
    //needed becuase n must always be larger than 1
    //we included it as comments just to show that we considered it

	//cout << "\nTest Case 6: Empty array" << endl;
	//vector <int> arr6;
	//int count1_expected_empty = 0;
	//int count2_expected_empty = 0;
	//int count1_result_empty = CountInversion(arr6);
	//int count2_result_empty = MergeSortCount(arr6, 0, arr6.size() - 1);
	//assert(count1_result_empty == count1_expected_empty);
	//assert(count2_result_empty == count2_expected_empty);
	//cout << "Count1: " << count1_result_empty << ", Count2: " << count2_result_empty << endl;
}