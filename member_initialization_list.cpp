#include <iostream>
using namespace std;
class CMatrix {
    public:
        CMatrix(int s);
        ~CMatrix();
        void FillArray();
        void Display();
    private:
        int **m_pnMatrix;
        const int m_nSize;
};

CMatrix::CMatrix(int s) : m_nSize(s), m_pnMatrix(0)
{
    m_pnMatrix = new int*[m_nSize];
    for (int x = 0; x < m_nSize; x++)
        m_pnMatrix[x] = new int [m_nSize];
}

CMatrix::~CMatrix()
{
    for (int x = 0; x < m_nSize; x++) delete m_pnMatrix[x];
    delete [] m_pnMatrix;
}

void CMatrix::FillArray()
{
    for (int x = 0; x < m_nSize; x++)
        for (int y = 0; y < m_nSize; y++)
            *(m_pnMatrix[x] + y) = y;
}

void CMatrix::Display()
{
    for (int x = 0; x < m_nSize; x++) {
        for (int y = 0; y < m_nSize; y++)
            cout << (*(m_pnMatrix[x] + y)) << " ";
        cout << "\n";
    }
}

int main()
{
    CMatrix m(4);
    m.FillArray();
    m.Display();
}
