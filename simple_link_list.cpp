#include <iostream>
using namespace std;
class CNode {
    public:
        int m_nData;
        CNode *m_pLink;
};
int main() {
    CNode *pHeadPtr, *pCurrPtr, *pTailPtr, *pDeleteThisNode;
    
    pCurrPtr = new CNode;
    pTailPtr = pHeadPtr = pCurrPtr;
    pCurrPtr->m_nData = 1;
    pCurrPtr->m_pLink = 0;
    
    pTailPtr->m_pLink = new CNode;
    pCurrPtr = pTailPtr->m_pLink;
    pCurrPtr->m_nData = 2;
    pCurrPtr->m_pLink = 0;
    pTailPtr = pCurrPtr;
    
    pTailPtr->m_pLink = new CNode;
    pCurrPtr = pTailPtr->m_pLink;
    pCurrPtr->m_nData = 3;
    pCurrPtr->m_pLink = 0;
    pTailPtr = pCurrPtr;
    
    pCurrPtr = pHeadPtr;
    while (pCurrPtr != 0) {
        pDeleteThisNode = pCurrPtr;
        cout << pCurrPtr->m_nData;
        pCurrPtr = pCurrPtr->m_pLink;
        delete pDeleteThisNode;
    }
}
