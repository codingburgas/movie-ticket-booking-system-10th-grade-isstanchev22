
#pragma once
#include "MovieManager.h"
#include "ShowManager.h"
#include "Booking.h"
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

public:
    void run();
};
