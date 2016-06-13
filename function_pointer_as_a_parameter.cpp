#include <iostream>
using namespace std;

double square(double y);

void tabulate(
        double (*func)(double y),
        double lower,
        double upper,
        double increment);

int main()
{
    tabulate(square, 0.0, 2.0, 0.1);
    
    return 0;
}

void tabulate(double (*func)(double y),
              double lower,
              double upper,
              double increment)
{
    double x;
    
    for (x = lower;
    x <= upper + 0.5 * increment;
    x += increment) {
        cout << x << " " << func(x);
    }
}

double square(double y)
{
    return (y * y);
}
