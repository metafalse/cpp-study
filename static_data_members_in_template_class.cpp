#include <iostream>
using namespace std;

template <typename DataType>
class CHouse {
    public:
        CHouse() { }
        static void SetRoomCount(DataType n);
        int ShowColorCount() const { return m_nTotalRooms; }
    private:
        static DataType m_nTotalRooms;
        static DataType m_nColor;
};

template <typename DataType>
void CHouse<DataType>::SetRoomCount(DataType n)
{
    m_nTotalRooms = n;
}

template<> int CHouse<int>::m_nColor = 0;
template<> int CHouse<int>::m_nTotalRooms = 10;

int main()
{
    CHouse<int>::SetRoomCount(4);
    CHouse<int> intObj;
    cout << "Total Rooms: " << intObj.ShowColorCount();
    cout << "\n";
    const CHouse<int> intConstObj;
    cout << "Total Rooms using const object: ";
    cout << intObj.ShowColorCount() << "\n";
}
