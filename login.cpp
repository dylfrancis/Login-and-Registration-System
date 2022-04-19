#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "login.h"
using namespace std;

void login::isLoggedIn()
{
    int count;
    string username, password, id, recordPass;
    system("cls");
    cout << "\t\t\t Please enter the username and password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> username;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    string loginHash = password;
    hash<string> mystdhash;
    int loginHashPassword = mystdhash(loginHash);

    ifstream input("data.txt");

    while (input >> id >> recordPass)
    {
        if (id == username && stoi(recordPass) == loginHashPassword)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << username << "\nLogin successful!\n";
        int choice = 1;
        while (choice != 2)
        {
            cout << "\t\t\t_____________________________________________\n\n\n";
            cout << "\t\t\t         Welcome to the CS 1021 Login!       \n\n";
            cout << "\t\t\t_______ Currently Logged In: " << username << " ________\n\n";
            cout << "\t\t\t_________           Menu           __________\n\n";
            cout << "\t | Press 1 to PLAY GAME                              |" << endl;
            cout << "\t | Press 2 to LOGOUT                                 |" << endl;
            cout << "\n\t\t\t Please Enter your choice: ";
            cin >> choice;
            cout << endl;

            if (choice == 1)
            {
                system("cls");
                drunkgame();
            }
            else if (choice == 2)
            {
                system("cls");
                cout << "Logging out" << endl;
            }
            else
            {
                system("cls");
                cout << "Choice invalid, try again";
            }
        }
    }
    else
    {
        cout << "\n Username or password is incorrect, please try again or register\n";
    }
}

void login::registration()
{
    string regUser, regPassword, regId, regPass;
    system("cls");
    cout << "\t\t\t Enter Username: ";
    cin >> regUser;
    cout << "\t\t\t Enter Password: ";
    cin >> regPassword;

    string hashing = regPassword;
    hash<string> mystdhash;
    int hashPassword = mystdhash(hashing);

    ifstream input("data.txt");
    while (input >> regId >> regPass)
    {
        if (regUser == regId)
        {
            int decision;
            cout << "\n\tUsername already taken.\n";
            cout << "\tEnter 1 to enter a new one\n";
            cout << "\tEnter 2 to go back to the menu\n";
            cout << "\t\tEnter here: ";
            cin >> decision;

            if (decision == 1)
            {
                registration();
            }
            else if (decision == 2)
            {
                system("cls");
                cout << "\tReturning to menu\n";
                return;
            }
            else
            {
                system("cls");
                cout << "\tInvalid Entry, returning to menu." << endl;
                return;
            }
        }
        else
        {
            ofstream f1("data.txt", ios::app);
            f1 << regUser << ' ' << hashPassword << endl;
            system("cls");
            cout << "\n\t\t\t Registration successful!\n";
            return;
        }
    }
}

void login::drunkgame()
{
    srand(time(0));
    const int size = 60;
    cout << "Enter a letter to begin \n ";
    char x;
    cin >> x;
    int position = size / 2;
    while (true)
    {
        cout << "|START|";
        for (int i = 0; i < size; i++)
        {
            if (i == position)
                cout << x;
            else
                cout << " ";
        }
        cout << "|END|" << endl;
        int move = rand() % 3 - 1;
        position = position + move;
        if (position < 1)
        {
            cout << "Guess you were too drunk to make it to the end..." << endl;
            break;
        }
        if (position > size - 1)
        {
            cout << "You might be drunk, but you made it to the end!" << endl;
            break;
        }
        for (int sleep = 0; sleep < 1000000; ++sleep)
            ;
    }
    string goBack;
    cout << "Press any key to go back: ";
    cin >> goBack;
    system("cls");
}