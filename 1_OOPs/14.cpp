// lose coupling eg 
#include<bits/stdc++.h>
using namespace std;
class MusicCompany{
    public: 
    virtual void playMusic() = 0; 
};
class Spotify:public MusicCompany{
    public:
    void playMusic() override {
        cout << "Playing spotify" << endl; 
    }
};
class YouTube:public MusicCompany{
    public:
    void playMusic() override {
        cout << "Playing YouTube" << endl; 
    }
};
class Apple:public MusicCompany{
    public:
    void playMusic() override {
        cout << "Playing Apple" << endl; 
    }
};
class MusicPlayer{
    private : 
    MusicCompany* musicCompany; 
    public: 

    // constructors 
    MusicPlayer(){musicCompany=nullptr;}
    MusicPlayer(MusicCompany* company):musicCompany(company) {}

    void setMusicCompany(MusicCompany* musicCompany){
        this->musicCompany = musicCompany; 
    }
    void playMusic(){
        if (musicCompany!=nullptr){
            musicCompany->playMusic(); 
        }
        else{
            cout << "No Company selected" << endl; 
        }
    }
}; 
int main(){
    MusicCompany* com1 = new Spotify; 
    MusicCompany* com2 = new Apple;
    MusicCompany* com3 = new YouTube;
    MusicCompany* com4 = new Spotify; 

    // creating service object 
    MusicPlayer player1(com1); 
    player1.playMusic();

    MusicPlayer player2(com2); 
    player2.playMusic(); 

    MusicPlayer player3; 
    player3.setMusicCompany(com3);
    player3.playMusic(); 

    MusicPlayer* player4 = new MusicPlayer(); 
    player4->setMusicCompany(com4);
    player4->playMusic(); 
    return 0;
}