#include <iostream>
using namespace std;

class CTruck;

class CCar {
    public:
        CCar(int p, int s) { m_nPassengers = p; m_nSpeed = s; }
        int sp_greater(CTruck &t);
    private:
        int m_nPassengers;
        int m_nSpeed;
};

class CTruck {
    public:
        CTruck(int w, int s) {m_nWeight = w, m_nSpeed = s;}
        friend int CCar::sp_greater(CTruck &t);
    private:
        int m_nWeight;
        int m_nSpeed;
};

int CCar::sp_greater(CTruck &t)
{
    return(m_nSpeed - t.m_nSpeed);
}

int main()
{
    int t;
    CCar c1(6, 55), c2(2, 120);
    CTruck t1(10000, 55), t2(20000, 72);
    
    cout << "Comparing c1 and t1: \n";
    t = c1.sp_greater(t1);
    
    if (t < 0) cout << "Truck is faster. \n";
    else if (t == 0) cout << "Car and truck speed is the same. \n";
    else cout << "Car is faster. \n";
    
    cout << "Comparing c2 and t2:\n";
    t = c2.sp_greater(t2);
    if (t < 0) cout << "Truck is faster. \n";
    else if (t == 0) cout << "Car and truck speed is the same. \n";
    else cout << "Car is faster. \n";
}
