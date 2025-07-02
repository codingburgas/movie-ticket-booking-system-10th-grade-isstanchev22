#include <iostream>
#include <string>
#include "../include/CityManager.h"
#include "../include/SeatManager.h"

using namespace std;

// Simple in-memory user system
bool loginSystem(string& username) {
    int choice;
    cout << "1. Register\n2. Login\nChoose option: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Register username: ";
        getline(cin, username);
        cout << "Registered successfully!\n";
        return true;
    } else if (choice == 2) {
        cout << "Login username: ";
        getline(cin, username);
        cout << "Logged in successfully!\n";
        return true;
    } else {
        cout << "Invalid option.\n";
        return false;
    }
}

int main() {
    string username;
    if (!loginSystem(username)) return 0;

    CityManager manager;
    manager.initializeCities();

    cout << "\nChoose a City:\n";
    manager.displayCities();
    int cityChoice;
    cout << "Enter city number: ";
    cin >> cityChoice;
    cityChoice--;

    cout << "\nChoose a Cinema in " << manager.getCity(cityChoice).name << ":\n";
    manager.displayCinemas(cityChoice);
    int cinemaChoice;
    cout << "Enter cinema number: ";
    cin >> cinemaChoice;
    cinemaChoice--;

    Cinema& selectedCinema = manager.getCinema(cityChoice, cinemaChoice);

    cout << "\nChoose a Movie in " << selectedCinema.name << ":\n";
    for (int i = 0; i < selectedCinema.movies.size(); ++i) {
        cout << i + 1 << ". " << selectedCinema.movies[i].title << endl;
    }
    int movieChoice;
    cout << "Enter movie number: ";
    cin >> movieChoice;
    movieChoice--;

    Movie& selectedMovie = selectedCinema.movies[movieChoice];
    cout << "\nChoose a Show for " << selectedMovie.title << ":\n";
    for (int i = 0; i < selectedMovie.shows.size(); ++i) {
        cout << i + 1 << ". " << selectedMovie.shows[i].time << endl;
    }
    int showChoice;
    cout << "Enter show number: ";
    cin >> showChoice;
    showChoice--;

    SeatManager seatManager;
    bool keepBooking = true;

    while (keepBooking) {
        cout << "\nSeat Map (Green = Available, Red = Taken):\n";
        seatManager.displaySeats();

        int row, col;
        cout << "\nEnter row (1-5): ";
        cin >> row;
        cout << "Enter column (1-8): ";
        cin >> col;

        if (seatManager.reserveSeat(row - 1, col - 1)) {
            cout << "Seat reserved successfully!\n";
        } else {
            cout << "Seat already taken or invalid. Try again.\n";
        }

        cout << "Book another seat? (1 = Yes, 0 = No): ";
        cin >> keepBooking;
    }

    cout << "\nThank you, " << username << "! Enjoy your movie.\n";
    return 0;
}
