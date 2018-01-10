#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //ofstream theFile("players.txt");
    //cout << "Enter players ID, name and money" << endl;
    //cout << "press Ctrl+D to quit\n" << endl;

    int id;
    string name;
    double money;

    //while(cin >> id >> name >> money) //reads from stdin until it sees Ctrl+D
    //{
    //    theFile << id << ' ' << name << ' ' << money << endl; //write to theFile instead of writing to stdout
    //}


    ifstream theFile("players.txt");
    while(theFile >> id >> name >> money) //reads from file until it reaches EOF marker
    {
        cout << id << ", " << name << ", " << money << endl;
    }

    return 0;
}
