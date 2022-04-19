#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "login.cpp"
using namespace std;

int main()
{
    login userLogin;
    int userChoice;
    cout << "\t\t\t_____________________________________________\n\n\n";
    cout << "\t\t\t         Welcome to the CS 1021 Login!       \n\n";
    cout << "\t\t\t_________           Menu           __________\n\n";
    cout << "\t | Press 1 to LOGIN                              |" << endl;
    cout << "\t | Press 2 to REGISTER                           |" << endl;
    cout << "\t | Press 3 to EXIT                               |" << endl;
    cout << "\n\t\t\t Please Enter your choice: ";
    cin >> userChoice;
    cout << endl;

    if (userChoice == 1)
    {
        userLogin.isLoggedIn();
        main();
    }
    else if (userChoice == 2)
    {
        userLogin.registration();
        main();
    }
    else if (userChoice == 3)
    {
        cout << "\t\t\t Goodbye! \n\n";
    }
    else
    {
        system("cls");
        cout << "\t\t\t Please select from the options above\n"
             << endl;
        main();
    }
}
