// enums - fixed set of named constants 
// collection of constant values under single name 
#include<bits/stdc++.h>
using namespace std; 
enum Day {Monday, Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday}; // unscoped enum ; the enumerators (members) are injected 
// into its surrounding scope - global scope 
enum class orderStatus {Placed, Shipped, Delivered, Cancelled}; // scoped enum hence we must specify the scope 
int main(){
    Day today = Saturday; 
    orderStatus status = orderStatus::Shipped; 
    switch(today){
        case Monday : 
        cout << "Today is Monday" << endl; 
        break;
        case Tuesday : 
        cout << "Today is Tuesday" << endl; 
        break;
        case Wednesday : 
        cout << "Today is Wednesday" << endl; 
        break;
        case Thursday : 
        cout << "Today is Thursday" << endl; 
        break;
        case Friday : 
        cout << "Today is Friday" << endl; 
        break;
        case Saturday : 
        cout << "Today is Saturday" << endl; 
        break;
        case Sunday : 
        cout << "Today is Sunday" << endl; 
        break;
    }

}