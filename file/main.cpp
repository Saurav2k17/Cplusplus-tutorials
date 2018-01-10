#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream buckyFile;  //creating file object
    buckyFile.open("tuna.txt");

    buckyFile << "I love tuna and tuna loves me !\n" << endl;
    buckyFile.close();

    ofstream buckysFile("beefjerky.txt");

    if(buckysFile.is_open())
    {
        cout << "okt he file is open" << endl;
    }
    else
    {
        cout << "bucky you meassed up" << endl;
    }

    buckysFile << "oi love the beef !\n" << endl;
    buckysFile.close();
    return 0;
}
