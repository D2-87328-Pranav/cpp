#include <iostream>
using namespace std;

class Product
{
    int id;
    string title;

public:
    int price;
    Product() : price(100)
    {
        id = 0;
        // price = 100;
        title = "NoTitle";
    }

    Product(int id, string title)
    {
        this->id = id;
        this->title = title;
    }

    virtual void accept()
    {
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
    }

    virtual void display()
    {
        cout << "Title: " << title << endl;
        cout << "ID: " << id << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Product
{
    string author;

public:
    Book()
    {
    }

    Book(int id, string title, string author) : Product(id, title)
    {
        this->author = author;
    }

    void accept()
    {
        cout << "Enter author name: ";
        cin.ignore();
        getline(cin, author);
        Product::accept();
    }

    void display()
    {
        cout << "\n** Book **" << endl;
        cout << "Author: " << author << endl;
        Product::display();
    }
    int calculatePrice()
    {
        // cout << "Price of Book: " << (0.90 * price) << endl;
        this->price = (0.90 * price);
        return price;
    }
};

class Tape : public Product
{
    string artist;

public:
    Tape()
    {
    }

    Tape(int id, string title, string artist) : Product(id, title)
    {
        this->artist = artist;
    }

    void accept()
    {
        cout << "Enter artist name: ";
        cin.ignore();
        getline(cin, artist);
        Product::accept();
    }

    void display()
    {
        cout << "\n** Tape **" << endl;
        cout << "Artist: " << artist << endl;
        Product::display();
    }
    int calculatePrice()
    {
        this->price = (0.95 * price);
        return price;
    }
};

int main()
{
    Product *arr[3];
    int choice;
    int bill = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << "\nSelect product " << (i + 1) << ":" << endl;

        cout << "1. Get Book" << endl;
        cout << "2. Get Tape" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            arr[i] = new Book();
            arr[i]->accept();
            Book *bk = (Book *)arr[i];
            bill = bill + bk->calculatePrice();
            break;
        }
        case 2:
        {
            arr[i] = new Tape();
            arr[i]->accept();
            Tape *tp = (Tape *)arr[i];
            bill = bill + tp->calculatePrice();
            break;
        }
        default:
        {
            cout << "Wrong Choice" << endl;
            break;
        }
        }
    }

    cout << "\n\n**Selected products are ** " << endl;
    for (int i = 0; i < 3; i++)
    {
        arr[i]->display();
    }
    cout << "\nTotal Bill: " << bill << endl;

    for (int i = 0; i < 3; i++)
    {
        delete arr[i];
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i] = NULL;
    }
    return 0;
}