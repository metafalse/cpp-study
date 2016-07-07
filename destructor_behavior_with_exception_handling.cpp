#include <iostream>

using namespace std;

class CTest {
    public:
        CTest() { }
        ~CTest() { }
        const char *ShowReason() const { return "Exception in CTest."; }
};

class CDemo {
    public:
        CDemo() { cout << "Constructing CDemo.\n"; }
        ~CDemo() { cout << "Destructing CDemo.\n"; }
};

int main()
{
    cout << "In main.\n";
    
    try {
        cout << "In try block.\n";
        CDemo D;
        cout << "In main(). Throwing CTest exception\n";
        throw CTest();
    }
    
    catch (CTest& eTest) {
        cout << "In catch handler.\n";
        cout << "Caught CTest exception type: ";
        cout << eTest.ShowReason() << "\n";
    }
    
    catch(char *str) {
        cout << "Caught some other exception: ";
        cout << str << "\n";
    }
    
    cout << "Back in main. Execution resumes here.\n";
    
    return 0;
}
