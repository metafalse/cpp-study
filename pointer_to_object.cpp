#include <iostream>
using namespace std;
#define STACK_SIZE 10
class CStack {
    private:
        long books[STACK_SIZE];
        int m_nSize;
    public:
        CStack() { m_nSize = -1; }
        long top() { return(books[m_nSize]);}
        long pop() { return (!Empty() ? books[m_nSize--] : -1);}
        void push(long i) { if(!Full()) books[++m_nSize] = i;}
        int Empty() { return (m_nSize < 0 ? 1 : 0); }
        int Full() { return (m_nSize == STACK_SIZE ? 1 : 0); }
        long bottom() { return books[0]; }
};
int main() {
    CStack *q = new CStack;
    
    for (int i = 0; i < STACK_SIZE; i++) q->push(i+2);
    
    cout << "Top of the stack book# is: " << q->top() << '\n';
    for (int i = 0; i < STACK_SIZE; i++)
    cout << q->pop() << " ";
    
    cout << "\nBottom of the stack book# is: " << q->bottom() << '\n';
    
    delete q;
}
