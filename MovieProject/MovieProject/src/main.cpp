#include <iostream>
#include <string>
#include <fstream>
#include "../include/Menu.h"         
#include "../include/Booking.h"      
#include "../include/Movie.h"       
#include "../include/Show.h"         
#include "../include/Cinemahall.h"  
#include "../include/Seat.h"         
#include "../include/User.h"

using namespace std;

void registerUser();
bool loginUser(string& username, bool& isAdmin);

int main() {
    string username;
    bool isAdmin = false;
    int choice;

    while (true) {
        showMainMenu();  

        cout << "Select option (1-5): ";
        cin >> choice;

        switch (choice) {
        case 1: 
            if (loginUser(username, isAdmin)) {
                cout << "Welcome, " << username << "!\n";
                if (isAdmin) { 
                    cout << 1;
                }
                else {
                    showUserMenu();
                }
            }
            break;

        case 2: 
            registerUser();
            break;

        case 3: 
            showContactInfo(); 
            break;

        case 0: 
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "Invalid option.\n";
        }
    }
}
