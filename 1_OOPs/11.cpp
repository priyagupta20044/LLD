#include<bits/stdc++.h>
using namespace std; 
class Parent{
    public : 
    void display(){
        cout << "Hello" << endl; 
    }
};
class A:virtual public Parent{
    public : 
};
class B:virtual public Parent{
    public : 
};
class C: public A, public B {
    
};
int main(){
    C obj; 
    obj.display(); // request for member 'display' is ambiguous 
    // this happens because there is no virtual base class 

    // we make A virtual base class to solve ambiguity 
    
}