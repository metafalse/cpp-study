#include <iostream>
#include <cstring>

using namespace std;

class CBase {
    public:
        CBase (const char* sName);
        const CBase &operator=(const char* sName);
        void Show() { cout << m_aName << "\n"; }
    protected:
        char m_aName[20];
};

CBase::CBase(const char* sName)
{
    cout << "CBase Constructor\n";
    strcpy(m_aName, sName);
}

const CBase &CBase::operator=(const char* sName)
{
    cout << "CBase Operator function\n";
    strcpy(m_aName, sName);
    return *this;
}

class CDerived : public CBase {
    public:
        CDerived(const char* sName) : CBase(sName)
        {
            cout << "CDerived Constructor\n";
        }
        
        const CDerived &operator=(const char* sName);
};

const CDerived &CDerived::operator=(const char* sName)
{
    cout << "CDerived Operator function\n";
    CBase::operator=(sName);
    
    return *this;
}

int main() {
    CDerived ObjD1("Suleman");
    ObjD1.Show();
    cout << "\n\n";
    cout << "Call to String Assignment\n";
    ObjD1 = "Saya";
    ObjD1.Show();
    ObjD1.CBase::Show();
    return 0;
}
