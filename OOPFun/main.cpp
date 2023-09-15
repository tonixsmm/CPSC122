#include "book.h"
#include "BookShelf.h"

int main(){
    // Make our Book object
    // Acutual memory is allocated when an object is created
    Book hp1; // invokes DVC
    hp1.setTitle("Harry Porter and the Sorcerer's Stone");
    hp1.setAuthor("JK Rowling");
    hp1.setNumPages(202);

    cout << hp1.getTitle() << endl;

    hp1.display();
    // hp1 is an "invoking" object, so in display(), it is hp1's title, author, numPages that are accessed
    // this is the syntax for calling a mmeber function
    // <object>.<member functions>()

    Book hp2; // invokes DVC
    hp2.setTitle("Harry Porter and the Chamber of Secrets");
    hp2.setAuthor("JK Rowling");
    hp2.setNumPages(300);
    hp2.display();

    // other member functions
    //myString.size() myString.at()

    // we can have pointers to object
    Book hp3 = hp2; // a copy of hp2
    // Invokes the copy constructor if one exists. If one does not exist, then performs memberwise copy assignment

    hp3.setTitle("Harry Porter anf the Prisoner of Azkaban");
    Book * bookPtr = &hp3;
    // can use -> to indirectly access hp3
    bookPtr -> display(); // dereference and select
    // Dynamically allocated a Book if we wanted to
    // PROBLEM when numPages in hp2 is copied to numPages in hp3. hp3 is freed before hp2, so we get a double free detected when we destruct hp2 and call delete numPages
    // SOLUTION? define a copy constructor, where we allocate new member for numPages in hp3

    Book hp4; // invokes DVC
    hp4.display();
    /* DISPLAYING, without having overwriting DVC
    Title: 
    Author: 
    Number of pages: 24998400 // garbage
    */

    Book hp5("Harry Porter and the Goblet of Fire", "JK Rowling", 450); // invokes EVC
    hp5.display();

    // 2 distinct implementation of dynamically memory allocated and objects
        // 1. dynamically allocate a Book object - they live in the heap entirely
        Book * hp6Ptr = new Book("Harry Porter and the Order of the Phoenix", "JK Rowling", 600); // EVC
        hp6Ptr -> display();
        delete hp6Ptr; // this one deallocates hp6Ptr independently
        // 2. dynamically allocate attributes of a Book object
    
    // RULE OF THREE: If you define any of the following then you should define all three
        // 1. destructor
        // 2. copy constructor
            // Book hp3(hp2);
        // 3. memberwise copy assignment operator (operator overloading)
            // hp3 = hp2;

    BookShelf shelf;
    shelf.display();

    BookShelf shelf2(5); // 5 default books on the shelf
    shelf2.display();

    BookShelf shelf3(shelf2);
    shelf3.display();
    
    return 0;
}