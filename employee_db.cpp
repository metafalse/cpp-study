/* author: Rei Iwatsuki */
/* compiler: Apple LLVM version 7.0.0 (clang-700.1.76) */
/* os: Mac OS X 10.10.5 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <typeinfo>

using namespace std;

enum Mode { NAME, AGE, SALARY };
enum Menu { ADD = 1, DELETE = 2, SEARCH = 3, LIST = 4, SAVE = 5, EXIT = 6 };
enum YesNo { YES_UPPER = 'Y', YES_LOWER = 'y', NO_UPPER = 'N', NO_LOWER = 'n' };

// An Employee as a node in the link list
class Employee {
    public:
        Employee();
        char name[21];
        char age[3];
        char salary[6];
        Employee *link;
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
        int Save();
        void Exit();
    public:
        Database();
        void Load(ifstream *);
        void Prompt();
        Employee *top;
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
        cout << "Specify input file." << endl;
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

void Database::Load(ifstream *InFile)
{
    Employee *emp = new Employee[16];
    char tmpc;
    Mode mode = NAME;

    int empno = 0;
    int pos = 0;
    while (1) {
        InFile->get(tmpc);
        if (InFile->eof()) {
            break;
        } else if (mode == NAME) {
            if (tmpc == ';') {
                mode = AGE;
                pos = 0;
                continue;
            }
            emp[empno].name[pos] = tmpc;
        } else if (mode == AGE) {
            if (tmpc == ';') {
                mode = SALARY;
                pos = 0;
                continue;
            }
            emp[empno].age[pos] = tmpc;
        } else if (mode == SALARY) {
            if (tmpc == '\n') {
                mode = NAME;
                pos = 0;
                empno++;
                continue;
            }
            emp[empno].salary[pos] = tmpc;
        }
        pos++;
    }

    InFile->close();

    Sort(emp, empno);
}

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
            cout << "Enter appropriate number." << endl << endl;
            continue;
        }
        
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
            cout << "Enter appropriate number." << endl << endl;
        }
    }
}

// Add an employee into the link list
void Database::Add()
{
    Employee temp;
    char firstName[10];
    cout << "Enter Employee First Name (up to 9 chars): ";
    cin >> setw(10) >> firstName;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');            
    char lastName[10];
    cout << "Enter Employee Last Name (up to 9 chars): ";
    cin >> setw(10) >> lastName;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');            
    strcpy(temp.name, strcat(strcat(firstName, " "), lastName));
    char age[3];
    cout << "Enter Employee Age: ";
    cin >> setw(3) >> dec >> temp.age;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');            
    char salary[7];
    cout << "Enter Employee Salary: ";
    cin >> setw(7) >> dec >> temp.salary;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');            

    Employee *emp = new Employee[16];
    Employee *curr = top;
    int empno = 0;
    while (1) {
        emp[empno] = *curr;
        empno++;
        if (curr->link == 0) {
            emp[empno] = temp;
            break;
        }
        curr = curr->link;
    }

    Sort(emp, empno);

    cout << endl;
}

// Delete an employee in the link list
void Database::Delete()
{
    uint input;
    cout << "Enter Employee No: ";
    cin >> dec >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    Employee *curr = top;
    int no = 1;
    while (1) {
        if (input - 1 == no) {
            if (curr->link->link == 0) {
                curr->link = 0;
            } else {
                curr->link = curr->link->link;
            }
            break;
        }
        if (curr->link == 0) {
            cout << "Employee No Not Found" << endl;
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
    char query[11];
    while (1) {
        cout << "Enter Employee First Name or Last Name: ";
        cin >> setw(11) >> query;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (cin.eof() || !cin.good()) // Check if input is invalid
        {
            cout << "Enter up to 10 charcters." << endl << endl;
            continue;
        }
        break;
    }

    Header();
    Employee *curr = top;
    int no = 1;
    bool noResult = true;
    while (1) {
        if (strstr(curr->name, query)) {
            Line(curr, no);
            noResult = false;
        }
        if (curr->link == 0) break;
        no++;
        curr = curr->link;
    }
    if (noResult) cout << "No Result" << endl;
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
            if (strcmp(emp[j].name, emp[j+1].name) > 0)
            {
                Employee temp = emp[j+1];
                emp[j+1] = emp[j];
                emp[j] = temp;
            }
        }
    }

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
    if (no < 10) {
        cout << setfill(' ') << setw(22) << left << curr->name;
    } else {
        cout << setfill(' ') << setw(21) << left << curr->name;            
    }
    cout << setfill(' ') << setw(11) << left << curr->age << ' ';
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
