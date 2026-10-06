#include "Movie.h"
// constructor - initializes base class and movie fields
Movie::Movie(string t, int y, string d, int dur) 
    : Item(t, y), director(d), duration(dur) {
}

string Movie::getInfo() const {
    return title + " (" + to_string(year) + ") directed by " + director 
           + ", " + to_string(duration) + " min";
}
// getter for director
string Movie::getDirector() const { 
    return director; 
}
int Movie::getDuration() const { 
    return duration; 
}
// setter for director
void Movie::setDirector(string d) { 
    director = d; 
}
void Movie::setDuration(int dur) { 
    duration = dur; 
}
