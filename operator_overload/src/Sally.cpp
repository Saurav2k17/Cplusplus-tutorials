#include "Sally.h"
#include <iostream>
using namespace std;

Sally::Sally()
{

}

Sally::Sally(int a)
{
    num = a;
}

Sally Sally::operator+(Sally aso)
{
    //Sally brandNew;
    //brandNew.num = this->num + aso.num;
    return(num + aso.num);
}
