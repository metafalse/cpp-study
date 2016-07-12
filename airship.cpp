/* author: Rei Iwatsuki */
/* compiler: Apple LLVM version 7.0.0 (clang-700.1.76) */
/* os: Mac OS X 10.10.5 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

enum AirShipType { AIRPLANE = 0, BALLOON = 1 };
enum EngineType { JET = 0, PROPELLER = 1 };
enum GasType { HELIUM = 0, HYDROGEN = 1 };

// A general base class
class Airship {
    public:
        virtual ~Airship();
        AirShipType airshipType;
        char maxPassengerCount[4];
        char maxCargoWeight[7];
        virtual char *GetName() = 0;
        virtual void SetName(char, int) = 0;
        virtual uint GetPowerSourceType() = 0;
        virtual void SetPowerSourceType(uint) = 0;
        virtual char *GetLength() = 0;
        virtual void SetLength(char, int) = 0;
};

class Airplane : public Airship {
    public:
        ~Airplane();
        char airplaneName[20];
        EngineType engineType;
        char maxRange[7];
        char *GetName();
        void SetName(char, int);
        // PowerSourceType of Airplene is engineType
        uint GetPowerSourceType();
        void SetPowerSourceType(uint);
        // Length of Airplane is maxRange
        char *GetLength();
        void SetLength(char, int);
};

class Balloon : public Airship {
    public:
        ~Balloon();
        char balloonName[20];
        GasType gasType;
        char maxAltitude[7];
        char *GetName();
        void SetName(char, int);
        // PowerSourceType of Balloon is gasType
        uint GetPowerSourceType();
        void SetPowerSourceType(uint);
        // Length of Balloon is maxAltitude
        char *GetLength();
        void SetLength(char, int);
};

class Program {
    public:
        Program();
        Airship *as[10];
        void Load(ifstream *);
        void Report();
};

Airship::~Airship()
{
}

Airplane::~Airplane()
{
}

Balloon::~Balloon()
{
}

char *Airplane::GetName()
{
    return airplaneName;
}

void Airplane::SetName(char c, int pos)
{
    airplaneName[pos] = c;
}

char *Balloon::GetName()
{
    return balloonName;
}

void Balloon::SetName(char c, int pos)
{
    balloonName[pos] = c;
}

uint Airplane::GetPowerSourceType()
{
    if (engineType == JET) {
        return 0;
    } else if (engineType == PROPELLER) {
        return 1;
    }
    return 0;
}

void Airplane::SetPowerSourceType(uint type)
{
    if (type == 0) {
        engineType = JET;
    } else if (type == 1) {
        engineType = PROPELLER;
    }
}

uint Balloon::GetPowerSourceType()
{
    if (gasType == HELIUM) {
        return 0;
    } else if (gasType == HYDROGEN) {
        return 1;
    }
    return 0;
}

void Balloon::SetPowerSourceType(uint type)
{
    if (type == 0) {
        gasType = HELIUM;
    } else if (type == 1) {
        gasType = HYDROGEN;
    }
}

char *Airplane::GetLength()
{
    return maxRange;
}

void Airplane::SetLength(char c, int pos)
{
    maxRange[pos] = c;
}

char *Balloon::GetLength()
{
    return maxAltitude;
}

void Balloon::SetLength(char c, int pos)
{
    maxAltitude[pos] = c;
}

Program::Program()
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

    Program pg;
    pg.Load(&InFile);
    pg.Report();

    return 0;
}

// Load an airship data from an input file into an array 
void Program::Load(ifstream *InFile)
{
    // Assign characters in the input file into an object derived from Class Airship one by one
    // If comma delimiter is read, next member begins to be read
    char tmpc;
    int i = 0;
    int j = 0;
    enum Mode { AIRSHIP_TYPE, AIRSHIP_NAME, NUMBER_OF_PASSENGERS,
     AMOUNT_OF_CARGO, ENGINE_GAS_TYPE, MAX_RANGE_ALTITUDE };
    Mode mode = AIRSHIP_TYPE;
    
    while (1) {
        InFile->get(tmpc); // get a character

        if (InFile->eof()) {
            break;
        }

        switch (mode) {
            case AIRSHIP_TYPE:
                if (tmpc == ',') {
                    mode = AIRSHIP_NAME;
                    continue;
                }
                // The first field in each line of input determines
                // whether the line describes an airplane or a balloon
                if (tmpc == '0') {
                    as[i] = new Airplane;
                    as[i]->airshipType = AIRPLANE;
                } else if (tmpc == '1') {
                    as[i] = new Balloon;
                    as[i]->airshipType = BALLOON;
                }
                break;
            case AIRSHIP_NAME:
                if (tmpc == ',') {
                    mode = NUMBER_OF_PASSENGERS;
                    j = 0;
                    continue;
                }
                as[i]->SetName(tmpc, j);
                j++;
                break;
            case NUMBER_OF_PASSENGERS:
                if (tmpc == ',') {
                    mode = AMOUNT_OF_CARGO;
                    j = 0;
                    continue;
                }
                as[i]->maxPassengerCount[j] = tmpc;
                j++;
                break;
            case AMOUNT_OF_CARGO:
                if (tmpc == ',') {
                    mode = ENGINE_GAS_TYPE;
                    j = 0;
                    continue;
                }
                as[i]->maxCargoWeight[j] = tmpc;
                j++;
                break;
            case ENGINE_GAS_TYPE:
                if (tmpc == ',') {
                    mode = MAX_RANGE_ALTITUDE;
                    continue;
                }
                as[i]->SetPowerSourceType(atoi(&tmpc));
                break;
            case MAX_RANGE_ALTITUDE:
                if (tmpc == '\n') { // End of line
                    mode = AIRSHIP_TYPE;
                    j = 0;
                    i++; // Go to next line
                    continue;
                }
                as[i]->SetLength(tmpc, j);
                j++;
                break;
        }
    }
}

// Once display a listing of airplanes and display balloons later
void Program::Report()
{
    // Iterate through the array and display airplanes only
    cout << "Listing of all Airplanes" << endl;
    cout << "Name                Engine Type     Maximum Range" << endl;
    cout << "------------------------------------------------" << endl;
    string engineType;
    for (int i = 0; i < 10; i++) {
        if (as[i]->airshipType != 0) continue; // If it is not an airplane
        cout << setfill(' ') << setw(20) << left << as[i]->GetName();
        if (as[i]->GetPowerSourceType() == 0) {
            engineType = "Jet";
        } else if (as[i]->GetPowerSourceType() == 1) {
            engineType = "Propeller";
        }
        cout << setfill(' ') << setw(16) << left << engineType;
        cout << setfill(' ') << setw(12) << left << as[i]->GetLength();
        cout << endl;
    }
    cout << endl;

    // Iterate through the array and display balloons only
    cout << "Listing of all Balloons" << endl;
    cout << "Name                Gas Type        Maximum Altitude" << endl;
    cout << "----------------------------------------------------" << endl;
    string gasType;
    for (int i = 0; i < 10; i++) {
        if (as[i]->airshipType != 1) continue; // If it is not a balloon
        cout << setfill(' ') << setw(20) << left << as[i]->GetName();
        if (as[i]->GetPowerSourceType() == 0) {
            gasType = "Helium";
        } else if (as[i]->GetPowerSourceType() == 1) {
            gasType = "Hydrogen";
        }
        cout << setfill(' ') << setw(16) << left << gasType;
        cout << setfill(' ') << setw(12) << left << as[i]->GetLength();
        cout << endl;
    }

    for (int i = 0; i < 10; i++) {
        delete as[i];
    }
}
