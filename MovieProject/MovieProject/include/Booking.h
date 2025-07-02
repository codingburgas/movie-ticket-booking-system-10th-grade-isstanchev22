
#pragma once
#include <string>
#include <vector>

class Booking {
private:
    std::string username;
    int showId;
    std::vector<int> seatNumbers;

public:
    Booking(std::string uname, int showId, std::vector<int> seats);

    std::string getUsername() const;
    int getShowId() const;
    std::vector<int> getSeatNumbers() const;

    void displayBooking() const;
    void saveToFile() const;

    static std::vector<Booking> loadBookings(const std::string& username);
};
