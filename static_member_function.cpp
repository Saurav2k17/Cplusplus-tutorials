/*

Static member functions have two interesting quirks worth noting. First, because static member functions are not attached to an object, they have no this pointer! This makes sense when you think about it -- the this pointer always points to the object that the member function is working on. Static member functions do not work on an object, so the this pointer is not needed.

Second, static member functions can directly access other static members (variables or functions), but not non-static members. This is because non-static members must belong to a class object, and static member functions have no class object to work with!

*/

#include <iostream>

class IDGenerator
{
private:
    static int s_nextID; // Here's the declaration for a static member
 
public:
     static int getNextID(); // Here's the declaration for a static function
};
 
// Here's the definition of the static member outside the class.  Note we don't use the static keyword here.
// We'll start generating IDs at 1
int IDGenerator::s_nextID = 1;
 
// Here's the definition of the static function outside of the class.  Note we don't use the static keyword here.
int IDGenerator::getNextID() { return s_nextID++; } 
 
int main()
{
    for (int count=0; count < 5; ++count)
        std::cout << "The next ID is: " << IDGenerator::getNextID() << '\n';
 
    return 0;
}
