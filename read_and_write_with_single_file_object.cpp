#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream FileObj("data.txt", ios::in | ios::out);
    
    if (!FileObj) {
        cout << "Cannot open output file.\n";
        return 1;
    }
    FileObj << 123 << "this is a test" << 23;
    FileObj << "Hello there!" << 99 << "sdf" << "\n";
    char cCharacter;
    char sLine[80], *pString;
    FileObj.seekp(0L);
    do {
        pString = sLine;
        cCharacter = FileObj.peek();
        if (isdigit(cCharacter)) {
            while(isdigit(*pString = FileObj.get()))
                pString++;
            FileObj.putback(*pString);
            *pString = '\0';
            cout << "Integer: " << atoi(sLine);
        }
        else if (isalpha(cCharacter)) {
            while(isalpha(*pString = FileObj.get()))
                pString++;
            FileObj.putback(*pString);
            *pString = '\0';
            cout << "String: " << sLine;
        }
        else
            FileObj.get();
        
        cout << '\n';
        
    } while(!FileObj.eof());
    
    FileObj.close();
    
    return 0;
}
