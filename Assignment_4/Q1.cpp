/*
Q1. Create a class Date with data memebrs day,month and year. 
Cretae a class Person with data members name,address and birthdate. The birthdate shoud be of 
type Date. 
Implement above classes. Test all functionalities in main().\ 
*/
#include<iostream>

using namespace std;

class Date{
    int day,month,year;

    public:

    void setDay(int day){
        this->day=day;
    }
    int getDay(){
        return this->day;
    }

    void setMonth(int month){
        this->month=month;
    }
    int getMonth(){
        return this->month;
    }

    void setYear(int year){
        this->year=year;
    }
    int getYear(){
        return year;
    }
};

class Person{
    string name;
    string address;
    Date birthday;

    public:

    void setName(string name){
        this->name=name;
    }

    string getName(){
        return this->name;
    }

    void setAddress(string address){
        this->address=address;
    }

    string getAddress(){
        return address;
    }

    void setDate(int day,int month,int year){
        
        birthday.setDay(day);
        birthday.setMonth(month);
        birthday.setYear(year);
    }

    void getDetail(){
        cout<<"Name : "<<this->getName()<<endl;
        cout<<"Address : "<<this->getAddress()<<endl;
        cout<<"Date : "<<birthday.getDay()<<"/"<<birthday.getMonth()<<"/"<<birthday.getYear()<<endl;
    }
};

int main(){
    Person p;
    int choice=8;
    string name,address;
    int day,month,year;
    while(choice!=6){
        cout<<"Enter your choice :\n.------------------- \n1.Set Name\n2.Set Address\n3.Set Birthday\n4.Get Details\n5.Exit\n";
        cin>>choice;
        if(choice==5)
        break;
        switch (choice)
        {
            case 1:
                cout<<"Enter your name :\n";
                cin>>name;
                p.setName(name);
                break;

            case 2:
                cout<<"Enter your Address : \n";
                cin>>address;
                p.setAddress(address);
                break;

            case 3:
                cout<<"Enter your Date : \n";
                cin>>day;
                cin>>month;
                cin>>year;
                p.setDate(day,month,year);
                break;

            case 4:
                p.getDetail();
                break;
        
        default:
            cout<<"Invalid input.\n";
            break;
        }
    }
    return 0;
}

