//========================================================
// Ritika, Max ,Allyson
// Jan 2023
// main.cpp
// This file ...
//========================================================

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int CountInversion(vector <int> &arr);
int MergeSortCount(vector <int> &arr, int left, int right);
int merge(vector <int> &arr, int left, int right, int mid);

int main ( int argc, char *argv[] ){
    int n;
    if ( argc > 1 )
        n = atoi(argv[1]);
    else
        n = 10;
    if (n < 1 || n > 50000){
        cout<< "Invalid Array Size !!" << endl;
        return 0;
    }

    vector <int> randArr;
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

    // call your function here
    int count1 = CountInversion(randArr);

    stop = std::clock();
    cout<< "\ncount1:       " << count1 << "        Time: " << (stop - start) / (double)(CLOCKS_PER_SEC / 1000)
    << " ms" << std::endl;


    start2 = std::clock();

    // call your function here
    int count2 = MergeSortCount(randArr, 0, randArr.size()-1);
     
    stop2 = std::clock();
    cout<< "count2:       " << count2 << "        Time: " << (stop2 - start2) / (double)(CLOCKS_PER_SEC / 1000)
    << " ms" << std::endl;

    return 0;
}

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

int MergeSortCount(vector <int> &arr, int left, int right){
    int mid,inversion = 0;
    if (left < right){
        mid = (left+right)/2;
        inversion += MergeSortCount(arr, left, mid);
        inversion += MergeSortCount(arr, mid+1, right);
        inversion += merge(arr, left, right, mid);        
    }
    return inversion;

}

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