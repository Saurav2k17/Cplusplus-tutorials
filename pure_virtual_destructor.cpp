// Pure Virtual Destructor
// If class contains pure virtual destructor, it must provide a function body for the pure virtual destructor.
// This seems strange that how a virtual function is pure if it requires a function body?
// But destructors are always called in the reverse order of the class derivation.
// That means derived class destructor will be invoked first & then base class destructor will be called.
// If definition for the pure virtual destructor is not provided then what function body will be called during object destruction?
// Therefore compiler & linker enforce existence of function body for pure virtual destructor. 
// It is important to note that class becomes abstract class when it contains pure virtual destructor.

#include <iostream> 
class Base 
{ 
	public: 
		virtual ~Base() = 0; // Pure virtual destructor 
/*		~Base() 
		{ 
			std::cout << "~Base() is executed\n"; 
		} 
*/
}; 

Base::~Base() 
{ 
	std::cout << "Pure virtual destructor is called\n"; 
} 

class Derived : public Base 
{ 
	public: 
		~Derived() 
		{ 
			std::cout << "~Derived() is executed\n"; 
		} 
}; 

int main() 
{ 
	//Base b ; // throws compilation error: cannot declare variable ‘b’ to be of abstract type ‘Base’
	Base* b = new Derived(); 
	delete b;
	//Derived* d = new Derived(); delete d;
	return 0; 
}

