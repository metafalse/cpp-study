#include <iostream>

using namespace std;

class CScreen {
    public:
        CScreen() { m_nRow = 0; m_nColumn = 0; }
        CScreen(int r, int c) { m_nRow = r; m_nColumn = c; }
        void GetPosition(int &r, int &c) { r = m_nRow; c = m_nColumn; }
        friend CScreen operator+(CScreen &win1, CScreen &win2);
        friend CScreen operator+(CScreen &win1, int i);
        friend CScreen operator+(int i, CScreen &win1);
    private:
        int m_nRow, m_nColumn;
};

CScreen operator+(CScreen &win1, CScreen &win2)
{
    CScreen temp;
    temp.m_nRow = win1.m_nRow + win2.m_nRow;
    temp.m_nColumn = win1.m_nColumn + win2.m_nColumn;
    
    return(temp);
}

CScreen operator+(CScreen &win1, int i)
{
    CScreen temp;
    
    temp.m_nRow = win1.m_nRow + i;
    temp.m_nColumn = win1.m_nColumn + i;
    
    return(temp);
}

CScreen operator+(int i, CScreen &win1)
{
    CScreen temp;
    
    temp.m_nRow = win1.m_nRow + i;
    temp.m_nColumn = win1.m_nColumn + i;
    
    return(temp);
}

int main()
{
    CScreen w1(10, 10), w2(5, 3), w3;
    int x, y;
    
    w3 = w1 + w2;
    w3.GetPosition(x, y);
    cout << "(w1+w2) X: " << x << ", Y: " << y << "\n";
    
    w1 = w1 + 10;
    w1.GetPosition(x, y);
    cout << "(w1+10) X: " << x << ", Y: " << y << "\n";
    
    w1 = 99 + w1;
    w1.GetPosition(x, y);
    cout << "(99+w1) X: " << x << ", Y: " << y << "\n";
}
