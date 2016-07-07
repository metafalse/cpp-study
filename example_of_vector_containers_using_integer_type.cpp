#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arNumbers;
    
    for (int i = 0; i < 5; i++) arNumbers.push_back(i * 12);
    
    cout << "Total Elements: " << int(arNumbers.size()) << endl;
    
    for (int i = 0; i < int(arNumbers.size()); i++)
    cout << "Value at position" << i << " is " << arNumbers[i] << endl;
}
