//  main.cpp
//  Practice
//
//  Created by Muhammad A Buttar on 9/14/18.
//  Copyright © 2018 AppleInc. All rights reserved.
//

#include <iostream>
using namespace std;

int linearSearch(const int [], int, int, int&);
int binarySearch(const int [], int , int, int&);

int main() {
    
    const int arraySize = 20;
    int result;
    int result2;
    int ncount1;
    int ncount2;
    
    int array1[arraySize] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int array2[arraySize] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    
    result = binarySearch(array1, arraySize, 5, ncount1);
    
    if (result == -1){
        cout << "The value was not found within the array" << "\n";
    }
    else{
        cout << "Number of binary search comparisons were " << ncount1 << "\n";
    }
    
    result2 = linearSearch(array2, arraySize, 5, ncount2);
   
    if (result2 == -1){
        cout << "The value was not found within the array" << "\n";
    }
    else{
        cout << "Number of linear search comparisons were " << ncount2 << "\n";
    }
    
    
    return 0;
}

int linearSearch(const int array[], int size, int value, int &counter)
{
    
    
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value){
            counter++;
            return i;
        }
        counter++;
    }
    
    return -1;
    
}

int binarySearch(const int array[], int size, int value, int &counter)
{
    int low = 0;
    int high = size-1;
    int mid;
  
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (value == array[mid])
        {
            counter++;
            return mid;
        }
        else if (value < array[mid])
        {
            counter++;
            high = mid - 1;
        }
        else
        {
             counter++;
            low = mid + 1;
        }
         counter++;
    }
    return -1;
}



