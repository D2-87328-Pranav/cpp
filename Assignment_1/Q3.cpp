/*
Q3. Write a menu driven program for Student in CPP language. Create a class student with data 
members roll no, name and marks. Implement the following functions 
void initStudent(); 
void printStudentOnConsole(); 
void acceptStudentFromConsole();
*/
#include<iostream>
#include <string>

using namespace std;

class Student{
    int roll;
    string name;
    int marks;

    public:

    void initStudent(){
        roll=0;
        //name='\0';
        marks=0;
    }

    void printStudentOnConsole(){
        cout<<roll<<"   "<<name<<"  "<<marks<<endl;
    }

    void acceptStudentFromConsole(){
        cout<<"Enter your roll no.\n";
        cin>>roll;
        cin.ignore();
        cout<<"Enter your name no.\n";
        getline(cin,name);
        cout<<"Enter your marks\n";
        cin>>marks;
    }

};

int main(){
    Student s1;
    int choice=4;
    s1.initStudent();
    while(choice){
        cout<<"Enter your choice :\n\n1.Accept \n2.Print\n3.Exit\n";
        cin>>choice;
        if(choice==3){
            break;
        }
        switch (choice)
        {
        case 1:
            s1.acceptStudentFromConsole();
            break;
        case 2:
            s1.printStudentOnConsole();
            break;
        default:
            cout<<"Invalid Input";
            break;
        }
    }
}