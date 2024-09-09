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
        Manager::accept();
        acceptSalesman();
    }

    void display()
    {
        Manager::display();
        displaySalesman();
    }
};

int menu()
{
    int choice;

    cout << "\n0. EXIT Menu" << endl;
    cout << "1. Accept Employee" << endl;
    cout << "2. Display the count of all employees with designation" << endl;
    cout << "3. Display all Managers" << endl;
    cout << "4. Display all Salesmen" << endl;
    cout << "5. Display all Sales Managers" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;
    return choice;
}

int main()
{

    Employee *arr[5];
    int choice, choice2;

    // arr[0] = new Manager();
    // arr[0]->accept();
    // arr[1] = new Salesman();
    // arr[1]->accept();
    // arr[2] = new SalesManager();
    // arr[2]->accept();
    // arr[3] = new Salesman();
    // arr[3]->accept();
    // arr[4] = new SalesManager();
    // arr[4]->accept();

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            cout << "\n----- Enter 5 Employee details -----";
            for (int i = 0; i < 5; i++)
            {
                cout << "\n1. Accept Manager" << endl;
                cout << "2. Accept Salesman" << endl;
                cout << "3. Accept Sales Manager" << endl;
                cout << "\nEnter your choice: ";
                cin >> choice2;

                switch (choice2)
                {
                case 1:
                {
                    cout << "\nEnter Manager details:";
                    arr[i] = new Manager();
                    arr[i]->accept();
                    break;
                }
                case 2:
                {
                    cout << "\nEnter Salesman details:";
                    arr[i] = new Salesman();
                    arr[i]->accept();
                    break;
                }
                case 3:
                {
                    cout << "\nEnter Sales Manager details:";
                    arr[i] = new SalesManager();
                    arr[i]->accept();
                    break;
                }
                default:
                    cout << "\nWrong choice" << endl;
                    break;
                }
            }
            break;
        }
        case 2:
        {
            int mana = 0, sales = 0, salesmana = 0;

            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]).name() == typeid(Manager).name())
                {
                    mana++;
                }
                else if (typeid(*arr[i]).name() == typeid(Salesman).name())
                {
                    sales++;
                }
                if (typeid(*arr[i]).name() == typeid(SalesManager).name())
                {
                    salesmana++;
                }
            }
            cout << endl;
            cout << "\n--------------------------" << endl;
            cout << mana << " are Managers" << endl;
            cout << sales << " are Salesmen" << endl;
            cout << salesmana << " are Sales Managers" << endl;
            cout << "\n--------------------------" << endl;
            break;
        }
        case 3:
        {
            cout << "\n--------------------------" << endl;
            cout << "\nManager List ->" << endl;
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]).name() == typeid(Manager).name())
                {
                    arr[i]->display();
                }
            }
            cout << "\n--------------------------" << endl;
            break;
        }
        case 4:
        {
            cout << "\n--------------------------" << endl;
            cout << "\nSalesmen List ->" << endl;
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]).name() == typeid(Salesman).name())
                {
                    arr[i]->display();
                }
            }
            cout << "\n--------------------------" << endl;
            break;
        }
        case 5:
        {
            cout << "\n--------------------------" << endl;
            cout << "\nSales Managers List ->" << endl;
            for (int i = 0; i < 5; i++)
            {
                if (typeid(*arr[i]).name() == typeid(SalesManager).name())
                {
                    arr[i]->display();
                }
            }
            cout << "\n--------------------------" << endl;
            break;
        }
        default:
            cout << "\nWrong choice" << endl;
            break;
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