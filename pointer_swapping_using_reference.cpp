#include <iostream>
using namespace std;
void swapPtr(int *&num1, int *&num2) {
    int *temp = num2;
    num2 = num1;
    num1 = temp;
}
int main() {
    int i=10, j=20;
    int *pi=&i, *pj=&j;
    
    cout << "Before swapping pointers:\tpi = ";
    cout << *pi << ";\tpj = " << *pj << "\n";
    swapPtr(pi,pj);
    cout << "After swapping pointers:\tpi = ";
    cout << *pi << ";\tpj = " << *pj << "\n";
}
