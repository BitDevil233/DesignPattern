#pragma once

#include <vector>
#include <memory>       // For std::shared_ptr
#include <stdexcept>    // Include this for std::out_of_range
#include "Book.h"
#include "Aggregate.h"

class BookShelf : public Aggregate {
public:
    BookShelf(int initialSize) : books_() { books_.reserve(initialSize); }

    Book getBookAt(int index) const {
        if (index >= 0 && index < books_.size()) {
            return books_[index];
        }
        throw std::out_of_range("Index out of range");
    }

    void appendBook(const Book &book) {
        books_.push_back(book);
    }

    int getLength() const {
        return books_.size();
    }

    std::shared_ptr<Iterator_BC> iterator() const override;

private:
    std::vector<Book> books_;
};
