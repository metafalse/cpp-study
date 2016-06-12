#include <iostream>
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
        cout << "Cannot open file";
        return 1;
    }
    
    char cCharacter;
    cout << "Enter a $ to stop\n";
    do {
        cout << ": ";
        cin.get(cCharacter);
        OutFile.put(cCharacter);
    } while (cCharacter != '$');
    
    OutFile.close();
    
    return 0;
}
