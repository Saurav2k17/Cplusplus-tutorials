#include <iostream>
using namespace std;

template <class Saurav> //template allows to use any kind of data-type in our function implementation
                        //template allows building generic data-type
Saurav addCrap(Saurav a, Saurav b)
{
    return a+b;
}

int main()
{
    int x = 12, y = 23, z;
    z = addCrap(x, y); //can't have two different types of data-type
    cout << z;
    return 0;
}
