// aggregation 
// students and school, here school is the whole and student is part 
// the lifecyles are loosely coupled because if school detroys then students continue to exist 
// students can be part of various schools and school doens't own the student 
// these are logically linked 

// IMPORTANT :  in the whole class, we create the vector of pointers to the part class, if otherwise, it indicates the ownership of the part by the whole which voilates the idea of aggregation 
// If we store the vector of pointer, it means even when the whole is destroyed, the parts continue to exists, as it refers to the pointers of part. 
#include <bits/stdc++.h>
using namespace std ;
class Student{
    private :
    string name ; 
    int roll_number; 

    public: 
    // constructor 
    Student(const string&name,int roll_number) : name(name),roll_number(roll_number) {}

    string getName(){return name;} 
}; 
class School {
    private:
    string name ; 
    vector<Student*>students; 

    public:
    // constructor 
    School(const string&name, const vector<Student*>&students):name(name),students(students){}

    void printStudents (); 
};
void inline School::printStudents(){
    cout << "Students of the school " << name << " are : " <<endl; 
    for (const auto &it:students){
        cout << "- " << it->getName()<<endl; 
    }
}
int main(){
    Student* s1 = new Student("Priya",139); 
    Student* s2 = new Student("Shreya",168); 
    Student* s3 = new Student("Tanya",199); 

    vector<Student*>students1 = {s1,s2}; 
    vector<Student*>students2 = {s2,s3}; 

    School sch1("DPS",students1);
    sch1.printStudents(); 

    School sch2("Amity",students2); 
    sch2.printStudents(); 
}