// src/User.h
#ifndef USER_H
#define USER_H

class User {
private:
    char name[50];
    char pin[50];

public:
    double balance;
    User(const char* n, const char* p);
    int checkName(const char* n);
    int checkPin(const char* p);
    void saveData(const char* fn);
    const char* getName() const;
};

#endif
