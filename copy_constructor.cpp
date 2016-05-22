#include <iostream>
using namespace std;
class CHouse {
    public:
        CHouse() { nBedRooms = nBathRooms = 0; }
        CHouse(int nBed, int nBath);
        CHouse(CHouse &Obj);
        void Show();
    private:
        int nBedRooms;
        int nBathRooms;
};
CHouse::CHouse(int nBed, int nBath) {
    nBedRooms = nBed;
    nBathRooms = nBath;
}
CHouse::CHouse(CHouse &Obj) {
    nBedRooms = Obj.nBedRooms;
    nBathRooms = Obj.nBathRooms;
}
void CHouse::Show() {
    cout << "Total Bed Rooms = " << nBedRooms << "\n";
    cout << "Total Bath Rooms = " << nBathRooms << "\n";
}
int main() {
    CHouse h1(3,1);
    CHouse h2 = h1;
    h2.Show();
}
