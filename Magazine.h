#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "Item.h"

class Magazine : public Item {
private:
    int issueNumber;  // which issue of the magazine

public:
    // constructor - takes title, year, and issue number
    Magazine(string t, int y, int issue);
    
    // override the getInfo function
    string getInfo() const override;
    
    // getter and setter for issue number
    int getIssueNumber() const;
    void setIssueNumber(int issue);
};
#endif
