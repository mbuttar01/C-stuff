//
//  main.cpp
//  Problem 2
//
//  Created by Muhammad A Buttar on 9/23/18.
//  Copyright © 2018 AppleInc. All rights reserved.
//

#include <iostream>
using namespace std;

void bubbleSort (int a[], int, int&);
void bubbleSort2 (int a[], int, int&);
void selectionSort (int a[], int, int&);
void insertionSort (int a[], int, int&);

int main() {
    
    int ncompare;
    int ncompare2;
    int ncompare3;
    int ncompare4;
    
    const int arraySize = 100;
    int array1[arraySize], array2[arraySize], array3[arraySize], array4[arraySize];
    
    for(int i = 0; i < arraySize; i++){
        array1[i] = rand()%100;
        array2[i] = array1[i];
        array3[i] = array1[i];
        array4[i] = array1[i];
    }

    
    for(int count = 0; count < arraySize; count++){
        cout << array1[count] << "\t" << array2[count] << "\t" << array3[count] << "\t" << array4[count] << "\n";
    }
    
    bubbleSort(array1, arraySize, ncompare);
    bubbleSort2(array2, arraySize, ncompare2);
    selectionSort(array3, arraySize, ncompare3);
    insertionSort(array4, arraySize, ncompare4);
    
    cout << "\n" << "Sorted array for bubble sort   : ";
    
    for(int count = 0; count < arraySize; count++){
        cout << array1[count] << " " ;
    }
    
    cout << "\n" << "Sorted array for bubble sort 2 : ";
    
    for(int count = 0; count < arraySize; count++){
        cout << array2[count] << " " ;
    }
    
    cout << "\n" << "Sorted array for selection sort : ";
    
    for(int count = 0; count < arraySize; count++){
        cout << array3[count] << " ";
    }
    cout << "\n" << "Sorted array for insertion sort : ";
    
    for(int count = 0; count < arraySize; count++){
        cout << array4[count] << " " ;
    }
    
    
    cout << "\n" << "\n" << "Number of comparisons for bubblesort: " << ncompare << "\n";
     cout << "Number of comparisons for bubblesort2: " << ncompare2 << "\n";
    cout << "Number of comparisons for selectionsort: " << ncompare3 << "\n";
    cout << "Number of comparisons for insertionsort: " << ncompare4 << "\n";
    
    return 0;
}

void bubbleSort(int a[], int Size, int &counter){
    
    int temp;
    bool swap = true;
    
    while (swap)
    {
        swap = false;
        for (int i = 0; i < Size - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                //swap
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
                
            }
            counter++;
        }
        
    }
    
}

void bubbleSort2(int a[], int Size, int &counter){
    
    int temp;
    bool swap = true;
    int j=0;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < Size - 1 - j; i++)  // j because the smallest value is placed in the first element after each iteration and soforth
        {
            if (a[i] > a[i + 1])
            {
                //swap
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swap = true;
            }
            
            counter++;
        }
        j++;
    }
    
}

void selectionSort(int a[], int size, int &counter)
{
    int min; // value
    int minIndex; // index
    
    for (int j = 0; j <= size - 2; j++)      // j = 0
    {
        min = a[j];
        minIndex = j;
        for (int i = j + 1; i < size; i++) // i = 1 through 9
        {
            if (a[i] < min)
            {
                min = a[i];
                minIndex = i;
            }
             counter++;
        }
        a[minIndex] = a[j];
        a[j] = min;
      
    }
    
}

void insertionSort(int a[], int size, int &counter)
{
    int key; // new card
    int j;
    for (int i = 1; i < size; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
             counter++;
        }
       
        a[j + 1] = key;
    }
}
