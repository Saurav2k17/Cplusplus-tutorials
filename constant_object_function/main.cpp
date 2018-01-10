#include <iostream>
#include "Sally.h"
using namespace std;

int main()
{
    Sally salObj;
    salObj.printShit();
    const Sally constObj;
    constObj.printShit2(); //constant object can only call constant function
    return 0;
}
