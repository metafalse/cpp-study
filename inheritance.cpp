#include <iostream>
using namespace std;

class CVehicle {
    public:
        void SetVehicleId(int nId) { m_nVehicleId = nId; }
        void ShowVehicleId() { cout << m_nVehicleId << '\n'; }
    
    private:
        int m_nVehicleId;
};

class CCar : private CVehicle {
    public:
        void SetCarId(int nId) { m_nCarId = nId; }
        void ShowCarId() { cout << m_nCarId << "\n"; }
    private:
        int m_nCarId;
};

int main(void) {
    CCar Jaguar;
    //Jaguar.SetVehicleId(120);
    Jaguar.SetCarId(150);
    
    //Jaguar.ShowVehicleId();
    Jaguar.ShowCarId();
    return 0;
}
