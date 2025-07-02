
#include "../include/ShowManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

ShowManager::ShowManager() : nextShowId(1) {}

void ShowManager::loadShows(const std::string& filename) {
    shows.clear();
    std::ifstream fin(filename);
    std::string line;
    while (getline(fin, line)) {
        Show s = Show::fromCSV(line);
        shows.push_back(s);
        if (s.getShowId() >= nextShowId)
            nextShowId = s.getShowId() + 1;
    }
}

void ShowManager::saveShows(const std::string& filename) const {
    std::ofstream fout(filename);
    for (const auto& s : shows) {
        fout << s.toCSV() << "\n";
    }
}

void ShowManager::addShow(int movieId, const std::string& time, int totalSeats) {
    Show s(nextShowId++, movieId, time, totalSeats);
    shows.push_back(s);
    std::cout << "Show added successfully.\n";
}

void ShowManager::displayShows() const {
    for (const auto& s : shows) {
        s.display();
    }
}

Show* ShowManager::getShowById(int showId) {
    for (auto& s : shows) {
        if (s.getShowId() == showId) return &s;
    }
    return nullptr;
}

void ShowManager::bookSeatsForShow(int showId, const std::vector<int>& seats) {
    Show* show = getShowById(showId);
    if (show) {
        for (int seat : seats) {
            if (!show->isSeatAvailable(seat)) {
                std::cout << "Seat " << seat << " is already booked.\n";
                return;
            }
        }
        show->bookSeats(seats);
        std::cout << "Seats booked successfully.\n";
    } else {
        std::cout << "Show ID not found.\n";
    }
}
