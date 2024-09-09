#include <iostream>
using namespace std;

class Employee
{
    int id;
    double salary;

public:
    Employee()
    {
        id = 100;
        salary = 0;
    }
    Employee(int id, double salary)
    {
        this->id = id;
        this->salary = salary;
    }

    virtual void accept()
    {
        cout << "\nEnter ID: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "\nID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    void setID(int id)
    {
        this->id = id;
    }

    int getID()
    {
        return id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return salary;
    }
};

class Manager : virtual public Employee
{
    double bonus;

public:
    Manager()
    {
        bonus = 0;
    }
    Manager(int id, double salary, double bonus) : Employee(id, salary)
    {
        this->bonus = bonus;
        // setID(id);                       // Alternatives
        // setSalary(salary);
    }

    void accept()
    {
        // cout << "\nEnter Manager details: " << endl;
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return bonus;
    }

protected:
    void acceptManager()
    {
        cout << "Enter bonus: ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus: " << bonus << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

public:
    Salesman()
    {
        commission = 0;
    }
    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commission = commission;
    }

    void accept()
    {
        // cout << "\nEnter Salesman details: " << endl;
        Employee::accept();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displaySalesman();
    }

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission()
    {
        return commission;
    }

protected:
    void acceptSalesman()
    {
        cout << "Enter commission: ";
        cin >> commission;
    }
    void displaySalesman()
    {
        // cout << "Employee is a Salesman" << endl;
        cout << "Commission: " << commission << endl;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
    }
    SalesManager(int id, double salary, double bonus, double commission) : Manager(id, salary, bonus)
    {
        setCommission(commission);
    }

    void accept()
    {
        cout << "\nEnter Sales manager details: " << endl;
        Manager::accept();
        acceptSalesman();
    }

    void display()
    {
        // cout << "\nSales Manager:" << endl;
        Manager::display();
        displaySalesman();
    }
};

int main()
{

    Employee *arr[5];

    arr[0] = new Manager();
    arr[0]->accept();

    arr[1] = new Salesman();
    arr[1]->accept();

    arr[2] = new SalesManager();
    arr[2]->accept();

    arr[3] = new Salesman();
    arr[3]->accept();

    arr[4] = new SalesManager();
    arr[4]->accept();

    // print all managers
    cout << "\n--------------------------" << endl;
    cout << "\nManager List ->" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (typeid(*arr[i]).name() == typeid(Manager).name())
        {
            arr[i]->display();
            // Manager *mana = (Manager *)arr[i]; // Downcasting
            // mana->displayManager();
        }
    }

    // print all salesmen
    cout << "\n--------------------------" << endl;
    cout << "\nSalesmen List ->" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (typeid(*arr[i]).name() == typeid(Salesman).name())
        {
            arr[i]->display();
            // Salesman *salesmen = (Salesman *)arr[i]; // Downcasting
            // salesmen->displaySalesman();
        }
    }

    // print all salesmanagers
    cout << "\n--------------------------" << endl;
    cout << "\nSales Managers List ->" << endl;
    for (int i = 0; i < 5; i++)
    {
        if (typeid(*arr[i]).name() == typeid(SalesManager).name())
        {
            arr[i]->display();
            // Salesman *salesmen = (Salesman *)arr[i]; // Downcasting
            // salesmen->displaySalesman();
        }
    }

    for (int i = 0; i < 5; i++)
    {
        delete arr[i];
    }
    for (int i = 0; i < 5; i++)
    {
        arr[i] = NULL;
    }
    return 0;
}