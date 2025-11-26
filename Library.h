#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"
#include "Member.h"
#include "Loan.h"

class Library {
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Loan> loans;

public:
    Library() = default;

    void addBook(const Book& b) {
        books.push_back(b);
    }

    void addMember(const Member& m) {
        members.push_back(m);
    }

    bool hasBook(const std::string& isbn) const {
        return std::any_of(books.begin(), books.end(),
                           [&](const Book& b) { return b.getISBN() == isbn; });
    }

    bool isBookAvailable(const std::string& isbn) const {
        for (const auto& loan : loans)
            if (loan.getISBN() == isbn && !loan.isReturned())
                return false;
        return true;
    }

    bool loanBook(const std::string& isbn,
                  const std::string& memberId,
                  const std::string& start,
                  const std::string& due)
    {
        if (!hasBook(isbn) || !isBookAvailable(isbn))
            return false;

        bool memberExists = std::any_of(
            members.begin(), members.end(),
            [&](const Member& m) { return m.getMemberId() == memberId; }
        );

        if (!memberExists)
            return false;

        try {
            loans.emplace_back(isbn, memberId, start, due);
        } catch (...) {
            return false;
        }

        return true;
    }

    bool returnBook(const std::string& isbn, const std::string& memberId) {
        for (auto& loan : loans) {
            if (loan.getISBN() == isbn &&
                loan.getMemberId() == memberId &&
                !loan.isReturned())
            {
                loan.markReturned();
                return true;
            }
        }
        return false;
    }

    std::vector<Book> findByAuthor(const std::string& authorName) const {
        std::vector<Book> result;
        for (const auto& b : books)
            if (b.getAuthor().getName() == authorName)
                result.push_back(b);
        return result;
    }

    std::string to_string() const {
        int activeLoans = 0;
        for (const auto& l : loans)
            if (!l.isReturned()) ++activeLoans;

        return "Library summary:\nBooks: " + std::to_string(books.size()) +
               "\nMembers: " + std::to_string(members.size()) +
               "\nActive loans: " + std::to_string(activeLoans);
    }
};

