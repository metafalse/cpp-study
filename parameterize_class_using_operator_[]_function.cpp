#include <iostream>
using namespace std;

template <typename ALL> class Vector {
    public:
        Vector(int n) { data = new ALL[n]; size = n; }
        ~Vector() { delete [] data; }
        ALL& operator[](int i) { return data[i]; }
    private:
        ALL *data;
        int size;
};

class info {
    public:
        char alpha;
        int num;
};
int main()
{
    Vector<int> x_int(8);
    for (int i = 0; i < 8; i++) x_int[i] = i * 3;
    for (int i = 0; i < 8; i++) cout << x_int[i] << ' ';
    cout << '\n';
    Vector<float> x_float(8);
    
    cout.setf(ios::showpoint);
    for (int i = 0; i < 8; i++) x_float[i] = i * 3.1;
    for (int i = 0; i < 8; i++) cout << x_float[i] << ' ';
    cout << '\n';
    Vector<info> x_info(5);
    x_info[0].alpha = 'A';
    x_info[1].alpha = 'B';
    x_info[2].alpha = 'C';
    x_info[3].alpha = 'D';
    x_info[4].alpha = 'E';
    x_info[0].num = 4;
    x_info[1].num = 6;
    x_info[2].num = 2;
    x_info[3].num = 1;
    x_info[4].num = 8;
    for (int i = 0; i < 5; ++i) {
        cout << x_info[i].alpha << '=';
        cout << x_info[i].num << ' ';
    }
    
    cout << '\n';
}
