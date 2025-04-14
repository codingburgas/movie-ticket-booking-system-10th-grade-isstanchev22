#include "../include/Movie.h"

Movie::Movie(int id, std::string title, std::string genre, std::string language, std::string releaseDate)
    : id(id), title(title), genre(genre), language(language), releaseDate(releaseDate) {
}

int Movie::getId() const { return id; }
std::string Movie::getTitle() const { return title; }
std::string Movie::getGenre() const { return genre; }
std::string Movie::getLanguage() const { return language; }
std::string Movie::getReleaseDate() const { return releaseDate; }

void Movie::displayInfo() const {
    std::cout << "Movie: " << title << "\n"
        << "Genre: " << genre << "\n"
        << "Language: " << language << "\n"
        << "Release Date: " << releaseDate << "\n";
}
