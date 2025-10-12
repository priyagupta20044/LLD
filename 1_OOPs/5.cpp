// friend function 
#include <bits/stdc++.h>
using namespace std; 
class Bob;  // forward declaration 
class Alice{
    int snacks; 
    public:
    Alice(int x){
        this->snacks = x; 
    }
    friend void exchange(Alice &a, Bob &b); 
    int getSnacks(); 
    void setSnacks(int x){
        this->snacks = x; 
    }
};
class Bob{
    int snacks; 
    public:
    Bob (int x){
        this->snacks = x; 
    }
    friend void exchange(Alice &a, Bob &b); 
    int getSnacks();
    void setSnacks(int x){
        this->snacks = x; 
    }
};
void exchange(Alice &a, Bob &b){
    int temp = a.getSnacks(); 
    a.setSnacks(b.getSnacks()); 
    b.setSnacks(temp); 
    return ; 
}
int Alice::getSnacks(){
    return snacks; 
}
int Bob::getSnacks(){
    return snacks; 
}
int main(){
    Alice a(5); 
    Bob b(4); 
    exchange(a,b); 
    cout << a.getSnacks() << endl ; 
    cout << b.getSnacks() << endl ; 
    return 0; 
}