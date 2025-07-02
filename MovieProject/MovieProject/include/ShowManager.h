
#pragma once
#include "Show.h"
#include <vector>

class ShowManager {
private:
    std::vector<Show> shows;
    int nextShowId;

public:
    ShowManager();

    void loadShows(const std::string& filename);
    void saveShows(const std::string& filename) const;

    void addShow(int movieId, const std::string& time, int totalSeats);
    void displayShows() const;
    Show* getShowById(int showId);
    void bookSeatsForShow(int showId, const std::vector<int>& seats);
};
