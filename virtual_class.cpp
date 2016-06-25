#include <iostream>

using namespace std;

class CElement {
    public:
        CElement (int x) { m_nTotal = x; }
        int GetTypeE() { return m_nTotal; }
    private:
        int m_nTotal;
};

class CHydrogen : public virtual CElement {
    public:
        CHydrogen (int x) : CElement(x), m_nType(x) { }
        int GetTypeH() { return m_nType; }
    private:
        int m_nType;
};

class COxygen : public virtual CElement {
    public:
        COxygen (int x) : CElement(x) { m_nType = x; }
        int GetTypeO() { return m_nType; }
    private:
        int m_nType;
};

class CWater : public CHydrogen, public COxygen {
    public:
        CWater (int h, int o, int e, int w) : CHydrogen(h), COxygen(o), CElement(e), m_nCups(w) { }
        void show();
    private:
        int m_nCups;
};

void CWater::show()
{
    cout << "Water cups = " << m_nCups << '\n';
    cout << "Hydrogen Elements = " << GetTypeH() << '\n';
    cout << "Oxygen Elements = " << GetTypeO() << '\n';
    cout << "Total Elements = " << GetTypeE() << '\n';
}

int main() {
    CWater ob(2, 1, 2, 5);
    ob.show();
    
    return 0;
}
