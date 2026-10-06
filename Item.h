#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
protected:
    string title;   // title of the item - book, movie, magazine
    int year;       // year it was published/released

public:
    Item(string t, int y);
  
    virtual ~Item() = default;

    virtual string getInfo() const = 0;

    // regular getters and setters 
    string getTitle() const;
    int getYear() const;
    void setTitle(string t);
    void setYear(int y);
};
#endif
