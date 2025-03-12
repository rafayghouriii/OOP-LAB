#include <iostream>
#include <string>
using namespace std;
class Books
{
    protected:
        string category;
    
    public:
        Books(string category)
        {
            this->category = category;
        }

        void virtual display()
        {
            cout << "genre: " << category << endl;
        }
};

class Mystery : public Books
{
    private:
        string book_title;
        string writer;
    
    public:
        Mystery(string t, string w) : Books("mystery"), book_title(t), writer(w) {}
    
        void display() override
        {
            Books::display();
            cout << "title: " << book_title << endl;
            cout << "author: " << writer << endl;
        }
};

class Novel : public Books
{
    private:
        string book_title;
        string writer;
    
    public:
        Novel(string t, string w) : Books("novel"), book_title(t), writer(w) {}
    
        void display() override
        {
            Books::display();
            cout << "title: " << book_title << endl;
            cout << "author: " << writer << endl;
        }
};

int main()
{
    Novel n("Charie and the chocolate factory", "enid blyton");
    Mystery m("Seven seas", "Raul garcia");
    n.display();
    cout<<endl;
    m.display();
    return 0;
}

