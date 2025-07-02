
#pragma once
#include <vector>
#include <string>

enum class SeatStatus { Available, Taken };

class Seat {
public:
    int row, col;
    SeatStatus status;
    Seat(int row, int col);

    bool isAvailable() const;
    void reserve();
    std::string display() const;
};

class SeatManager {
private:
    std::vector<std::vector<Seat>> seats;

public:
    SeatManager(int rows = 5, int cols = 8);
    void displaySeats() const;
    bool reserveSeat(int row, int col);
};
