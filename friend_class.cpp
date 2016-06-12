#include <iostream>
#include <iomanip>

using namespace std;

class CQuadratic;

class CComplex {
    private:
        float m_fReal;
        float m_fImag;
        friend CQuadratic;
};

class CQuadratic {
    public:
        CQuadratic(float r, float i);
        void Print();
    private:
        CComplex m_Number;
};

CQuadratic::CQuadratic(float r, float i)
{
    m_Number.m_fReal = r;
    m_Number.m_fImag = i;
}

void CQuadratic::Print()
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout << " Real Number: ";
    cout << setprecision(2) << m_Number.m_fReal;
    cout << " Imaginary Number: ";
    cout << setprecision(2) << m_Number.m_fImag;
    cout << "\n";
}

int main()
{
    CQuadratic Q(9.0, 5.5);
    Q.Print();
}
