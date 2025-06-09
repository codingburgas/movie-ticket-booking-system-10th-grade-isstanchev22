#include "../include/Show.h"
#include <iostream>

Show::Show(const Movie& movie, std::string time, int totalSeats)
    : movie(movie), time(time) {
    for (int i = 1; i <= totalSeats; ++i) {
        std::string type;
        if (i <= totalSeats / 3) type = "Silver";
        else if (i <= 2 * totalSeats / 3) type = "Gold";
        else type = "Platinum";

        seats.emplace_back(i, type);
    }
}

void Show::displaySeats() const {
    for (const auto& seat : seats) {
        seat.displaySeatStatus();
    }
}

bool Show::bookSeat(int seatNumber) {
    if (seatNumber < 1 || seatNumber > seats.size()) return false;
    if (!seats[seatNumber - 1].getIsBooked()) {
        seats[seatNumber - 1].bookSeat();
        return true;
    }
    return false;
}

Movie Show::getMovie() const {
    return movie;
}

std::string Show::getTime() const {
    return time;
}
 