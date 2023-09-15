#ifndef BOOKSHELF_H
#define BOOKSHELF_H

// BookShelf will have a private member variable for a dynamically allocated array of Books and a private member variable for the size (number of Books) of the BookShelf

#include <iostream>
#include "book.h"

using namespace std;

class BookShelf {
    private:
        int numBooks;   // Size
        Book * books;   // Dynamically allocated array of Books
    public:
        BookShelf();
        BookShelf(int); // Allocate an array of a certain number of default book
        BookShelf(const BookShelf&);    // Copy constructor
        void display();
        ~BookShelf();
};

#endif