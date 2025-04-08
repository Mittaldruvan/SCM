#include <iostream>
#include <string.h>
#include <fstream>
#include "Patient.h"
#include "Doctor.h"
using namespace std;
main()
{

    int i;
    char a;
    do
    {
        cout << "Press 1 for Calling Patient menu." << "\n";
        cout << "Press 2 for Calling Doctor menu." << "\n";
        cout << "Enter number for calling a menu:";
        cin >> i;
        switch (i)
        {
        case 1:
            getPatientMenu();
            break;
        case 2:
            getDoctorMenu();
            break;
        }
        cout << "\n"
             << "If u want to call a menu againn(y/n):";
        cin >> a;
    } while (a == 'y');
}
