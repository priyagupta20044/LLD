// incline functions 
#include<bits/stdc++.h>
using namespace std; 
class Student{
    string name; 
    int m1,m2; 

    public:
    Student(string name,int m1 ,int m2){
        this->name = name; 
        this->m1 = m1; 
        this->m2 = m2; 
    }
    // inline function
    float avg(); 

    // scope resolved function 
    void display(); 
};
inline float Student::avg(){
    return ((float)m1+m2)/2; 
}
void Student::display(){
    cout << "The marks of the student are : " << m1 << " " << m2 << endl; 
}
int main(){
    Student s1("Priya",99,100); 
    s1.display(); 
    cout << s1.avg() << endl; 
    return 0; 
}