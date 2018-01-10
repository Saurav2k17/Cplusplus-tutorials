#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1("OMG i think i am preggy!!!");
    cout << s1 << endl;
    cout << s1.substr(17, 8) << endl; //substr(17, 8) pulls out characters starting from 17 and upto next 8 characters.

    string one("apples ");
    string two("beans ");
    cout << one << two << endl;
    one.swap(two);                      //swaps string one with two
    cout << one << two << endl;

    string three("ham is spam oh yes i am!");
    cout << three << endl;
    cout << three.find("am") << endl; //gives the first occurence of am found in string three, rfind is used to find in reverse direction
    three.erase(11); //erases from 11th character onwards including the 11th character from string three
    cout << three << endl;
    s1.replace(17, 9, "an idiot!!!"); //replaces with the argument string starting from 17th character and totally replaces 9 characters
    cout << s1 << endl;
    s1.insert(20, "frikin "); //inserts the argument string at exactly the 20th character
    cout << s1 << endl;
    return 0;
}
