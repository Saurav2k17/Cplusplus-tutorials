#include <iostream>
#include "Birthday.h"
#include "People.h"
using namespace std;

int main()
{
    Birthday birthObj(10, 10, 1988);
    People sauravSahu("Saurav The King", birthObj);
    sauravSahu.printInfo();
    return 0;
}
