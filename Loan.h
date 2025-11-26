#pragma once
#include <string>
#include <stdexcept>
#include <utility>

class Loan {
    std::string isbn;
    std::string memberId;
    std::string startDate;
    std::string dueDate;
    bool returned;

    bool isValidDateOrder(const std::string& start, const std::string& due) const {
        return start <= due;
    }

public:
    Loan(std::string i, std::string m, std::string start, std::string due)
        : isbn(std::move(i)),
          memberId(std::move(m)),
          startDate(std::move(start)),
          dueDate(std::move(due)),
          returned(false)
    {
        if (isbn.empty())
            throw std::invalid_argument("ISBN cannot be empty");

        if (memberId.empty())
            throw std::invalid_argument("Member ID cannot be empty");

        if (!isValidDateOrder(startDate, dueDate))
            throw std::invalid_argument("dueDate must be >= startDate");
    }

    const std::string& getISBN() const { return isbn; }
    const std::string& getMemberId() const { return memberId; }
    const std::string& getStartDate() const { return startDate; }
    const std::string& getDueDate() const { return dueDate; }
    bool isReturned() const { return returned; }

    void markReturned() {
        returned = true;
    }

    bool isOverdue(const std::string& today) const {
        return !returned && dueDate < today;
    }

    std::string to_string() const {
        return "Loan: ISBN " + isbn +
               ", Member " + memberId +
               ", " + startDate + " → " + dueDate +
               (returned ? " (returned)" : " (active)");
    }
};
