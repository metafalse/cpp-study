#include <iostream>
using namespace std;

template <typename DataType>
class CHouse {
    public:
        CHouse(int n);
        ~CHouse() { delete [] data; }
        DataType& operator[](int i) { return data[i]; }
    private:
        DataType *data;
        int size;
};

template <typename DataType> CHouse<DataType>::CHouse(int n)
{
    data = new DataType[n];
    size = n;
}
class CFurniture {
    public:
        char m_Chair;
        int m_nTable;
};
class ManageHouseInfo {
    public:
        ManageHouseInfo(CHouse<CFurniture> &x);
        void Show(CHouse<CFurniture> &x);
};
void ManageHouseInfo::Show(CHouse<CFurniture> &x)
{
    for (int i = 0; i < 5; i++)
        cout << x[i].m_Chair << '=' << x[i].m_nTable << ' ';
    cout << '\n';
}
ManageHouseInfo::ManageHouseInfo(CHouse<CFurniture> &x)
{
    x[0].m_Chair = 'A';
    x[1].m_Chair = 'B';
    x[2].m_Chair = 'C';
    x[3].m_Chair = 'D';
    x[4].m_Chair = 'E';
    x[0].m_nTable = 4;
    x[1].m_nTable = 6;
    x[2].m_nTable = 2;
    x[3].m_nTable = 1;
    x[4].m_nTable = 8;
}
int main()
{
    CHouse<CFurniture> x(5);
    ManageHouseInfo obj(x);
    obj.Show(x);
}
