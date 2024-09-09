#include <iostream>
using namespace std;

class Date
{
    int day, month, year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout << "\nEnter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Person
{
    string name, address;
    Date birthdate;

public:
    Person()
    {
        this->name = "NoName";
        this->address = "NoAddress";
    }

    void acceptPerson()
    {
        cout << "\nEnter name: ";
        // cin.ignore();
        getline(cin, name);

        cout << "Enter address: ";
        // cin.ignore();
        getline(cin, address);

        cout << "Enter birthdate: ";
        birthdate.acceptDate();
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: ";
        birthdate.displayDate();
        cout << endl;
    }
};

class Employee : public Person
{
    int id;
    double sal;
    string dept;
    Date doj;

public:
    Employee()
    {
        this->id = 0;
        this->sal = 0;
        this->dept = "NoDept";
    }

    Employee(int id, double sal, string dept)
    {
        this->id = id;
        this->sal = sal;
        this->dept = dept;
    }

    void acceptEmployee()
    {
        Person::acceptPerson();
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> sal;
        cout << "Enter department: ";
        cin.ignore();
        getline(cin, dept);
        cout << "Enter date of joining: ";
        doj.acceptDate();
    }

    void printEmployee()
    {
        Person::displayPerson();
        cout << "ID: " << id << endl;
        cout << "Salary: " << sal << endl;
        cout << "Department: " << dept << endl;
        cout << "Date of Joining: ";
        doj.displayDate();
        cout << "\n";
    }
};

int main()
{
    // Person p1;
    Employee e1;

    e1.acceptEmployee();

    cout << "\n\nPrinting Employee Details:" << endl;
    e1.printEmployee();

    return 0;
}