/*
Q2. Write a class for Time and provide the functionality 
Time() 
Time(int h,int m,int s) 
getHour() 
getMinute() 
getSeconds() 
printTime() 
setHour() 
setMinute() 
setSeconds() 
In main create array of objects of Time. 
Allocate the memory for the array and the object dynamically.
*/

#include<iostream>

using namespace std;

class Time{
    int hour,min,sec;
    public:
    Time(){

    }
    Time(int h,int m,int s){
        this->hour=h;
        this->min=m;
        this->sec=s;
    } 
    int getHour(){
        return hour;
    } 
    int getMinute() {
        return min;
    }
    int getSeconds(){
        return sec;
    } 
    void printTime() {
        cout<<hour<<":"<<min<<":"<<sec;
    }
    void setHour(int h){
        this->hour=h;
    } 
    void setMinute(int min){
        this->min=min;
    } 
    void setSeconds(int sec){
        this->sec=sec;
    } 
};

int main(){
    Time **ptr=new Time*[5];
    ptr[0]= new Time(3,4,5);
    ptr[1] = new Time(4,6,7);
    ptr[2] = new Time(5,7,8);
    ptr[3] = new Time(1,3,8);
    ptr[4] = new Time(3,7,7);

    cout<<ptr[1]->getHour()<<":"<<ptr[1]->getMinute()<<":"<<ptr[1]->getSeconds();

    for(int i=0;i<5;i++){
        delete ptr[i];
    }
    delete[] ptr;
    
    return 0;   
}