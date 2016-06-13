#include <iostream>

using namespace std;

class CScreen {
    public:
        CScreen() { m_nRow = 0; m_nColumn = 0; }
        CScreen(int r, int c) { m_nRow = r; m_nColumn = c; }
        void GetPosition(int &r, int &c) { r = m_nRow; c = m_nColumn; }
        CScreen operator+(CScreen &win2);
        CScreen operator+(int i);
    private:
        int m_nRow, m_nColumn;
};

CScreen CScreen::operator+(CScreen &win2)
{
    CScreen temp;
    temp.m_nRow = m_nRow + win2.m_nRow;
    temp.m_nColumn = m_nColumn + win2.m_nColumn;
    return(temp);
}

CScreen CScreen::operator+(int i)
{
    CScreen temp;
    temp.m_nRow = m_nRow + i;
    temp.m_nColumn = m_nColumn + i;
    
    return(temp);
}

int main()
{
    CScreen w1(10, 10), w2(5, 3), w3;
    int x, y;
    
    w3 = w1 + w2;
    w3.GetPosition(x, y);
    cout << "(w1+w2) X: " << x << ", Y: " << y << "\n";
    
    w3 = w1 + 100;
    //w3.GetPosition(x, y);
    cout << "(w1+100) X: " << x << ", Y: " << y << "\n";
}
