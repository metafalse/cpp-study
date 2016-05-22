#include <iostream>
#include <cstring>
using namespace std;
class CEmployee {
    public:
        void Create(int TotalEmp);
        void GetEmpData(CEmployee *pFreshNode);
        void ComputeWage(CEmployee *pCurNode);
        void Remove(CEmployee *pHeadNode);
    private:
        char m_aName[30];
        unsigned int m_nAge;
        unsigned int m_nSalary;
        CEmployee *m_pLink;
};
void CEmployee::Remove(CEmployee *pHeadNode) {
    CEmployee *pCurr, *pDeleteThisNode;
    
    pCurr = pHeadNode;
    while (pCurr != 0) {
        pDeleteThisNode = pCurr;
        cout << "\nDeleting: \n" << pCurr->m_aName;
        pCurr = pCurr->m_pLink;
        delete pDeleteThisNode;
    }
}
void CEmployee::GetEmpData(CEmployee *pFreshNode) {
    cout << "Enter the employee's name: ";
    cin >> pFreshNode->m_aName;
    cout << "Enter the employee's age: ";
    cin >> pFreshNode->m_nAge;
    cout << "Enter the employee's salary: ";
    cin >> pFreshNode->m_nSalary;
    cout << "\n";
}
void CEmployee::Create(int nTotalEmp) {
    CEmployee *pFreshNode, *pHeadNode, *pCurNode;
    
    for (int i=0; i < nTotalEmp; i++) {
        pFreshNode = new CEmployee;
        GetEmpData(pFreshNode);
        pFreshNode->m_pLink = 0;
        if (i == 0) {
            pHeadNode = pFreshNode;
            pCurNode = pFreshNode;
        } else {
            pCurNode->m_pLink = pFreshNode;
            pCurNode = pFreshNode;
        }
    }
    pCurNode = pHeadNode;
    ComputeWage(pCurNode);
    Remove(pHeadNode);
}
void CEmployee::ComputeWage(CEmployee *pCurNode) {
    int nNumHours; float fWeekPay; static char caSearchName[31];
    cout << "\nEnter employee's Name to compute pay: ";
    cin >> caSearchName;
    while (pCurNode != 0) {
        if (strcmp(caSearchName, pCurNode->m_aName) == 0) {
            cout << "How many hours did";
            cout << pCurNode->m_aName << " work this week? ";
            cin >> nNumHours;
            fWeekPay = (pCurNode->m_nSalary / 2080) * nNumHours;
            cout << "Annual salary is: ";
            cout << pCurNode->m_nSalary << "\n";
            cout << pCurNode->m_aName << "'s ";
            cout << " pay this week is: " << fWeekPay;
            break;
        }
        else pCurNode = pCurNode->m_pLink;
    }
}
int main() {
    int nNumEmp;
    cout << "Enter the number of employees to process: ";
    cin >> nNumEmp;
    
    CEmployee Worker;
    Worker.Create(nNumEmp);
}
