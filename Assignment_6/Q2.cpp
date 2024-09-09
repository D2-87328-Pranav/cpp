/*
Q2. Write a user defined function factorial() that calculates factorial of given number and it throws 
exception if number entered by user is negative.
*/


#include<iostream>
using namespace std;

void factorial(int f){

    if(f<0){
        throw 1;
    }
    int fact=1;
    for(int i=1;i<=f;i++){
        fact=fact*i;
    }
    cout<<"Factorial : "<<fact;
    
}

int main(){
    int f;
    cout<<"Enter the number :\n";
    cin>>f;
    
    try{
        factorial(f);
    }
    catch(int e){
        cout<<"Invalid Input.";
    }
    
    return 0;
}