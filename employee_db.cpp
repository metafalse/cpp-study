/* author: Rei Iwatsuki */
/* compiler: Apple LLVM version 7.0.0 (clang-700.1.76) */
/* os: Mac OS X 10.10.5 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <typeinfo>

using namespace std;

#define CAPACITY 16 // Max count of employees

// An Employee as a node in the link list
class Employee {
    public:
        Employee();
        char name[21];
        char age[3];
        char salary[6];
        Employee *link; // Link to next employee node
};

class Database {
    private:
        void Sort(Employee[], int count);
        void Header();
        void Line(Employee *, int);
        void Add();
        void Delete();
        void Search();
        void List();
        int  Save();
        void Exit();
        int  count;
    public:
        Database();
        void Load(ifstream *);
        void Prompt();
        Employee *top; // An employee node in front of the link list
};

Employee::Employee()
{
    link = 0;
}

Database::Database()
{
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "Specify input file" << endl;
        return 1;
    }

    ifstream InFile(argv[1]);

    if (!InFile) {
        cout << "Cannot open input file" << endl;
        return 1;
    }

    Database db;
    db.Load(&InFile);
    db.Prompt();

    return 0;
}

// Load an employee data from an input file into the link list 
void Database::Load(ifstream *InFile)
{
    // Assign characters in the input file into object Employee one by one
    // If semicolon delimiter is read, next member begins to be read
    Employee *emp = new Employee[CAPACITY];
    char tmpc;
    int i = 0;
    int j = 0;
    enum Mode { NAME, AGE, SALARY };
    Mode mode = NAME;

    while (1) {
        if (i >= CAPACITY) {
            cout << "Number of employees in input file is larger than the capacity" << endl << endl;
            exit(0);
        }

        InFile->get(tmpc);
        if (InFile->eof()) {
            break;
        } else if (mode == NAME) {
            if (tmpc == ';') {
                mode = AGE;
                j = 0;
                continue;
            }
            emp[i].name[j] = tmpc;
        } else if (mode == AGE) {
            if (tmpc == ';') {
                mode = SALARY;
                j = 0;
                continue;
            }
            emp[i].age[j] = tmpc;
        } else if (mode == SALARY) {
            if (tmpc == '\n') {
                mode = NAME;
                j = 0;
                i++;
                continue;
            }
            emp[i].salary[j] = tmpc;
        }
        j++;
    }

    InFile->close();
    Sort(emp, i);
    count = i + 1;
}

// Let users choose a function in the menu  
void Database::Prompt()
{
    int input;
    while (1) {
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. List All Employees" << endl;
        cout << "5. Save Employee Database" << endl;
        cout << "6. Exit Employee Database" << endl;
        cout << "Enter Your Choice: ";
        cin >> input;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (cin.eof() || !cin.good()) // Check whether input is invalid
        {
            cout << "Enter appropriate number" << endl << endl;
            continue;
        }

        enum Menu { ADD = 1, DELETE = 2, SEARCH = 3, LIST = 4, SAVE = 5, EXIT = 6 };
        if (input == ADD) {
            Add();
        } else if (input == DELETE) {
            Delete();
        } else if (input == SEARCH) {
            Search();
        } else if (input == LIST) {
            List();
        } else if (input == SAVE) {
            Save();
        } else if (input == EXIT) {
            Exit();
        } else {
            cout << "Enter appropriate number" << endl << endl;
        }
    }
}

// Add an employee into the link list
void Database::Add()
{
    if (count >= CAPACITY) {
        cout << "There are any space to add an employee" << endl << endl;
        return;
    }

    // Prompt user input
    Employee temp;
    string firstName;
    cout << "Enter new employee's first name: ";
    while (1) {
        cin >> firstName;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (strlen(firstName.c_str()) > 9) {
            cout << "Enter up to 9 chars: ";
            continue;
        }
        break;
    }

    string lastName;
    cout << "Enter new employee's last name: ";
    while (1) {
        cin >> lastName;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (strlen(lastName.c_str()) > 9) {
            cout << "Enter up to 9 chars: ";
            continue;
        }
        break;
    }

    string test = firstName + " " + lastName;
    strcpy(temp.name, test.c_str());

    string age;
    cout << "Enter new employee's age: ";
    while (1) {
        cin >> age;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (strlen(age.c_str()) > 2) {
            cout << "Enter up to 99: ";
            continue;
        }
        bool isDigit = true;
        for (int i = 0; i < strlen(age.c_str()); i++) {
            if (!isdigit(age[i])) isDigit = false;
        }
        if (isDigit == true) {
            strcpy(temp.age, age.c_str());
            break;
        }
        cout << "Enter digit: ";
    }

    string salary;
    cout << "Enter new employee's salary: ";
    while (1) {
        cin >> salary;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (strlen(salary.c_str()) > 6) {
            cout << "Enter up to 999,999: ";
            continue;
        }
        bool isDigit = true;
        for (int i = 0; i < strlen(salary.c_str()); i++) {
            if (!isdigit(salary[i])) isDigit = false;
        }
        if (isDigit == true) {
            strcpy(temp.salary, salary.c_str());
            break;
        }
        cout << "Enter digit: ";
    }

    // Assign employees in the link list and new employee into an array of object once
    Employee *emp = new Employee[CAPACITY];
    Employee *curr = top;
    int i = 0;
    while (1) {
        emp[i] = *curr;
        i++;
        if (curr->link == 0) {
            emp[i] = temp;
            break;
        }
        curr = curr->link;
    }

    // Sort the array and assign it into the link list
    Sort(emp, i);
    cout << endl;
    count++;
}

// Delete an employee in the link list
void Database::Delete()
{
    uint input;
    cout << "Enter employee no: ";
    cin >> dec >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    Employee *curr = top;
    int no = 1;
    while (1) {
        if (input - 1 == no) {
            // Skip the employee node to be deleted
            if (curr->link->link == 0) {
                curr->link = 0;
            } else {
                curr->link = curr->link->link;
            }
            break;
        }
        if (curr->link == 0) {
            cout << "Employee no not found" << endl;
            break;
        }
        no++;
        curr = curr->link;
    }
    cout << endl;
}

// Search employees from the link list
void Database::Search()
{
    cout << "Enter employee's' first or last name: ";
    string query;
    while (1) {
        cin >> query;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (strlen(query.c_str()) > 9) {
            cout << "Enter up to 9 chars: ";
            continue;
        }
        break;
    }

    Header();
    Employee *curr = top;
    int no = 1;
    bool noResult = true;
    while (1) {
        if (strstr(curr->name, query.c_str())) {
            Line(curr, no);
            noResult = false;
        }
        if (curr->link == 0) break;
        no++;
        curr = curr->link;
    }
    if (noResult) cout << "No result" << endl;
    cout << endl;
}

// Display all employees from the link list 
void Database::List()
{
    Header();
    Employee *curr = top;
    int no = 1;
    while (1) {
        Line(curr, no);
        if (curr->link == 0) break;
        no++;
        curr = curr->link;
    }
    cout << endl;
}

// Save all employee data into a file
int Database::Save()
{
    ofstream OutFile("output.txt");

    if (!OutFile) {
        cout << "Cannot open output file.\n";
        return 1;
    }
    
    Employee *curr = top;
    while (1) {
        OutFile << curr->name << ';' << curr->age << ';' << curr->salary;
        if (curr->link == 0) break;
        OutFile << endl;
        curr = curr->link;
    }

    cout << endl;
    OutFile.close();

    return 0;
}

// Exit from this program
void Database::Exit()
{
    char input;
    while (1) {
        cout << "Do you want to save into a file? (y/n): " << endl;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        enum YesNo { YES_UPPER = 'Y', YES_LOWER = 'y', NO_UPPER = 'N', NO_LOWER = 'n' };
        if (input == YES_UPPER || input == YES_LOWER) {
            Save();
        } else if (input != NO_UPPER && input != NO_LOWER) {
            cout << "Please enter the appropriate character" << endl;
            continue;
        }
        exit(0);
    }
}

// Sort employees by their name and assign them into the link list
void Database::Sort(Employee emp[], int count)
{
    // Bubble Sort
    for (int i = count; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcasecmp(emp[j].name, emp[j+1].name) > 0)
            {
                Employee temp = emp[j+1];
                emp[j+1] = emp[j];
                emp[j] = temp;
            }
        }
    }

    // Assign the sorted list into the link list
    for (int i = 0; i < count; i++) {
        emp[i].link = &emp[i+1];
    }
    top = &emp[0];
}

// Display the header of the employee list
void Database::Header()
{
    cout << "# Employee Name          Age         Salary" << endl;
    cout << "=============================================" << endl;    
}

// Display each line of the employee list
void Database::Line(Employee *curr, int no)
{
    cout << no << ". ";

    if (no < 10) { // Arrange width
        cout << setfill(' ') << setw(22) << left << curr->name;
    } else {
        cout << setfill(' ') << setw(21) << left << curr->name;            
    }

    cout << setfill(' ') << setw(11) << left << curr->age << ' ';

    // Display salary using comma
    int digits = sizeof(curr->salary);
    for (int i = sizeof(curr->salary) - 1; !isdigit(curr->salary[i]); i--) {
        digits--;
    }
    for (int i = 0; i < digits; i++) {
        if (i != 0 && (digits - i) % 3 == 0) cout << ',';
        cout << curr->salary[i];
    }
    cout << endl;
}
