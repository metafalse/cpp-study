#include <iostream>
#include <iomanip>
using namespace std;

ostream &Space(ostream& Obj)
{
    Obj << " ";
    return Obj;
}

// Dollar:
ostream &Dollar(ostream& Obj)
{
    Obj << "$";
    return Obj;
}

//At:
ostream &At(ostream& Obj)
{
    Obj << "@";
    return Obj;
}

int main()
{
    cout << "Quantity:";
    cout << 120;
    cout << Space;
    cout << At;
    cout << Space;
    cout << Dollar;
    cout << 90;
}
