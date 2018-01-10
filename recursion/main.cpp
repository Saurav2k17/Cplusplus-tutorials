#include <iostream>

using namespace std;

int factorial(int x) {
    if(x == 1)
        return 1;
    else
        return x*factorial(x-1);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    return 0;
}
