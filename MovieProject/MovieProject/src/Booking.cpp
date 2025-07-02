
#include "../include/Booking.h"
#include <iostream>
#include <fstream>
#include <sstream>

Booking::Booking(std::string uname, int show, std::vector<int> seats)
    : username(uname), showId(show), seatNumbers(seats) {}

std::string Booking::getUsername() const {
    return username;
}

int Booking::getShowId() const {
    return showId;
}

std::vector<int> Booking::getSeatNumbers() const {
    return seatNumbers;
}

void Booking::displayBooking() const {
    std::cout << "Booking for " << username << " | Show ID: " << showId << " | Seats: ";
    for (int seat : seatNumbers) std::cout << seat << " ";
    std::cout << std::endl;
}

void Booking::saveToFile() const {
    std::ofstream fout("bookings.txt", std::ios::app);
    fout << username << "," << showId;
    for (int seat : seatNumbers) {
        fout << "," << seat;
    }
    fout << "\n";
    fout.close();
}

std::vector<Booking> Booking::loadBookings(const std::string& username) {
    std::vector<Booking> bookings;
    std::ifstream fin("bookings.txt");
    std::string line;

    while (getline(fin, line)) {
        std::stringstream ss(line);
        std::string user;
        getline(ss, user, ',');

        if (user == username) {
            std::string sid;
            getline(ss, sid, ',');
            int showId = std::stoi(sid);
            std::vector<int> seats;
            std::string seatStr;
            while (getline(ss, seatStr, ',')) {
                seats.push_back(std::stoi(seatStr));
            }
            bookings.emplace_back(user, showId, seats);
        }
    }
    return bookings;
}
