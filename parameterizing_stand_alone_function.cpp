#include <iostream>
using namespace std;

template <typename B>
B square(const B number)
{
    return(number * number);
}

int main()
{
    const int ix = 5;
    const float fx = 5.0;
    cout.setf(ios::showpoint);
    cout << "INTEGER SQUARE: " << square(ix) << "\n";
    cout << "FLOAT SQUARE: " << square(fx) << "\n";
}
