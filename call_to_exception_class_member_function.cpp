#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {
        char * buff = new char[1000000000000000000];
        strcpy(buff, "Suleman");
        cout << buff << "\n";
        if (buff) delete [] buff;
    }
    catch (bad_alloc& alloc_failure)
    {
        cout << "memory allocation failure\n";
        cout << alloc_failure.what();
    }
    catch (exception& std_ex)
    {
        cout << std_ex.what() << endl;
    }
    catch (...)
    {
        cout << "unrecognized exception" << endl;
    }
}
