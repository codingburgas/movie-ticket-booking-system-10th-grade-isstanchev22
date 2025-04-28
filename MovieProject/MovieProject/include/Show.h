#pragma once
#include <vector>
#include "Seat.h"
#include "Movie.h"

class Show {
public:
    Show(const Movie& movie, std::string time, int totalSeats);

    void displaySeats() const;
    bool bookSeat(int seatNumber);
    Movie getMovie() const;
    std::string getTime() const;

private:
    Movie movie;
    std::string time;
    std::vector<Seat> seats;
};
