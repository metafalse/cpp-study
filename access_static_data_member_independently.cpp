#include <iostream>
using namespace std;

class CComputer {
    public:
        static int m_nBuffers;
        int Display() { return m_nBuffers; }
};
int CComputer::m_nBuffers;
int main()
{
    CComputer Config, Windows;
    
    CComputer::m_nBuffers = 100;
    
    cout << "CComputer::m_nBuffers ";
    cout << CComputer::m_nBuffers << "\n";
    cout << "Config object can see m_nBuffers value as: ";
    cout << Config.Display() << "\n";
    cout << "Windows object can see m_nBuffers value as: ";
    cout << Windows.Display() << "\n";
}
