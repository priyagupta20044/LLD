// function overloading 
#include<bits/stdc++.h>
using namespace std; 
class MyClass {
    private: 
    int x,y,z; 
    public:
    MyClass(int x=0, int y=0, int z=0){
        this->x = x; 
        this->y = y;
        this->z = z;
    }
    MyClass(int x=0, int y=0){
        this->x = x; 
        this->y = y;
        this->z = z;
    }
    int sum (int x, int y){
        return x+y; 
    }
    int sum(int x, int y, int z){
        return x+y+z; 
    }

};
int main(){
    MyClass c1(4,2,7); 
    cout << c1.sum(4,7)<<endl; 
    cout << c1.sum(29,3,2); 
    return 0; 
}