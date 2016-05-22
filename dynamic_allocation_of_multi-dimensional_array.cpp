#include <iostream>
using namespace std;
int main(){
    int x, y, nNumber=10;
    int **pnMatrix=0;
    pnMatrix = new int*[nNumber];
    for (x=0; x<nNumber; x++)
        pnMatrix[x] = new int[nNumber];
        
    for (x=0; x<nNumber;  x++)
        for (y=0; y<nNumber; y++)
            *(pnMatrix[x] + y) = y;
            
    for (x=0; x<nNumber; x++) {
        for (y=0; y<nNumber; y++)
            cout << pnMatrix[x][y];
            
        cout << "\n";
    }
    
    for (x=0; x<nNumber; x++)
        delete [] pnMatrix[x];
        
    delete [] pnMatrix;
}
