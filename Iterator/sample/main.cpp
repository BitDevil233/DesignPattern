#include <iostream>
#include <memory>
#include "BookShelf.h"
#include "BookShelfIterator.h"

int main() {
    BookShelf bookShelf(4);
    bookShelf.appendBook(Book("Around the World in 80 Days"));
    bookShelf.appendBook(Book("Bible"));
    bookShelf.appendBook(Book("Cinderella"));
    bookShelf.appendBook(Book("Daddy-Long-Legs"));
    bookShelf.appendBook(Book("East of Eden"));
    bookShelf.appendBook(Book("Frankenstein"));
    bookShelf.appendBook(Book("Gulliver's Travels"));
    bookShelf.appendBook(Book("Hamlet"));

    auto it = bookShelf.iterator();
    Book book;
    while (it->hasNext()) {
        it->next(book);
        std::cout << book.getName() << std::endl;
    }

    return 0;
}

