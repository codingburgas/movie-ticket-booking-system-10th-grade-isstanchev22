#include "../include/booking.h"
#include "../include/seat.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

void bookSeat(const std::string& username) {
    std::ifstream file("films.txt");
    std::vector<std::string> films;
    std::string line;
    int i = 1;

    std::cout << "\n--- Available Movies ---\n";
    while (getline(file, line)) {
        std::cout << i << ". " << line << "\n";
        films.push_back(line);
        i++;
    }

    if (films.empty()) {
        std::cout << "No films available.\n";
        return;
    }

    int movieChoice;
    std::cout << "Select movie number: ";
    std::cin >> movieChoice;
    std::cin.ignore();
    if (movieChoice < 1 || movieChoice > films.size()) {
        std::cout << "Invalid movie selection.\n";
        return;
    }

    std::string selectedMovie = films[movieChoice - 1];
    std::string date;
    std::cout << "Enter date (e.g. 2025-07-10): ";
    std::getline(std::cin, date);

    displaySeatLayout(selectedMovie, date);

    std::string seat;
    std::cout << "Choose a seat: ";
    std::cin >> seat;

    if (!isSeatAvailable(selectedMovie, date, seat)) {
        std::cout << "Seat already booked.\n";
        return;
    }

    markSeatAsBooked(selectedMovie, date, seat);

    std::ofstream booking("bookings.txt", std::ios::app);
    booking << username << " " << selectedMovie << " " << date << " " << seat << "\n";

    std::cout << "Seat " << seat << " successfully booked for " << selectedMovie << " on " << date << ".\n";
}
