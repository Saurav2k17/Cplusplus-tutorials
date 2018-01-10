#include <iostream>
#include "Mother.h"
#include "Daughter.h"
using namespace std;

int main()
{
    Mother mom;
    mom.sayName();
    cout << endl;
    Daughter tina;
    tina.sayName(); //daughter class inherits the property of mother class
    return 0;
}
