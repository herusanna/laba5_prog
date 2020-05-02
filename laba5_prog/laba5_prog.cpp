/*5 variant*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include<string.h>
using namespace std;
struct data
{
    int day;
    int month;
    int year;
    bool isCorrect();
} dat[256];
bool data::isCorrect()
{
    bool result = false;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        if ((day <= 31) && (day > 0))
            result = true;
        break;
    }

    case 4:
    case 6:
    case 9:
    case 11:
    {
        if ((day <= 30) && (day > 0))
            result = true;
        break;
    }
    case 2: {
        if ((day <= 28) && (day > 0))
            result = true;
        break;
    }
    return result;
    }
}
struct name
{
    char F[56];
    char I[32];
    char O[32];
    void setName() {
        ofstream f;
        f.open("D:\\patient.txt", ios::out);

        cout << "\nFirst name : ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(F, 56);

        cout << endl << "Second name : ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(I, 32);

        cin.ignore(cin.rdbuf()->in_avail());
        cout << endl << "Last name : ";
        cin.getline(O, 32);
    }
    void showName(){
        ofstream f;
        f.open("D:\\patient.txt", ios::out);
        cout << "FIO: " << F << " " << I << " " << O << endl;

    }

};
struct adress
{
    int index;
    char country[30];
    char region[30];
    char district[30];
    char city[20];
    char street[20];
    int house;
    int apartment;
    void setAdress() {
        ofstream f;
        f.open("D:\\patient.txt", ios::out);

        cout << endl << "Index: ";
        while (!(cin >> index))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Country:  ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(country, 30);

        cout << endl << "Region: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(region, 30);

        cout << endl << "District: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(district, 30);

        cout << endl << "City: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(city, 20);

        cout << endl << "Street: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(street, 20);

        cout << endl << "House: ";
        while (!(cin >> house))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Apartment: ";
        while (!(cin >> apartment))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }
    }
    void showAdress() {
        ofstream f;
        f.open("D:\\patient.txt", ios::out);

        cout << "Index: " << index << endl;
        cout << "Country: " << country << endl;
        cout << "Region: " << region << endl;
        cout << "District: " << district << endl;
        cout << "City: " << city << endl;
        cout << "Street: " << street << endl;
        cout << "House: " << house << endl;
        cout << "Apartment: " << apartment;
    }
};
struct hospital
{
    int NumHosp;
    int Department;
    int NumCard;
    char Diagnosis[30];
    int BloodType;
    void setHospital()
    {
        ofstream f;
        f.open("D:\\patient.txt", ios::out);

        cout << endl << "Hospital number: ";
        while (!(cin >> NumHosp))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Hospital department: ";
        while (!(cin >> Department))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Medical card number: ";
        while (!(cin >> NumCard))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Patient's diagnosis: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(Diagnosis, 30);

        cout << endl << "Patient's blood type: ";
        while (!(cin >> BloodType))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }
    }
    void showHospital()
    {
        ofstream f;
        f.open("D:\\patient.txt", ios::out);

        cout << endl << "Hospital's number: " << NumHosp;
        cout << endl << "Hospital department: " << Department;
        cout << endl << "Medical card number: " << NumCard;
        cout << endl << "Patient's diagnosis: " << Diagnosis;
        cout << endl << "Patient's blood type: " << BloodType;
    }
};
struct patient
{
    name person;
    adress home;
    hospital Data;
    long Tele;
    char Sex[30];
    char Nationality[30];
    int Height;
    int Weight;
    void setInfo() {
        ofstream f;
        f.open("D:\\patient.txt", ios::out);

        person.setName();
        home.setAdress();
        Data.setHospital();

        cout << endl << "Telephon number: ";
        cin >> Tele;

        cout  <<endl << "Sex: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(Sex, 8);

        cout << endl << "Nationality: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(Nationality, 30);

        cout << endl << "Height: ";
        cin >> Height;

        cout << endl << "Weight: ";
        cin >> Weight;
    }
    void showInfo() {
        ofstream f;
        f.open("D:\\patient.txt", ios::out);

        person.showName();

        cout << "Telephon number: " << Tele << endl;

        home.showAdress();

        Data.showHospital();

        cout<< endl << "Sex: " << Sex << endl;
        cout << "Nationality: " << Nationality << endl;
        cout << "Height: " << Height << endl;
        cout << "Weight:" << Weight << endl;
        
    }
};

void  InitPerson(patient* Man, int* size)
{
    ofstream f;
    f.open("D:\\patient.txt", ios::out);

    for (size_t i = 0; i < *size; i++)
    {
        (Man + i)->setInfo();
    }
}

void sortPerson(patient* Man, int* size) 
{
    ofstream f;
    f.open("D:\\patient.txt", ios::out);

    for (int i = 0; i < *size; i++)
    {
        for (int j = 0; j < *size - 1; j++) {
            if (int((Man + j)->person.F[0]) > int((Man + j + 1)->person.F[0]))
            {
                swap((Man + j)->person, (Man + j + 1)->person);
                swap((Man + j)->Tele, (Man + j + 1)->Tele);
                swap((Man + j)->home, (Man + j + 1)->home);
                swap((Man + j)->Data, (Man + j + 1)->Data);
                swap((Man + j)->Sex, (Man + j + 1)->Sex);
                swap((Man + j)->Nationality, (Man + j + 1)->Nationality);
                swap((Man + j)->Height, (Man + j + 1)->Height);
                swap((Man + j)->Weight, (Man + j + 1)->Weight);
            }
        }
    }
}
void showPerson(patient* Man, int* size) {
    ofstream f;
    f.open("D:\\patient.txt", ios::out);

    for (size_t i = 0; i < *size; i++)
    {
        (Man + i)->showInfo();
    }
}

void searchPerson(hospital* Men, patient* Man, int* size ) {

        for (size_t i = 0; i < *size; i++)
        {
            if ((Men+i)->Department == 18)
                (Man+i)->showInfo();
        }
}

/*
void searchPerson(patient* Man, int num) {
    (Man + num - 1)->showInfo();
}
*/
 void lvl1() {
     ofstream f;
     f.open("D:\\patient.txt", ios::out);     
     int size;
     //int num;
     cout << "Enter size of patients: ";
     cin >> size;
     int* tempSize = &size;
     patient* Man = new patient[size];
     //name* Person = new name[size];
     hospital* Men = new hospital[size];
     InitPerson(Man, tempSize);
     sortPerson(Man, tempSize);
     int varForSwitch;
   cout << "What would you like to do:" << endl << "1. See patient's data" << endl << "2.Search patient's data by hospital's department" << endl << "3. Exit the program";
   cout << "Choose your action 1-3: ";
   cin >> varForSwitch;
   switch (varForSwitch)
   {
   case 1:
       for (int i = 0; i < size; i++)
       {
           cout << "Patient " << i + 1 << ":" << endl << endl;
           showPerson(Man, tempSize);
       }
       break;
   case 2:
       cout << "See patients from 18 hospital's department" << endl;

       //searchPerson(Men, Man, tempSize);
       break;
   case 3:
       break;
   default:
       cout << "Action not found." << endl;
       break;
   }
   
     f.close();
 }

void lvl2() {
    //FILE* read;
    int i = 0, n = 0, min = dat[0].year;
    fstream F;
    F.open("D:\\data.txt");
    if (F) {
        while (!F.eof()) {
            F >> dat[i].day >> dat[i].month >> dat[i].year;
            i++;
        }
        n = i++;
        min = dat[0].year;
        for (i = 0; i < n; i++)
        {
            if (dat[i].year < min)
                min = dat[i].year;
        }
        cout << "min year:\t" << min << endl << endl;
    }
    F.close();
}
void lvl3() {
 /*   
    ifstream fstream("test.txt");
    while (fstream.peek() != EOF)
    {
        string line;
        while (getline(fstream, line) && !line.empty())
        {
            double x;
            for (stringstream stream(line); stream >> x;)
                cout << x << " ";
            cout <<endl;
        }
        cout << "end of matrix" << endl;
    }
   */
}
int main()
{
    int varForSwitch;
    cout << "Choose level 1-3:\t";
    cin >> varForSwitch;
    switch (varForSwitch)
    {
    case 1:
        cout << "Your choice was 1 level:\n\n";
        lvl1();
        break;
    case 2:
        cout << "Your choice was 2 level:\n\n";
        lvl2();
        break;
    case 3:
        cout << "Your choice was 3 level:\n\n";
        lvl3();
        break;
    default:
        cout << "Action not found." << endl;
        break;
    }
    system("pause");
    return 0;
}
