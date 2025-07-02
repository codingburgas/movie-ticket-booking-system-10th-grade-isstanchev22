
#pragma once
#include <string>
#include "../include/Show.h"
#include <vector>


class Movie {
public:
    std::string title;
    std::vector<Show> shows;
    Movie(const std::string& title);
    void addShow(const std::string& time);
};

class Cinema {
public:
    std::string name;
    std::vector<Movie> movies;

    Cinema(const std::string& name);
    void loadDefaultMovies();
};

class City {
public:
    std::string name;
    std::vector<Cinema> cinemas;

    City(const std::string& name);
    void addCinema(const std::string& cinemaName);
};

class CityManager {
private:
    std::vector<City> cities;

public:
    void initializeCities();
    void displayCities() const;
    void displayCinemas(int cityIndex) const;
    City& getCity(int index);
    Cinema& getCinema(int cityIndex, int cinemaIndex);
    int getCityCount() const;
    int getCinemaCount(int cityIndex) const;
};
