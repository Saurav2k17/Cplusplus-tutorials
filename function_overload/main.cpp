#include <iostream>

using namespace std;

void printNumber(int x) {
    cout << "I am printing an integer " << x << endl;
}

void printNumber(float x) {
    cout << "I am printing a float number " << x << endl;
}

int main()
{
    int a = 12;
    float b = 23.34;
    printNumber(a);
    printNumber(b);
    return 0;
}
