#include "Item.h"

Item::Item(string t, int y) : title(t), year(y) {
    
}

// getter for title
string Item::getTitle() const { 
    return title; 
}
// getter for year
int Item::getYear() const { 
    return year; 
}
// setter for title - allows updating later
void Item::setTitle(string t) { 
    title = t; 
}
// setter for year
void Item::setYear(int y) { 
    year = y; 
}
