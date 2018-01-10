#include <iostream>
using namespace std;

int main()                //exception handling is a way of catching programming errors
{
    int momsAge = 30;
    int sonsAge = 34;
    try
    {
        if(sonsAge > momsAge)
            throw 99; // if you change 99 (int type) to some other data-type, then the default catch would be called
    }
    catch(int x) //this function won't be called if nothing is thrown away
    {
        cout << "Son cannot be older than Mom: ERROR NUMBER " << x << endl;
    }

    catch(...) //default catch when type is not specified
    {
        cout << "Son cannot be older than Mom: ERROR NUMBER " << endl;
    }
}
