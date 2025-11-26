#pragma once
#include <string>
#include <stdexcept>
#include <utility>

class Author {
    std::string name;
    int birthYear;
    static int total;

    bool isValidYear(int y) const {
        return y >= 1850 && y <= 2025;
    }

public:
    Author() : name("Unknown"), birthYear(1900) {
        ++total;
    }

    Author(std::string n, int y)
        : name(std::move(n)), birthYear(y)
    {
        if (!isValidYear(y))
            throw std::invalid_argument("Invalid birth year");
        ++total;
    }

    ~Author() = default;

    const std::string& getName() const { return name; }
    int getBirthYear() const { return birthYear; }

    void setBirthYear(int y) {
        if (!isValidYear(y))
            throw std::invalid_argument("Invalid birth year");
        birthYear = y;
    }

    std::string to_string() const {
        return name + " (born " + std::to_string(birthYear) + ")";
    }

    static int getTotal() { return total; }
};

inline int Author::total = 0;

