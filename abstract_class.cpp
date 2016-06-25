#include <iostream>
using namespace std;

class CArea {
    protected:
        double m_fDim1;
        double m_fDim2;
    public:
        void Setarea(double d1, double d2) { m_fDim1=d1; m_fDim2=d2; }
        virtual double Getarea() = 0;
};

class CTriangle : public CArea {
    public:
        double Getarea() { return (0.5 * m_fDim1 * m_fDim2); }
};

class CRectangle : public CArea {
    public:
        double Getarea() { return (m_fDim1 * m_fDim2); }
};

int main()
{
    CArea *pArea;
    CRectangle *pR = new CRectangle;
    CTriangle *pT = new CTriangle;
    
    pR->Setarea(3.3, 4.5);
    pT->Setarea(4.0, 5.0);
    
    pArea = pR;
    cout << "Rectangle has area: " << pArea->Getarea() << "\n";
    
    pArea = pT;
    cout << "Triangle has area: " << pArea->Getarea() << "\n";
    
    delete pR;
    delete pT;
}
