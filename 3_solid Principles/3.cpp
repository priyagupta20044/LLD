#include<iostream>
using namespace std;
// Liskov's substitution principle 
// the derived class must be able to substitue the parent 
// there shoudln't be exclusive properties which violates the properties of the parent 
// In other words, if A->B, then whenever we call a function of A (promised by parent), the child is expected to behave in that way. shouldn't break

// voilation of LSP 
class Account{
    public: 
    virtual void makePayment() = 0; 
};
class SavingAccount: public Account{
    public: 
    void makePayment() override{
        cout << "Making Payment" << endl; 
    }
};
class FixedDepositAccount : public Account{
    public: 
    void makePayment()override{
        throw runtime_error("Payment not allowed via FD account"); // this method is not allowed, so these classes cannot susbtitute each other 
    }
};

// follwing LSP 
class Account1{
    public:
    virtual void display() = 0; 
}; 
class WithdrawableAcccount:public Account1{
    public: 
    virtual void makePayment() = 0; 
}; 
class SavingAccount1 : public WithdrawableAcccount{
    public: 
    void display() override{
        cout << "This is a savings account" << endl ; 
    }
    void makePayment()override{
        cout << "Payment via saving account" << endl; 
    }
};
class FDAccount:public Account1{
    public: 
    void display() override{
        cout << "This is an FD Account" << endl; 
    }
};
int main(){
    Account* a1 = new FixedDepositAccount(); 
    Account1* a2 = new FDAccount(); 
    Account* a3 = new SavingAccount(); 
    WithdrawableAcccount* a4 = new SavingAccount1(); 

    // a1->makePayment(); 
    a2->display(); 
    a3->makePayment(); 
    a4->makePayment(); 
    a4->display(); 
    return 0;
}