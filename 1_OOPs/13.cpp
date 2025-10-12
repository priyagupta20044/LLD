// loose coupling 
// Tight Coupling → When one class is directly dependent on a specific implementation of another class.
// Loose Coupling → When classes depend on abstractions (interfaces/abstract classes) rather than concrete implementations. This makes swapping implementations easier.
#include <bits/stdc++.h>
using namespace std; 
class PaymentGateway{
    public: 
    virtual float makePayment(int i) = 0;  // pure virtual function 
    // interface 
};
class Razorpay : public PaymentGateway{
    public:
    float makePayment(int i) override {
        cout << "Razorpay : " << i+0.1*i << endl; 
        return i + 0.1*i ; // added taxes; 
    } 
};
class Stripe : public PaymentGateway{
    public:
    float makePayment(int i) override {
        cout << "Stripe : " << i+0.2*i << endl; 
        return i + 0.2*i ; // added taxes; 
    } 
};
class ProcessPayment {
    private: 
    PaymentGateway* paymentGateway; 
    public : 
    // default constructor 
    ProcessPayment () {paymentGateway=nullptr;} 
    // parameterized constructor- not exactly a parameter but we pass a pointer to it 
    ProcessPayment (PaymentGateway* gateway) : paymentGateway(gateway)  {} // inject the payment gateway at the time of creating the object.
    
    // this allows us to change the gateway
    void setGateway(PaymentGateway* gateway){
        paymentGateway=gateway; 
    }

    void payment(int amount){
        if (paymentGateway!=nullptr){
            paymentGateway->makePayment(amount); 
        }
        else {
            cout << "No mode gateway selected" << endl;
        }
    }

}; 
int main(){
    PaymentGateway* mode1 = new Stripe;
    ProcessPayment process1(mode1); 
    process1.payment(44); 

    PaymentGateway* mode2 = new Razorpay; 
    ProcessPayment process2; 
    process2.setGateway(mode2); 
    process2.payment(44);
}