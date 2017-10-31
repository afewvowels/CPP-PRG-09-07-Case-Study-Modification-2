//
//  main.cpp
//  CPP-PRG-09-07-Case-Study-Modification-2
//
//  Created by Keith Smith on 10/31/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify Program 9-19 (the United Cause case study program) so the arrptr array is
//  sorted in descending order instead of ascending order.
#include <iostream>

using namespace std;

int *fillArray(int);
int *arrSelectSort(int *, int);
void showArray(const int [], int);
void showArrPtr(int *, int);

int main()
{
    //    const int NUM_DONATIONS = 15;
    //
    //    int donations[NUM_DONATIONS] = { 5, 100, 5, 25, 10,
    //                                     5, 25, 5, 5, 100,
    //                                     10, 15, 10, 5, 10 };
    //
    //    int *arrPtr[NUM_DONATIONS] = { nullptr, nullptr, nullptr, nullptr, nullptr,
    //                                   nullptr, nullptr, nullptr, nullptr, nullptr,
    //                                   nullptr, nullptr, nullptr, nullptr, nullptr };
    int NUM_DONATIONS;
    
    int *donations = nullptr;
    int *arrPtr = nullptr;
    
    cout << "Please enter how many donations were made: ";
    cin >> NUM_DONATIONS;
    
    donations = fillArray(NUM_DONATIONS);
    arrPtr = new int[NUM_DONATIONS];
    
    arrPtr = arrSelectSort(donations, NUM_DONATIONS);
    
    cout << "The donations, sorted in ascending order, are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);
    
    cout << "The donations, in their original order, are: \n";
    showArray(donations, NUM_DONATIONS);
    
    return 0;
}

int *fillArray(int size)
{
    int *intArr = nullptr;
    
    intArr = new int[size];
    
    for(int i = 0 ; i < size ; i++)
    {
        cout << "Please enter donation number " << (i + 1) << ": ";
        cin >> *(intArr + i);
    }
    
    return intArr;
}

int *arrSelectSort(int *arr, int size)
{
    int startScan, minIndex;
    int *minElem = nullptr;
    
    for (startScan = 0 ; startScan < (size - 1) ; startScan++)
    {
        minIndex = startScan;
        minElem = &arr[startScan];
        
        for (int index = startScan + 1 ; index < size ; index++)
        {
            if(arr[index] > *minElem)
            {
                minElem = &arr[index];
                minIndex = index;
            }
        }
        
        swap(arr[minIndex], arr[startScan]);
        //        arr[minIndex] = arr[startScan];
        //        arr[startScan] = minElem;
    }
    
    
    return arr;
}

void showArray(const int arr[], int size)
{
    for (int count = 0 ; count < size ; count++)
    {
        cout << arr[count] << " ";
    }
    cout << endl;
}

void showArrPtr(int *arr, int size)
{
    for (int count = 0 ; count < size ; count++)
    {
        cout << *(arr + count) << " ";
    }
    cout << endl;
}

void swap(int *intA, int *intB)
{
    int *intTemp = nullptr;
    
    intTemp = intA;
    intA = intB;
    intB = intTemp;
}

