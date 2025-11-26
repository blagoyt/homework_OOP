#pragma once
#include <string>
#include <stdexcept>
#include <utility>

class Member {
    std::string name;
    std::string memberId;
    int yearJoined;

    bool isValidYear(int y) const {
        return y >= 1900 && y <= 2025;
    }

public:
    Member()
        : name("Unknown"),
          memberId("N/A"),
          yearJoined(2000)
    {}

    Member(std::string n, std::string id, int year)
        : name(std::move(n)),
          memberId(std::move(id)),
          yearJoined(year)
    {
        if (memberId.empty())
            throw std::invalid_argument("Member ID cannot be empty");

        if (!isValidYear(year))
            throw std::invalid_argument("Invalid yearJoined");
    }

    const std::string& getName() const { return name; }
    const std::string& getMemberId() const { return memberId; }
    int getYearJoined() const { return yearJoined; }

    void setMemberId(const std::string& id) {
        if (id.empty())
            throw std::invalid_argument("Member ID cannot be empty");
        memberId = id;
    }

    void setYearJoined(int y) {
        if (!isValidYear(y))
            throw std::invalid_argument("Invalid yearJoined");
        yearJoined = y;
    }

    std::string to_string() const {
        return name + " (ID: " + memberId + ", joined " +
               std::to_string(yearJoined) + ")";
    }
};
