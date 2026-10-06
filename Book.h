#ifndef BOOK_H
#define BOOK_H
#include "Item.h"
class Book : public Item {
private:
    string author;  // who wrote the book

public:
    // constructor - takes title, year, and author
    Book(string t, int y, string a);
    string getInfo() const override;
   
    // extra functions specific to books
    string getAuthor() const;
    void setAuthor(string a);
};
#endif
