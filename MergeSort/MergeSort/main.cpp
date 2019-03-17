#include <iostream>
using namespace std;

void mergeSort(int a[], int low, int high);
void merge(int a[], int leftLow, int leftHigh, int rightLow, int rightHigh);

int main()
{
    int list[5] = {5, 1, 3, 2, 4};
    mergeSort(list, 0, 4);
    
    for (int i = 0; i < 5; i++)
        cout << list[i] << endl;
    
    system("pause");
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    
    if (low < high) // base case
    {
        mid = (high + low) / 2; // divide
        mergeSort(a, low, mid); // conquer the left
        mergeSort(a, mid + 1, high); // conquer the right
        merge(a, low, mid, mid + 1, high); // merge
    }
}

void merge(int a[], int leftLow, int leftHigh, int rightLow, int rightHigh)
{
    int *temp = new int[rightHigh - leftLow + 1];
    int leftIndex = leftLow;
    int rightIndex = rightLow;
    int tempIndex = 0;
    
    while (leftIndex <= leftHigh && rightIndex <= rightHigh)
    {
        if (a[leftIndex] < a[rightIndex])
        {
            temp[tempIndex] = a[leftIndex];
            leftIndex++;
        }
        else
        {
            temp[tempIndex] = a[rightIndex];
            rightIndex++;
        }
        tempIndex++;
    }
    while (leftIndex <= leftHigh) // remaining values on the left
    {
        temp[tempIndex] = a[leftIndex];
        leftIndex++;
        tempIndex++;
    }
    while (rightIndex <= rightHigh) // remaining values on the right
    {
        temp[tempIndex] = a[rightIndex];
        rightIndex++;
        tempIndex++;
    }
    tempIndex = 0;
    for (int i = leftLow; i <= rightHigh; i++)
    {
        a[i] = temp[tempIndex];
        tempIndex++;
    }
    delete[] temp;
}
