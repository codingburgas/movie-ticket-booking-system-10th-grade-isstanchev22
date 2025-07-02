
#include "../include/User.h"
#include <sstream>

User::User(const std::string& uname, const std::string& pwd, bool admin)
    : username(uname), password(pwd), isAdmin(admin) {}

std::string User::getUsername() const {
    return username;
}

bool User::checkPassword(const std::string& pwd) const {
    return password == pwd;
}

bool User::getIsAdmin() const {
    return isAdmin;
}

std::string User::toCSV() const {
    return username + "," + password + "," + (isAdmin ? "1" : "0");
}

User User::fromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string uname, pwd, adminFlag;
    getline(ss, uname, ',');
    getline(ss, pwd, ',');
    getline(ss, adminFlag, ',');
    return User(uname, pwd, adminFlag == "1");
}
