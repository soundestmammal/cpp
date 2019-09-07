#include <iostream>
#include <string>
using namespace std;

class Book {

private:
    int numPages;
    string bookName;
    string author;
    string publishDate;

public:
    Book() {
        numPages = 0;
        bookName = "None";
        author = "Jane Doe";
        publishDate = "Never";
    }

    Book(int n, string b, string a, string p) {
        numPages = n;
        bookName = b;
        author = a;
        publishDate = p;
    }

    ~Book() {
        cout << "Destructor" << endl;
    }

    int getNumPages() { return numPages; }
    void setNumPages(int p) {
        if(p > 0) {
            numPages = p;
        }
    }
    string getBookName() { return bookName; }
    void setBookName(string b) { bookName = b; }
    string getAuthor() { return author; }
    void setAuthor(string a) { author = a; }
    string getPublishDate() { return publishDate; }
    void setPublishDate(string pd) { publishDate = pd; }

    void getAllInfo() {
        cout << "Book Name:     " << getBookName() << endl;
        cout << "Number of pages:   " << getNumPages() << endl;
        cout << "Author     " << getAuthor() << endl;
        cout << "Publish Date   " << getPublishDate() << endl;
    }
};

class Nose {
    private:
        int size;
        string type;
        static int counter;
    public:
        Nose(int size = 5, string type = "Normal") {
            if(size > 10 || size < 1) {
                cout << "That is an invalid nose size. Defaulted to average size of 5. [1,10]" << endl;
                this->size = 5;
            }
            this->size = size;
            this->type = type;
            counter++;
        }

        void setSize(int s) { size = s; }
        int getSize() { return size; }
        void setType(string t) { type = t; }
        string getType() { return type; }
        static void showCounter() {
            cout << "Current count:     " << counter << endl;
        }

};

int Nose::counter = 0;

int main() {
    Book book1;
    Book book2(314, "Algorithms", "CLRS", "April 2010");
    book1.getAllInfo();
    book2.getAllInfo();
    
    Nose nose1;
    Nose nose2(8, "Large");
    cout << nose1.getSize() << endl;
    cout << nose1.getType() << endl;
    nose2.showCounter();
    
    return 0;
}