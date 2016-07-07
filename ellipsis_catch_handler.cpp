#include <iostream>

using namespace std;

int main()
{
    char *buf;
    int num = 0;
    
    try {
        buf = new char[512];
        if (buf == 0) throw "Memory allocation failure!";
        if (num == 0) throw num;
    } catch (char *str) {
        cout << "Exception raised: " << str << "\n";
    } catch (...) {
        cout << "Handle following type of Exception:\n";
        cout << "C exceptions\nSystem generated ";
        cout << "and Application generated exceptions.\n";
        cout << "Memory protection, divided by zero, and ";
        cout << "floating point exceptions.\n";
    }
    return 0;
}
