#include <iostream>
using namespace std;

class stankFist {
    public:
        stankFist() {
           stinkyVar = 0;
        }
    private:
        int stinkyVar;
    friend void stinkysFriend(stankFist &sfo); //stinkysFriend function is here the friend of the class stankFist, so it could access all the members of this class.
};

void stinkysFriend(stankFist &sfo)
{
    sfo.stinkyVar = 99;
    cout << sfo.stinkyVar;
}


int main()
{
    stankFist bob;
    stinkysFriend(bob);
    return 0;
}
