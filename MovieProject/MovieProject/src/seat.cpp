#include "../include/seat.h"
#include <fstream>
#include <iostream>
#include <vector>

const int ROWS = 5;
const int COLS = 5;
const char SEAT_ROWS[] = { 'A', 'B', 'C', 'D', 'E' };

std::string generateSeatKey(const std::string& movie, const std::string& date) {
    return movie + "_" + date + "_seats.txt";
}

void displaySeatLayout(const std::string& movie, const std::string& date) {
    std::string filename = generateSeatKey(movie, date);
    std::vector<std::string> booked;
    std::ifstream file(filename);
    std::string s;
    while (file >> s) {
        booked.push_back(s);
    }

    std::cout << "Available Seats (X = booked):\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 1; j <= COLS; ++j) {
            std::string seat = std::string(1, SEAT_ROWS[i]) + std::to_string(j);
            bool taken = false;
            for (const auto& b : booked) {
                if (b == seat) taken = true;
            }
            std::cout << (taken ? "X " : seat + " ");
        }
        std::cout << "\n";
    }
}

bool isSeatAvailable(const std::string& movie, const std::string& date, const std::string& seat) {
    std::ifstream file(generateSeatKey(movie, date));
    std::string s;
    while (file >> s) {
        if (s == seat) return false;
    }
    return true;
}

void markSeatAsBooked(const std::string& movie, const std::string& date, const std::string& seat) {
    std::ofstream file(generateSeatKey(movie, date), std::ios::app);
    file << seat << "\n";
}
