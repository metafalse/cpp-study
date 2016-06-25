#include <iostream>
using namespace std;

class CWood {
    public:
        CWood (int x = 3) { m_nType = x; }
        int GetTypeW() { return m_nType; }
    private:
        int m_nType;
};

class CMetal {
    public:
        CMetal (int x = 2) { m_nType = x; }
        int GetTypeM() { return m_nType; }
    private:
        int m_nType;
};

class CDesk : public CWood, public CMetal {
    public:
        CDesk (int x = 1, int y = 2, int z = 3) : CWood(y), CMetal(z)
        { m_nType = x; }
        
        void Show();
    private:
        int m_nType;
};

void CDesk::Show()
{
    cout << GetTypeM() << ' ';
    cout << GetTypeW() << ' ' << m_nType << '\n';
}

int main() {
    CDesk ob(10, 20, 30);
    ob.Show();
    
    return 0;
}
