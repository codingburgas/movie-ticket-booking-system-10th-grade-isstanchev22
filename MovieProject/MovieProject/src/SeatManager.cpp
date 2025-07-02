
#include "../include/SeatManager.h"
#include <iostream>
#include <iomanip>

Seat::Seat(int row, int col) : row(row), col(col), status(SeatStatus::Available) {}

bool Seat::isAvailable() const {
    return status == SeatStatus::Available;
}

void Seat::reserve() {
    status = SeatStatus::Taken;
}

std::string Seat::display() const {
    return status == SeatStatus::Available ? "\033[32m[O]\033[0m" : "\033[31m[X]\033[0m";
}

SeatManager::SeatManager(int rows, int cols) {
    seats.resize(rows);
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            seats[r].emplace_back(r, c);
        }
    }
}

void SeatManager::displaySeats() const {
    std::cout << "   ";
    for (int c = 0; c < seats[0].size(); ++c)
        std::cout << std::setw(4) << c + 1;
    std::cout << std::endl;

    for (int r = 0; r < seats.size(); ++r) {
        std::cout << std::setw(2) << r + 1 << " ";
        for (const auto& seat : seats[r]) {
            std::cout << " " << seat.display();
        }
        std::cout << std::endl;
    }
}

bool SeatManager::reserveSeat(int row, int col) {
    if (row < 0 || row >= seats.size() || col < 0 || col >= seats[0].size()) return false;
    if (!seats[row][col].isAvailable()) return false;
    seats[row][col].reserve();
    return true;
}
