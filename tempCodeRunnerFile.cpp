#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    string reldate;
    string genre;
    int rating;

public:
    // Constructor
    Book(string title, string author, string reldate, string genre, int rating) {
        this->title = title;
        this->author = author;
        this->reldate = reldate;
        this->genre = genre;
        this->rating = rating;
    }

    // Destructor
    ~Book() {
        cout << "Deleting book: " << title << endl;
    }

    void display() const {
        cout << "\nBook Details" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Release Date: " << reldate << endl;
        cout << "Genre: " << genre << endl;
        cout << "Rating: " << rating << "/5" << endl;
    }

    string gettitle() const {
        return title;
    }
};

int main() {
    vector<Book> books;
    char performAnother;

    do {
        int choice;
        
        cout << "\nEnter operation:\n";
        cout << "1. Add book\n2. Display all books\n3. Search a book\n4. Exit\n";
        cout << "Enter your choice: ";
        
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        cin.ignore();  // Clear input buffer

        switch (choice) {
        case 1: {
            char addMore;
            do {
                string title, author, reldate, genre;
                int rating;

                cout << "\nEnter book title: ";
                getline(cin, title);

                cout << "Enter book author: ";
                getline(cin, author);

                cout << "Enter book release date: ";
                getline(cin, reldate);

                cout << "Enter book genre: ";
                getline(cin, genre);

                cout << "Enter book rating (1-5): ";
                while (!(cin >> rating) || rating < 1 || rating > 5) {
                    cout << "Invalid input. Enter a rating between 1 and 5: ";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                cin.ignore();  // Clear input buffer

                books.push_back(Book(title, author, reldate, genre, rating));
                cout << "New book added successfully.\n";

                // Ask if the user wants to add another book
                cout << "Do you want to add another book? (Y/N): ";
                cin >> addMore;
                cin.ignore();

            } while (addMore == 'Y' || addMore == 'y');
            break;
        }

        case 2: {
            if (books.empty()) {
                cout << "\nNo books available." << endl;
            } else {
                cout << "\nList of Books:\n";
                for (const auto &book : books) {
                    book.display();
                    cout << "------------------" << endl;
                }
            }
            break;
        }

        case 3: {
            if (books.empty()) {
                cout << "\nNo books available to search." << endl;
                break;
            }

            string searchtitle;
            cout << "\nEnter book title to search: ";
            cin.ignore();  
            getline(cin, searchtitle);

            bool found = false;
            for (const auto &book : books) {
                if (book.gettitle() == searchtitle) {
                    cout << "\nBook Found:\n";
                    book.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nBook not found." << endl;
            }
            break;
        }

        case 4:
            cout << "\nExiting program. Goodbye!" << endl;
            return 0;

        default:
            cout << "\nInvalid choice. Please enter a valid option." << endl;
        }

        // Ask if the user wants to perform another operation
        cout << "\nDo you want to perform another operation? (Y/N): ";
        cin >> performAnother;
        cin.ignore();

    } while (performAnother == 'Y' || performAnother == 'y');

    cout << "\nExiting program. Goodbye!" << endl;
    return 0;
}
