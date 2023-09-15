#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;

// OOP: Object-oriented programming
// Object is an instance of a class
// Class is a keyword in C++. It is a collection of STATE and BEHAVIOR that completely describes something
// State: Attribute (aka member variables) - represents data
// Behavior: member functions (aka methods) that operates on the state of an object (aka attribute)
// Classes in C++: They are like struct definition, with an addition of a few things

// Class definition should be in the header file of the same name
class Book {
    // access modikiers (specifiers) that define the visibility (aka the scope) for members
    // puclic and private
    // by default, all memebers of a class are private, meaning only accessible in this class (declaration)
    // in order for main (outside of the Book class), we need to declare them public
    private:
        // declare members of the Book class
        // attributes
        string title;
        string author;
        int * numPages;
    public:
        // Constructor: a special member function that creates objects by initializing their attribute values
        // C++ always has a default constructor that is automatically called every time a Book object is made. However, it doesn't do anything for us
        // We want to override the default constructor in order to properly initialize Books
        // Constructor has no return type
        // We can overload constuctor (0 or more parameters)
        // default value constructor (DVC) has no arguments
        Book(); // DVC prototype - same name as the class
        Book(string, string, int); // Explicit value constructor (EVC) prototypes. Can have many EVC as we want, but only one DVC
        // EVC accepts arguments to initialize attribute values to
        // same rules for function overloading apply to constructor overloading
        
        // A copy constructor is a constructor that is called when a new object is initialized with a new object's data
        // Called in one of two cases:
            // 1. Book b(otherBook); // where otherBook is a Book object
            // 2. Book b = otherBook; // where otherBook is a Book object
            // NOTE: The copy constructor is not called with b = otherBook;
            // Because this is not object creation since b alreasy exists, this is memberwise copy assignment
            Book (const Book&); // Copy constructor

        // Destructor: a special member function that is called automatically when an object is about to be destroyed (aka destructed aka deallocated)
        // What should it do?
            // free/release any resources (e.g., close files, etc.)
            // free/ release any dynamically allocated memory address
        // no return type, no arguments
        // there is only one destructor, cannot overload
        ~Book();

        // getters (aka accessors): member function that gets the values of private attributes
        string getTitle();
        string getAuthor();
        int getNumPages();
        // setters (aka mutators): member function that sets values of private attributes
        void setTitle(string);
        void setAuthor(string);
        void setNumPages(int);

        void display();

        // OPERATOR OVERLOADING
        const Book & operator=(const Book &);
};


#endif