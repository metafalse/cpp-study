#include <iostream>
using namespace std;

class CFruit {
    public:
        CFruit();
        virtual ~CFruit();
    protected:
        char *pFruit;
};

CFruit::CFruit()
{
    pFruit = new char[5];
    cout << "Fruit class allocates 5 bytes\n";
}

CFruit::~CFruit()
{
    delete[] pFruit;
    cout << "Fruit class frees 5 bytes\n";
}

class CApple : public CFruit {
    public:
        CApple();
        ~CApple();
    private:
        char *pApple;
};

CApple::CApple() : CFruit()
{
    pApple = new char[1000];
    cout << "CApple class allocates 1000 bytes\n";
}

CApple::~CApple()
{
    delete[] pApple;
    cout << "CApple class frees 1000 bytes\n";
}

int main()
{
    const int Forever = 1;
    
    while (Forever) {
        CFruit *pFruit = new CApple;
        
        delete pFruit;
    }
}
