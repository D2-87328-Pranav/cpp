/*
Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll. 
Mostly they do, but sometimes a car goes by without paying. 
The tollbooth keeps track of the number of cars that have gone by and of the total amount of money 
collected. Model this tollbooth with a class called tollbooth. 
The two data items are a type unsigned int to hold the total number of cars, and a type double to 
hold the total amount of money collected. 
A constructor initializes all data members to 0. A member function called payingCar() increments 
the car total and adds 0.50 to the cash total. An other function, called nopayCar() 
increments the car total but adds nothing to the cash total. Finally, a member function called 
printOnConsole() displays the two totals and number of paying as well as non paying cars total. 
*/
#include<iostream>
using namespace std;

class TollBooth{
    unsigned int cars;
    double money;
    public:
    TollBooth(){
        cars=0;
        money=0;
    }

    void payingCar(){
        money=money+0.50;
        cars=cars+1;
    }

    void nopayCar(){
        cars=cars+1;
    }

    void printOnConsole(){
        cout<<"Total number of cars = "<<cars<<"    "<<"\nTotal paying cars="<<money/0.50<<"\nTotal not paying cars="<<cars-(money/0.50)<<"\nAmount collected = \n"<<money;
    }

};

int main(){
    int choice = 5;
    TollBooth tb;
    while (1)
    {
        cout << "Enter your choice\n-------------------\n";
        cout << "1.Paying cars\n";
        cout << "2.Not paying cars.\n";
        cout << "3.Print on console.\n";
        cout << "4.Exit.\n";
        cin >> choice;

        if (choice == 4)
            break;

        switch (choice)
        {
            case 1:
                tb.payingCar();
                break;

            case 2:
                tb.nopayCar();
                break;

            case 3:
                tb.printOnConsole();
                break;
        
            default:
                cout << "Invalid input\n";
                break;
        }
        
    }
    return 0;
}