#include <iostream>
#include <string>

using namespace std;

class CString {
    public:
        CString(char *pcStr);
        ~CString();
        void Show();
    private:
        char *m_pcStr;
        int m_nLen;
};

int main() {
    CString s1("This is a test"), s2("I like C++");
    s1.Show();
    s2.Show();
}

CString::CString(char *pcStr) {
    m_nLen = strlen(pcStr);
    m_pcStr = new char[m_nLen+1];
    strcpy(m_pcStr, pcStr);
}

CString::~CString() {
    cout << "Freeing p\n";
    if (m_pcStr) delete m_pcStr;
}

void CString::Show() {
    cout << m_pcStr << " - length: " << m_nLen;
    cout << "\n";
}
