
#include "../include/MovieManager.h"
#include <iostream>

Show::Show(const std::string& time) : time(time) {}
Movie::Movie(const std::string& title) : title(title) {}

void Movie::addShow(const std::string& time) {
    shows.emplace_back(time);
}

void MovieManager::loadDefaultMovies() {
    Movie m1("Inception");
    m1.addShow("12:00");
    m1.addShow("15:00");

    Movie m2("Interstellar");
    m2.addShow("13:00");
    m2.addShow("18:00");

    Movie m3("The Matrix");
    m3.addShow("10:30");
    m3.addShow("20:00");

    Movie m4("John Wick");
    m4.addShow("14:45");
    m4.addShow("22:15");

    Movie m5("Oppenheimer");
    m5.addShow("17:00");
    m5.addShow("21:00");

    movies = {m1, m2, m3, m4, m5};
}

void MovieManager::displayMovies() const {
    for (size_t i = 0; i < movies.size(); ++i) {
        std::cout << i + 1 << ". " << movies[i].title << std::endl;
    }
}

void MovieManager::displayShows(int movieIndex) const {
    const auto& showList = movies[movieIndex].shows;
    for (size_t i = 0; i < showList.size(); ++i) {
        std::cout << i + 1 << ". " << showList[i].time << std::endl;
    }
}

Movie& MovieManager::getMovie(int index) {
    return movies[index];
}

Show& MovieManager::getShow(int movieIndex, int showIndex) {
    return movies[movieIndex].shows[showIndex];
}

int MovieManager::getMovieCount() const {
    return static_cast<int>(movies.size());
}

int MovieManager::getShowCount(int movieIndex) const {
    return static_cast<int>(movies[movieIndex].shows.size());
}

void MovieManager::deleteMovie(int id)
{
}
