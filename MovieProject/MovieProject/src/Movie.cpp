#include "../include/Movie.h"
#include <iostream>
#include <sstream>

Movie::Movie() : id(0), duration(0) {}

Movie::Movie(int id, std::string title, std::string genre, int duration)
    : id(id), title(title), genre(genre), duration(duration) {}

int Movie::getId() const { return id; }
std::string Movie::getTitle() const { return title; }
std::string Movie::getGenre() const { return genre; }
int Movie::getDuration() const { return duration; }

void Movie::display() const {
    std::cout << "ID: " << id << " | Title: " << title << " | Genre: " << genre << " | Duration: " << duration << " min" << std::endl;
}

std::string Movie::toCSV() const {
    return std::to_string(id) + "," + title + "," + genre + "," + std::to_string(duration);
}

Movie Movie::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string idStr, title, genre, durationStr;
    getline(ss, idStr, ',');
    getline(ss, title, ',');
    getline(ss, genre, ',');
    getline(ss, durationStr, ',');

    int id = std::stoi(idStr);
    int duration = std::stoi(durationStr);

    return Movie(id, title, genre, duration);
}
