#include <iostream>
using namespace std;

void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void swap(int &a, int &b);

int main()
{
 return 0;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(a, low, high); // divide
        quickSort(a, low, pivotIndex - 1); // conquere the left
        quickSort(a, pivotIndex + 1, high); // conquere the right
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int pivotIndex = low;
    
    for (int i = low + 1; i <= high; i++)
    {
        if (a[i] < pivot)
        {
            pivotIndex++;
            swap(a[i], a[pivotIndex]);
        }
    }
    swap(a[low], a[pivotIndex]);
    return pivotIndex;
}

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}
