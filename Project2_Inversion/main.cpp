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
int MergeSortCount(vector <int> &arr);

int main ( int argc, char *argv[] ){
    int n;
    if ( argc > 1 )
        n = atoi(argv[1]);
    else
        n = 10;
    if (n < 1 || n > 50000){
        cout<< "Invalid";
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
    int count2 = MergeSortCount(randArr);

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

int MergeSortCount(vector <int> &arr){
    
    return 0;
}