  #include <iostream>
#include <cstring>

using namespace std;

class CEmployee {
    public:
        void Init(int size);
        void Set(const char *n, int id, int a);
        void Display();
    private:
        char *m_pcName;
        int m_nIdNum;
        int m_nAge;
};

void CEmployee::Init(int size)
{
    m_pcName = new char [size];
    memset(m_pcName, '\0', size+1);
}

void CEmployee::Set(const char *n, int id, int a)
{
    strcpy(m_pcName, n);
    m_nIdNum = id;
    m_nAge = a;
}

void CEmployee::Display()
{
    cout << "Name: " << m_pcName;
    cout << "  ID: " << m_nIdNum;
    cout << "  Age: " << m_nAge << "\n";
    if (m_pcName) delete [] m_pcName;
}

int main()
{
    CEmployee *ptrWorkerData = new CEmployee;
    
    ptrWorkerData->Init(20);
    ptrWorkerData->Set("Johnson",905,47);
    ptrWorkerData->Display();
    
    delete ptrWorkerData;
}
