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

class Employee {
    private:
    public:
        Employee();
        char name[20];
        char age[3];
        char salary[6];
        Employee *link;
};

class Database {
    private:
    public:
        Database();
        void Add();
        void Delete();
        void Search();
        void List();
        int Save();
        void Exit();
        void Header();
        void Line(Employee *, int);
        void Sort(Employee[], int count);
        
        Employee *top;
};

Employee::Employee()
{
    link = 0;
}

Database::Database()
{
}

void Database::Sort(Employee emp[], int count)
{
    // Bubble Sort
    while (count > 0) {
        for (int i = 0; i < count; i++) {
            if (strcmp(emp[i].name, emp[i+1].name) > 0)
            {
                Employee temp = emp[i+1];
                emp[i+1] = emp[i];
                emp[i] = temp;
            }
        }
        count--;
    }
}

void Database::Add()
{
    Employee temp;
    char firstName[10];
    cout << "Enter Employee First Name: ";
    cin >> firstName;
    char lastName[10];
    cout << "Enter Employee Last Name: ";
    cin >> lastName;
    strcpy(temp.name, strcat(strcat(firstName, " "), lastName));
    char age[3];
    cout << "Enter Employee Age: ";
    cin >> temp.age;
    char salary[6];
    cout << "Enter Employee Salary: ";
    cin >> temp.salary;

    Employee *curr = top;
    Employee *emp = new Employee[16];
    int empno = 0;
    while (1) {
        emp[empno] = *curr;
        empno++;
        if (curr->link != 0) {
            curr = curr->link;
        } else {
            emp[empno] = temp;
            break;
        }       
    }

    Sort(emp, empno);

    for (int i = 0; i <= empno-1; i++) {
        emp[i].link = &emp[i+1];
    }
    top = &emp[0];

    cout << endl;
}

void Database::Delete()
{
    char input;
    cout << "Enter Employee No or C) ancel: ";
    cin >> input;
    if (input == 'C' || input == 'c') return;

    Employee *curr = top;
    int no = 1;
    while (1) {
        if (atoi(&input) - 1 == no && curr->link->link != 0) {
            curr->link = curr->link->link;
            break;
        }
        no++;
        if (curr->link != 0) {
            curr = curr->link;
        } else {
            cout << "Employee No Not Found" << endl;
            break;
        }       
    }
}

void Database::Header()
{
    cout << "# Employee Name          Age         Salary" << endl;
    cout << "=============================================" << endl;    
}

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

void Database::Search()
{
    char query[10];
    cout << "Enter Employee First Name or Last Name: ";
    cin >> query;

    Header();
    Employee *curr = top;
    int no = 1;
    bool noResult = true;
    while (1) {
        if (strstr(curr->name, query)) {
            Line(curr, no);
            noResult = false;
        }
        no++;
        if (curr->link != 0) {
            curr = curr->link;
        } else {
            break;
        }       
    }
    if (noResult) cout << "No Result" << endl;
    cout << endl;
}

void Database::List()
{
    Header();
    Employee *curr = top;
    int no = 1;
    while (1) {
        Line(curr, no);
        no++;
        if (curr->link != 0) {
            curr = curr->link;
        } else {
            break;
        }
    }
    cout << endl;
}

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
        if (curr->link != 0) {
            OutFile << endl;
            curr = curr->link;
        } else {
            break;
        }       
    }

    OutFile.close();

    return 0;
}

void Database::Exit()
{
    char input;
    while (1) {
        cout << "Do you want to save into a file? (y/n): " << endl;
        cin >> input;

        if (input == YES_UPPER || input == YES_LOWER) {
            Save();
        } else if (input != NO_UPPER && input != NO_LOWER) {
            cout << "Please enter the appropriate character" << endl;
            continue;
        }
        exit(0);
    }
}

//int main(int argc, char *argv[])
int main()
{
    //if (argc != 2) {
    //    cout << "Usage: PR <filename>\n";
    //    return 1;
    //}
    //ifstream InFile(argv[1]);
    ifstream InFile("input.txt");

    if (!InFile) {
        cout << "Cannot open input file.\n";
        return 1;
    }

    Employee *emp = new Employee[16];
    char tmpc;
    Mode mode = NAME;

    int empno = 0;
    int pos = 0;
    while (1) {
        InFile.get(tmpc);
        if (InFile.eof()) {
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

    InFile.close();

    Database db;

    db.Sort(emp, empno);

    for (int i = 0; i <= empno-1; i++) {
        emp[i].link = &emp[i+1];
    }

    db.top = &emp[0];
    
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
        
        if (input == ADD) {
            db.Add();
        } else if (input == DELETE) {
            db.Delete();
        } else if (input == SEARCH) {
            db.Search();
        } else if (input == LIST) {
            db.List();
        } else if (input == SAVE) {
            db.Save();
        } else if (input == EXIT) {
            db.Exit();
        }
    }

    return 0;
}
