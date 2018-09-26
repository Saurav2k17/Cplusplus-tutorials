/*

One nuance of C++ that is often missed or misunderstood is that access control works on a per-class basis, not a per-object basis. This means that when a function has access to the private members of a class, it can access the private members of any object of that class type that it can see.

In the example, copyFrom() is a member of DateClass, which gives it access to the private members of DateClass. This means copyFrom() can not only directly access the private members of the implicit object it is operating on (copy), it also means it has direct access to the private members of DateClass parameter d! If parameter d were some other type, this would not be the case.

*/

#include <iostream>
 
class DateClass // members are private by default
{
	int m_month; // private by default, can only be accessed by other members
	int m_day; // private by default, can only be accessed by other members
	int m_year; // private by default, can only be accessed by other members
 
public:
	void setDate(int month, int day, int year)
	{
		m_month = month;
		m_day = day;
		m_year = year;
	}
 
	void print()
	{
		std::cout << m_month << "/" << m_day << "/" << m_year;
	}
 
	
	void copyFrom(const DateClass &d)
	{
		// Note that we can access the private members of d directly
		m_month = d.m_month;
		m_day = d.m_day;
		m_year = d.m_year;
	}
};
 
int main()
{
	DateClass date;
	date.setDate(9, 26, 2018); // okay, because setDate() is public
	
	DateClass copy;
	copy.copyFrom(date); // okay, because copyFrom() is public
	copy.print();
 
	return 0;
}
