#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arNumbers;
    
    for (int i = 0; i < 5; i++) arNumbers.push_back(i * 12);
    
    cout << "Total Elements: " << int(arNumbers.size()) << endl;
    
    vector<int>::iterator itNum = arNumbers.begin();
    
    for (; itNum < arNumbers.end(); itNum++) {
        cout << "Value at position=> " << int((itNum - arNumbers.begin()));
        cout << " is " << *itNum << endl;
    }
}
