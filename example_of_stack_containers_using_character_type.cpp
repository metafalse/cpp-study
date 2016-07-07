#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack <char> alphabet;
    for (int i = 0; i < 10; i++) alphabet.push('A'+i);
    
    cout << "There are " << alphabet.size();
    cout << " alphabet in the stack " << endl;
    cout << "The alphabet on the top of stack is ";
    cout << alphabet.top() << endl;
    
    alphabet.pop();
    cout << "Now top alphabet is " << alphabet.top() << endl;
    cout << alphabet.size();
}
