#include "Magazine.h"

// constructor - passes to base class, sets issue number
Magazine::Magazine(string t, int y, int issue) 
    : Item(t, y), issueNumber(issue) {
    
}

// getInfo for magazines
string Magazine::getInfo() const {
    return title + " (" + to_string(year) + ") Issue #" + to_string(issueNumber);
}

// getter for issue number
int Magazine::getIssueNumber() const { 
    return issueNumber; 
}

// setter for issue number
void Magazine::setIssueNumber(int issue) { 
    issueNumber = issue; 
}
