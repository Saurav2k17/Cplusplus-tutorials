#include <iostream>
#include "Sally.h"
using namespace std;

int main()
{
    Sally a(23);
    Sally b(34);
    //Sally c;
    //c = a + b;
    cout << (a + b).num << endl;
    return 0;
}
