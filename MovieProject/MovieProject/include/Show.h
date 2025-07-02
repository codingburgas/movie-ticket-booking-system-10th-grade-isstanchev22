
#pragma once
#include <string>
#include <vector>

class Show {

public:
    int showId;
    int movieId;
    std::string time;  // e.g., "2025-07-01 18:00"
    int totalSeats;
    std::vector<bool> seatStatus;  // true = booked 
    Show();
    Show(int showId, int movieId, std::string time, int totalSeats);

    int getShowId() const;
    int getMovieId() const;
    std::string getTime() const;
    int getTotalSeats() const;
    std::vector<bool> getSeatStatus() const;

    void display() const;
    void bookSeats(const std::vector<int>& seats);
    bool isSeatAvailable(int seatNum) const;

    std::string toCSV() const;
    static Show fromCSV(const std::string& line);
};
