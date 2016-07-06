#include <iostream>
using namespace std;

template <typename T>
class Stack {
    public:
        Stack(int = 10);
        ~Stack() { delete [] stackPtr; }
        int push(const T&);
        int pop(T &item);
        int isEmpty() const { return top == -1; }
        int isFull() const { return top == size - 1; }
    private:
        int size;
        int top;
        T* stackPtr;
};

template <class T>
Stack<T>::Stack(int s)
{
    size = s > 0 && s < 1000 ? s : 10;
    top = -1;
    stackPtr = new T[size];
}

template <class T>
int Stack<T>::push(const T& item)
{
    if (!isFull()) {
        stackPtr[++top] = item;
        return 1;
    }
    return 0;
}

template <class T>
int Stack<T>::pop(T& popValue)
{
    if (!isEmpty()) {
        popValue = stackPtr[top--];
        return 1;
    }
    return 0;
}

int main()
{
    Stack<float> fs(5);
    cout << "Pushing elements onto fs" << endl;
    float f = 1.1;
    while (fs.push(f)) {
        cout << f << ' ';
        f += 1.1;
    }
    cout << endl << "Stack Full." << endl << "Pop from fs" << endl;
    while (fs.pop(f)) cout << f << ' ';
    cout << endl << "Stack Empty" << endl << endl;
    Stack<int> is;
    cout << "Pushing elements onto is" << endl;
    for (int i = 1; (is.push(i)); i++) cout << i << ' ';
    cout << endl << "Stack Full." << endl << "Pop from is" << endl;
    int i = 0;
    while (is.pop(i)) cout << i << ' ';
    cout << endl << "Stack Empty" << endl;
}
