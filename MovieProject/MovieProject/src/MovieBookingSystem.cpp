#include "../include/MovieBookingSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>

void MovieBookingSystem::loadAll() {
    movieManager.loadMovies("movies.csv");
    showManager.loadShows("shows.csv");
    
    std::ifstream fin("bookings.csv");
    std::string line;
    while (getline(fin, line)) {
        bookings.push_back(Booking::fromCSV(line));
    }
}

void MovieBookingSystem::saveAll() {
    movieManager.saveMovies("movies.csv");
    showManager.saveShows("shows.csv");
    
    std::ofstream fout("bookings.csv");
    for (const auto& b : bookings) {
        fout << b.toCSV() << "\n";
    }
}

void MovieBookingSystem::adminMenu() {
    int choice;
    do {
        std::cout << "\n--- Admin Menu ---\n";
        std::cout << "1. Add Movie\n2. Delete Movie\n3. Add Show\n4. View Movies\n5. View Shows\n0. Exit\nChoice: ";
        std::cin >> choice;
        if (choice == 1) {
            std::string title, genre;
            int duration;
            std::cout << "Enter title: "; std::cin.ignore(); getline(std::cin, title);
            std::cout << "Enter genre: "; getline(std::cin, genre);
            std::cout << "Enter duration (min): "; std::cin >> duration;
            movieManager.addMovie(title, genre, duration);
        } else if (choice == 2) {
            int id;
            std::cout << "Enter movie ID to delete: "; std::cin >> id;
            movieManager.deleteMovie(id);
        } else if (choice == 3) {
            int movieId, seats;
            std::string time;
            std::cout << "Enter movie ID: "; std::cin >> movieId;
            std::cout << "Enter show time (e.g. 2025-07-01 18:00): "; std::cin.ignore(); getline(std::cin, time);
            std::cout << "Enter total seats: "; std::cin >> seats;
            showManager.addShow(movieId, time, seats);
        } else if (choice == 4) {
            movieManager.displayMovies();
        } else if (choice == 5) {
            showManager.displayShows();
        }
    } while (choice != 0);
}

void MovieBookingSystem::bookSeats() {
    std::string username;
    int showId, seatCount;
    std::cout << "Enter username: "; std::cin.ignore(); getline(std::cin, username);
    std::cout << "Enter Show ID: "; std::cin >> showId;
    std::cout << "How many seats to book? "; std::cin >> seatCount;

    std::vector<int> seats(seatCount);
    std::cout << "Enter seat numbers (0-indexed): ";
    for (int i = 0; i < seatCount; ++i) std::cin >> seats[i];

    showManager.bookSeatsForShow(showId, seats);
    bookings.emplace_back(username, showId, seats);
}

void MovieBookingSystem::userMenu() {
    int choice;
    do {
        std::cout << "\n--- User Menu ---\n";
        std::cout << "1. View Movies\n2. View Shows\n3. Book Tickets\n4. View Bookings\n0. Exit\nChoice: ";
        std::cin >> choice;
        if (choice == 1) {
            movieManager.displayMovies();
        } else if (choice == 2) {
            showManager.displayShows();
        } else if (choice == 3) {
            bookSeats();
        } else if (choice == 4) {
            for (const auto& b : bookings) b.displayBooking();
        }
    } while (choice != 0);
}

void MovieBookingSystem::run() {
    loadAll();
    int role;
    std::cout << "--- Movie Booking System ---\n";
    std::cout << "Select role: 1. Admin  2. User\nChoice: ";
    std::cin >> role;
    if (role == 1)
        adminMenu();
    else
        userMenu();
    saveAll();
}

#include "../include/UserManager.h"

void MovieBookingSystem::start() {
    UserManager userManager;
    userManager.loadUsers("users.csv");

    std::string choice;
    std::cout << "Welcome to the Movie Booking System!\n";
    std::cout << "1. Login\n2. Register\nChoose an option: ";
    std::cin >> choice;

    std::string username, password;
    bool isAdmin = false;

    if (choice == "1") {
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
        User* user = userManager.loginUser(username, password);
        if (!user) {
            std::cout << "Login failed.\n";
            return;
        }
        isAdmin = user->getIsAdmin();
        std::cout << "Login successful.\n";
    } else if (choice == "2") {
        std::cout << "Choose a username: ";
        std::cin >> username;
        std::cout << "Choose a password: ";
        std::cin >> password;
        std::cout << "Registering as admin? (1 for yes, 0 for no): ";
        std::cin >> isAdmin;
        if (!userManager.registerUser(username, password, isAdmin)) {
            std::cout << "Username already exists.\n";
            return;
        }
        userManager.saveUsers("users.csv");
        std::cout << "Registered successfully. Please restart to login.\n";
        return;
    } else {
        std::cout << "Invalid choice.\n";
        return;
    }

    if (isAdmin) {
        runAdminMenu();
    } else {
        runUserMenu();
    }
}
