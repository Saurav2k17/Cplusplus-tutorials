#include "Sally.h"
#include <iostream>
using namespace std;


Sally::Sally()
{
    cout << "I am in the constructor." << endl;
}

Sally::~Sally()
{
    cout << "I am in the destructor." << endl;
}

void Sally::printCrap() {
    cout << "did someone say steak?" << endl;
}
