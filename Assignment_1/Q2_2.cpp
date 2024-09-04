/*
Q2. Write a menu driven program for Date in a CPP language using structure and also using class. 
Date is having data members day, month, year. Implement the following functions. 
void initDate(); 
void printDateOnConsole(); 
void acceptDateFromConsole(); 
bool isLeapYear();
*/

#include<iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

    public:

    void initDate()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    void printDateOnConsole()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }

    void acceptDateFromConsole()
    {
        cout<<"Enter the Date :\n";
        cin>>day;
        cin>>month;
        cin>>year;
    }

    bool isLeapYear()
    {
        if(year%100==0){
            if(year%400==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(year%4==0){
                return true;
            }
            else{
                return false;
            }
        }
    }
    
};

int main(){
    int choice=4;
    Date d1;
    d1.initDate();
    while (choice)
    {
        cout<<"Enter your choice : \n\n1.Accept date\n2.Print date\n3.Is leap year\n4.Exit\n\n";
        cin>>choice;
        if (choice == 4)
        {
            break;
        }
        switch(choice)
        {
            case 1:
                d1.acceptDateFromConsole();
                break;

            case 2:
                d1.printDateOnConsole();
                break;

            case 3: 
                if(d1.isLeapYear())
                    cout<<"Yes"<<endl;
                else
                    cout<<"No"<<endl;
                break;

            default:
                printf("Invalid choice.\n");
        
        }
    }
    return 0;
}
