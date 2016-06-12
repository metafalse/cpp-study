#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream OutFile("readme.txt");
    
    if (!OutFile) {
        cout << "Cannot open output file.\n";
        return 1;
    }
    OutFile << "Tax_Return_1996_Amount:";
    OutFile << 100 << "\n";
    
    OutFile.close();
    
    ifstream InFile("readme.txt");
    
    if (!InFile) {
        cout << "Cannot open input file.\n";
        return 1;
    }
    
    char Str[80];
    
    InFile >> Str;
    
    cout << Str << "\n";
    
    InFile.close();
    
    return 0;
}
