#include<iostream>
using namespace std;
// Dependency inversions states that the high level class shouldn't depend on low level class 
// They both should depend on abstraction 

// Voilation 
class EmailSender{
    public: 
    void send(){
        cout << "Sending Email" <<endl; 
    }
};
class NotificationCentre{
    private:
    EmailSender emailSender; 
    public:
    NotificationCentre(EmailSender emailSender):emailSender(emailSender){}
    void notify(){
        emailSender.send(); 
    }
};
// we cannot add/switch another type of message without rewriting the notification centre class

// following DI 
class Sender{
    public:
    virtual void send() = 0; 
};
class EmailSender1:public Sender{
    public:
    void send() override{
        cout << "Sending an email" <<endl; 
    }
};
class SMSSender:public Sender{
    public:
    void send() override{
        cout << "Sending an SMS" << endl; 
    }
};
class NotificationCentre1{
    private:
    Sender* sender; // lose coupling ; writing a pointer -> aggrgative relationship 

    public:
    NotificationCentre1(Sender*sender):sender(sender) {}
    void notify() {
        sender->send(); 
    }
};
int main(){
    EmailSender s0; 
    NotificationCentre n0(s0); 
    n0.notify(); 
    Sender* s1 = new SMSSender() ;  
    Sender* s2 = new EmailSender1(); 
    NotificationCentre1 n1(s1);
    NotificationCentre1 n2(s2); 
    n1.notify(); 
    n2.notify(); 
    return 0;
}