#include <iostream>
#include "../include/Menu.h"

using namespace std;

void showMainMenu() {
    cout << "\n===== Welcome to MovieMate =====\n";
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Movies\n";
    cout << "4. Locations\n";
    cout << "5. Contact\n";
    cout << "0. Exit\n";
    cout << "==================================\n";
}

void showUserMenu() {
    cout << "\n===== User Menu =====\n";
    cout << "1. View Movies\n";
    cout << "2. Book Tickets\n";
    cout << "3. My Bookings\n";
    cout << "0. Logout\n";
    cout << "======================\n";
}

void showContactInfo() {
    cout << "\n===== Contact Us =====\n";
    cout << "Email: support@cinebooking.com\n";
    cout << "Phone: +1 (555) 123-4567\n";
    cout << "=======================\n";
}


