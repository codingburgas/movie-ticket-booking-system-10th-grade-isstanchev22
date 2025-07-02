
#include "../include/UserManager.h"
#include <fstream>
#include <sstream>

void UserManager::loadUsers(const std::string& filename) {
    users.clear();
    std::ifstream fin(filename);
    std::string line;
    while (getline(fin, line)) {
        users.push_back(User::fromCSV(line));
    }
}

void UserManager::saveUsers(const std::string& filename) {
    std::ofstream fout(filename);
    for (const auto& user : users) {
        fout << user.toCSV() << "\n";
    }
}

bool UserManager::registerUser(const std::string& username, const std::string& password, bool isAdmin) {
    for (const auto& user : users) {
        if (user.getUsername() == username)
            return false; // already exists
    }
    users.emplace_back(username, password, isAdmin);
    return true;
}

User* UserManager::loginUser(const std::string& username, const std::string& password) {
    for (auto& user : users) {
        if (user.getUsername() == username && user.checkPassword(password)) {
            return &user;
        }
    }
    return nullptr;
}
