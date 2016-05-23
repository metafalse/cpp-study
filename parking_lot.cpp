/* author: Rei Iwatsuki */
/* Apple LLVM version 7.0.0 (clang-700.1.76) */

#include <iostream>
#include <iomanip>

using namespace std;

enum Input {
    DISPLAY_LOWER  = 'd', DISPLAY_UPPER  = 'D', // D) isplay
    PARK_LOWER     = 'p', PARK_UPPER     = 'P', // P) ark
    RETRIEVE_LOWER = 'r', RETRIEVE_UPPER = 'R', // R) etrieve
    QUIT_LOWER     = 'q', QUIT_UPPER     = 'Q', // Q) uit
};

#define STACK_SIZE 5 // Each Alley(Stack) accomodate five cars

// An space accomodate one car in stack that is node of link list as well
class Space {
    public:
        Space();
        int ticketNo; // Ticket no. of the a car parked in this space
        Space *link; // Link to next node of inner space in a stack
};

// An alley that accomodate five car as a stack that have five spaces
class Stack {
    public:
        Stack();
        void Shift();
        Space *top; // Space in front of this stack
};

class Parking {
    private:
        int nextTicketNo; // Ticket no. for next parking
        int vacancy; // How many spaces there are currently in Alley A  
        void MoveBetweenStacks(Stack &, Stack &);
    public:
        Parking();
        void Exec();
        void Display();
        void Park();
        void Retrieve();
        Stack a; // Alley A
        Stack b; // Alley B
};

Space::Space()
{
    ticketNo = 0;
}

Stack::Stack()
{
    top = new Space;
}

Parking::Parking()
{
    nextTicketNo = 1;
    vacancy = STACK_SIZE;
}

int main()
{
    Parking p;
    p.Exec();
}

void Parking::Exec()
{    
    char input;
    do {
        // Prompt user input
        cout << "D) isplay\tP) ark\tR) etrieve\tQ) uit: ";
        cin >> input;
        if (cin.eof() || !cin.good()) // Check if input is invalid
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
        else
        {
            cout << "Please enter the appropriate character\n";
        }
    } while (input != QUIT_LOWER && input != QUIT_UPPER); // Repeat until quit
}

// Display the contents of Alley A
void Parking::Display()
{
    // When there are no cars in Alley A
    if (a.top->ticketNo == 0)
    {
        cout << "CAR NOT PARKED IN MY LOT\n";
        return;
    }
    
    // Display all cars in Alley A
    cout << "Alley A:\t";
    Space *curr;
    curr = a.top;
    while (curr->ticketNo != 0) // Repeat until there are no cars anymore inner side
    {
        cout << curr->ticketNo << "\t";
        curr = curr->link; // See next node inner side
    }
    cout << "\n";
}

// Park a car
void Parking::Park()
{
    // If there are no space in Alley A anymore
    if (vacancy == 0)
    {
        cout << "My Lot is Full\n";
        return;
    }
    
    // Push new node to Alley A
    Space *fresh = new Space;
    fresh->ticketNo = nextTicketNo;
    fresh->link = a.top;
    a.top = fresh;
    
    cout << "Ticket no. = " << a.top->ticketNo << "\n";
    vacancy--;
    nextTicketNo++;
}

// Retrieve a car
void Parking::Retrieve()
{
    // If there are no cars in Alley A
    if (vacancy == STACK_SIZE)
    {
        cout << "Lot is Empty, No cars to Retrieve\n";
        return;
    }
    
    // Prompt user input ticket no. of the car user want to retrieve
    cout << "Ticket no. : ";
    int retrieveNo;
    cin >> dec >> retrieveNo;
    
    while (1) // Repeat until break
    {
        // If the car user want to retrieve is not found after checking all cars in Alley A 
        if (a.top->ticketNo == 0)
        {
            cout << "CAR NOT PARKED IN MY LOT\n";
            break;            
        }
        // If the car user want to retrieve is found
        else if (a.top->ticketNo == retrieveNo)
        {
            a.Shift();
            vacancy++;
            break;
        }
        // Pull a car from Alley A and push it into Alley B
        else
        {
            MoveBetweenStacks(a, b);
            a.Shift();
        }
    }
    
    // After the retrieve completes, put all cars from Alley B into Alley A
    while (b.top->ticketNo != 0)
    {
        MoveBetweenStacks(b, a);
        b.Shift();
    }
}

// Move a car in front of 'from' Stack into in front of 'to' Stack
void Parking::MoveBetweenStacks(Stack& from, Stack& to)
{
    Space *fresh = new Space;
    fresh->ticketNo = from.top->ticketNo;
    fresh->link = to.top;
    to.top = fresh;
}

// Shift all contents of this alley outside once
void Stack::Shift()
{
    Space *trash;
    trash = top;
    top = top->link;
    delete trash;
}
