#include <iostream>
#include <iomanip>
using namespace std;

class CClock {
    public:
        CClock();
        CClock Tick();
        void PrintTime();
        CClock operator++();
        CClock operator++(int);
    private:
        int m_Hour;
        int m_Minutes;
        int m_TimeType;
};

CClock::CClock()
{
    m_Hour = 12;
    m_Minutes = 0;
    m_TimeType = 0;
}

CClock CClock::Tick()
{
    ++m_Minutes;
    if (m_Minutes == 60) {
        m_Hour++;
        m_Minutes = 0;
    }
    if (m_Hour == 13)
        m_Hour = 1;
    
    if (m_Hour == 12 && m_Minutes == 0)
        m_TimeType = !m_TimeType;
    return *this;
}

CClock CClock::operator++()
{
    return Tick();
}

CClock CClock::operator++(int)
{
    CClock c = *this;
    Tick();
    
    return c;
}

void CClock::PrintTime()
{
    cout << setfill('0') << setw(2) << m_Hour;
    cout << ':' << setw(2) << m_Minutes << setfill(' ');
    
    cout << (m_TimeType ? " PM" : " AM") << endl;
}

int main()
{
    CClock clkObj1, clkObj2;
    
    clkObj1 = clkObj2++;
    
    cout << "Clock clkObj1 = ";
    clkObj1.PrintTime();
    
    cout << "Clock clkObj2 = ";
    clkObj2.PrintTime();
}
