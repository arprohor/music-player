#include <bits/stdc++.h>
using namespace std;



class Song {
public:
    Song(string title,string artist) {
        
    }

    virtual void play() const {
        cout << "Playing: " << title<< artist << std::endl;
    }

private:
    string title;
    string artist;
};


class Playlist {
public:
    void addSong(Song song) {
        songs.push_back(song);
    }

    void playAll() const {
        for (const Song& song : songs) {
            song.play();
        }
    }

private:
    vector<Song> songs;
};

class MusicPlayer {
public:
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void next() = 0;
    virtual void previous() = 0;
};

class SimpleMusicPlayer : public MusicPlayer {
public:
    SimpleMusicPlayer(const Playlist& playlist)
        : playlist(playlist), isPlaying(false) {}

    void play() override {
        if (!isPlaying) {
            playlist.playAll();
            isPlaying = true;
        }
    }

    void pause() override {
        if (isPlaying) {
            cout << "Pausing" <<endl;
            isPlaying = false;
        }
    }

    void stop() override {
        if (isPlaying) {
            cout << "Stopping" << endl;
            isPlaying = false;
        }
    }

    void next() override {
        cout << "Playing next song" << endl;
    }

    void previous() override {
        cout << "Playing previous song" << endl;
    }

private:
    Playlist playlist;
    bool isPlaying;
};

int main() {
    Song song1("Song Title 1", "Artist 1");
    Song song2("Song Title 2", "Artist 2");

    Playlist playlist;
    playlist.addSong(song1);
    playlist.addSong(song2);

    SimpleMusicPlayer musicPlayer(playlist);

    musicPlayer.play();
    musicPlayer.pause();
    musicPlayer.play();
    musicPlayer.next();
    musicPlayer.previous();
    musicPlayer.stop();

    return 0;
}
