// aggregation 
// This is a type of relationship which is stronger form of association. 
// It is a "has-a" relationship and represents a "whole-part" relationship. 
// The part can exist independently of the whole. 
// The part can be shared by multiple wholes. 
// These are logically linked and their lifetimes are independent. 

// IMPORTANT :  in the whole class, we create the vector of pointers to the part class, if otherwise, it indicates the ownership of the part by the whole which voilates the idea of aggregation 
// If we store the vector of pointer, it means even when the whole is destroyed, the parts continue to exists, as it refers to the pointers of part. 

// we use heap allocation (pointer object) for 
// - dynamic sharing 
// - runtime polumorphism (parent pointer and child object)
// - outlive the scope (lifetime)

// Use pointers inside collections when:
// - You want aggregation (objects live outside the collection).
// - You want sharing across multiple owners.
// - You don’t want the collection to destroy the objects.
#include<bits/stdc++.h>
using namespace std; 
class Professor{
    private : 
    string name ; 

    public: 
    // constructor 
    Professor(const string &name):name(name) {} // this takes a non constant literal as the parameter. To make it constant we add const 
    
    string getName(){return name;}
};
class Department{
    private:
    string name; 
    vector<Professor*>professors; 

    public: 
    // constructor
    Department(const string&name,const vector<Professor*>&professors):name(name),professors(professors) {}

    void printProfessors(); 
};
void inline Department::printProfessors(){
    cout  << "Professors of " << name << " department are : "<<endl; 
    for (const auto it:professors){
        cout << it->getName() << endl; 
    }
}
int main(){
    Professor* p1 = new Professor("Jenny"); 
    Professor* p2 = new Professor("Raj"); // here we create pointer because the constructor takes pointer as the argument. Though we can create a normal object and pass the pointer to this object 

    vector<Professor*>prof = {p1,p2}; 

    Department dept("CSE",prof); // we create a normal object since we do not need to share + simpler
    dept.printProfessors();
}