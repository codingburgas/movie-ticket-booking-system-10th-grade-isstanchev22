#include <iostream>
#include <fstream>
#include <string>
#include "../include/menu.h"
#include "../include/login.h"
#include "../include/admin.h"
#include "../include/booking.h"

void showMenu() {
    int choice;
    std::string user, pass;
    bool loggedIn = false;
    std::string currentUser;

    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Login\n2. Register\n3. Movies\n4. Locations\n5. Contact\n6. Book Seat\n0. Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::cout << "Username: ";
            std::cin >> user;
            std::cout << "Password: ";
            std::cin >> pass;

            if (login(user, pass)) {
                std::cout << "Login successful!\n";
                currentUser = user;
                loggedIn = true;
                if (user == "admin") {
                    adminPanel();
                }
                else {
                    std::cout << "Welcome " << user << "!\n";
                }
            }
            else {
                std::cout << "Invalid credentials.\n";
            }
        }
        else if (choice == 2) {
            std::cout << "Choose username: ";
            std::cin >> user;
            std::cout << "Choose password: ";
            std::cin >> pass;
            registerUser(user, pass);
            std::cout << "Registration successful!\n";
        }
        else if (choice == 3) {
            std::ifstream file("films.txt");
            std::string film;
            std::cout << "--- Available Movies ---\n";
            while (getline(file, film)) {
                std::cout << film << "\n";
            }
        }
        else if (choice == 4) {
            std::cout << "Cinema Locations:\n1. Downtown\n2. Uptown\n";
        }
        else if (choice == 5) {
            std::cout << "Contact us at: contact@cinema.com\n";
        }
        else if (choice == 6) {
            if (loggedIn && currentUser != "admin") {
                bookSeat(currentUser);
            }
            else if (!loggedIn) {
                std::cout << "Please login to book a seat.\n";
            }
            else {
                std::cout << "Admins cannot book seats.\n";
            }
        }
    } while (choice != 0);
}
