#include <iostream>
#include <fstream>
#include <string>
#include "../include/User.h"

using namespace std;

bool loginUser(string& username, bool& isAdmin) {
    string password, u, p, role;

    cout << "\n=== Login ===\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream infile("users.txt");
    while (infile >> u >> p >> role) {
        if (u == username && p == password) {
            isAdmin = (role == "admin");
            cout << "Login successful!\n";
            return true;
        }
    }

    cout << "Login failed: Invalid credentials.\n";
    return false;
}

void registerUser() {
    string username, password;

    cout << "\n=== Register ===\n";
    cout << "Choose a username: ";
    cin >> username;
    cout << "Choose a password: ";
    cin >> password;

    ifstream infile("users.txt");
    string u, p, r;
    while (infile >> u >> p >> r) {
        if (u == username) {
            cout << "Username already exists!\n";
            return;
        }
    }
    infile.close();

    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << " user\n";
    cout << "Registration successful!\n";
}
