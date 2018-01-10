#include "Sally.h"
#include <iostream>

using namespace std;

Sally::Sally()
{
    cout << "I am in the constructor" << endl;
}

void Sally::printShit()
{
    cout << "i am in the regular function" << endl;
}

void Sally::printShit2() const
{
    cout << "i am in the constant function" << endl;
}
