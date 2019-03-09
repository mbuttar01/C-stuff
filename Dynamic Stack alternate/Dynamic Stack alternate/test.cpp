#include <iostream>
#include "DynStack.h"
using namespace std;

int main()
{
    int num = 0;

    DynStack<int> S;
    
    S.push(5);
    
    S.pop(num);
    
    cout << num << "\n";
    
    
   
    return 0;
}
