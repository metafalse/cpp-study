#include <iostream>
#include <limits>
#include <cctype>
#include <cstring>
using namespace std;
int main()
{
    int input = 0;
    cout << "Enter the number: ";
    while (cin >> input || !cin.eof()) {
        if (cin.good()) {
            if (input < 0) break;
            else cout << "You Enterd " << input << "\n";
        }
        else if (!isdigit(input)) cout << "Not a number\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter the number: ";
    }
}
