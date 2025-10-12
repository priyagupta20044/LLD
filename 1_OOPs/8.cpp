// calling different types of constructors in multi-level inheritence 
#include<bits/stdc++.h>
using namespace std; 
class Line{
    int x; 
    public:
    Line (){
        cout << "Line default"<<endl; 
        this->x=0;
    }
    Line(int x) {
        cout << "Line parameterized"<<endl; 
        this->x=x;
    }
}; 
class Rectangle:public Line {
    int y; 
    public:
    Rectangle(){
        cout << "Rectangle default"<<endl; 
        this->y=0; 
    }
    Rectangle(int y){
        cout << "Rectangle parameterized 1"<<endl; 
        this->y = y; 
    }
    Rectangle (int x, int y) : Line(x){
    cout << "Rectangle parameterized 2"<<endl; 
        this->y=y; 
    }
};
class Cuboid : public Rectangle{
    int z; 
    public: 
    Cuboid (){
        cout << "Cuboid default"<<endl ; 
        this->z=0; 
    }
    Cuboid (int z){
        cout << "Cuboid parameterized 1"<<endl; 
        this->z=z;
    }
    Cuboid (int y, int z):Rectangle(y){
        cout << "Cuboid parameterized 2"<<endl;
        this->z=z;  
    }
    Cuboid (int x, int y, int z):Rectangle(x,y){
        cout << "Cuboid parameterized 3"<<endl;
        this->z=z;  
    }
};
int main(){
    Cuboid c1;
    cout << endl; 
    Cuboid c2(1); 
    cout << endl; 
    Cuboid c3(3,4); 
    cout << endl; 
    Cuboid c4(6,7,8); 
}