// src/main.cpp
#include "User.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip.h>

using namespace std;

int startMenu() {
    cout << setw(50) << " *** Main Menu ***" << endl;
    cout << setw(44) << " 1- Balance" << endl;
    cout << setw(44) << " 2- Deposit" << endl;
    cout << setw(45) << " 3- Withdraw" << endl;
    cout << setw(51) << " 4- Funds Transfer" << endl;
    cout << setw(51) << " 5- Mini Statement" << endl;
    cout << setw(41) << " 6- Exit" << endl;
    cout << " Selection: ";
    int op;
    cin >> op;
    return op;
}

void processUser(User &user, User* users[], int size) {
    int option;
    do {
        option = startMenu();
        switch (option) {
            // Add the rest of your processUser function here
        }
    } while (option != 6);
}

int main() {
    clrscr();
    User u1("Waseem", "1234");
    User u2("Ali", "1235");
    User u3("Ahmad", "2135");
    User u4("Aysha", "1236");
    User u5("Zafar", "1267");

    User* users[] = {&u1, &u2, &u3, &u4, &u5};

    char n[50], p[50];
    int loginAttempts = 0;

    while (loginAttempts < 3) {
        cout << setw(60) << " *** Welcome to SG ATM Application *** \n";
        cout << "Enter your name: ";
        cin >> n;
        cout << "Enter your PIN: ";
        cin >> p;

        User* currentUser = NULL;

        for (int i = 0; i < 5; ++i) {
            if (users[i]->checkName(n) && users[i]->checkPin(p)) {
                currentUser = users[i];
                break;
            }
        }

        if (currentUser == NULL) {
            cout << "Invalid Username or PIN! \n";
            loginAttempts++;
            if (loginAttempts == 3) {
                cout << "You have reached the maximum limit of Invalid Attempts. Exiting...\n";
                getche();
                return 1;
            }
        } else {
            processUser(*currentUser, users, 5);
            cout << "*** Would you like to continue? *** \n";
            cout << "1- YES \n";
            cout << "2- NO \n";
            int cont;
            cin >> cont;
            if (cont == 2) {
                break;
            }
            loginAttempts = 0; // Reset login attempts after successful login
            clrscr(); // Clear screen
        }
    }
    for (int i = 0; i < 5; i++) {
        char filename[20];
        sprintf(filename, "file%d.txt", i + 1);
        users[i]->saveData(filename);
    }
    getche(); // Pause
    return 0;
}
