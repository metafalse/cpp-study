#include <iostream>

using namespace std;

class CScreen {
    public:
        CScreen() { m_nRow = 0; m_nColumn = 0; }
        CScreen(int r, int c) { m_nRow = r; m_nColumn = c; }
        int operator==(CScreen &win2);
        int operator&&(CScreen &win2);
    private:
        int m_nRow, m_nColumn;
};

int CScreen::operator==(CScreen &win2)
{
    if (m_nRow == win2.m_nRow && m_nColumn == win2.m_nColumn) return(1);
    else return(0);
}

int CScreen::operator&&(CScreen &win2)
{
    return ((m_nRow && win2.m_nRow) && (m_nColumn && win2.m_nColumn));
}

int main()
{
    CScreen w1(10, 10), w2(5, 3), w3(10, 10), w4(0, 0);
    int x, y;
    
    // (w1.operator==(w2))
    if (w1 == w2) cout << "w1 same as w2\n";
    else cout << "w1 and w2 differ\n";
    
    if (w1 == w3) cout << "w1 same as w3\n";
    else cout << "w1 and w3 differ\n";
    
    if (w1 && w2) cout << "w1 && w2 is true\n";
    else cout << "w1 && w2 is false\n";
    
    if (w1 && w4) cout << "w1 && w4 is true\n";
    else cout << "w1 && w4 is false\n";
}
