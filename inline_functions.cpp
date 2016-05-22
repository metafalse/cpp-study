#include <iostream>
using namespace std;

inline double Round(double fAmount) {
  long lCents = long(100.0 * fAmount + 0.5);
  return double(lCents) /100.0;
}
class CInvoice {
  public:
    void GetData();
    void Display();
    private:
    double m_fPrice;
    int m_nInvoiceNum;
};
int main() {
  CInvoice Items;
  Items.GetData();
  Items.Display();
}
void CInvoice::GetData() {
  cout << "Enter Invoice Number:";
  cin >> m_nInvoiceNum;
  
  cout << "Regular price: ";
  cin >> m_fPrice;
}
void CInvoice::Display() {
  cout << "Invoice Number = " << m_nInvoiceNum << '\n';
  cout << "Regular Price = $" << Round(m_fPrice) << '\n';
}
