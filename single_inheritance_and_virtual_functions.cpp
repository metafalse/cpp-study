#include <iostream>
using namespace std;

enum Birds {BIRD,PARROT,PARAKEET};

class CBird {
    public:
        virtual void GetData();
        virtual void History() { }
        virtual void ShowData() { cout << m_Color << '\n'; }
        
    protected:
        int m_Color;
};

void CBird::GetData()
{
    cout << "Enter Data For Bird: ";
    cin >> m_Color;
}

class CParrot : public CBird {
    public:
        void GetData();
        void ShowData() { cout << m_b << '\n'; }
        virtual void Name() { }

    protected:
        int m_b;
};

void CParrot::GetData()
{
    cout << "Enter Data For Parrot: ";
    cin >> m_b;
}

class CParakeet : public CParrot {
    public:
    void GetData();
    void ShowData() { cout << m_c << '\n'; }
    void Name() { }

    private:
    int m_c;
};

void CParakeet::GetData()
{
    cout << "Enter Data For Parakeet: ";
    cin >> m_c;
}

int main() {
    CBird *pBird;
    int nBirdType = 0;
    cout << "Enter Bird Type: ";
    cin >> nBirdType;
    switch (nBirdType) {
        case BIRD:
            pBird = new CBird;
            break;
        case PARROT:
            pBird = new CParrot;
            break;
        case PARAKEET:
            pBird = new CParakeet;
            break;
    }
    pBird->GetData();
    pBird->ShowData();
    delete pBird;
}
