/*
Q1. Write a class to find volume of a Cylinder by using following members. (volume of 
Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI) 
Class having following member functions: 
Cylinder() 
Cylinder(double radius, double height) 
getRadius() 
setRadius() 
getHeight() 
setHeight() 
calculateVolume() 
Initialize members using constructor member initializer list.
*/
#include<iostream>
using namespace std;

class Cylinder{

    private:

    static double pi;
    double radius;
    double height;

    public:

    Cylinder(){
        radius=10;
        height=10;
    }

    Cylinder(double radius, double height){
        this->radius=radius;
        this->height=height;
    }

    void setRadius(double radius){
        this->radius=radius;
    }

    int getRadius(){
        return radius;
    }

    void setHeight(double height){
        this->height=height;
    }

    int getHeight(){
        return height;
    }

    void calculateVolume(){
        cout<<"\nVolume = "<<pi*radius*radius*height;
    }

};

double Cylinder::pi=3.14;

int main(){
    double c1,c2;
    Cylinder cy;
    cy.setHeight(20);
    cy.setRadius(5);
    cout<<cy.getHeight();
    cout<<cy.getRadius();
    cy.calculateVolume();
    return 0;
}