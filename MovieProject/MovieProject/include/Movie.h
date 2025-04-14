#pragma once
#include <string>
#include <iostream>

class Movie {
public:
    Movie(int id, std::string title, std::string genre, std::string language, std::string releaseDate);

    int getId() const;
    std::string getTitle() const;
    std::string getGenre() const;
    std::string getLanguage() const;
    std::string getReleaseDate() const;

    void displayInfo() const;

private:
    int id;
    std::string title;
    std::string genre;
    std::string language;
    std::string releaseDate;
};
