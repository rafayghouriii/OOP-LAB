#include <iostream>
#include <vector>
using namespace std;
class Book 
{
	public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i)
	{
		
	}
    void display() const
	{
        cout << "title: " << title << ", author: " << author << ", ISBN: " << isbn <<endl;
    }
};

class Catalog
{
	private:
	vector<Book*> books;
	public:
    void addbook(Book* book)
	{
        books.push_back(book);
    }
    void removebook(const string& isbn)
	{
        for (size_t i = 0; i < books.size(); ++i)
		{
            if (books[i]->isbn == isbn)
			{
                books.erase(books.begin() + i);
                break;
            }
        }
    }
    Book* findbook(const string& isbn) {
        for (Book* book : books) {
            if (book->isbn == isbn) {
                return book;
            }
        }
        return nullptr;
    }
};

class Library
{
	private:
    string name;
    string address;
    Catalog catalog;
    vector<Book*> books;

	public:
    Library(string n, string addr) : name(n), address(addr)
	{
		
	}
    void addbook(Book* book)
	{
        books.push_back(book);
        catalog.addbook(book);
    }
    void removebook(const string& isbn)
	{
        for(size_t i = 0; i < books.size(); ++i)
		{
            if (books[i]->isbn == isbn)
			{
                books.erase(books.begin() + i);
                break;
            }
        }
        catalog.removebook(isbn);
    }
    void findbookincatalog(const string& isbn)
	{
        Book* book = catalog.findbook(isbn);
        if (book)
		{
            cout <<"book found in catalog: "<<endl;
            book->display();
        } else {
            cout <<"Book not found in catalog"<<endl;
        }
    }
    void displaybooks()
	{
        cout <<"library: " << name << " ("<<address<<")\nBooks: "<<endl;
        for(Book* book : books) book->display();
    }
};
int main()
{
    Library lib("Town Library", "Addison Park St.");
    Book book1("C++ Primer", "Stanley B. Lippman", "154525449");
    Book book2("Effective Modern C++", "Scott Meyers", "5286332421");
    lib.addbook(&book1);
    lib.addbook(&book2);
    lib.displaybooks();
    lib.findbookincatalog("2489542389");
    lib.findbookincatalog("04235240");
    lib.removebook("154525449");
    lib.displaybooks();
    
    return 0;
}
