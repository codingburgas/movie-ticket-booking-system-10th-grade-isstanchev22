#include "../include/admin.h"
#include <iostream>
#include <fstream>
#include <string>

void adminPanel() {
    int choice;
    std::string film;

    do {
        std::cout << "\n--- Admin Panel ---\n";
        std::cout << "1. Add Movie\n2. View Movies\n0. Back\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::cout << "Enter movie name: ";
            std::getline(std::cin, film);
            std::ofstream file("films.txt", std::ios::app);
            file << film << std::endl;
        }
        else if (choice == 2) {
            std::ifstream file("films.txt");
            std::cout << "--- Movie List ---\n";
            while (getline(file, film)) {
                std::cout << film << "\n";
            }
        }
    } while (choice != 0);
}
