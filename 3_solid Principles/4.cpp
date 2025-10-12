#include<iostream>
using namespace std;
// Interface segregation Principle (ISP)
// The interfaces must serve purpose specific to clients 
// Shouldn't force a client to inherit from an interface it doesnn't need. 
// but this is speicifically for interfaces

// voilation 
class MediaPlayer{
    public: 
    virtual void playSound() = 0; 
    virtual void playVideo() = 0; 
};
class MP3Player1:public MediaPlayer{
    public: 
    void playSound() override{
        cout << "Playing sound on MP3 Player1" << endl; 
    }
    void playVideo() override{
        cout << "Error: can't play video on MP3 Player1" <<endl; // not required 
    }
};
class VLCPlayer1:public MediaPlayer{
    public: 
    void playSound() override{
        cout << "Playing sound on VLC Player1" << endl; 
    }
    void playVideo() override{
      cout << "Playing video on VLC Player1" <<endl; 
    }
};

// following ISP 
class VoicePlayer{
    public: 
    virtual void playSound() = 0; 
};
class VideoPlayer{
    public: 
    virtual void playVideo() = 0;
};
class MP3Player2 : public VoicePlayer{
    public: 
    void playSound() override{
        cout << "Playing sound on MP3 Player2" << endl; 
    }
};
class VLCPlayer2:public VoicePlayer, public VideoPlayer{
    public: 
    void playSound() override{
        cout << "Playing sound on VLC player2" << endl; 
    }
    void playVideo() override{
        cout << "Playing video on VLC Player2" << endl; 
    }
};
int main(){
    MediaPlayer* p1 = new VLCPlayer1(); 
    MediaPlayer* p2 = new MP3Player1(); 
    MP3Player2* p3 = new MP3Player2(); 
    VLCPlayer2* p4 = new VLCPlayer2(); 

    p1->playSound(); 
    p1->playVideo(); 
    p2->playSound(); 
    p2->playVideo(); 
    p3->playSound(); 
    p4->playSound();
    p4->playVideo(); 
    return 0;
}