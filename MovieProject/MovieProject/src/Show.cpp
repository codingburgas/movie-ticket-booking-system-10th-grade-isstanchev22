
#include "../include/Show.h"
#include <iostream>
#include <sstream>

Show::Show() : showId(0), movieId(0), totalSeats(0) {}

Show::Show(int showId, int movieId, std::string time, int totalSeats)
    : showId(showId), movieId(movieId), time(time), totalSeats(totalSeats) {
    seatStatus.resize(totalSeats, false);
}

int Show::getShowId() const { return showId; }
int Show::getMovieId() const { return movieId; }
std::string Show::getTime() const { return time; }
int Show::getTotalSeats() const { return totalSeats; }
std::vector<bool> Show::getSeatStatus() const { return seatStatus; }

void Show::display() const {
    std::cout << "Show ID: " << showId << " | Movie ID: " << movieId << " | Time: " << time << " | Seats: " << totalSeats << std::endl;
}

void Show::bookSeats(const std::vector<int>& seats) {
    for (int seat : seats) {
        if (seat >= 0 && seat < totalSeats) seatStatus[seat] = true;
    }
}

bool Show::isSeatAvailable(int seatNum) const {
    if (seatNum < 0 || seatNum >= totalSeats) return false;
    return !seatStatus[seatNum];
}

std::string Show::toCSV() const {
    std::string csv = std::to_string(showId) + "," + std::to_string(movieId) + "," + time + "," + std::to_string(totalSeats);
    for (bool status : seatStatus) {
        csv += "," + std::to_string(status);
    }
    return csv;
}

Show Show::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string item;
    int showId, movieId, totalSeats;
    std::string time;

    getline(ss, item, ','); showId = std::stoi(item);
    getline(ss, item, ','); movieId = std::stoi(item);
    getline(ss, time, ',');
    getline(ss, item, ','); totalSeats = std::stoi(item);

    std::vector<bool> status;
    while (getline(ss, item, ',')) {
        status.push_back(item == "1");
    }

    Show show(showId, movieId, time, totalSeats);
    show.seatStatus = status;
    return show;
}
