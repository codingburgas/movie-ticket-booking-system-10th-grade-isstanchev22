
#pragma once
#include <string>

class User {
private:
    std::string username;
    std::string password;
    bool isAdmin;

public:
    User(const std::string& uname, const std::string& pwd, bool admin);

    std::string getUsername() const;
    bool checkPassword(const std::string& pwd) const;
    bool getIsAdmin() const;

    std::string toCSV() const;
    static User fromCSV(const std::string& line);
};
