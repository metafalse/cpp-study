/* author: Rei Iwatsuki */
/* Apple LLVM version 7.0.0 (clang-700.1.76) */

#include <iostream>
#include <iomanip>

using namespace std;

enum Input {
    DISPLAY_LOWER  = 'd', DISPLAY_UPPER  = 'D',
    PARK_LOWER     = 'p', PARK_UPPER     = 'P',
    RETRIEVE_LOWER = 'r', RETRIEVE_UPPER = 'R',
    QUIT_LOWER     = 'q', QUIT_UPPER     = 'Q',
};

#define STACK_SIZE 5

class Space {
    public:
        Space();
        int value;
        Space *link;
};

class Stack {
    public:
        Stack();
        void Shift();
        Space *top;
};

class Parking {
    private:
        int ticketNo;
        int vacancy;
        void MoveBetweenStacks(Stack &, Stack &);
    public:
        Parking();
        void Exec();
        void Display();
        void Park();
        void Retrieve();
        Stack a;
        Stack b;
};

int main()
{
    Parking p;
    p.Exec();
}

Space::Space()
{
    value = 0;
}

Stack::Stack()
{
    top = new Space;
}

Parking::Parking()
{
    ticketNo = 0;
    vacancy = STACK_SIZE;
}

void Parking::Exec()
{    
    char input;
    do {
        cout << "D) isplay\tP) ark\tR) etrieve\tQ) uit: ";
        cin >> input;
        if (cin.eof() || !cin.good())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            exit(0);
        }
        
        if (input == DISPLAY_LOWER || input == DISPLAY_UPPER)
        {
            Display();
        }
        else if (input == PARK_LOWER || input == PARK_UPPER)
        {
            Park();
        }
        else if (input == RETRIEVE_LOWER || input == RETRIEVE_UPPER)
        {
            Retrieve();
        }
    } while (input != QUIT_LOWER && input != QUIT_UPPER);
}

void Parking::Display()
{
    if (a.top->value == 0)
    {
        cout << "CAR NOT PARKED IN MY LOT\n";
        return;
    }
    
    cout << "Alley A:";
    Space *curr;
    curr = a.top;
    while (curr->value != 0)
    {
        cout << curr->value << "\t";
        curr = curr->link;
    }
    cout << "\n";
}

void Parking::Park()
{
    if (vacancy == 0)
    {
        cout << "My Lot is Full\n";
        return;
    }
    
    ticketNo++;
    vacancy--;
    Space *fresh = new Space;
    fresh->value = ticketNo;
    fresh->link = a.top;
    a.top = fresh;
}

void Parking::Retrieve()
{
    if (vacancy == STACK_SIZE)
    {
        cout << "Lot is Empty, No cars to Retrieve\n";
        return;
    }
    
    cout << "Ticket no. : ";
    int retrieveNo;
    cin >> dec >> retrieveNo;
    
    while (1)
    {
        if (a.top->value == 0)
        {
            cout << "CAR NOT PARKED IN MY LOT\n";
            break;            
        }
        else if (a.top->value == retrieveNo)
        {
            a.Shift();
            vacancy++;
            break;
        }
        else
        {
            MoveBetweenStacks(a, b);
            a.Shift();
        }
    }
    
    while (b.top->value != 0)
    {
        MoveBetweenStacks(b, a);
        b.Shift();
    }
}

void Parking::MoveBetweenStacks(Stack& from, Stack& to)
{
    Space *fresh = new Space;
    fresh->value = from.top->value;
    fresh->link = to.top;
    to.top = fresh;
}

void Stack::Shift()
{
    Space *trash;
    trash = top;
    top = top->link;
    delete trash;
}
