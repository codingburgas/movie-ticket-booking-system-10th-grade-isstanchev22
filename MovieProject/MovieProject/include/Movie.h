
#pragma once
#include <string>
#include <vector>

class Movie {
private:
    int id;
    std::string title;
    std::string genre;
    int duration; // in minutes

public:
    Movie();
    Movie(int id, std::string title, std::string genre, int duration);

    int getId() const;
    std::string getTitle() const;
    std::string getGenre() const;
    int getDuration() const;

    void display() const;
    std::string toCSV() const;

    static Movie fromCSV(const std::string& line);
};
