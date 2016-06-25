#include <iostream>
using namespace std;

class CBird {
    public:
        CBird (int x) { a = x; }
        int GetBird() { return a; }
    private:
        int a;
};

class CParrot : public CBird {
    public:
        CParrot (int x, int y) : CBird (y) { b = x; }
        int GetParrot() { return b; }
    private:
        int b;
};

class CParakeet : public CParrot {
    public:
        CParakeet (int x, int y, int z) : CParrot (y, z) { c = x; }
        void Show();
    private:
        int c;
};

void CParakeet::Show()
{
    cout << GetBird() << ' ' << GetParrot() << ' ' << c << '\n';
}

int main(void) {
    CParakeet ob(1, 2, 3);
    ob.Show();
    
    cout << ob.GetBird() << ' ' << ob.GetParrot() << '\n';
    
    return 0;
}
