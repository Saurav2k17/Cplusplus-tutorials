#include "Sally.h"
#include <iostream>

using namespace std;

Sally::Sally(int a, int b)
:regVar(a), constVar(b) //member variable initialization
{

}

void Sally::print()
{
    cout << "The regular variable is " << regVar << " and the constant variable is " << constVar << endl;
}
