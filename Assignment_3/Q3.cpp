/*
Q3. Stack is a Last-In-First-Out data structure. Write a Stack class that stores int type of data. It 
implements stack using Dynamically allocated array. Stack size should be passed in parameterized 
constructor. If size is not given, allocate stack of size 5. 
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().
*/

#include<iostream>

using namespace std;

class Stack{
    static int top;
    int data;
    int size;
    int *stack;

    public:

    Stack(int size){
        this->size=size;
        stack=new int[this->size];
    }

    void push(int data){
        if(top!=size-1){
            stack[++top]=data;
        }
        else{
            cout<<"Stack is full";
        }
    }

    void pop(){
        if(top==-1){
            cout<<"Stack is empty";
        }
        else{
            top--;
        }
    }

    void peek(){
        cout<<"The top element is :"<<stack[top];
    }

    void print(){
        for(int i=0;i<top+1;i++){
            cout<<stack[i]<<"   ";
        }
        cout<<"\n";
    }

    
    
};

int Stack::top=-1;

int main(){

    Stack st(5);
    int choice=5;
    int data;

    while(choice!=6){
        cout<<"Enter your choice :\n-----------------\n1.push\n2.pop\n3.peek\n4.print\n5.Exit\n";
        cin>>choice;
        switch(choice){
            case 1:{
                cout<<"Enter value to be pushed.\n";
                cin>>data;
                st.push(data);
                break;
            }
            case 2:{
                st.pop();
                break;
            }
            case 3:{
                st.peek();
                break;
            }
            case 4:{
                st.print();
                break;
            }
            default:{
                cout<<"Invalid Input\n";
                break;
            }
        }
    }
}