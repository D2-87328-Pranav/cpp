/*
Q2. Write a menu driven program for Student management. 
Create a class student with data members name, gender, rollNumber(Auto generated) and array to 
keep marks of three subjects.  
Accept every thing from user and Print name, rollNumber, gender and percentage. 
Provide global functions void sortRecords() and int searchRecords() for sorting and searching array. 
In main(), create Student* arr[5] and provide facility for accept, print, search and sort. 
Search function returns index of found Student, otherwise returns -1. 
sortRecord sorts the students array based on roll no in descending order.
*/


#include<iostream>

using namespace std;

class Student{
    string name;
    int rollnumber;
    int static generatenumber;
    string gender;
    double persentage;
    int marks[3];

    public:

    Student(){
        this->rollnumber=generatenumber++;
    }

    void setName(string name){
        this->name=name;
    }

    string getName(){
        return this->name;
    }

    void setgender(string gender){
        this->gender=gender;
    }

    string getgender(){
        return this->gender;
    }

    void marksEntry(int marks1,int marks2,int marks3){
        this->marks[0]=marks1;
        this->marks[1]=marks2;
        this->marks[2]=marks3;
    }

    double calculate(){
        this->persentage=((this->marks[0]+this->marks[1]+this->marks[2])/300)*100;
    }



};

int Student::generatenumber=1;


int main(){
    Student *st=new Student[5];
    string name;
    int choice;
    static int i=1;
    int roll;
    int marks1,marks2,marks3;

    while(choice!=6){
        cout<<"Enter your choice :\n";
        cout<<"1.Add details of a student.\n2.Get student details.\n3.Exit\n";
        cin>>choice;
        switch (choice)
        {
            if(choice==3)
            break;
            case 1:
                cout<<"Enter Students Name:"<<endl;
                cin>>name;
                st[i].setName(name);

                cout<<"Enter Gender :\n";
                cin>>name;
                st[i].setgender(name);

                cout<<"Enter marks : \n";
                cin>>marks1;
                cin>>marks2;
                cin>>marks3;

                st[i].calculate();
                i++;

                break;

            case 2:
                cout<<"Enter roll number :";
                cin>>roll;
                cout<<roll<<"   "<<st[roll].getName()<<"   "<<st[roll].getgender()<<"   "<<st[roll].calculate();
                break;
        
        default:
            cout<<"Invalid input.\n";
            break;
        }
    }

}

