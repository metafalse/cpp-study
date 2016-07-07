#include <iostream>

using namespace std;

int main()
{
    try {
        throw 5;
    } catch (int num) {
        cout << "Exception for Number " << num << " occurred\n";
    }
    
    return 0;
}
