/*

Why use static variables inside classes? One great example is to assign a unique ID to every instance of the class. Here’s an example of that.

Because s_idGenerator is shared by all Something objects, when a new Something object is created, the constructor grabs the current value out of s_idGenerator and then increments the value for the next object. This guarantees that each instantiated Something object receives a unique id (incremented in the order of creation). This can really help when debugging multiple items in an array, as it provides a way to tell multiple objects of the same class type apart!

*/


#include <iostream>

class Something
{
private:
    static int s_idGenerator;
    int m_id;
 
public:
    Something() { m_id = s_idGenerator++; } // grab the next value from the id generator
 
    int getID() const { return m_id; }
};
 
// Note that we're defining and initializing s_idGenerator even though it is declared as private above.
// This is okay since the definition isn't subject to access controls.
int Something::s_idGenerator = 1; // start our ID generator with value 1
 
int main()
{
    Something first;
    Something second;
    Something third;
 
    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';
    return 0;
}
