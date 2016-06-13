#include <iostream>
using namespace std;

class CVector {
    public:
        CVector(int n);
        ~CVector();
        int &operator[](int i);
        
    private:
        int *m_Data;
        int m_Size;
};

CVector::CVector(int n)
{
    m_Data = new int[n];
    m_Size = n;
}

CVector::~CVector()
{
    delete [] m_Data;
}

int& CVector::operator[](int i)
{
    return m_Data[i];
}

int main()
{
    CVector Obj(8);
    
    for (int i = 0; i < 8; i++) Obj[i] = i * 3;
    
    for (int i = 0; i < 8; i++) cout << Obj[i] << ' ';
    
    cout << '\n';
}
