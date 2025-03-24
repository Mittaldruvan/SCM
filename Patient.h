#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;
class patient
{
public:
    char name[50];
    int pn, id;
    // public:
    patient()
    {
        strcpy(name, "");
        id = 0;
        pn = 0;
    }
    patient(char name1[], int id1, int pn1)
    {
        strcpy(name, name1);
        id = id1;
        pn = pn1;
    }
    void displayP()
    {
        cout << left << setw(20) << name << setw(20) << id << setw(20) << pn << "\n";
        // cout << "Name of the patient:";
        // cout << name << "\n";
        // cout << "Id of the patient:";
        // cout << id << "\n";
        // cout << "Phone No. of the patient:";
        // cout << pn << "\n";
    }
    friend void searchP();
};
void readP()
{
    // char Name, Id, PhoneNo;
    patient p1;
    ifstream fin("Patient.dat", ios::binary);
    cout << left << setw(20) << "Name" << setw(20) << "Id" << setw(20) << "PhoneNo" << "\n";
    while (fin.read((char *)&p1, sizeof(p1)))
        p1.displayP();
    fin.close();
};
void writeP()
{
    char name[50];
    int id, pn;
    char b;
    ofstream fout("Patient.dat", ios::binary);
    do
    {
        cout << "Enter the name of the patient:";
        cin >> name;
        cout << "Enter id of the patient:";
        cin >> id;
        cout << "Enter phone no. of the patient:";
        cin >> pn;
        patient p1(name, id, pn);
        fout.write((char *)&p1, sizeof(p1));
        cout << "Do you want enter next patient details(y/n):";
        cin >> b;

    } while (b == 'y');
    fout.close();
};
void cpycontentP()
{
    patient p1;
    ifstream fin("Patient.dat", ios::binary);
    ofstream fout("Patientcopy.dat", ios::binary);
    while (fin.read((char *)&p1, sizeof(p1)))
    {
        fout.write((char *)&p1, sizeof(p1));
        // p1.displayP();
    }
    //     fout.close();
    remove("Patient.dat");
    rename("Patientcopy.dat", "Patient.dat");
};
int searchP(int n)
{
    int x = 0;
    patient p1;
    ifstream fin("Patient.dat", ios::binary);
    // int n;
    // cout << "Enter id of the patient for checking:";
    // cin >> n;
    while (fin.read((char *)&p1, sizeof(p1)))
    {
        if (p1.id == n)
        {
            x = 1;
            // cout << "\n";
            break;
        }
    }
    fin.close();
    return x;
}
void insertP()
{
    char name[50];
    int id, pn;
    patient p1;
    ifstream fin("Patient.dat", ios::binary);
    ofstream fout("Patientcopy.dat", ios::binary);
    while (fin.read((char *)&p1, sizeof(p1)))
    {
        fout.write((char *)&p1, sizeof(p1));
        p1.displayP();
    }
    cout << "Enter the name of the patient:";
    cin >> name;
    cout << "Enter id of the patient:";
    cin >> id;
    cout << "Enter phone no. of the patient:";
    cin >> pn;
    patient p2(name, id, pn);
    fout.write((char *)&p2, sizeof(p2));
    fout.close();
    fin.close();
    remove("Patient.dat");
    rename("Patientcopy.dat", "Patient.dat");
};
int deletedetialP(int y)
{
    ifstream fin("Patient.dat", ios::binary);
    patient p1;
    ofstream fout("Patientcopy.dat", ios::binary);
    while (fin.read((char *)&p1, sizeof(p1)))
        if (y != p1.id)
        {
            // q = 1;
            fout.write((char *)&p1, sizeof(p1));
        }
    fout.close();
    fin.close();
    remove("Patient.dat");
    rename("Patientcopy.dat", "Patient.dat");
};
int updateP(int k)
{
    ifstream fin("Patient.dat", ios::binary);
    patient p1;
    ofstream fout("Patientcopy.dat", ios::binary);
    while (fin.read((char *)&p1, sizeof(p1)))
        if (k == p1.id)
        {
            cout << "Enter the name of the patient:";
            cin >> p1.name;
            // cout << "Enter id of the patient:";
            // cin >> id;
            cout << "Enter phone no. of the patient:";
            cin >> p1.pn;
            fout.write((char *)&p1, sizeof(p1));
        }
        else
        {
            fout.write((char *)&p1, sizeof(p1));
            // cout<<"Details not updated.";
        }
    p1.displayP();
    fout.close();
    fin.close();
    remove("Patient.dat");
    rename("Patientcopy.dat", "Patient.dat");
};
int searchandinsertP(int n)
{
    int x = searchP(n);
    if (x == 1)
    {
        cout << "Already exists.";
    }
    if (x == 0)
    {
        char name[50];
        int id, pn;
        ifstream fin("Patient.dat", ios::binary);
        patient p1;
        ofstream fout("Patientcopy.dat", ios::binary);
        while (fin.read((char *)&p1, sizeof(p1)))
        {
            fout.write((char *)&p1, sizeof(p1));
            p1.displayP();
        }
        cout << "Enter the name of the patient:";
        cin >> name;
        cout << "Enter id of the patient:";
        cin >> id;
        cout << "Enter phone no. of the patient:";
        cin >> pn;
        patient p2(name, id, pn);
        fout.write((char *)&p2, sizeof(p2));
        fout.close();
        fin.close();
    }
    remove("Patient.dat");
    rename("Patientcopy.dat", "Patient.dat");
};
int searchdeleteP(int n)
{
    int x = searchP(n);
    if (x == 0)
    {
        cout << "Not exists.";
    }
    if (x == 1)
    {
        ifstream fin("Patient.dat", ios::binary);
        patient p1;
        ofstream fout("Patientcopy.dat", ios::binary);
        while (fin.read((char *)&p1, sizeof(p1)))
            if (n != p1.id)
            {
                // q = 1;
                fout.write((char *)&p1, sizeof(p1));
            }
        fout.close();
        fin.close();
    }
    remove("Patient.dat");
    rename("Patientcopy.dat", "Patient.dat");
};
int searchupdateP(int n)
{
    int x = searchP(n);
    if (x == 0)
    {
        cout << "Not exists.";
    }
    if (x == 1)
    {
        ifstream fin("Patient.dat", ios::binary);
        patient p1;
        ofstream fout("Patientcopy.dat", ios::binary);
        while (fin.read((char *)&p1, sizeof(p1)))
            if (n == p1.id)
            {
                cout << "Enter the name of the patient:";
                cin >> p1.name;
                // cout << "Enter id of the patient:";
                // cin >> p1.id;
                cout << "Enter phone no. of the patient:";
                cin >> p1.pn;
                fout.write((char *)&p1, sizeof(p1));
            }
            else
            {
                fout.write((char *)&p1, sizeof(p1));
                // cout<<"Details not updated.";
            }
        // p1.displayP();
        fout.close();
        fin.close();
    }
    remove("Patient.dat");
    rename("Patientcopy.dat", "Patient.dat");
};
patient searchshowP(int n)
{
    patient p1;
    int x = searchP(n);
    if (x == 0)
    {
        cout << "Not exists.";
    }
    if (x == 1)
    {
        ifstream fin("Patient.dat", ios::binary);
        while (fin.read((char *)&p1, sizeof(p1)))
            if (n == p1.id)
            {
                p1.displayP();
                return p1;
            }
    }
};
void getPatientMenu()
{
    int i, n, x, q, l;
    char d;
    do
    {
        cout << "Press 1 for writing." << "\n";
        cout << "Press 2 for reading." << "\n";
        cout << "Press 3 for copy content." << "\n";
        cout << "Press 4 for search a detail of patient." << "\n";
        cout << "Press 5 for insert a detail of patient." << "\n";
        cout << "Press 6 for delete a detail of patient." << "\n";
        cout << "Press 7 for update a detail of patient." << "\n";
        cout << "Press 8 for search and insert a detail of patient." << "\n";
        cout << "Press 9 for search and update a detail of patient." << "\n";
        cout << "Press 10 for search and delete a detail of patient." << "\n";
        cout << "Press 11 for search and show a detail of patient." << "\n";
        cout << "Enter number for calling a function:";
        cin >> i;
        switch (i)
        {
        case 1:
            writeP();
            break;
        case 2:
            readP();
            break;
        case 3:
            cpycontentP();
            break;
        case 4:
            // int n;
            cout << "Enter id of the patient for checking:";
            cin >> n;
            x = searchP(n);
            break;
        case 5:
            insertP();
            break;
        case 6:
            int y;
            cout << "Enter the id detail u want to delete:";
            cin >> y;
            q = deletedetialP(y);
            break;
        case 7:
            int k;
            cout << "Enter the id detail u want to update:";
            cin >> k;
            l = updateP(k);
            break;
        case 8:
            // int n;
            cout << "Enter id of the patient:";
            cin >> n;
            x = searchandinsertP(n);
            break;
        case 9:
            // int n;
            cout << "Enter the id detail u want to delete:";
            cin >> n;
            x = searchdeleteP(n);
            break;
        case 10:
            // int n;
            cout << "Enter the id detail u want to update:";
            cin >> n;
            x = searchupdateP(n);
            break;
        case 11:
            // int n;
            cout << "Enter the id detail u want to show:";
            cin >> n;
            patient p1 = searchshowP(n);
            // p1.displayP();
            break;
        }
        cout << "\n"
             << "If u want to call a function againn(y/n):";
        cin >> d;
    } while (d == 'y');
}