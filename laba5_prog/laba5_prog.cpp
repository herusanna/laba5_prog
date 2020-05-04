/*5 variant*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include <time.h>

using namespace std;
ofstream f;
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
    void showName() {

        f << "FIO: " << F << " " << I << " " << O << endl;

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

        f << "Index: " << index << endl;
        f << "Country: " << country << endl;
        f << "Region: " << region << endl;
        f << "District: " << district << endl;
        f << "City: " << city << endl;
        f << "Street: " << street << endl;
        f << "House: " << house << endl;
        f << "Apartment: " << apartment;
    }
};
struct hospital
{
    int NumHosp;
    int NumCard;
    char Diagnosis[30];
    int BloodType;
    void setHospital()
    {

        cout << endl << "Hospital number: ";
        while (!(cin >> NumHosp))
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
        f << endl << "Hospital's number: " << NumHosp;
        f << endl << "Medical card number: " << NumCard;
        f << endl << "Patient's diagnosis: " << Diagnosis;
        f << endl << "Patient's blood type: " << BloodType;
    }
};
struct patient
{
    int Department;
    name person;
    adress home;
    hospital Data;
    long Tele;
    char Sex[30];
    char Nationality[30];
    int Height;
    int Weight;
    void setInfo()
    {

        person.setName();
        home.setAdress();
        Data.setHospital();
        cout << endl << "Hospital department: ";
        while (!(cin >> Department))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }
        cout << endl << "Telephon number: ";
        cin >> Tele;

        cout << endl << "Sex: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(Sex, 8);

        cout << endl << "Nationality: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(Nationality, 30);

        cout << endl << "Height: ";
        while (!(cin >> Height))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }

        cout << endl << "Weight: ";
        while (!(cin >> Weight))
        {
            cout << "Wrong input" << endl;
            cin.clear();
            cin.ignore(65535, '\n');
        }
    }
    void showInfo()
    {

        person.showName();

        f << "Telephon number: " << Tele << endl;

        home.showAdress();

        Data.showHospital();
        f << endl << "Hospital department: " << Department;
        f << endl << "Sex: " << Sex << endl;
        f << "Nationality: " << Nationality << endl;
        f << "Height: " << Height << endl;
        f << "Weight:" << Weight << endl;

    }
};

void  InitPerson(patient* Man, int* size)
{
    for (size_t i = 0; i < *size; i++)
    {
        (Man + i)->setInfo();
    }
}

void sortPerson(patient* Man, int* size)
{

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
void showPerson(patient* Man, int* size)
{
    for (size_t i = 0; i < *size; i++)
    {
        (Man + i)->showInfo();
    }
}

void searchPerson(patient* Man, int* size)
{
    for (size_t i = 0; i < *size; i++)
    {
        if (((Man + i)->Department) == 18)
            (Man + i)->showInfo();
    }
}
/*
void deletePerson(patient* Man, int* size, int num)
{
    if (Man + num - 1) {
        for (size_t i = num; i < *size; i++)
        {
            (Man + i) = (Man + i + 1);
        }
        --*size;
    }
}
*/
void lvl1() {
    f.open("D:\\patient.txt");
    int size;
    //int num;
    cout << "Enter size of patients: ";
    while (!(cin >> size))
    {
        cout << "Wrong input" << endl;
        cin.clear();
        cin.ignore(65535, '\n');
    }
    int* tempSize = &size;
    patient* Man = new patient[size];
    InitPerson(Man, tempSize);
    sortPerson(Man, tempSize);
    int varForSwitch;
    cout << "What would you like to do:" << endl << "1. Save data of patiens" << endl << "2.Save patient's data by hospital's department" << endl << "3. Exit the program";
    cout << "\n\nChoose your action 1-3: ";
    cin >> varForSwitch;
    switch (varForSwitch)
    {
    case 1:
        for (int i = 0; i < size; i++)
        {
            f << "Patient " << i + 1 << ":" << endl << endl;
            showPerson(Man, tempSize);
        }
        break;
    case 2:
        f << "Patients from 18 hospital's department:" << endl;
        searchPerson(Man, tempSize);
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
    fstream F;
    fstream FALE;
    F.open("D:\\test.txt");
    FALE.open("D:\\det.txt");
    srand(time(0));
    string line;
    int zindex, yindex = 3, xindex = 3, det;
    cout << "\nInput quantity of matrix:\t";
    if (F.is_open()) {
        cin >> zindex;
        int*** arr = new int** [zindex];
        for (int i = 0; i < zindex; i++) {
            arr[i] = new int* [yindex];

            for (int j = 0; j < yindex; j++) {
                arr[i][j] = new int[xindex];
            }
        }
        for (int z = 0; z < zindex; z++)
            for (int y = 0; y < yindex; y++)
                for (int x = 0; x < xindex; x++)
                    arr[z][y][x] = rand() % 5 + 1;

        for (int z = 0; z < zindex; z++) {
            for (int y = 0; y < yindex; y++) {
                for (int x = 0; x < xindex; x++) {
                    F.width(3);
                    F << arr[z][y][x];
                }
                F << endl;
            }
            F << endl;
        }
        for (int z = 0; z < zindex; z++) {
            det = arr[z][0][0] * arr[z][1][1] * arr[z][2][2] + arr[z][2][0] * arr[z][0][1] * arr[z][1][2] + arr[z][1][0] * arr[z][2][1] * arr[z][0][2] - arr[z][2][0] * arr[z][1][1] * arr[z][0][2] - arr[z][0][0] * arr[z][2][1] * arr[z][1][2] - arr[z][1][0] * arr[z][0][1] * arr[z][2][2];
            FALE << det;
            FALE << endl;
        }
        FALE.close();
        F.close();
        /*ifstream F;
        F.open("D:\\test.txt");
        while (getline(F, line))
        {
            cout << line << endl;
        }*/
        ifstream FALE;
        FALE.open("D:\\det.txt");
        int k = 1;
        for (int z = 0; z < zindex; z++) {
        equa:
            if (k > zindex)
                break;
            cout << k << " equation = " << arr[z][0][0] << " * " << arr[z][1][1] << " * " << arr[z][2][2] << " + " << arr[z][2][0] << " * " << arr[z][0][1] << " * " << arr[z][1][2] << " + " << arr[z][1][0] << " * " << arr[z][2][1] << " * " << arr[z][0][2] << " - " << arr[z][2][0] << " * " << arr[z][1][1] << " * " << arr[z][0][2] << " - " << arr[z][0][0] << " * " << arr[z][2][1] << " * " << arr[z][1][2] << " - " << arr[z][1][0] << " * " << arr[z][0][1] << " * " << arr[z][2][2] << " = ";
            if (FALE.is_open()) {
                while (getline(FALE, line))
                {
                    cout << line << endl;
                    k++;
                    goto equa;
                }
            }
        }                           
    }
    FALE.close();
    F.close();    
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
