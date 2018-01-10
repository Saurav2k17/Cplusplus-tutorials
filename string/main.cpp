#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    getline(cin, x); // a whole sentence could be read by this inbuilt function
    cout << x << endl;

    string s1("hampster "); //creating string with constructor
    string s2;
    string s3;

    s2=s1;
    s3.assign(s2);

    cout << s1 << s2 << s3 << endl;

    string s4 = "omgwtfbbq";
    cout << s4.at(3) << endl; //string is array of characters and we can access individual characters by at() function.

    for(unsigned int x=0; x < s4.length(); x++)
        {
            cout << s4.at(x);
        }

    return 0;
}
