#include <iostream>
using namespace std;

template <class First, class Second> //template allows to use any kind of data-type in our function implementation
                                     //template allows building generic data-type
First smaller(First a, Second b)
{
    return (a<b?a:b);
}

int main()
{
    int x = 12;
    double y = 3.1;
    cout << smaller(x, y); //can have two different types of data-type

    return 0;
}
