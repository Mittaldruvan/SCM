#include <iostream>
#include <string.h>
#include <fstream>
#include<iomanip>
using namespace std;
class doctor
{
public:
    char name[50];
    int id;
    char spec[100];
    // public:
    doctor()
    {
        strcpy(name, "");
        id = 0;
        strcpy(spec, "");
    }
    doctor(char name1[], int id1, char spec1[])
    {
        strcpy(name, name1);
        id = id1;
        strcpy(spec, spec1);
    }
    void displayD()
    {
        cout<<left<<setw(20)<<name<<setw(20)<<id<<setw(10)<<spec<<"\n";
        // cout << "Name of the doctor:";
        // cout << name << "\n";
        // cout << "Id of the doctor:";
        // cout << id << "\n";
        // cout << "Specialization of the doctor:";
        // cout << spec << "\n";
    }
    friend void searchD();
};
void readD()
{
    doctor d1;
    ifstream fin("doctor.dat", ios::binary);
    
    cout << left << setw(20) << "Name" << setw(20) << "Id" << setw(10) << "Specialization" << "\n";
    while (fin.read((char *)&d1, sizeof(d1)))
        d1.displayD();
    fin.close();
};
void writeD()
{
    char name[50];
    int id;
    char spec[100], b;
    ofstream fout("doctor.dat", ios::binary);
    do
    {
        cout << "Enter the name of the doctor:";
        cin >> name;
        cout << "Enter id of the doctor:";
        cin >> id;
        cout << "Enter specialization of the doctor:";
        cin >> spec;
        doctor d1(name, id, spec);
        fout.write((char *)&d1, sizeof(d1));
        cout << "Do you want enter next doctor details(y/n):";
        cin >> b;

    } while (b == 'y');
    fout.close();
};
void cpycontentD()
{
    doctor d1;
    ifstream fin("doctor.dat", ios::binary);
    ofstream fout("doctorcopy.dat", ios::binary);
    while (fin.read((char *)&d1, sizeof(d1)))
    {
        fout.write((char *)&d1, sizeof(d1));
        // d1.displayD();
    }
    //     fout.close();
    remove("doctor.dat");
    rename("doctorcopy.dat", "doctor.dat");
};
int searchD(int n)
{
    int x = 0;
    doctor d1;
    ifstream fin("doctor.dat", ios::binary);
    // int n;
    // cout << "Enter id of the doctor for checking:";
    // cin >> n;
    while (fin.read((char *)&d1, sizeof(d1)))
    {
        if (d1.id == n)
        {
            x = 1;
            // cout << "\n";
            break;
        }
    }
    fin.close();
    return x;
};
void insertD()
{
    char name[50];
    int id;
    char spec[100];
    doctor d1;
    ifstream fin("doctor.dat", ios::binary);
    ofstream fout("doctorcopy.dat", ios::binary);
    while (fin.read((char *)&d1, sizeof(d1)))
    {
        fout.write((char *)&d1, sizeof(d1));
        d1.displayD();
    }
    cout << "Enter the name of the doctor:";
    cin >> name;
    cout << "Enter id of the doctor:";
    cin >> id;
    cout << "Enter specialization of the doctor:";
    cin >> spec;
    doctor d2(name, id, spec);
    fout.write((char *)&d2, sizeof(d2));
    fout.close();
    fin.close();
    remove("doctor.dat");
    rename("doctorcopy.dat", "doctor.dat");
};
int deletedetialD(int y)
{
    ifstream fin("doctor.dat", ios::binary);
    doctor d1;
    ofstream fout("doctorcopy.dat", ios::binary);
    while (fin.read((char *)&d1, sizeof(d1)))
        if (y != d1.id)
        {
            // q = 1;
            fout.write((char *)&d1, sizeof(d1));
        }
    fout.close();
    fin.close();
    remove("doctor.dat");
    rename("doctorcopy.dat", "doctor.dat");
};
int updateD(int k)
{
    ifstream fin("doctor.dat", ios::binary);
    doctor d1;
    ofstream fout("doctorcopy.dat", ios::binary);
    while (fin.read((char *)&d1, sizeof(d1)))
        if (k == d1.id)
        {
            cout << "Enter the name of the doctor:";
            cin >> d1.name;
            // cout << "Enter id of the doctor:";
            // cin >> d1.id;
            cout << "Enter specialization of the doctor:";
            cin >> d1.spec;
            fout.write((char *)&d1, sizeof(d1));
        }
        else
        {
            fout.write((char *)&d1, sizeof(d1));
            // cout<<"Details not updated.";
        }
    d1.displayD();
    fout.close();
    fin.close();
    remove("doctor.dat");
    rename("doctorcopy.dat", "doctor.dat");
};
int searchandinsertD(int n)
{
    int x = searchD(n);
    if (x == 1)
    {
        cout << "Already exists.";
    }
    if (x == 0)
    {
        char name[50];
        int id;
        char spec[100];
        ifstream fin("doctor.dat", ios::binary);
        doctor d1;
        ofstream fout("doctorcopy.dat", ios::binary);
        while (fin.read((char *)&d1, sizeof(d1)))
        {
            fout.write((char *)&d1, sizeof(d1));
            d1.displayD();
        }
        cout << "Enter the name of the doctor:";
        cin >> name;
        cout << "Enter id of the doctor:";
        cin >> id;
        cout << "Enter specialization of the doctor:";
        cin >> spec;
        doctor d2(name, id, spec);
        fout.write((char *)&d2, sizeof(d2));
        fout.close();
        fin.close();
    }
    remove("doctor.dat");
    rename("doctorcopy.dat", "doctor.dat");
};
int searchdeleteD(int n)
{
    int x = searchD(n);
    if (x == 0)
    {
        cout << "Not exists.";
    }
    if (x == 1)
    {
        ifstream fin("doctor.dat", ios::binary);
        doctor d1;
        ofstream fout("doctorcopy.dat", ios::binary);
        while (fin.read((char *)&d1, sizeof(d1)))
            if (n != d1.id)
            {
                // q = 1;
                fout.write((char *)&d1, sizeof(d1));
            }
        fout.close();
        fin.close();
    }
    remove("doctor.dat");
    rename("doctorcopy.dat", "doctor.dat");
};
int searchupdateD(int n)
{
    int x = searchD(n);
    if (x == 0)
    {
        cout << "Not exists.";
    }
    if (x == 1)
    {
        ifstream fin("doctor.dat", ios::binary);
        doctor d1;
        ofstream fout("doctorcopy.dat", ios::binary);
        while (fin.read((char *)&d1, sizeof(d1)))
            if (n == d1.id)
            {
                cout << "Enter the name of the doctor:";
                cin >> d1.name;
                // cout << "Enter id of the doctor:";
                // cin >> d1.id;
                cout << "Enter specialization of the doctor:";
                cin >> d1.spec;
                fout.write((char *)&d1, sizeof(d1));
            }
            else
            {
                fout.write((char *)&d1, sizeof(d1));
                // cout<<"Details not updated.";
            }
        // d1.displayD();
        fout.close();
        fin.close();
    }
    remove("doctor.dat");
    rename("doctorcopy.dat", "doctor.dat");
};
doctor searchshowD(int n)
{
    doctor d1;
    int x = searchD(n);
    if (x == 0)
    {
        cout << "Not exists.";
    }
    if (x == 1)
    {
        ifstream fin("doctor.dat", ios::binary);
        while (fin.read((char *)&d1, sizeof(d1)))
            if (n == d1.id)
            {
                d1.displayD();
                return d1;
            }
    }
};
void getDoctorMenu()
{
    int i, n, x, q, l;
    char d;
    do
    {
        cout << "Press 1 for writing." << "\n";
        cout << "Press 2 for reading." << "\n";
        cout << "Press 3 for copy content." << "\n";
        cout << "Press 4 for search a detail of doctor." << "\n";
        cout << "Press 5 for insert a detail of doctor." << "\n";
        cout << "Press 6 for delete a detail of doctor." << "\n";
        cout << "Press 7 for update a detail of doctor." << "\n";
        cout << "Press 8 for search and insert a detail of doctor." << "\n";
        cout << "Press 9 for search and update a detail of doctor." << "\n";
        cout << "Press 10 for search and delete a detail of doctor." << "\n";
        cout << "Press 11 for search and show a detail of doctor." << "\n";
        cout << "Enter number for calling a function:";
        cin >> i;
        switch (i)
        {
        case 1:
            writeD();
            break;
        case 2:
            readD();
            break;
        case 3:
            cpycontentD();
            break;
        case 4:
            // int n;
            cout << "Enter id of the doctor for checking:";
            cin >> n;
            x = searchD(n);
            break;
        case 5:
            insertD();
            break;
        case 6:
            int y;
            cout << "Enter the id detail u want to delete:";
            cin >> y;
            q = deletedetialD(y);
            break;
        case 7:
            int k;
            cout << "Enter the id detail u want to update:";
            cin >> k;
            l = updateD(k);
            break;
        case 8:
            // int n;
            cout << "Enter id of the doctor:";
            cin >> n;
            x = searchandinsertD(n);
            break;
        case 9:
            // int n;
            cout << "Enter the id detail u want to delete:";
            cin >> n;
            x = searchdeleteD(n);
            break;
        case 10:
            // int n;
            cout << "Enter the id detail u want to update:";
            cin >> n;
            x = searchupdateD(n);
            break;
        case 11:
            // int n;
            cout << "Enter the id detail u want to show:";
            cin >> n;
            doctor d1 = searchshowD(n);
            break;
        }
        cout << "\n"
             << "If u want to call a function againn(y/n):";
        cin >> d;
    } while (d == 'y');
}