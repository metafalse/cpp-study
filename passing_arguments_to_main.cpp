#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "Usage: WRITE <filename>\n";
        return 1;
    }
    
    ofstream OutFile(argv[1]);
    
    if (!OutFile) {
        cout << "Cannot open output file.\n";
        return 1;
    }
    
    cout << "Write strings to disk, RETURN to stop\n";
    
    char StrBuf[80];
    memset(StrBuf, '\0', 80);
    
    char *pStr = StrBuf;
    
    do {
        cout << ": ";
        cin.getline(pStr, 80);
        OutFile << pStr << "\n";
    } while (*pStr);
    
    OutFile.close();
    
    return 0;
}
