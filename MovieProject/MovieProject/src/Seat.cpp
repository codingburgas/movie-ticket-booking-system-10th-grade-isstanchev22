#include "../include/Seat.h"
#include<iostream>
Seat::Seat(int number, std::string type)
    : seatNumber(number), type(type), isBooked(false) {
}

int Seat::getSeatNumber() const { return seatNumber; }
std::string Seat::getType() const { return type; }
bool Seat::getIsBooked() const { return isBooked; }

void Seat::bookSeat() { isBooked = true; }

void Seat::displaySeatStatus() const {
    std::cout << "Seat " << seatNumber << " (" << type << "): "
        << (isBooked ? "Booked" : "Available") << "\n";
}
