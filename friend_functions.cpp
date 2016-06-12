#include <iostream>
#include <iomanip>
using namespace std;
class CSpoons;
class CCups {
    public:
        CCups(int num = 1) { m_nQuantity = num; }
        int GetTotal() { return m_nQuantity; }
        friend int Add (const CCups&, const CSpoons&);
    private:
        int m_nQuantity;
};
class CSpoons {
    public:
        CSpoons(int num = 1) { m_nQuantity = num; }
        int GetTotal() { return m_nQuantity; }
        friend int Add (const CCups&, const CSpoons&);
    private:
        int m_nQuantity;
};

int Add(const CCups& Obj1, const CSpoons& Obj2)
{
    return(Obj1.m_nQuantity + Obj2.m_nQuantity);
}

int main()
{
    CCups cupObject(6);
    CSpoons spoonObject(6);
    
    cout << "\nCups Total   = " << cupObject.GetTotal();
    cout << "\nSpoons Total = " << cupObject.GetTotal();
    cout << "\nTotal inventory = ";
    cout << Add(cupObject, spoonObject) << "\n";
}
