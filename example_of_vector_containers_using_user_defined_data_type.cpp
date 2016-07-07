#include <iostream>
#include <vector>
using namespace std;
struct Furniture {
    char m_Chair;
    int  m_nTable;
    Furniture(char c, int t) : m_Chair(c), m_nTable(t) { }
};

int main()
{
    vector<Furniture> vObj;
    for (int i = 0; i < 10; i++) vObj.push_back(Furniture('A'+i,i));
    
    for (int i = 0; i < vObj.size(); i++) {
        cout << vObj[i].m_Chair << " " << vObj[i].m_nTable << endl;
    }
}
