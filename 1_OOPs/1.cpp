// classes and objects 
#include<bits/stdc++.h>
using namespace std;
class Car{
    private :
    string brand; 
    string model; 
    int speed; 

    public : 
    // default constructor 
    Car (){
        this->brand = "NA"; 
        this->model = "NA"; 
        this->speed = 0;
    }
    // parameterized constructor 
    Car (string brand, string model, int speed){
        this->brand = brand; 
        this->model = model; 
        this->speed = speed; 
    }

    // member functions can access the private member 
    void displayDetails(){
        cout << "Brand : " << brand << " Model : " << model << " Speed : " << speed << endl; 
    }
    void increment(int inc){
        speed += inc; 
    }

    // getters 
    string getBrand(){
        return this->brand; 
    }
    string getModel(){
        return this->model;
    }
    int getSpeed(){
        return this->speed; 
    }
    // setters
    void setModel(string model){
        this->model = model ;
    }
    void setBrand(string brand){
        this->brand = brand ;
    }
    void setSpeed(int speed){
        this->speed = speed; 
    }

};
int main(){ 
    Car car1 ; 
    Car car2("Honda","Two",93); 
    car1.getSpeed(); 
    car2.getSpeed();
    car2.displayDetails(); 
    car1.setBrand("Toyota"); 
    car1.displayDetails(); 
    return 0; 
}