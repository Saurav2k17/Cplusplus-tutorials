#include <iostream>
#include <string>
using namespace std;

class SauravClass
{
   public:
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
    SauravClass so;
    //so.name = "Saurav Kumar Sahu";
    so.setName("Accessing private variable through public function");
    cout << so.getName() << endl;
    return 0;
}
