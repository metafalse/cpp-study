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
    
    private:
    public:
        Space();
        int value;
        Space *link;
};

class Stack {
    
    private:
    public:
        Stack();
        Space *head;
        Space *tail;
};

class Parking {
    
    private:
        int currNo;
        int vacancy;
    public:
        Parking();
        void Exec();
        void Display();
        void Park();
        void Retrieve();
        Stack *a;
        Stack *b;
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
    tail = new Space;
}

Parking::Parking()
{
    currNo = 0;
    vacancy = STACK_SIZE;
}

void Parking::Exec()
{
    a = new Stack;
    b = new Stack;
    
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
    if (!a->tail->value)
    {
        cout << "CAR NOT PARKED IN MY LOT" << "\n";
        return;
    }
    cout << "Alley A:";
    Space *c;
    c = a->tail;
    while (c->value != 0)
    {
        cout << c->value << "\t";
        //cout << "\nc-link: " << c->link << "\n  ";
        c = c->link;
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
    currNo++;
    vacancy--;
    a->head = new Space;
    //cout << "Ticket no. = " << currNo << "\n";
    a->head->value = currNo;
    //cout << "head->value = " << head->value << "\n";
    a->head->link = a->tail;
    //cout << "head->link = " << head->link << "\n";
    a->tail = a->head;
    //cout << "head->link = " << head->link << "\n";
}

void Parking::Retrieve()
{
    cout << "Ticket no. : ";
    int retrieveNo;
    cin >> dec >> retrieveNo;
    
    while (1)
    {
        if (a->tail->value == retrieveNo)
        {
            Space *c;
            c = a->tail;
            a->tail = a->tail->link;
            delete c;
            vacancy++;
            break;
        }
        else if (a->tail->value == 0)
        {
            cout << "CAR NOT PARKED IN MY LOT" << "\n";
            break;            
        }
        else
        {
            b->head = new Space;
            b->head->value = a->tail->value;
            b->head->link = b->tail;
            b->tail = b->head;
            Space *c;
            c = a->tail;
            a->tail = a->tail->link;
            delete c;
            //cout << "tail->value" << tail->value << "\n";
            //cout << "b->tail->value" << b->tail->value << "\n";
        }
    }
    
    while (b->tail->value != 0)
    {
        a->head = new Space;
        a->head->value = b->tail->value;
        a->head->link = a->tail;
        a->tail = a->head;
        Space *c;
        c = b->tail;
        b->tail = b->tail->link;
        delete c;
        //cout << "tail->link" << tail->link << "\n";
        //cout << "tail->value" << tail->value << "\n";
        //cout << "b->tail->value" << b->tail->value << "\n";
    }
}
