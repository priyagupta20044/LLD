#include<iostream>
using namespace std;
// Open closed principle means open to extension but closed to modification 
// the behaviour of the class must be extensible, but is shouldn't be modified 

// in accordance to OCP 
class Shape{
    public: 
    virtual double area() = 0; 
};
class Rectangle : public Shape{
    double l,b ; 
    public: 
    Rectangle( double l, double b){
        this->l = l; 
        this->b = b; 
    }
    double area() override {
        return l*b; 
    }
};
class Circle : public Shape{
    double r; 
    public:
    Circle(double r){
        this->r = r; 
    }
    double area() override{
        return 3.14*r*r;
    }
};
class AreaCalculator {
    public: 
    double calculate(Shape* s){
        cout << s->area()<<endl; 
    }
};
int main(){
    Shape* r = new Rectangle(4,7); 
    AreaCalculator calc; 
    calc.calculate(r);
    return 0;
}