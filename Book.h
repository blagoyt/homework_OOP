#pragma once
#include <string>
#include <stdexcept>
#include <utility>
#include "Author.h"

class Book {
    std::string title;
    Author author;
    int year;
    double price;
    std::string isbn;

    static int totalBooks;

    bool isValidYear(int y) const {
        return y >= 1500 && y <= 2025;
    }

public:
    Book()
        : title("Untitled"),
          author(),
          year(2000),
          price(0.0),
          isbn("N/A")
    {
        ++totalBooks;
    }

    Book(std::string t, Author a, int y, double p, std::string i)
        : title(std::move(t)),
          author(std::move(a)),
          year(y),
          price(p),
          isbn(std::move(i))
    {
        if (!isValidYear(y))
            throw std::invalid_argument("Invalid year");

        if (p < 0)
            throw std::invalid_argument("Negative price");

        ++totalBooks;
    }


    Book(const Book& other) = default;

    Book(Book&& other) noexcept = default;

    Book& operator=(const Book& other) = default;

    Book& operator=(Book&& other) noexcept = default;

    ~Book() {
        --totalBooks;
    }

    const std::string& getTitle() const { return title; }
    const Author& getAuthor() const { return author; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    const std::string& getISBN() const { return isbn; }

    void setYear(int y) {
        if (!isValidYear(y))
            throw std::invalid_argument("Invalid year");
        year = y;
    }

    void setPrice(double p) {
        if (p < 0)
            throw std::invalid_argument("Negative price");
        price = p;
    }

    std::string to_string() const {
        return "\"" + title + "\" by " + author.getName() +
               " (" + std::to_string(year) + "), " +
               std::to_string(price) + " ыт., ISBN: " + isbn;
    }

    static int getTotalBooks() { return totalBooks; }
};

inline int Book::totalBooks = 0;

