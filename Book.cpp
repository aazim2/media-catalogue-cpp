#include "Book.h"
#include <sstream>  

// constructor - passes title and year to base class, then sets author
Book::Book(string t, int y, string a) : Item(t, y), author(a) {
   
}
string Book::getInfo() const {
    return title + " (" + to_string(year) + ") by " + author;
}
// getter for author
string Book::getAuthor() const { 
    return author; 
}
// setter for author - can change if needed
void Book::setAuthor(string a) { 
    author = a; 
}
