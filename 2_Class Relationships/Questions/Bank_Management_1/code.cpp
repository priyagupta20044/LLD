#include<bits/stdc++.h>
using namespace std;
class Account{
    double balance; 
    public:
    Account (double balance): balance(balance){} 
    void depositMoney(double money){
        balance += money;
    }
    void withdrawMoney(double money){
        if (balance>=money){
            balance -= money; 
        }
        else {
            throw runtime_error("Insufficient Balance");
        }
    } 
};
class User{
    string name; 
    Account*account;

    public:
    User (const string&name):name(name){}
    void depositMoney(double money){
        account->depositMoney(money);
    }
    void withdrawMoney(double money){
        account->withdrawMoney(money); 
    }
};
class Bank{
    string name; 
    vector<Account>accounts; 
    vector<User>users; 

    public: 
    Bank(const string&name):name(name){}
    void addAccount(double balance){
        Account account(balance);
        accounts.emplace_back(account);
    }
    void addUser(const string&name){
        User user(name);
        users.emplace_back(user); 
    }
};
class AccountManager{
    Bank* bank; 
    public:
    AccountManager(Bank*bank):bank(bank){}
    void createAccount(double balance){
        bank->addAccount(balance);
    }
};
class UserManager{
    Bank* bank; 
    public: 
    UserManager(Bank*bank):bank(bank){}
    void createUser(const string&name){
        bank->addUser(name); 
    }
};
class BankManager{
    Bank* bank; 
    AccountManager* accountManager; 
    UserManager* userManager; 

    public: 
    BankManager(Bank*bank):bank(bank) {
        accountManager = new AccountManager(bank); 
        userManager = new UserManager(bank); 
    }
    void authorizeAccountCreation(string name, double balance){
        accountManager->createAccount(balance); 
        userManager->createUser(name);
    }
};
int main(){
    Bank* bank = new Bank("Axis"); 
    BankManager* bm = new BankManager(bank);  

    bm->authorizeAccountCreation("Alice",10332.22);
    return 0;
}