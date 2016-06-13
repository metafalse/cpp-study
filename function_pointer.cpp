#include <iostream>
using namespace std;
int square(int x);
int cube(int x);

int main()
{
    int y, x = 5;
    int (*func)(int x);
    
    func = square;
    y = func(x);
    cout << "Square of " << x << " is " << y << "\n";
    
    func = cube;
    y = func(x);
    cout << "Cube of " << x << " is " << y << "\n";
    
    return 0;
}

int square (int x)
{
    return (x * x);
}

int cube (int x)
{
    return (x * x * x);
}
