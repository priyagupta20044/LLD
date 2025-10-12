// dependency injection 
// when the class doesn't create the object inside it , but we pass it externally 
// it just stores an instance of it 
// it increases modularity, testability, and loose coupling 

#include<bits/stdc++.h>
using namespace std; 
class Fruit {
    string name;
    public: 
    Fruit (const string&name) : name(name) {}
};
class Basket{
    Fruit* fruit ; // dependency injection - from external code when it is passed as a parameter 
    public: 
    Basket (Fruit *fruit) : fruit(fruit) {}
};

int main(){
    Fruit *f1 = new Fruit("Apple"); 
    Basket b1 (f1); // externally injected 
    return 0;
}