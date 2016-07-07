#include <iostream>

using namespace std;

class Exit{};

int main()
{
    int num;
    cout << "enter a number; 99 to exit" << endl;
    try
    {
        while (true)
        {
            cin >> num;
            
            if (num == 99) throw Exit();
            
            cout << "you entered: " << num << "\n";
            cout << "enter another number " << endl;
        }
    }
    catch (Exit&)
    {
        cout << "time to go home!" << endl;
    }
    return 0;
}
