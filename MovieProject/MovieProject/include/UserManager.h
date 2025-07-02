
#pragma once
#include "User.h"
#include <vector>
#include <string>

class UserManager {
private:
    std::vector<User> users;

public:
    void loadUsers(const std::string& filename);
    void saveUsers(const std::string& filename);
    bool registerUser(const std::string& username, const std::string& password, bool isAdmin);
    User* loginUser(const std::string& username, const std::string& password);
};
