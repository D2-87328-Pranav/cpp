/*
Q4. Create a namespace NStudent. Create the Student class(created as per Q3) inside namespace. 
Create the object of student and perform accept and display student.
*/

#include<iostream>

using namespace std;

namespace NStudent{
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
}

int main(){
    NStudent::Student s1;
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