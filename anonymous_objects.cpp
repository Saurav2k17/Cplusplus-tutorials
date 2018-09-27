/*

ANONYMOUS OBJECTS

#include <iostream>
 
class Cents
{
private:
    int m_cents;
 
public:
    Cents(int cents) { m_cents = cents; }
 
    int getCents() const { return m_cents; }
};
 
Cents add(const Cents &c1, const Cents &c2)
{
    Cents sum = Cents(c1.getCents() + c2.getCents());
    return sum;
}
 
int main()
{
    Cents cents1(6);
    Cents cents2(8);
    Cents sum = add(cents1, cents2);
    std::cout << "I have " << sum.getCents() << " cents." << std::endl;
 
    return 0;
}
In the above example, we’re using quite a few named Cents values. In the add() function, we have a Cents value named sum that we’re using as an intermediary value to hold the sum before we return it. And in function main(), we have another Cents value named sum also used as an intermediary value.


We can make our program simpler by using anonymous values:


#include <iostream>
 
class Cents
{
private:
    int m_cents;
 
public:
    Cents(int cents) { m_cents = cents; }
 
    int getCents() const { return m_cents; }
};
 
Cents add(const Cents &c1, const Cents &c2)
{
    return Cents(c1.getCents() + c2.getCents()); // return anonymous Cents value
}
 
int main()
{
    Cents cents1(6);
    Cents cents2(8);
    std::cout << "I have " << add(cents1, cents2).getCents() << " cents." << std::endl; // print anonymous Cents value
 
    return 0;
}
This version of add() functions identically to the one above, except it uses an anonymous Cents value instead of a named variable. Also note that in main(), we no longer use a named “sum” variable as temporary storage. Instead, we use the return value of add() anonymously!

As a result, our program is shorter, cleaner, and generally easier to follow (once you understand the concept).

In fact, because cents1 and cents2 are only used in one place, we can anonymize this even further:

*/


#include <iostream>
 
class Cents
{
private:
    int m_cents;
 
public:
    Cents(int cents) { m_cents = cents; }
 
    int getCents() const { return m_cents; }
};
 
Cents add(const Cents &c1, const Cents &c2)
{
    return Cents(c1.getCents() + c2.getCents()); // return anonymous Cents value
}
 
int main()
{
    std::cout << "I have " << add(Cents(6), Cents(8)).getCents() << " cents." << std::endl; // print anonymous Cents value
 
    return 0;
}
