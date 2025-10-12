// composition 
// strongest type of association 
// 'has-a' relationship between the whole class and its parts 
// unlike aggregation it comes with the ownership and lifecycle dependency 
// If the container goes away, so do its parts 
// Parts is not shared by mulitple containers and its life depends on its whole 
// The container is responsible for creating, maangin and destroying the parts. 

#include<bits/stdc++.h>
using namespace std; 
class Room{
    private: 
    string name; 

    public : 
    // constructor 
    Room (const string &name) : name(name) {}

    void display(){
        cout << "The name of the room is : " << name << endl ;
    }
};
class House{
    private: 
    vector<Room> rooms; // created the vector of static objects not the pointers because we strore the original objects whose lifecycle is controlled rather than storing their instances in the form of pointer 

    public: 
    // constructor 
    House (){
        rooms.emplace_back("Living Room"); 
        rooms.emplace_back("Bed Room"); 
        rooms.emplace_back("Balcony"); 
    }
    // the constructor is responsible for creating the objects inside it which are intrinsic to the whole. 
    // We do not pass parameters or tell the house how to build "rooms" because it defines its own set of standards 
    void showHouse(){
        for (auto &it:rooms){
            it.display(); 
        }
    }
};

int main(){
    House h1; 
    h1.showHouse(); 
}