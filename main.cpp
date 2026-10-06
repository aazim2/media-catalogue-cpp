#include <iostream>
#include <vector>
#include <limits>
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

using namespace std;
void clearInput() {
    cin.clear();  // clear error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discard remaining input
}
void addItem(vector<Book>&, vector<Movie>&, vector<Magazine>&);
void updateItem(vector<Book>&, vector<Movie>&, vector<Magazine>&);
void viewItem(vector<Book>&, vector<Movie>&, vector<Magazine>&);
void listAll(vector<Book>&, vector<Movie>&, vector<Magazine>&);

int main() {
    vector<Book> books;
    vector<Movie> movies;
    vector<Magazine> magazines;

    int choice;  // stores user menu choice
    
    cout << "      WELCOME TO MY LIBRARY SYSTEM      " << endl;
    do {
        
        cout << "=== MAIN MENU ===" << endl;// display menu options
        cout << "1. Add a new item" << endl;
        cout << "2. Update an existing item" << endl;
        cout << "3. View an item by ID" << endl;
        cout << "4. List all items in library" << endl;
        cout << "5. Exit program" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        
        switch (choice) {//user choice
            case 1: 
                addItem(books, movies, magazines);  // add new item
                break;
            case 2: 
                updateItem(books, movies, magazines);  // update existing
                break;
            case 3: 
                viewItem(books, movies, magazines);  // view one item
                break;
            case 4: 
                listAll(books, movies, magazines);  // show everything
                break;
            case 5: 
                cout << "Thanks for using my library system!" << endl;
                
                break;
            default: 
                cout << "Invalid choice. Please enter 1, 2, 3, 4, or 5.\n";
                break;
        }
    } while (choice != 5);  // exit when user chooses 5

    return 0;  // program ends successfully
}

void addItem(vector<Book>& books, vector<Movie>& movies, vector<Magazine>& magazines) {
    int type;
    cout << "\n--- ADD NEW ITEM ---" << endl;
    cout << "What type of item do you want to add?" << endl;
    cout << "1. Book" << endl;
    cout << "2. Movie" << endl;
    cout << "3. Magazine" << endl;
    cout << "Choice: ";
    cin >> type;
    clearInput();  // important! otherwise getline will skip

    string title;
    int year;

    cout << "Enter title: "; // get common info for all items
    getline(cin, title);
    cout << "Enter year: ";
    cin >> year;
    clearInput();

    if (type == 1) {
        string author;
        cout << "Enter author name: ";
        getline(cin, author);
        
        books.push_back(Book(title, year, author));
        cout << "\n[SUCCESS] Book added to library!" << endl;
        cout << "Your book ID is: " << books.size() << endl;
        cout << "(Remember this ID to view or update later)\n" << endl;
    }
    else if (type == 2) {
        string director; // adding a movie - need director and duration
        int duration;
        cout << "Enter director name: ";
        getline(cin, director);
        cout << "Enter duration (in minutes): ";
        cin >> duration;
        clearInput();
        
        movies.push_back(Movie(title, year, director, duration));
        cout << "\n[SUCCESS] Movie added to library!" << endl;
        cout << "Your movie ID is: " << movies.size() << endl;
        cout << "(Remember this ID to view or update later)\n" << endl;
    }
    else if (type == 3) {
        int issue;  // adding a magazine - need issue number
        cout << "Enter issue number: ";
        cin >> issue;
        clearInput();
        
        magazines.push_back(Magazine(title, year, issue));
        cout << "\n[SUCCESS] Magazine added to library!" << endl;
        cout << "Your magazine ID is: " << magazines.size() << endl;
        cout << "(Remember this ID to view or update later)\n" << endl;
    }
    else {
        cout << "Invalid type. Please choose 1, 2, or 3.\n";
    }
}

void updateItem(vector<Book>& books, vector<Movie>& movies, vector<Magazine>& magazines) {
    int type, userID;
    cout << "\n--- UPDATE ITEM ---" << endl;
    cout << "What type of item do you want to update?" << endl;
    cout << "1. Book" << endl;
    cout << "2. Movie" << endl;
    cout << "3. Magazine" << endl;
    cout << "Choice: ";
    cin >> type;
    cout << "Enter the ID of the item to update: ";
    cin >> userID;
    clearInput();

    int internalID = userID - 1;// IMPORTANT: convert user ID (starts at 1) to internal index (starts at 0)

    if (type == 1) {
        if (internalID >= 0 && internalID < (int)books.size()) {// update a book. first check if ID exists
            string title, author;
            int year;
            
            cout << "Enter new title: ";
            getline(cin, title);
            cout << "Enter new year: ";
            cin >> year;
            clearInput();
            cout << "Enter new author: ";
            getline(cin, author);
            
            books[internalID].setTitle(title);  // update all fields
            books[internalID].setYear(year);
            books[internalID].setAuthor(author);
            cout << "\n[SUCCESS] Book updated successfully!\n" << endl;
        } else {
            cout << "\n[ERROR] Invalid ID. Book not found.\n" << endl;
        }
    }
    else if (type == 2) {
        if (internalID >= 0 && internalID < (int)movies.size()) { // update a movie
            string title, director;
            int year, duration;
            
            cout << "Enter new title: ";
            getline(cin, title);
            cout << "Enter new year: ";
            cin >> year;
            cout << "Enter new director: ";
            clearInput();  // need to clear before getline
            getline(cin, director);
            cout << "Enter new duration (minutes): ";
            cin >> duration;
            clearInput();
            
            movies[internalID].setTitle(title);
            movies[internalID].setYear(year);
            movies[internalID].setDirector(director);
            movies[internalID].setDuration(duration);
            cout << "\n[SUCCESS] Movie updated successfully!\n" << endl;
        } else {
            cout << "\n[ERROR] Invalid ID. Movie not found.\n" << endl;
        }
    }
    else if (type == 3) {
        if (internalID >= 0 && internalID < (int)magazines.size()) {  // update a magazine
            string title;
            int year, issue;
            
            cout << "Enter new title: ";
            getline(cin, title);
            cout << "Enter new year: ";
            cin >> year;
            cout << "Enter new issue number: ";
            cin >> issue;
            clearInput();
            
            magazines[internalID].setTitle(title);
            magazines[internalID].setYear(year);
            magazines[internalID].setIssueNumber(issue);
            cout << "\n[SUCCESS] Magazine updated successfully!\n" << endl;
        } else {
            cout << "\n[ERROR] Invalid ID. Magazine not found.\n" << endl;
        }
    }
    else {
        cout << "Invalid type. Please choose 1, 2, or 3.\n";
    }
}

void viewItem(vector<Book>& books, vector<Movie>& movies, vector<Magazine>& magazines) {
    int type, userID;
    cout << "\n--- VIEW ITEM ---" << endl;
    cout << "What type of item do you want to view?" << endl;
    cout << "1. Book" << endl;
    cout << "2. Movie" << endl;
    cout << "3. Magazine" << endl;
    cout << "Choice: ";
    cin >> type;
    cout << "Enter the ID of the item to view: ";
    cin >> userID;
    clearInput();
    
    int internalID = userID - 1;// convert user ID to internal index

    if (type == 1) {
        if (internalID >= 0 && internalID < (int)books.size()) {  // view a book
            cout << books[internalID].getInfo() << endl;
        } else {
            cout << "\n[ERROR] Invalid ID. Book not found.\n" << endl;
        }
    }
    else if (type == 2) {
        if (internalID >= 0 && internalID < (int)movies.size()) {
            cout << movies[internalID].getInfo() << endl;
        } else {
            cout << "\n[ERROR] Invalid ID. Movie not found.\n" << endl;
        }
    }
    else if (type == 3) {
        if (internalID >= 0 && internalID < (int)magazines.size()) {
            cout << magazines[internalID].getInfo() << endl;
        } else {
            cout << "\n[ERROR] Invalid ID. Magazine not found.\n" << endl;
        }
    }
    else {
        cout << "Invalid type. Please choose 1, 2, or 3.\n";
    }
}

void listAll(vector<Book>& books, vector<Movie>& movies, vector<Magazine>& magazines) {
    cout << "           LIBRARY CATALOG              " << endl;
    
    
    cout << "--- BOOKS ---" << endl;// display all books
    if (books.empty()) {
        cout << "No books in library yet. Add some!\n" << endl;
    } else {
        for (size_t i = 0; i < books.size(); i++) {
            cout << "[" << i + 1 << "] " << books[i].getInfo() << endl;// show user ID = index + 1
        }
        cout << endl;
    }
    
    cout << "--- MOVIES ---" << endl;// display all movies
    if (movies.empty()) {
        cout << "No movies in library yet. Add some!\n" << endl;
    } else {
        for (size_t i = 0; i < movies.size(); i++) {
            cout << "[" << i + 1 << "] " << movies[i].getInfo() << endl;
        }
        cout << endl;
    }
    cout << "--- MAGAZINES ---" << endl;// display all magazines
    if (magazines.empty()) {
        cout << "No magazines in library yet. Add some!\n" << endl;
    } else {
        for (size_t i = 0; i < magazines.size(); i++) {
            cout << "[" << i + 1 << "] " << magazines[i].getInfo() << endl;
        }
        cout << endl;
    }  
    cout << "Total items: " << (books.size() + movies.size() + magazines.size()) << endl;
}
