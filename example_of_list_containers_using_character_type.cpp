#include <iostream>
#include <list>
using namespace std;

int main()
{
    list <char> alphabet;
    for (int i = 0; i < 10; i++) alphabet.push_front('A' + i);
    
    alphabet.reverse();
    alphabet.insert(alphabet.end(), 'Z');
    alphabet.push_back('P');
    alphabet.push_front('K');
    for(list<char>::iterator list_iter = alphabet.begin();
    list_iter != alphabet.end(); list_iter++)
    cout << *list_iter << " ";
    cout << endl;
    
    while (!alphabet.empty()) {
        cout << alphabet.front() << " ";
        alphabet.pop_front();
    }
    cout << endl;
    
    cout << "There are " << alphabet.size();
    cout << " alphabet in the list " << endl;
}
