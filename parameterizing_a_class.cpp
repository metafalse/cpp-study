#include <iostream>
using namespace std;

template <typename Type>
class Array {
    public:
        Array(int sz = 0);
        ~Array() { delete [] m_AnyArray; }
        void Init(Type nData, int nIndex);
        int GetSize() { return m_Size; }
        void Show();
    private:
        Type *m_AnyArray;
        int m_Size;
};

template <typename Type>
Array<Type>::Array(int sz)
{
    m_AnyArray = new Type[sz];
    m_Size = sz;
}

template <typename Type>
void Array<Type>::Init(Type nData, int nIndex)
{
    m_AnyArray[nIndex] = nData;
}

template <typename Type>
void Array<Type>::Show()
{
    for (int i=0; i < m_Size; i++) cout << m_AnyArray[i] << " ";
    cout << "\n";
}
int main()
{
    Array<int> intArray(30);
    for (int i=0; i < intArray.GetSize(); i++) intArray.Init(i, i);
    intArray.Show();
    
    Array<char> charArray(26);
    for (int Alpha=0; Alpha < charArray.GetSize(); Alpha++)
        charArray.Init('A' + Alpha, Alpha);
    charArray.Show();
}
