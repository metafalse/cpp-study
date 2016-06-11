#include <iostream>
using namespace std;
class CApple {
    public:
        CApple(int i) { m_nData = i; }
        void add(int i) { m_nData = i + 10; }
        int GetData() const { return m_nData; }
    private:
        int m_nData;
};
int main() {
    CApple Washington(60);
    Washington.add(10);
    int k = Washington.GetData();
    cout << "The Washington object Value is " << k << "\n";
    
    const CApple Macintash = 42;
    
    //Macintash.add(17);
    
    int count = Macintash.GetData();
    cout << "The Macintash object Value is " << count << "\n";
}
