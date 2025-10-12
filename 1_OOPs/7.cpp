// imheritence 
#include <bits/stdc++.h>
using namespace std ;
class Base{
    int x; 
    public: 
    // default constructor 
    Base(){
        cout << "Base default"<<endl; 
        this->x=0;
    }
    // parameterized constructor 
    Base(int x){
        cout << "Base parameterized"<<endl; 
        this->x=x; 
    }
};
class Derived : public Base{
    int y; 
    public:
    // default constructor 
    Derived(){
        cout << "Derived default"<<endl; 
        this->y=0;
    }
    // parameterized constructor 
    Derived(int y){
        cout << "Derived parameterized"<<endl; 
        this->y=y; 
    }
    Derived(int x, int y):Base(x){ // this calls the parameterized constructor of the base 
        cout << "Derived parameterized 2"<<endl;
        this->y=y; 
    }
};
int main(){
    Derived d1; // base constructor is always called first -> base, then derived 
    Derived d2(4); // the default constructor of the base is always called, even if parameterised of the derived is called 
    Derived d3(2,5); // the specific declaration of constructor in derived class leds to execution of parameterized constructor of base
    return 0; 
}