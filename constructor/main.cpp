#include <iostream>
#include <string>
using namespace std;

class SauravClass
{
   public:
       SauravClass(string z) {
       cout << "This is Constructor getting created automatically" << endl;
       cout << z << endl;
       //setName(z);
       }
       void setName(string x) {
        name = x;
       }
       string getName() {
        return name;
       }
    private:
       string name;
};

int main()
{
    SauravClass so("Passing string through object");
    //so.name = "Saurav Kumar Sahu";
    so.setName("Accessing private variable through public function");
    cout << so.getName() << endl;
    return 0;
}
