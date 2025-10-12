// counting the number of objects a class has using static variable and functions 
#include<bits/stdc++.h>
using namespace std; 
class Animal{
    string name; 
    int age, speed; 
    static int count;  // accessed by any function. Always initialized to 0 
    public:
    Animal(string name, int age, int speed){
        this->name = name; 
        this->age = age; 
        this->speed = speed; 
        count ++; 
    }

    int getCount(){
        return count; 
    }
    static int getCount2(){
        return count;  // static function can only access static variable 
    }
};
int Animal::count ; // storage allocation for the variable since it is not the part of any object but rather the class 
int main(){
    Animal a1("s",4,5); 
    Animal a2("g",1,7); 
    Animal a3("w",6,2);

    cout << a1.getCount() << endl; 
    cout << Animal::getCount2() << endl;  // calling static function 
    return 0; 
}