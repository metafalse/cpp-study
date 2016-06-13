#include <iostream>
using namespace std;

class CMatrix {
    public:
        CMatrix(unsigned int row, unsigned int col);
        ~CMatrix() { delete [] m_pData; }
        int& operator ()(unsigned int row, unsigned int col);
    private:
        unsigned int m_nRows, m_nCols;
        int *m_pData;
};

CMatrix::CMatrix(unsigned int row, unsigned int col)
{
    m_nRows = row;
    m_nCols = col;
    m_pData = new int [row * col];
}

int& CMatrix::operator ()(unsigned int row, unsigned int col)
{
    return m_pData[m_nCols * row + col];
}

int main()
{
    CMatrix Array(10, 10);
    for (int i=0, r=0; r < 10; r++) {
        for (int c=0; c < 10; c++) {
            Array(r, c) = i++;
        }
    }
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            if (c == 9) cout << "\n";
            else cout << " " << Array(r, c) << " ";
        }
    }
}
