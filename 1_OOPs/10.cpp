// runtime polymorphism and virtual functions
#include <bits/stdc++.h>
using namespace std ;
class Car {
    int x; 
    public : 
    virtual void start() = 0; // pure virtual functions are equated to 0; their only purpose it to be overridden
    void display(){
        cout << "Hello display" << endl; 
    }

    // this class has both - concrete & virtual functions - it is abstract class ; its object cannot be instantiated 
};
class Swift : public Car {
    int y; 
    public : 
    void start(){
        cout << "Swift Start" << endl; 
    }
};
class Innova : public Car{
    int z; 
    public : 
    void start(){
        cout << "Innova Start" << endl; 
    }
};
int main(){
    Car* ptr = new Swift; 
    ptr->start(); // op -> Swift start 
    Car* ptr2 = new Innova ; 
    ptr2->start(); // op -> innova start  
    // achieved runtime polymorphism by : 
    // 1. Pointer of base class 
    // 2. object of derived class 
    // 3. overriding of functions 
    // in the base class we defined the functions as virtual ones 
}