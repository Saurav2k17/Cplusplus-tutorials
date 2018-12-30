// Illustrating concept of Virtual Function
// Runtime polymorphism is achieved through a pointer (or reference) of base class type.
// Also, a base class pointer can point to the objects of base class as well as to the objects of derived class.
// In the following code, base class pointer ‘bptr’ contains the address of object ‘d’ of derived class
// Late binding (Run-time) is done in accordance with the content of pointer (i.e. location pointed to by pointer) 
// Early binding (Compile-time) is done according to the type of pointer
// Since print() function is declared with virtual keyword so it will bind at run-time
// Output is print derived class as pointer is pointing to object of derived class
// show() is non-virtual so it will bind during compile time (output is show base class as pointer is of base type)


#include <iostream> 
using namespace std; 

class base 
{ 
	public: 
		virtual void print() 
		{
			cout << "print base class" << endl;
		} 

		void show() 
		{
			cout << "show base class" << endl;
		} 
}; 

class derived : public base 
{ 
	public: 
		void print() 
		{
			cout << "print derived class" << endl;
		} 

		void show() 
		{
			cout << "show derived class" << endl;
		} 
}; 

int main() 
{ 
	base *bptr; 
	derived d; 
	bptr = &d; 
	
	// virtual function, bind at runtime 
	bptr->print(); 
	
	// Non-virtual function, bind at compile time 
	bptr->show();
	//d.show();
	return 0; 
} 

