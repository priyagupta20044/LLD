// inheritence 
#include <bits/stdc++.h>
using namespace std; 
class Rectangle{
    int l,b; 
    public:
    Rectangle(int l=0, int b=0){
        this->l = l ; 
        this->b = b ;
    }
    void setLength(int l) {this->l = l;}
    void setBreadth(int b) {this->b = b;}
    int getLength() {return l;}
    int getBreadth() {return b;}

    void display(); 
};
void Rectangle :: display(){
    cout << "Length : " << l << " Breadth : " << b << endl; 
}
class Cuboid : public Rectangle{ // publicly inherited
    int h; 
    public:
    Cuboid(int l,int b, int h){
        this->h = h; // accessing its own private member 
        setLength(l); // accessing the public members of the parent class 
        setBreadth(b); 
        // this->l = l -> this is wrong; base cannot access the private members of parent; private are not inherted by base 
    }
    void display();
};
void Cuboid :: display(){
    cout << "Length : " << getLength() << " Breadth : " << getBreadth() << " Height : " << h << endl; 
}
int main(){
    Rectangle r1(3,5); 
    Cuboid c1(10,4,6) ; 
    r1.display(); 
    c1.display(); 
    return 0; 
}