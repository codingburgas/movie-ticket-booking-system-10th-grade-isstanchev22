
#pragma once
#include "../include/MovieManager.h"
#include "../include/ShowManager.h"
#include "../include/Booking.h"
#include <vector>

class MovieBookingSystem {
private:
    MovieManager movieManager;
    ShowManager showManager;
    std::vector<Booking> bookings;

    void loadAll();
    void saveAll();
    void adminMenu();
    void userMenu();
    void bookSeats();
    void start();

public:
    void run();
};
