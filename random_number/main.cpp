#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0)); //seeded random number, seeded with current time, this makes the random number truly random

    for(int x = 1; x < 25; x++) {
        cout << 1+(rand()%6) << endl;
    }
    cout << "You are done!" << endl;
    return 0;
}
