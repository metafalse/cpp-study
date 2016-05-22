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

class Parking {
    
    private:
        int currNo;
        int vacancy;
    public:
        Parking();
        void Sub();
        void Display();
        void Park();
        void Retrieve();
        void Quit();
        int value;
        Parking *b;
        Parking *link;
        Parking *head;
        Parking *tail;
};

int main()
{
    Parking p;
    p.Sub();
}

void Parking::Sub()
{
    Parking *p;
    tail = new Parking;
    tail->value = 0;
    b = new Parking;
    b->tail = new Parking;
    b->tail->value = 0;
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

Parking::Parking()
{
    currNo = 0;
    vacancy = STACK_SIZE;
}

void Parking::Display()
{
    if (!tail->value)
    {
        cout << "CAR NOT PARKED IN MY LOT" << "\n";
        return;
    }
    cout << "Alley A:";
    Parking *c;
    c = tail;
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
    head = new Parking;
    //cout << "Ticket no. = " << currNo << "\n";
    head->value = currNo;
    //cout << "head->value = " << head->value << "\n";
    head->link = tail;
    //cout << "head->link = " << head->link << "\n";
    tail = head;
    //cout << "head->link = " << head->link << "\n";
}

void Parking::Retrieve()
{
    cout << "Ticket no. : ";
    int retrieveNo;
    cin >> dec >> retrieveNo;
    while (1)
    {
        if (tail->value == retrieveNo)
        {
            cout << "hit: " << tail->value << "\n";
            Parking *c;
            c = tail;
            tail = tail->link;
            delete c;
            vacancy++;
            break;
        }
        else if (tail->value == 0)
        {
            cout << "CAR NOT PARKED IN MY LOT" << "\n";
            break;            
        }
        else
        {
            b->head = new Parking;
            b->head->value = tail->value;
            b->head->link = b->tail;
            b->tail = b->head;
            Parking *c;
            c = tail;
            tail = tail->link;
            delete c;
            //cout << "tail->value" << tail->value << "\n";
            //cout << "b->tail->value" << b->tail->value << "\n";
        }
    }
    while (b->tail->value != 0)
    {
        head = new Parking;
        head->value = b->tail->value;
        head->link = tail;
        tail = head;
        Parking *c;
        c = b->tail;
        b->tail = b->tail->link;
        delete c;
        //cout << "tail->link" << tail->link << "\n";
        //cout << "tail->value" << tail->value << "\n";
        //cout << "b->tail->value" << b->tail->value << "\n";
    }
}

void Parking::Quit()
{
    
}
