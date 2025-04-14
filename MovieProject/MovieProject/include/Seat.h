#pragma once
#include <string>

class Seat {
public:
    Seat(int number, std::string type);
    int getSeatNumber() const;
    std::string getType() const;
    bool getIsBooked() const;

    void bookSeat();

    void displaySeatStatus() const;
private:
    int seatNumber;
    std::string type;
    bool isBooked;

};