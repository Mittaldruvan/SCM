#include <iostream>
#include <string.h>
#include <fstream>
#include<iomanip>
#include "Patient.h"
#include "Doctor.h"
using namespace std;
class Appointment
{
public:
    int Aid, Did, Pid, toa;
    char d[100];
    // public:
    Appointment()
    {
        Aid = 0;
        Did = 0;
        Pid = 0;
        toa = 0;
        strcpy(d, "");
    }
    Appointment(int Aid1, int Did1, int Pid1, int toa1, char d1[])
    {
        Aid = Aid1;
        Did = Did1;
        Pid = Pid1;
        toa = toa1;
        strcpy(d, d1);
    }
    void display()
    {
        cout<<left<<setw(10)<<Aid<<setw(10)<<Did<<setw(10)<<Pid<<setw(10)<<toa<<setw(5)<<d<<"\n";
        // cout << "Appointment Id of the patient:";
        // cout << Aid << "\n";
        // cout << "Id of the doctor:";
        // cout << Did << "\n";
        // cout << "Patient id of the patient:";
        // cout << Pid << "\n";
        // cout << "Time of the appointment:";
        // cout << toa << "\n";
        // cout << "Name of the disease:";
        // cout << d << "\n";
        // cout<<"\n";
        searchshowD(Did);
        searchshowP(Pid);
    }
    friend void search();
};
void read()
{
    Appointment a1;
    ifstream fin("Appointment.dat", ios::binary);
    cout<<left<<setw(10)<<"Aid"<<setw(10)<<"Did"<<setw(10)<<"Pid"<<setw(10)<<"Toa"<<setw(5)<<"Disease"<<"\n";
    while (fin.read((char *)&a1, sizeof(a1)))
        a1.display();
    fin.close();
};
void write()
{
    int Aid, Did, Pid, toa;
    char d[100], b;
    ofstream fout("Appointment.dat", ios::binary);
    do
    {
        cout << "Enter the appointment Id of the patient:";
        cin >> Aid;
        cout << "Enter id of the doctor:";
        cin >> Did;
        cout << "Enter patient id of the patient:";
        cin >> Pid;
        cout << "Enter time of the appointment:";
        cin >> toa;
        cout << "Enter name of the disease:";
        cin >> d;
        Appointment a1(Aid, Did, Pid, toa, d);
        fout.write((char *)&a1, sizeof(a1));
        cout << "Do you want enter next patient's appointment details(y/n):";
        cin >> b;

    } while (b == 'y');
    fout.close();
};
void cpycontent()
{
    Appointment a1;
    ifstream fin("Appointment.dat", ios::binary);
    ofstream fout("Appointmentcopy.dat", ios::binary);
    while (fin.read((char *)&a1, sizeof(a1)))
    {
        fout.write((char *)&a1, sizeof(a1));
        // a1.display();
    }
    //     fout.close();
    remove("Appointment.dat");
    rename("Appointmentcopy.dat", "Appointment.dat");
};
int search(int n)
{
    int x = 0;
    Appointment a1;
    ifstream fin("Appointment.dat", ios::binary);
    // int n;
    // cout << "Enter id of the Appointment for checking:";
    // cin >> n;
    while (fin.read((char *)&a1, sizeof(a1)))
    {
        if (a1.Aid == n)
        {
            x = 1;
            cout << "Yes, it is in data entered."<<"\n";
            break;
        }
    }
    fin.close();
    return x;
};
void insert()
{
    int Aid, Did, Pid, toa;
    char d[100];
    Appointment a1;
    ifstream fin("Appointment.dat", ios::binary);
    ofstream fout("Appointmentcopy.dat", ios::binary);
    while (fin.read((char *)&a1, sizeof(a1)))
    {
        fout.write((char *)&a1, sizeof(a1));
        a1.display();
    }
    cout << "Enter the appointment Id of the patient:";
    cin >> Aid;
    cout << "Enter id of the doctor:";
    cin >> Did;
    cout << "Enter patient id of the patient:";
    cin >> Pid;
    cout << "Enter time of the appointment:";
    cin >> toa;
    cout << "Enter name of the disease:";
    cin >> d;
    Appointment a2(Aid, Did, Pid, toa, d);
    fout.write((char *)&a2, sizeof(a2));
    fout.close();
    fin.close();
    remove("Appointment.dat");
    rename("Appointmentcopy.dat", "Appointment.dat");
};
int deletedetial(int y)
{
    ifstream fin("Appointment.dat", ios::binary);
    Appointment a1;
    ofstream fout("Appointmentcopy.dat", ios::binary);
    while (fin.read((char *)&a1, sizeof(a1)))
        if (y != a1.Aid)
        {
            // q = 1;
            fout.write((char *)&a1, sizeof(a1));
        }
    fout.close();
    fin.close();
    remove("Appointment.dat");
    rename("Appointmentcopy.dat", "Appointment.dat");
};
int update(int k)
{
    ifstream fin("Appointment.dat", ios::binary);
    Appointment a1;
    ofstream fout("Appointmentcopy.dat", ios::binary);
    while (fin.read((char *)&a1, sizeof(a1)))
        if (k == a1.Aid)
        {
            // cout << "Enter the appointment Id of the patient:";
            // cin >> a1.Aid;
            cout << "Enter id of the doctor:";
            cin >> a1.Did;
            cout << "Enter patient id of the patient:";
            cin >> a1.Pid;
            cout << "Enter time of the appointment:";
            cin >> a1.toa;
            cout << "Enter name of the disease:";
            cin >> a1.d;
            fout.write((char *)&a1, sizeof(a1));
        }
        else
        {
            fout.write((char *)&a1, sizeof(a1));
            // cout<<"Details not updated.";
        }
    a1.display();
    fout.close();
    fin.close();
    remove("Appointment.dat");
    rename("Appointmentcopy.dat", "Appointment.dat");
};
int searchandinsert(int n)
{
    int x = search(n);
    if (x == 1)
    {
        cout << "Already exists.";
    }
    if (x == 0)
    {
        int Aid, Did, Pid, toa;
        char d[100];
        ifstream fin("Appointment.dat", ios::binary);
        Appointment a1;
        ofstream fout("Appointmentcopy.dat", ios::binary);
        while (fin.read((char *)&a1, sizeof(a1)))
        {
            fout.write((char *)&a1, sizeof(a1));
            a1.display();
        }
        cout << "Enter the appointment Id of the patient:";
        cin >> Aid;
        cout << "Enter id of the doctor:";
        cin >> Did;
        cout << "Enter patient id of the patient:";
        cin >> Pid;
        cout << "Enter time of the appointment:";
        cin >> toa;
        cout << "Enter name of the disease:";
        cin >> d;
        Appointment a2(Aid, Did, Pid, toa, d);
        fout.write((char *)&a2, sizeof(a2));
        fout.close();
        fin.close();
    }
    remove("Appointment.dat");
    rename("Appointmentcopy.dat", "Appointment.dat");
};
int searchdelete(int n)
{
    int x = search(n);
    if (x == 0)
    {
        cout << "Not exists.";
    }
    if (x == 1)
    {
        ifstream fin("Appointment.dat", ios::binary);
        Appointment a1;
        ofstream fout("Appointmentcopy.dat", ios::binary);
        while (fin.read((char *)&a1, sizeof(a1)))
            if (n != a1.Aid)
            {
                // q = 1;
                fout.write((char *)&a1, sizeof(a1));
            }
        fout.close();
        fin.close();
    }
    remove("Appointment.dat");
    rename("Appointmentcopy.dat", "Appointment.dat");
};
int searchupdate(int n)
{
    int x = search(n);
    if (x == 0)
    {
        cout << "Not exists.";
    }
    if (x == 1)
    {
        ifstream fin("Appointment.dat", ios::binary);
        Appointment a1;
        ofstream fout("Appointmentcopy.dat", ios::binary);
        while (fin.read((char *)&a1, sizeof(a1)))
            if (n == a1.Aid)
            {
                // cout << "Enter the appointment Id of the patient:";
                // cin >> a1.Aid;
                cout << "Enter id of the doctor:";
                cin >> a1.Did;
                cout << "Enter patient id of the patient:";
                cin >> a1.Pid;
                cout << "Enter time of the appointment:";
                cin >> a1.toa;
                cout << "Enter name of the disease:";
                cin >> a1.d;
                fout.write((char *)&a1, sizeof(a1));
            }
            else
            {
                fout.write((char *)&a1, sizeof(a1));
                // cout<<"Details not updated.";
            }
        // a1.display();
        fout.close();
        fin.close();
    }
    remove("Appointment.dat");
    rename("Appointmentcopy.dat", "Appointment.dat");
};
void getAppointmentmenu()
{
    int i, n, x, q, l;
    char e;
    do
    {
        cout << "Press 1 for writing detail of appointment of patient." << "\n";
        cout << "Press 2 for reading detail of appointment of patient." << "\n";
        cout << "Press 3 for copy content detail of appointment of patient." << "\n";
        cout << "Press 4 for search a detail of appointment of patient." << "\n";
        cout << "Press 5 for insert a detail of appointment of patient." << "\n";
        cout << "Press 6 for delete a detail of appointment of patient." << "\n";
        cout << "Press 7 for update a detail of appointment of patient." << "\n";
        cout << "Press 8 for search and insert a detail of appointment of patient." << "\n";
        cout << "Press 9 for search and update a detail of appointment of patient." << "\n";
        cout << "Press 10 for search and delete a detail of appointment of patient." << "\n";
        cout << "Enter number for calling a function:";
        cin >> i;
        switch (i)
        {
        case 1:
            write();
            break;
        case 2:
            read();
            break;
        case 3:
            cpycontent();
            break;
        case 4:
            // int n;
            cout << "Enter appointment id of patient for checking:";
            cin >> n;
            x = search(n);
            break;
        case 5:
            insert();
            break;
        case 6:
            int y;
            cout << "Enter the id detail u want to delete:";
            cin >> y;
            q = deletedetial(y);
            break;
        case 7:
            int k;
            cout << "Enter the id detail u want to update:";
            cin >> k;
            l = update(k);
            break;
        case 8:
            // int n;
            cout << "Enter appointment id of the patient:";
            cin >> n;
            x = searchandinsert(n);
            break;
        case 9:
            // int n;
            cout << "Enter the id detail u want to delete:";
            cin >> n;
            x = searchdelete(n);
            break;
        case 10:
            // int n;
            cout << "Enter the id detail u want to update:";
            cin >> n;
            x = searchupdate(n);
            break;
        }
        cout << "\n"
             << "If u want to call a function againn(y/n):";
        cin >> e;
    } while (e == 'y');
}