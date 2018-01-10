#include <iostream>
using namespace std;

template <class T>
class spunky //this could handle any data-type
{
    public:
        spunky(T x)
        {
            cout << x << " is not a character !" << endl;
        }
};

template <>
class spunky<char> //this handles only char data-type, specializing in only one data-type
{
    public:
        spunky(char x)
        {
            cout << x << " is indeed a character !" << endl;
        }
};

int main()
{
    spunky<int> obj1(12);
    spunky<double> obj2(12.234);
    spunky<char> obj3('d');
    return 0;
}
