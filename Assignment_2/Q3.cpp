/*
Q3. Write a class Address with data members (string building, string street, string city ,int pin) 
 Implement constructors, getters, setters, accept(), and display() methods. 
Test the class functunalities by creating the object of class and calling all the functions. 
*/

#include<iostream>

using namespace std;

class Address{
    private:
    string building;
    string street;
    string city;
    int pin;

public:

    Address(){

    }

    void setBuilding(string name){
        building=name;
    }

    string getBuilding(){
        return building;
    }

    void setStreet(string name){
        street=name;
    }

    string getStreet(){
        return street;
    }
    
    void setCity(string name){
        city=name;
    }

    string getCity(){
        return city;
    }

    void setPin(int pin){
        pin=pin;
    }

    int getPin(){
        return pin;
    }

    void accept(){
        cout<<"Enter building name:\n";
        cin>>building;
        cout<<"Enter city name :\n";
        cin>>city;
        cout<<"Enter street name:\n";
        cin>>street;
        cout<<"Enter PIN code:\n";
        cin>>pin;
    }

    void display(){
        cout<<"Building = \n"<<this->building;
        cout<<"City = \n"<<this->city;
        cout<<"Street = \n"<<this->street;
        cout<<"PIN = \n"<<this->pin;
    }

};

int main(){
    Address ad;
    ad.accept();
    ad.display();
    return 0;
}