#pragma once
#include <string>
void displaySeatLayout(const std::string& movie, const std::string& date);
bool isSeatAvailable(const std::string& movie, const std::string& date, const std::string& seat);
void markSeatAsBooked(const std::string& movie, const std::string& date, const std::string& seat);