#ifndef MOVIE_H
#define MOVIE_H
#include "Item.h"
class Movie : public Item {
private:
    string director;  // who directed the movie
    int duration;     // length in minutes

public:
    // constructor - takes title, year, director, and duration
    Movie(string t, int y, string d, int dur);
    
    // override the getInfo function
    string getInfo() const override;
    
    // getters and setters for movie-specific stuff
    string getDirector() const;
    int getDuration() const;
    void setDirector(string d);
    void setDuration(int dur);
};
#endif
