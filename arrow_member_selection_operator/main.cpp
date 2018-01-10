#include <iostream>
using namespace std;
#include "Sally.h"

int main()
{
    Sally sallyObject;
    Sally *sallyPointer = &sallyObject;
    sallyObject.printCrap();   //accessing member function through object
    sallyPointer->printCrap(); //accessing member function through pointer object
}
