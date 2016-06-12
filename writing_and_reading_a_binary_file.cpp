#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream OutFile("readme.dat", ios::binary);
    
    if (!OutFile) {
        cerr << "Cannot open output file.\n";
        return 1;
    }
    
    char sOutBuff[] = "Tax Return 1996 Amount:";
    double dAmount = 100.00;
    
    OutFile.write(sOutBuff, strlen(sOutBuff));
    OutFile.write((char *) &dAmount, sizeof(double));
    OutFile.close();
    
    ifstream InFile("readme.dat", ios::binary);
    if (!InFile) {
        cerr << "Cannot open input file.\n";
        return 1;
    }
    char sInBuff[23];
    double nSum;
    InFile.read(sInBuff, 23);
    InFile.read((char *)&nSum, sizeof(double));
    nSum = nSum + 100;
    cout << sInBuff << nSum << "\n";
    
    InFile.close();
    return 0;
}
