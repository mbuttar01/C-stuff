#include "DynamicStack.h"
# include <iostream>
using namespace std;


int main()
{
    DynIntStack S;
    int result = 0;
    
    S.push(3);
    S.push(1);
    S.push(5);
    S.push(2);
    S.push(8);
    S.push(9);
    
    result = S.getMin();
    
    cout << result << endl;
    
    return 0;
}

