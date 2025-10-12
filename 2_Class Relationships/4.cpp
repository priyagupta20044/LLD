// dependency 
// when one object relies on another object but does so without storing instace of it 
// "uses-a" relationship 
// short lived, no ownership 
// happens when the other object is passed as paramter or is the return type 

#include<bits/stdc++.h>
using namespace std; 
class Document{
    string content; 
    public: 
    void display() const { // const avoids accidental alterations 
        cout << content <<endl; 
    }
};
class Printer{
    public: 
    void print(const Document &document) const {
        document.display(); 
    }
};