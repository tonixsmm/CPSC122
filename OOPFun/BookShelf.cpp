#include "BookShelf.h"

BookShelf::BookShelf(){
    // An empty BookShelf
    numBooks = 0;
    books = nullptr;
}

BookShelf::BookShelf(int numBookParam){
    numBooks = numBookParam;
    books = new Book[numBooks];
}

// COPY CONSTRUCTOR
BookShelf::BookShelf(const BookShelf& otherShelf){
    // No shared memory with otherShelf. Make a copy of its books!!
    numBooks = otherShelf.numBooks;
    if (numBooks > 0){
        books = new Book[numBooks];
        for (int i = 0; i < numBooks; i++){
            books[i] = otherShelf.books[i];
        }
    }
    else {
        books = nullptr;
    }
}

BookShelf::~BookShelf(){
    if (books != nullptr){
        delete [] books;
        books = nullptr;
        numBooks = 0;
    }
}

void BookShelf::display(){
    cout << "******Book Shelf Books******" << endl;
    for (int i = 0; i < numBooks; i++){
        books[i].display();
        cout << endl;
    }
}