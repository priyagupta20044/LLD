#include<iostream>
using namespace std;
// S - single responsibilty principle 
// The class must have only single reason to change, ie it should serve only one responsibility
// If it has multiple responsibilities, change in one can break the other 

// voilation of SRP 
class DeliveryApp{
    public: 
    void delivery(){
        cout << "Doing food delivery"; 
    }
    void generateInvoice(){
        cout << "Generating invoices"; 
    }
};

// in accordange to SRP 
class DeliveryParterner{
    public: 
    void delivery(){
        cout << "Doing food delivery"; 
    }
};
class InvoiceGenarator{
    public: 
    void generateInvoice(){
        cout << "Generating invoices"; 
    }
};
int main(){
    
    return 0;
}