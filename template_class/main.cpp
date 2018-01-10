#include <iostream>
using namespace std;

template <class T>

class Bucky
{
    T first, second;
    public:
        Bucky(T a, T b)
        {
            first = a;
            second = b;
        }
        T bigger();
};

template <class T>  //to define member function of a class outside of the class, you again need to declare this template
T Bucky<T>::bigger() //Bucky<T> signifies function template parameter is again T
{
    return(first>second?first:second);
}

int main()
{
    Bucky<int> bo(93, 45);  //Bucky<int> signifies int parameters being passed
    cout << bo.bigger();
    return 0;
}
