#include ""
#include <fstream>
#include <string>

bool login(const std::string& username, const std::string& password) {
    std::ifstream file("users.txt");
    std::string u, p;
    while (file >> u >> p) {
        if (u == username && p == password) return true;
    }
    return false;
}

void registerUser(const std::string& username, const std::string& password) {
    std::ofstream file("users.txt", std::ios::app);
    file << username << " " << password << std::endl;
}
