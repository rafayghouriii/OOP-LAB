#include <iostream>
#include <vector>
using namespace std;

class Media 
{
protected:
    string title, pubDate, uniqueId, publisher;

public:
    Media(string t, string date, string id, string pub)
        : title(t), pubDate(date), uniqueId(id), publisher(pub) {}

    virtual void showInfo() const
    {
        cout << "title: " << title << "\npublication date: " << pubDate
             << "\nunique id: " << uniqueId << "\npublisher: " << publisher << "\n";
    }

    string getTitle() const { return title; }
    string getPubDate() const { return pubDate; }

    virtual ~Media() {}
};

class Book : public Media 
{
private:
    string writer, isbn;
    int totalPages;

public:
    Book(string t, string date, string id, string pub, string w, string num, int pages)
        : Media(t, date, id, pub), writer(w), isbn(num), totalPages(pages) {}

    void showInfo() const override
    {
        Media::showInfo();
        cout << "writer: " << writer << "\nisbn: " << isbn << "\npages: " << totalPages << "\n";
    }

    string getWriter() const { return writer; }
};

class DVD : public Media 
{
private:
    string director;
    int duration;
    float rating;

public:
    DVD(string t, string date, string id, string pub, string d, int dur, float r)
        : Media(t, date, id, pub), director(d), duration(dur), rating(r) {}

    void showInfo() const override
    {
        Media::showInfo();
        cout << "director: " << director << "\nduration: " << duration << " min\nrating: " << rating << "\n";
    }
};

class CD : public Media 
{
private:
    string artist, genre;
    int trackCount;

public:
    CD(string t, string date, string id, string pub, string a, string g, int tracks)
        : Media(t, date, id, pub), artist(a), genre(g), trackCount(tracks) {}

    void showInfo() const override
    {
        Media::showInfo();
        cout << "artist: " << artist << "\ngenre: " << genre << "\ntracks: " << trackCount << "\n";
    }
};

void searchMedia(const vector<Media*>& collection, string searchTitle)
{
    for (auto item : collection)
    {
        if (item->getTitle() == searchTitle)
        {
            cout << "found:\n";
            item->showInfo();
            return;
        }
    }
    cout << "media not found.\n";
}

void searchMedia(const vector<Media*>& collection, string searchWriter, bool isWriter)
{
    for (auto item : collection)
    {
        Book* bookPtr = dynamic_cast<Book*>(item);
        if (bookPtr && bookPtr->getWriter() == searchWriter)
        {
            cout << "found:\n";
            bookPtr->showInfo();
            return;
        }
    }
    cout << "book not found.\n";
}

void searchMedia(const vector<Media*>& collection, int year)
{
    for (auto item : collection)
    {
        if (stoi(item->getPubDate()) == year)
        {
            cout << "found:\n";
            item->showInfo();
            return;
        }
    }
    cout << "no media found from year " << year << ".\n";
}

int main() 
{
    vector<Media*> collection;

    collection.push_back(new Book("silent ocean", "1995", "b123", "penguin books", "alex carter", "9876543210", 350));
    collection.push_back(new DVD("galaxy quest", "2001", "d567", "universal studios", "lisa roberts", 135, 7.9));
    collection.push_back(new CD("moonlight vibes", "2010", "c789", "sony music", "lucas evans", "jazz", 12));

    cout << "library collection:\n";
    for (auto item : collection)
    {
        item->showInfo();
        cout << "-----------------\n";
    }

    cout << "\nsearching by title:\n";
    searchMedia(collection, "galaxy quest");

    cout << "\nsearching by writer:\n";
    searchMedia(collection, "alex carter", true);

    cout << "\nsearching by year:\n";
    searchMedia(collection, 2010);

    for (auto item : collection) delete item;

    return 0;
}

