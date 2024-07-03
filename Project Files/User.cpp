// src/User.cpp
#include "User.h"
#include <cstring>
#include <fstream>
using namespace std;

User::User(const char* n, const char* p) {
    strcpy(name, n);
    strcpy(pin, p);
    balance = 100;
}

int User::checkName(const char* n) {
    return strcmp(n, name) == 0;
}

int User::checkPin(const char* p) {
    return strcmp(p, pin) == 0;
}

void User::saveData(const char* fn) {
    ofstream userFile(fn);
    userFile << "Username: " << name << endl;
    userFile << "PIN: " << pin << endl;
    userFile << "Balance: " << balance << endl;
    userFile.close();
}

const char* User::getName() const {
    return name;
}
