// interfaces 
#include <bits/stdc++.h>
using namespace std; 
class Base {
    public:
    virtual int func() = 0; // pure virtual function 
    virtual int display() = 0; // pure virtual function 
    // since this only has pure virtual function - interface ; only meant to for runtmime polymorphism  
};
class Derived : public Base{
    int func(){
        cout << "Func" << endl ; 
        return 0; 
    }
    int display(){
        cout << "Display" << endl; 
        return 0; 
    }
};

// new example - also using the keyword "override"

class PaymentGateway{
    public: 
    virtual void makePayment() = 0; 
    // since it has only pure virtual function it is an interface
};
class PayTM:public PaymentGateway{
    public: 
    void makePayment() override { // override keyword is used to explicily override a function -> doesn't create a new function in case of typos 
        cout << "Make payment using PayTM" << endl ; 
    }
};
class Stripe : public PaymentGateway{
    public : 
    void makePayment() override {
        cout << "Make payment using Stripe" << endl; 
    }
};
int main(){
    PaymentGateway* mode1 = new Stripe; 
    PaymentGateway* mode2  = new PayTM; 
    mode1->makePayment(); 
    mode2->makePayment(); 
}