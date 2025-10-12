// runtime polymorphism and virtual functions
#include <bits/stdc++.h>
using namespace std ;
class Car {
    int x; 
    public : 
    void start(){
        cout << "Car Start" << endl; 
    }
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
    ptr->start(); // op -> Car start = this is wrong according to real world scenario 
    //because in overriding the function of the pointer is called instead of base 
    // The pointer is of type base and object is of type derived so desirably we want the function of object to be called 
    // in order to achieve this runtime polymorphism we use the concept of virtual classes 
}