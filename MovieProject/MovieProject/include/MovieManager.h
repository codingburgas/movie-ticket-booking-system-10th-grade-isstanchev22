
#pragma once
#include <string>
#include <vector>

class Show {
public:
    std::string time;
    Show(const std::string& time);
};

class Movie {
public:
    std::string title;
    std::vector<Show> shows;

    Movie(const std::string& title);
    void addShow(const std::string& time);
};

class MovieManager {
private:
    std::vector<Movie> movies;

public:
    void loadDefaultMovies();
    void displayMovies() const;
    void displayShows(int movieIndex) const;
    Movie& getMovie(int index);
    Show& getShow(int movieIndex, int showIndex);
    int getMovieCount() const;
    int getShowCount(int movieIndex) const;
};
