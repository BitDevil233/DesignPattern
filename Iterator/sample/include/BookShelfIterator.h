#pragma once

#include "Iterator_BC.h"
#include "BookShelf.h"

class BookShelfIterator : public Iterator_BC {
public:
    BookShelfIterator(const BookShelf &bookShelf) : bookShelf_(bookShelf), index_(0) {}

    bool hasNext() const override {
        return index_ < bookShelf_.getLength();
    }

    bool next(Book &book) override {
        if (hasNext()) {
            book = bookShelf_.getBookAt(index_++);
            return true;
        }
        return false;
    }

private:
    const BookShelf &bookShelf_;
    int index_;
};
