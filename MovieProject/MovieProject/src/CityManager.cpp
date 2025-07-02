
#include "../include/CityManager.h"
#include <iostream>

Show::Show(const std::string& time) : time(time) {}
Movie::Movie(const std::string& title) : title(title) {}
void Movie::addShow(const std::string& time) { shows.emplace_back(time); }

Cinema::Cinema(const std::string& name) : name(name) { loadDefaultMovies(); }

void Cinema::loadDefaultMovies() {
    static int counter = 0;
    std::vector<std::string> allTitles = {
        "Inception", "Interstellar", "The Matrix", "John Wick", "Oppenheimer",
        "Dune", "Avatar", "Tenet", "Barbie", "The Batman",
        "Gladiator", "Joker", "Mad Max", "Fight Club", "The Godfather"
    };

    for (int i = 0; i < 5; ++i) {
        std::string title = allTitles[(counter * 5 + i) % allTitles.size()];
        Movie m(title);
        m.addShow("12:00");
        m.addShow("15:30");
        movies.push_back(m);
    }
    ++counter;
}

City::City(const std::string& name) : name(name) {}
void City::addCinema(const std::string& cinemaName) { cinemas.emplace_back(cinemaName); }

void CityManager::initializeCities() {
    City plovdiv("Plovdiv");
    plovdiv.addCinema("Arena Plovdiv");
    plovdiv.addCinema("Cinema City Markovo Tepe");

    City sofia("Sofia");
    sofia.addCinema("Cinema City Paradise");
    sofia.addCinema("Arena Mladost");
    sofia.addCinema("Odeon Cinema");

    City burgas("Burgas");
    burgas.addCinema("Cinema City Burgas");
    burgas.addCinema("Arena Burgas");

    cities.push_back(plovdiv);
    cities.push_back(sofia);
    cities.push_back(burgas);
}

void CityManager::displayCities() const {
    for (size_t i = 0; i < cities.size(); ++i) {
        std::cout << i + 1 << ". " << cities[i].name << std::endl;
    }
}

void CityManager::displayCinemas(int cityIndex) const {
    const auto& cinemas = cities[cityIndex].cinemas;
    for (size_t i = 0; i < cinemas.size(); ++i) {
        std::cout << i + 1 << ". " << cinemas[i].name << std::endl;
    }
}

City& CityManager::getCity(int index) { return cities[index]; }
Cinema& CityManager::getCinema(int cityIndex, int cinemaIndex) { return cities[cityIndex].cinemas[cinemaIndex]; }
int CityManager::getCityCount() const { return static_cast<int>(cities.size()); }
int CityManager::getCinemaCount(int cityIndex) const { return static_cast<int>(cities[cityIndex].cinemas.size()); }
